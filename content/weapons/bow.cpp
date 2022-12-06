#include "bow.h"

#include "hit.h"

Bow::Bow(int damage) : Weapon{"bow", damage} {}

void Bow::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Hit{defender, damage});
    // Can add interesting features here
}