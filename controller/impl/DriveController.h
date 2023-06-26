#pragma once

#include "../IController.h"

class DriverController : public IController {
public:
    List<string> brands;

    void load() override {
        loadFromFile();
    }

    bool existsDriverData() {
        fstream drivers_data("../drivers.dat");
        return drivers_data.is_open();
    }

    void createDriversData(int max) {

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