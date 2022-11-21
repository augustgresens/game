#include "move.h"

#include "actor.h"
#include "engine.h"
#include "opendoor.h"

Move::Move(Vec direction) : direction{direction} {}

Result Move::perform(Engine& engine) {
    Vec position = actor->get_position();
    Vec new_position = position + direction;
    Tile& tile = engine.dungeon.tiles(new_position);
    if (tile.is_wall() || tile.actor) {
        return failure();
    } else if (tile.is_door() || tile.actor) {
        actor->move_to(new_position);
        return alternative(OpenDoor());
    } else {
        actor->change_direction(direction);
        actor->move_to(new_position);
        return success();
    }
}