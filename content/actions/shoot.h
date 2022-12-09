#pragma once
#include "action.h"
#include "vec.h"

class Shoot : public Action {
public:
    Shoot(Actor& defender, Vec direction);
    Result perform(Engine& engine) override;

private:
    Actor& defender;
    Vec direction;
};