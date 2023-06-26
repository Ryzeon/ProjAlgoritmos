#pragma once

#include "IController.h"

using namespace utils;

class ControllerBinder {

private:


    List<IController*> *controllers;


public:
    ControllerBinder() {
        controllers = new List<IController*>();
    }

    static ControllerBinder& getInstance() {
        static ControllerBinder instance;
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