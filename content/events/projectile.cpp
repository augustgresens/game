#include "projectile.h"

#include <cmath>

#include "engine.h"
#include "event.h"
#include "hit.h"

constexpr int duration = 5;
Projectile::Projectile(Sprite& sprite, Vec direction)
    : Event{duration}, sprite{sprite}, copy{sprite} {
    if (direction == Vec{1, 0}) {
        starting_angle = -90;
    } else if (direction == Vec{-1, 0}) {
        starting_angle = 90;
    } else if (direction == Vec{0, 1}) {
        starting_angle = 0;
    } else if (direction == Vec{0, 1}) {
        starting_angle = 180;
    }
}

void Projectile::execute(Engine&) {
    if (starting_angle == 90) {
        sprite.shift.x += duration * frame_count;
    } else if (starting_angle == -90) {
        sprite.shift.x -= duration * frame_count;
    } else if (starting_angle == 0 || starting_angle == 180) {
        sprite.shift.y += duration * frame_count;
    } else if (starting_angle == 0 || starting_angle == 180) {
        sprite.shift.y -= duration * frame_count;
    }  // assuming cartesian
}

void Projectile::when_done(Engine& engine) {
    sprite = copy;

    // engine.events.add(Hit{defender, damage});
}