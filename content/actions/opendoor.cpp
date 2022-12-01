#include "opendoor.h"

#include "actor.h"
#include "engine.h"
#include "updatefov.h"

OpenDoor::OpenDoor(Vec position) : position{position} {}

Result OpenDoor::perform(Engine& engine) {
    bool opened_any_doors = false;
    Tile tile = engine.dungeon.tiles(position);
    if (tile.is_door()) {
        Door& door = engine.dungeon.doors.at(position);
        if (!door.is_open()) {
            door.open();
            tile.walkable = true;
            opened_any_doors = true;
        }
    }

    if (opened_any_doors) {
        engine.events.add(UpdateFOV{});
        return success();
    } else {
        return failure();
    }
}