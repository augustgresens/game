#pragma once

#include "action.h"

class Actor;

class Rest : public Action {
public:
    Result perform(Engine& engine) override;
};