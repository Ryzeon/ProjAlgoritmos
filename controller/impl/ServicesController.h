#pragma once

#include "../IController.h"
#include "../impl/ClientController.h"
#include "../ControllerBinder.h"
#include "../impl/DriveController.h"
#include "../../model/Driver.h"
#include "../../model/Client.h"
#include "../../model/UserReview.h"
#include "../../model/Service.h"

using namespace drive_now_models;

class ServicesController : public IController {
public:
    void load()  override {

    }


    string getName() {
        return "review";
    }
};
