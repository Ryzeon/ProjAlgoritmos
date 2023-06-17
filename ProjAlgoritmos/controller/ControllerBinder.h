#pragma once

class ControllerBinder {

    // Using Singleton pattern
private:
    ControllerBinder();

    ~ControllerBinder() {
    }

    static ControllerBinder *instance;
public:
    static ControllerBinder *getInstance() {
        if (instance == nullptr) {
            instance = new ControllerBinder();
        }
        return instance;
    }

};