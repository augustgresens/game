#pragma once
#include "action.h"
#include "sprite.h"
#include "vec.h"

class Shoot : public Action {
public:
    Result perform(Engine& engine) override;

private:
    int damage;
    Sprite arrow;
};