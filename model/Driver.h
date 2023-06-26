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

        static CarInfo* generateRandom(List<string> models) {
            static string colors[] = {"black", "white", "red", "blue", "green", "yellow", "gray", "purple", "orange"};
            CarInfo* car_info = new CarInfo();
            car_info->plate = "";
            for (int i = 0; i < 6; i++) {
                car_info->plate += char(rand() % 26 + 65);
            }
            car_info->model = models.get(rand() % models.getSize());
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
            return car_info;
        }
    };


	class Driver: public Client {
	public:
		CarInfo* car_info;

        static Driver* generateRandom(List<string> names, List<string> lastname, List<string> models) {
            Driver* driver = new Driver();
            driver->id = "";
            for (int i = 0; i < 10; i++) {
                if (rand() % 2 == 0) {
                    driver->id += char(rand() % 26 + 65);
                } else {
                    driver->id += char(rand() % 26 + 97);
                }
            }
            driver->name = names.get(rand() % names.getSize());
//            driver->name = names[rand() % names.getSize()];
            driver->lastname = lastname.get(rand() % lastname.getSize());
//            driver->lastname = lastname[rand() % lastname.getSize()];
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
            encoded += to_string(credit_card->cvv) + ",";
            encoded += to_string(credit_card->type) + ",";
            encoded += car_info->encode();
            return encoded;
        }

        static Driver* decode(string from) {
            auto* driver = new Driver();
            // decode
            int index = 0;
            string temp = "";
            for (char c : from) {
                if (c == ',') {
                    switch (index) {
                        case 0:
                            driver->id = temp;
                            break;
                        case 1:
                            driver->name = temp;
                            break;
                        case 2:
                            driver->lastname = temp;
                            break;
                        case 3:
                            driver->mail = temp;
                            break;
                        case 4:
                            driver->phone = temp;
                            break;
                        case 5:
                            driver->pwd = temp;
                            break;
                        case 6:
                            driver->credit_card->number = temp;
                            break;
                        case 7:
                            driver->credit_card->expiration = temp;
                            break;
                        case 8:
                            driver->credit_card->cvv = stoi(temp);
                            break;
                        case 9:
                            driver->credit_card->type = CC_Type(stoi(temp));
                            break;
                    }
                    if (index < 10) {
                        temp = "";
                        index++;
                    } else {
                        temp += c;
                    }
                } else {
                    temp += c;
                }
            }
            driver->car_info = CarInfo::decode(temp);
            return driver;
        }

        class ServiceLocation {
        public:
            string serviceId;

        };
};


}
