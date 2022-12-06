#include "sword_big.h"

#include "hit.h"

BigSword::BigSword(int damage) : Weapon{"sword_big", damage} {}

void BigSword::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Hit{defender, damage});
    // Can add interesting features here
}