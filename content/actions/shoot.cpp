#include "shoot.h"

#include "engine.h"

Shoot::Shoot(Actor& defender, Vec direction)
    : defender{defender}, direction{direction} {}

Result Shoot::perform(Engine&) {
    Vec new_position = actor->get_position() + direction;
    actor->attack(defender);
    return success();
}