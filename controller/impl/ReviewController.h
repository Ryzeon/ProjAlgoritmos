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

    List<UserReview*> reviews;

    void load() override {
        vector<string> reviews = FileUtils::read("../reviews.dat");
        if (reviews.size() > 0) {
            loadReviews(reviews);
        }
    }

    void loadReviews(vector<string> lines) {
        for (string line : lines) {
            UserReview* review = UserReview::decode(line);
            reviews.add(review);
        }
    }

    void saveReview(UserReview* review) {
        reviews.add(review);
        FileUtils::write("../reviews.dat", review->encode());
    }

    List<UserReview*> getReviewsByUser(string userID) {
     return reviews.search([&] (UserReview* user) {
         return user->clientID == userID;
     });
    }

    List<UserReview*> getReviewByDriver(string driverID) {
        return reviews.search([&] (UserReview* user) {
            return user->driverID == driverID;
        });
    }

    string getName() override {
        return "review";
    }

};