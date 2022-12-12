#pragma once
#include "actor.h"
#include "camera.h"
#include "event.h"
#include "sprite.h"

class Projectile : public Event {
public:
    Projectile(Sprite& sprite, Vec direction, Vec starting_position,
               Vec ending_position);
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;

private:
    Sprite& sprite;
    Sprite copy;
    double starting_angle;
    Vec direction;
    Sprite arrow;
    Vec position;
    Vec starting_position;
    Vec ending_position;
};