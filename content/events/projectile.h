#pragma once
#include "actor.h"
#include "engine.h"
#include "vec.h"

class Projectile : public Event {
public:
    Projectile(Vec direction, Vec starting_position, int projectile_length);
    void execute(Engine &engine) override;
    // void when_done(Engine& engine) override;

private:
    Vec direction;
    Vec starting_position;
    int projectile_length;
    Vec position;

    // Not sure if I need to have arrow and position as private data.
    // Sprite arrow;
    // Vec position;
};