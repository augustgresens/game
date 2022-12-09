#include "spear.h"

#include "hit.h"
#include "swing.h"

Spear::Spear(int damage) : Weapon{"spear", damage} {}

void Spear::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
}