#include "projectile.h"

#include "actor.h"
#include "camera.h"
#include "event.h"
#include "sprite.h"

Projectile::Projectile(direction, starting_position, projectile_distance)
    : Event{projectile_distance},
      direction{direction},
      starting_position{starting_position},
      projectile_length{projectile_distance} {}

void Projectile::execute(Engine& engine) {
    if (frame_count == 0) {
        direction = actor->get_direction();
        arrow = engine.graphics.get_sprite("arrow");  // Sprite arrow?
        if (direction == Vec{1, 0}) {
            arrow.angle = 90;
        } else if (direction == Vec{-1, 0}) {
            arrow.angle = -90;
        } else if (direction == Vec{0, 1}) {
            arrow.angle = 0;
        } else if (direction == Vec{0, -1}) {
            arrow.angle = 180;
        }
    }
    position = position + direction;  // Vec position?
    engine.camera.add_overlay(position, arrow);
}

// void Projectile::when_done(Engine& engine) {
// Maybe remove the arrow sprite?
// }