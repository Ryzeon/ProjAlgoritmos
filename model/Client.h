#pragma once

#include <iostream>
#include <utility>
#include "../utils/Utils.h"

using namespace std;
using namespace utils;

namespace drive_now_models {

    enum CC_Type {
        VISA,
        MASTER,
        AMEX,
        DINNERS
    };

    class CreditCard {
        public:
        string number;
        string expiration;
        int cvv;
        CC_Type type;

        static CreditCard* generateRandom() {
            CreditCard* cc = new CreditCard();
            string number;
            for (int i = 0; i < 16; i++) {
                number += to_string(rand() % 10);
            }
            cc->expiration = "12/24";
            cc->cvv = rand() % 1000;
            cc->type = CC_Type(rand() % 4);
            return cc;
        }
    };

    class Client {
    public:
        string id;
        string name;
        string lastname;
        string mail;
        string phone;
        string pwd;

        CreditCard* credit_card;

Client() {
    credit_card = CreditCard::generateRandom();
}

    Client(string name, string lastname, string mail, string phone, string pwd) {

        this->id = StringUtils::generateID();

        this->name = std::move(name);
        this->lastname = std::move(lastname);
        this->mail = std::move(mail);
        this->phone = std::move(phone);
        this->pwd = std::move(pwd);
        credit_card = CreditCard::generateRandom();
    }

    string encode() {
        string encoded = "";
        encoded += id + ",";
        encoded += name + ",";
        encoded += lastname + ",";
        encoded += mail + ",";
        encoded += phone + ",";
        encoded += pwd + ",";
        encoded += credit_card->number + ",";
        encoded += credit_card->expiration + ",";
        encoded += credit_card->cvv + ",";
        encoded += to_string(credit_card->type);
        return encoded;
    }

    static Client* decode(string from) {
        Client* client = new Client();
        int pos = 0;
        string token;
        while ((pos = from.find(",")) != string::npos) {
            token = from.substr(0, pos);
            from.erase(0, pos + 1);
            switch (pos) {
                case 0:
                    client->id =  token;
                    break;
                case 1:
                    client->name = token;
                    break;
                case 2:
                    client->lastname = token;
                    break;
                case 3:
                    client->mail = token;
                    break;
                case 4:
                    client->phone = token;
                    break;
                case 5:
                    client->pwd = token;
                    break;
                case 6:
                    client->credit_card->number = token;
                    break;
                case 7:
                    client->credit_card->expiration = token;
                    break;
                case 8:
                    client->credit_card->cvv = stoi(token);
                    break;
                case 9:
                    client->credit_card->type = CC_Type(stoi(token));
                    break;
            }
        }
        return client;
    }

    };
}
