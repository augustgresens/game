#include "sword_big.h"

#include "hit.h"
#include "swing.h"

BigSword::BigSword(int damage) : Weapon{"sword_big", damage} {}

void BigSword::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
}