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
        vector<string> lines = FileUtils::read("../services.dat");
        if (lines.size() > 0) {
            loadServices(lines);
        } else {
            createRandomServices(200);
            lines = FileUtils::read("../services.dat");
            loadServices(lines);
        }
    }

    void createRandomService(int max) {
        List<Service*> services;
        ClientController* client = (ClientController*) ControllerBinder::getInstance().getController("client");
        DriverController* driver = (DriverController*) ControllerBinder::getInstance().getController("driver");
        for (int i = 0; i < max; i++) {
            Service* service = Service::generateRandom(client->getRandomClient(), driver->getRandomDriver());
            services.add(service);
        }
        saveToFile(services);
    }

    string getName() {
        return "review";
    }
};
