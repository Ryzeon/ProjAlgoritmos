#pragma once

#include "Client.h"

#include <vector>
#include <cstring>

namespace drive_now_models {

    class CarInfo {
    public:
        string plate;
        string model;
        string color;
        int capacity;
        float cost_per_km;

    public:
        string getNiceCarInfo() {
            return model + " " + color + " " + plate;
        }

        string encode() {
            return plate + "," + model + "," + color + "," + to_string(capacity) + "," + to_string(cost_per_km);
        }

        static CarInfo* generateRandom(vector<string> models) {
            static string colors[] = {"black", "white", "red", "blue", "green", "yellow", "gray", "purple", "orange"};
            CarInfo* car_info = new CarInfo();
            car_info->plate = "";
            for (int i = 0; i < 6; i++) {
                car_info->plate += char(rand() % 26 + 65);
            }
            car_info->model = models[rand() % models.size()];
            car_info->color =  colors[rand() % 9];
            car_info->capacity = rand() % 4 + 1;
            car_info->cost_per_km = (rand() % 30 + 20) / 10.0;
            return car_info;
        }

        static CarInfo* decode(string encoded) {
            CarInfo* car_info = new CarInfo();
            // without split() function
            int index = 0;
            string temp = "";
            for (char c : encoded) {
                if (c == ',') {
                    switch (index) {
                        case 0:
                            car_info->plate = temp;
                            break;
                        case 1:
                            car_info->model = temp;
                            break;
                        case 2:
                            car_info->color = temp;
                            break;
                        case 3:
                            car_info->capacity = stoi(temp);
                            break;
                        case 4:
                            car_info->cost_per_km = stof(temp);
                            break;
                    }
                    temp = "";
                    index++;
                } else {
                    temp += c;
                }
            }
        }
    };


	class Driver: public Client {
	public:
		CarInfo* car_info;        

        static Driver* generateRandom(vector<string> names, vector<string> lastname, vector<string> models) {
            Driver* driver = new Driver();
            driver->id = "";
            for (int i = 0; i < 10; i++) {
                if (rand() % 2 == 0) {
                    driver->id += char(rand() % 26 + 65);
                } else {
                    driver->id += char(rand() % 26 + 97);
                }
            }
            driver->name = names[rand() % names.size()];
            driver->lastname = lastname[rand() % lastname.size()];
            driver->mail = driver->name + "." + driver->lastname + "@gmail.com";
            driver->phone = "+569" + to_string(rand() % 100000000);
            driver->pwd = "1234";
            driver->credit_card = CreditCard::generateRandom();
            driver->car_info = CarInfo::generateRandom(models);
            return driver;
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
            encoded += to_string(credit_card->type) + ",";
            encoded += car_info->encode();
            return encoded;
        }

        static Driver* decode(string from) {
            Driver* driver = new Driver();
            int pos = 0;
            string token;
            while ((pos = from.find(",")) != string::npos) {
                token = from.substr(0, pos);
                from.erase(0, pos + 1);
                switch (pos) {
                    case 0:
                        driver->id =  token;
                        break;
                    case 1:
                        driver->name = token;
                        break;
                    case 2:
                        driver->lastname = token;
                        break;
                    case 3:
                        driver->mail = token;
                        break;
                    case 4:
                        driver->phone = token;
                        break;
                    case 5:
                        driver->pwd = token;
                        break;
                    case 6:
                        driver->credit_card->number = token;
                        break;
                    case 7:
                        driver->credit_card->expiration = token;
                        break;
                    case 8:
                        driver->credit_card->cvv = stoi(token);
                        break;
                    case 9:
                        driver->credit_card->type = CC_Type(stoi(token));
                        break;
                    case 10:
                        driver->car_info = CarInfo::decode(token);
                        break;
                }
            }
            return driver;
        }
};


}
