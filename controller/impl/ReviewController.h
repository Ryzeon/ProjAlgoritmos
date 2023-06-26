#pragma once

#include "../IController.h"
#include "../impl/ClientController.h"
#include "../ControllerBinder.h"
#include "../impl/DriveController.h"
#include "../../model/Driver.h"
#include "../../model/Client.h"
#include "../../model/UserReview.h"

using namespace drive_now_models;

class ReviewController : public IController {
public:

    void load() override {
        vector<string> reviews = FileUtils::read("../reviews.dat");
        if (reviews.size() > 0) {
            loadReviews(reviews);
        } else {
            createRandomReviews(200);
            reviews = FileUtils::read("../reviews.dat");
            loadReviews(reviews);
        }
    }

    void createRandomReviews(int max) {
        List<UserReview*> reviews;
        ClientController* client = (ClientController*) ControllerBinder::getInstance().getController("client");
        DriverController* driver = (DriverController*) ControllerBinder::getInstance().getController("driver");
        ReviewController* driver = (DriverController*) ControllerBinder::getInstance().getController("driver");
        for (int i = 0; i < max; i++) {
            UserReview* review = UserReview::generateRandom(client->getRandomClient(), driver->getRandomDriver());
            reviews.add(review);
        }
        saveToFile(reviews);
    }

    void saveToFile(List<UserReview*> reviews) {
        vector<string> lines;
        for (int i = 0 ; i < reviews.getSize(); i++) {
            lines.push_back(reviews.get(i)->encode());
        }
        FileUtils::write_lines("../reviews.dat", lines);
    }

    void loadReviews(vector<string> lines) {

    }

    string getName() override {
        return "review";
    }

};