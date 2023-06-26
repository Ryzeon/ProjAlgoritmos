#pragma once

#include "../utils/Utils.h";

#include <math.h>

using namespace utils;

namespace driver_now_models
{

    enum ServiceStatus
    {
        ON_THE_WAY,
        REVIEW_PENDING,
        FINISHED,
    };

    class Service
    {
    public:
        string id;
        string from, to;
        float price;
        float distance;
        string client_id, driver_id;
        string date;
        ServiceStatus status;

        long long time_remaining;

        Service() {
            this->id = StringUtils::generateID();
            this->from = "";
            this->to = "";
            this->price = 0;
            this->distance = 0;
            this->client_id = "";
            this->driver_id = "";
            this->date = "";
            this->status = ON_THE_WAY;
            this->time_remaining = 0;
        }

        Service(string from, string to, float price, float distance, string client_id, string driver_id, string date)
        {
            this->id = StringUtils::generateID();
            this->from = from;
            this->to = to;
            this->price = price;
            this->distance = distance;
            this->client_id = client_id;
            this->driver_id = driver_id;
            this->date = date;
            this->status = ON_THE_WAY;
            this->time_remaining =
                    (long long)ceil(distance);
            this->time_remaining = this->time_remaining * 60 * 1000;
        }

        string encode() {
            string encoded = "";
            encoded += id + ",";
            encoded += from + ",";
            encoded += to + ",";
            encoded += to_string(price) + ",";
            encoded += to_string(distance) + ",";
            encoded += client_id + ",";
            encoded += driver_id + ",";
            encoded += date + ",";
            encoded += to_string(status) + ",";
            encoded += to_string(time_remaining);
            return encoded;
        }

        static Service* decode(string encoded) {
            Service *service = new Service();
            int index = 0;
            string temp = "";
            for (char c : encoded) {
                if (c == ',') {
                    switch (index) {
                        case 0:
                            service->id = temp;
                            break;
                        case 1:
                            service->from = temp;
                            break;
                        case 2:
                            service->to = temp;
                            break;
                        case 3:
                            service->price = stof(temp);
                            break;
                        case 4:
                            service->distance = stof(temp);
                            break;
                        case 5:
                            service->client_id = temp;
                            break;
                        case 6:
                            service->driver_id = temp;
                            break;
                        case 7:
                            service->date = temp;
                            break;
                        case 8:
                            service->status = (ServiceStatus)stoi(temp);
                            break;
                        case 9:
                            service->time_remaining = stoll(temp);
                            break;
                    }
                    index++;
                    temp = "";
                } else {
                    temp += c;
                }
            }
            return service;
        }

        void endService()
        {
            if (time_remaining < 1)
            {
                this->status = REVIEW_PENDING;
            } else {
                time_remaining--;
            }
        }

        // in controller update time remaining to reduce and update status
    };

    class ServiceRequest {
    public:
        string from, to;
        float base_price;
        float current_price;
        float distance;
        string client_id;

        void sendToDrivers() {
        }

        void cancel() {

        }

        void updatePrice(float new_price) {
            this->current_price = new_price;
        }

        void takeService(string driver_id) {
        };
    };

    class RouteFinder {

    public:
        static float find_best_route(string from, string to) {
            float distance = 0;
            int fromCount = from.length();
            int toCount = to.length();
            distance = (float) (rand() % (fromCount + toCount) + 1);
        };
    };
};