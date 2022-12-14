#pragma once

#include "engine.h"

class Shoot : public Action {
public:
    Shoot();
    Result perform(Engine& engine) override;

private:
    Vec position;
};