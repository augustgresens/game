#include "projectile.h"

#include <cmath>

#include "engine.h"
#include "event.h"
#include "hit.h"

constexpr int duration = 5;
Projectile::Projectile(Sprite& sprite, Vec direction)
    : Event{duration}, sprite{sprite}, copy{sprite} {
    if (direction == Vec{1, 0}) {
        sprite.angle = -90;
    } else if (direction == Vec{-1, 0}) {
        sprite.angle = 90;
    } else if (direction == Vec{0, 1}) {
        sprite.angle = 0;
    } else if (direction == Vec{0, -1}) {
        sprite.angle = 180;
    }
}

void Projectile::execute(Engine& engine) {
    // engine.events.add(AnimationEvent{position});
    engine.camera.add_overlay(position, sprite);
}

void Projectile::when_done(Engine&) {
    sprite = copy;

    // engine.events.add(Hit{defender, damage});
}

// how do I add distance from shoot.cpp