#pragma once

#include "../IController.h"
#include "../../model/Client.h"

using namespace drive_now_models;
using namespace utils;

class ClientController : public IController {

public:
    List<string> names;
    List<string> lastnames;
    List<Client*> clients;

    void load() override {
        loadFromFile();
        vector<string> lines = FileUtils::read("../clients.dat");
        if (lines.size() > 0) {
            loadClients(lines);
        } else  {
            generateRandomClient(1000);
            lines = FileUtils::read("../clients.dat");
            loadClients(lines);
        }
        cout << "Clients loaded: " << clients.getSize() << endl;
    }

    void loadClients(vector<string> lines) {
        for (string line : lines) {
            Client* client = Client::decode(line);
            clients.add(client);
        }
    }

    void generateRandomClient(int max) {
        List<Client*> randomClients;
        for (int i = 0; i < max; i++) {
            Client* client = Client::generateRandom(names, lastnames);
            randomClients.add(client);
        }
        saveToFile(randomClients);
    }

    void saveToFile(List<Client*> clients) {
        vector<string> lines;
        for (int i = 0 ; i < clients.getSize(); i++) {
            lines.push_back(clients.get(i)->encode());
        }
        FileUtils::write_lines("../clients.dat", lines);
    }

    void loadFromFile() {
        vector<string> lines = FileUtils::read("../names.dat");
        for (string a: lines) {
            vector<string> splitted = StringUtils::split(a, '-');
            names.add(splitted[0]);
            lastnames.add(splitted[1]);
        }
    }

    string getName() override {
        return "client";
    }
};