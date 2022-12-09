```c++
if(tile.actor) {
    // True if the actor is on the tile
    // False when the actor isn't on the tile
}
```
key_bindings["space"] = reaction/function
key_bindings["w"] = reaction/function
key_bindings["a"] = reaction/function
key_bindings["s"] = reaction/function
key_bindings["d"] = reaction/function

{
    {"Space", shoot},
    {"Left", move_left}
    {"Right", move_right}
    {"Up", move_up}
    {"Down", move_down}
}

Result  success()
        failure()
        alternative(  Open door  )

Move(position)
    if(tile_is_door()) {
        Door& door = engine.dungeon.doors.at(pos);
        if (!door_is_open()){
            return alternative(openDoor(door));
        }
    }

    if(tile.is_walkable() == true) {
        return success();
    }
    else {
        return alternative{position};
    }

np = actor->get_position() + actor->get_direction()