#include "projectile.h"

#include "engine.h"
#include "hit.h"
#include "vec.h"

Projectile::Projectile(Sprite sprite, Vec direction, Vec starting_position,
                       Vec ending_position, int damage)
    : Event{static_cast<int>(distance(ending_position, starting_position))},
      sprite{sprite},
      direction{direction},
      position{starting_position},
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
    Tile& tile = engine.dungeon.tiles(position);
    if (tile.actor) {
        engine.events.add(Hit{*tile.actor, damage});
    }
}