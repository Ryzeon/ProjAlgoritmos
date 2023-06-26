#pragma once

#include "../IController.h"
#include "../../model/Driver.h"

using namespace drive_now_models;

class LoginController : public IController {
public:
    void load() override {

    }

    string getName() override {
        return "login";
    }

    bool verifiy_login(string username, string pwd) {
       ClientController* controller = (ClientController*)  ControllerBinder::getInstance().getController("client");
       List<Client*> cs = controller->clients.search([&] (Client* client) {
           return client->name == username && client->pwd == pwd;
       });
       return cs.getSize() > 0;
    }
};