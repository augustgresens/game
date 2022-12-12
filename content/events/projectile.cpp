#include "projectile.h"

#include "engine.h"
#include "hit.h"

constexpr int duration = 5;

Projectile::Projectile(Sprite sprite, Vec direction, Vec starting_position,
                       Vec ending_position, int damage)
    : Event{duration},
      sprite{sprite},
      direction{direction},
      starting_position{starting_position},
      ending_position{ending_position},
      damage{damage} {
    if (direction == Vec{1, 0}) {
        sprite.angle = 90;
    } else if (direction == Vec{-1, 0}) {
        sprite.angle = -90;
    } else if (direction == Vec{0, 1}) {
        sprite.angle = 0;
    } else if (direction == Vec{0, -1}) {
        sprite.angle = 180;
    }
}

void Projectile::execute(Engine& engine) {
    engine.camera.add_overlay(position, arrow);
    position = position + direction;
}

void Projectile::when_done(Engine& engine) {
    ending_position = position;
    Tile& tile = engine.dungeon.tiles(ending_position);
    if (tile.actor) {
        engine.events.add(Hit{*tile.actor, damage});
    }
}