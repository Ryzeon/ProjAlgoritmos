#pragma once
#include "../utils/Utils.h"
#include "IController.h"

using namespace utils;

class ControllerBinder {

private:
    static ControllerBinder *instance;

    List<IController*> *controllers;

    ControllerBinder() {
        controllers = new List<IController*>();
    }
public:
    static ControllerBinder *getInstance() {
        if (instance == nullptr) {
            instance = new ControllerBinder();
        }
        return instance;
    }

    void addController(IController* controller) {
        controllers->add(controller);
    }

    void init() {
        for (int i = 0; i < controllers->getSize(); i++) {
            controllers->get(i)->load();
        }
    }


    IController& getController(string name) {
        for (int i = 0; i < controllers->getSize(); i++) {
            if (controllers->get(i)->getName() == name) {
                return *controllers->get(i);
            }
        }
        throw "Controller not found";
    }
};