#include "axe.h"

#include "hit.h"

Axe::Axe(int damage) : Weapon{"axe", damage} {}

void Axe::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Hit{defender, damage});
    // Can add interesting features here
}