#pragma onceonce

#include "../IController.h"

class DriverNowController : public IController {

    void load() override {

   }

    string getName() override {
        return "driver_now";
    }
};