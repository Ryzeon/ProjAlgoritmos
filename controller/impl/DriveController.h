#pragma once

#include "../IController.h"

class DriverController : public IController {
public:
    List<string> brands;

    void load() override {
        loadFromFile();
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