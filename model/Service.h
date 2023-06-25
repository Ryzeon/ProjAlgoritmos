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
        string from, to;
        float price;
        float distance;
        string client_id, driver_id;
        string date;
        ServiceStatus status;

        long long time_remaining;

        Service(string from, string to, float price, float distance, string client_id, string driver_id, string date)
        {
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
};