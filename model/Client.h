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

        static CreditCard *generateRandom() {
            CreditCard *cc = new CreditCard();
            string number = "";
            for (int i = 0; i < 16; i++) {
                number += to_string(rand() % 10);
            }
            cc->number = number;
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

        CreditCard *credit_card;

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

        static Client* generateRandom(List<string> name, List<string> lastname) {
            Client* client = new Client();
            client->id = "";
            for (int i = 0; i < 10; i++) {
                if (rand() % 2 == 0) {
                    client->id += char(rand() % 26 + 65);
                } else {
                    client->id += char(rand() % 26 + 97);
                }
            }
            client->name = name.get(rand() % name.getSize());
            client->lastname = lastname.get(rand() % lastname.getSize());
            client->mail = client->name + "." + client->lastname + "@gmail.com";
            client->phone = "+569" + to_string(rand() % 100000000);
            string pass = "";
            for (int i = 0; i < 4; i++) {
                pass += to_string(rand() % 10);
            }
            for (int i = 0; i < 4; i++) {
                pass += char(rand() % 26 + 65);
            }
            for (int i = 0; i < 4; i++) {
                pass += char(rand() % 26 + 97);
            }
            client->pwd = pass;
            client->credit_card = CreditCard::generateRandom();
            return client;
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
            encoded += to_string(credit_card->cvv) + ",";
            encoded += to_string(credit_card->type);
            return encoded;
        }

        static Client *decode(string from) {
            Client *client = new Client();
            int index = 0;
            string temp = "";
            for (char c : from) {
                if (c == ',') {
                    switch (index) {
                        case 0:
                            client->id = temp;
                            break;
                        case 1:
                            client->name = temp;
                            break;
                        case 2:
                            client->lastname = temp;
                            break;
                        case 3:
                            client->mail = temp;
                            break;
                        case 4:
                            client->phone = temp;
                            break;
                        case 5:
                            client->pwd = temp;
                            break;
                        case 6:
                            client->credit_card->number = temp;
                            break;
                        case 7:
                            client->credit_card->expiration = temp;
                            break;
                        case 8:
                            client->credit_card->cvv = stoi(temp);
                            break;
                        case 9:
                            client->credit_card->type = CC_Type(stoi(temp));
                            break;
                        default:
                            break;
                    }
                    temp = "";
                    index++;
                } else {
                    temp += c;
                }
            }
            return client;
        }

    };
}
