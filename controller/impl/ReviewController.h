#pragma once

#include "../IController.h"
#include "../../model/Driver.h"

using namespace drive_now_models;

class ReviewController : public IController {
public:
    void load() override {

    }

    string getName() override {
        return "review";
    }

};