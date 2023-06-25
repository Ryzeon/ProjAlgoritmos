#pragma once

#include <iostream>

using namespace std;

namespace drive_now_models {
    class UserReview {
        public:
            string clientID;
            string driverID;
            int stars;
            string comment;
            string date;

            string encode() {
                string encoded = "";
                encoded += clientID + ";";
                encoded += driverID + ";";
                encoded += to_string(stars) + ";";
                encoded += comment + ";";
                encoded += date;
                return encoded;
            }

            static UserReview* decode(string input) {
                UserReview* review = new UserReview();
                int index = 0;
                string temp = "";
                for (char c : input) {
                    if (c == ';') {
                        switch (index) {
                            case 0:
                                review->clientID = temp;
                                break;
                            case 1:
                                review->driverID = temp;
                                break;
                            case 2:
                                review->stars = stoi(temp);
                                break;
                            case 3:
                                review->comment = temp;
                                break;
                            case 4:
                                review->date = temp;
                                break;
                        }
                        temp = "";
                        index++;
                    } else {
                        temp += c;
                    }
                }
                return review;
            }
    };   


};