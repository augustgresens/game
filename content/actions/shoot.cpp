#include "shoot.h"

#include "actor.h"
#include "attack.h"
#include "engine.h"
#include "projectile.h"
#include "vec.h"

Shoot::Shoot(int damage) : damage{damage} {}

Result Shoot::perform(Engine& engine) {
    Sprite sprite = engine.graphics.get_sprite("arrow");
    starting_position = actor->get_position();
    direction = actor->get_direction();
    new_position = starting_position + direction;
    while (open_tile) {
        Tile& tile = engine.dungeon.tiles(new_position);
        if (tile.is_wall()) {
            open_tile = false;
        } else if (tile.is_door()) {
            Door& door = engine.dungeon.doors.at(new_position);
            if (!door.is_open()) {
                open_tile = false;
            }
        } else if (tile.actor) {
            open_tile = false;
            engine.events.add(Projectile{sprite, direction, starting_position,
                                         ending_position});
            return alternative(Attack{*tile.actor});
        } else {
            new_position = new_position + direction;
        }
    }
    ending_position = new_position;
    return success();
}