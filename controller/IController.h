#pragma once

#include <iostream>

#include "../utils/Utils.h"

using namespace std;
using namespace utils;

class IController {
public:

    virtual void load() {
        // TODO - implement IController::save
    };

    virtual string getName() {
        return "N/A";
    }
};