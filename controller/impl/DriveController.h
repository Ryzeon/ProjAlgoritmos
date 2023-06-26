#pragma once

#include "../IController.h"
#include "../../model/Driver.h"

using namespace drive_now_models;

class DriverController : public IController {
public:
    List<string> brands;

    List<Driver*> drivers;

    void load() override {
        loadFromFile();
        vector<string> lines = FileUtils::read("../drivers.dat");
        if (lines.size() > 0) {
            loadDriversData(lines);
        } else {
            createDriversData(1000);
            lines = FileUtils::read("../drivers.dat");
            loadDriversData(lines);
        }
        cout << "Drivers loaded: " << drivers.getSize() << endl;
    }

    void loadDriversData(vector<string> lines) {
        for (string line : lines) {
            Driver* driver = Driver::decode(line);
            drivers.add(driver);
        }
    }

    void createDriversData(int max) {
        List<Driver*> drivers;
        ClientController* client = (ClientController*) ControllerBinder::getInstance().getController("client");
        for (int i = 0; i < max;  i++) {
            Driver* driver = Driver::generateRandom(client->names, client->lastnames, brands);
            drivers.add(driver);
        }
        saveToFile(drivers);
    }

    void saveToFile(List<Driver*> drivers) {
        vector<string> lines;
        for (int i = 0 ; i < drivers.getSize(); i++) {
            lines.push_back(drivers.get(i)->encode());
        }
        FileUtils::write_lines("../drivers.dat", lines);
    }

    void loadFromFile() {
        vector<string> lines = FileUtils::read("../cars.dat");
        for (string a: lines) {
           brands.add(a);
        }
    }

    string getName() override {
        return "driver";
    }
};