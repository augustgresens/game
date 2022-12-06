#pragma once
#include "engine.h"
#include "weapon.h"

class Bow : public Weapon {
public:
    Bow(int damage);
    void use(Engine& engine, Actor& attacker, Actor& defender) override;
};