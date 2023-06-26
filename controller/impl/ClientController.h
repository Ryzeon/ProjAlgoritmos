#pragma once

#include "../IController.h"

class ClientController : public IController {

public:
    List<string> names;
    List<string> lastnames;

    void load() override {
        loadFromFile();
    }

    void loadFromFile() {
        vector<string> lines = FileUtils::read("../names.dat");
        for (string a: lines) {
            // split by " " and add to names and lastnames
            vector<string> splitted = StringUtils::split(a, ' ');
            names.add(splitted[0]);
            lastnames.add(splitted[1]);
        }
    }

    string getName() override {
        return "client";
    }
};