#pragma once

#include <iostream>

using namespace std;

class IController {
public:

    virtual void load() {
        // TODO - implement IController::save
    };

    virtual string getName() {
        return "N/A";
    }
};