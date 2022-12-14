#include "projectile.h"

#include "camera.h"
#include "event.h"
#include "sprite.h"

Projectile::Projectile(Vec direction, Vec starting_position,
                       int projectile_distance)
    : Event{projectile_distance},
      direction{direction},
      position{starting_position},
      projectile_length{projectile_distance} {}

void Projectile::execute(Engine& engine) {
    Sprite arrow = engine.graphics.get_sprite("arrow");
    if (frame_count == 0) {
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
    position = position + direction;
    engine.camera.add_overlay(position, arrow);
}

// void Projectile::when_done(Engine& engine) {
// Maybe remove the arrow sprite?
// }
