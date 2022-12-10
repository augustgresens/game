#pragma once
#include "actor.h"
#include "event.h"

class Projectile : public Event {
public:
    Projectile(Sprite& sprite, Vec direction);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Sprite& sprite;
    Sprite copy;
    double starting_angle;
    Vec position;
};