#include "move.h"

#include "actor.h"
#include "attack.h"
#include "engine.h"
#include "opendoor.h"

Move::Move(Vec direction) : direction{direction} {}

Result Move::perform(Engine& engine) {
    Vec position = actor->get_position();
    Vec new_position = position + direction;
    Tile& tile = engine.dungeon.tiles(new_position);
    if (tile.is_wall()) {
        return failure();
    }
    // if (tile.actor) {
    //     return alternative(Attack{*tile.actor});
    // }
    if (tile.is_door()) {
        Door& door = engine.dungeon.doors.at(position);
        if (!door.is_open()) {
            return alternative(OpenDoor{new_position});
        }
    }
    actor->change_direction(direction);
    actor->move_to(new_position);
    return success();
}