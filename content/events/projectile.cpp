#include "projectile.h"

#include "engine.h"
#include "hit.h"

constexpr int duration = 5;

Projectile::Projectile(Sprite& sprite, Vec direction, Vec starting_position,
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
    // The issue might be here with sprite?
    arrow.angle = sprite.angle;
    if (frame_count == 0) {
        AnimatedSprite sprite = engine.graphics.get_animated_sprite("arrow", 1);
        number_of_frames = sprite.number_of_frames();
    }
    engine.camera.add_overlay(position, sprite.get_sprite());
    // arrow for sprite.get_sprite()?
    sprite.update();
    // position = position + direction;
}

void Projectile::when_done(Engine& engine) {
    ending_position = position;
    Tile& tile = engine.dungeon.tiles(ending_position);
    engine.events.add(Hit{*tile.actor, damage});
}