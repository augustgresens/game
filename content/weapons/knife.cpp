#include "knife.h"

#include "hit.h"

Knife::Knife(int damage) : Weapon{"knife", damage} {}

void Knife::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Hit{defender, damage});
    // Can add interesting features here
}