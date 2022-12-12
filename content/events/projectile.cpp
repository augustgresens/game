#include "projectile.h"

#include "camera.h"
#include "engine.h"
#include "event.h"
#include "hit.h"
#include "sprite.h"

constexpr int duration = 5;

Projectile::Projectile(Sprite& sprite, Vec direction, Vec starting_position,
                       Vec ending_position)
    : Event{duration},
      sprite{sprite},
      copy{sprite},
      direction{direction},
      starting_position{starting_position},
      ending_position{ending_position} {
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
    if (frame_count == 0) {
        arrow = engine.graphics.get_sprite("arrow");
        arrow.angle = sprite.angle;
    }
    engine.camera.add_overlay(position, arrow);
    position = position + direction;
}

void Projectile::when_done(Engine& engine) {
    Tile& tile = engine.dungeon.tiles(position);
    engine.events.add(Hit{*tile.actor, 3});
}

// how do I add distance from shoot.cpp