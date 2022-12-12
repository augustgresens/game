#include "bow.h"

#include "actor.h"
#include "hit.h"
#include "projectile.h"
#include "swing.h"

Bow::Bow(int damage) : Weapon{"bow", damage} {}

void Bow::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    if (distance(defender.get_position(), attacker.get_position()) == 1) {
        engine.events.add(Swing{sprite, direction, defender, damage});
    } else {
        engine.events.add(Projectile{sprite, direction, attacker.get_position(),
                                     defender.get_position(), 3});
    }
}