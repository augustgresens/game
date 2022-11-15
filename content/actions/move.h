#pragma once
#include "action.h"
#include "vec.h"

class Move : public Action {
public:
    int move(Vec direction);
    Result perform(Engine& engine) override;

private:
    Vec direction;
};