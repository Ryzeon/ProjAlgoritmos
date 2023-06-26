#pragma once

#include <iostream>

using namespace std;

namespace utils {
    class StringUtils {
    public:
        static string generateID() {
            string random_id = "";
            for (int i = 0; i < 10; i++) {
                if (rand() % 2 == 0) {
                    random_id += char(rand() % 26 + 65);
                } else {
                    random_id += char(rand() % 26 + 97);
                }
            }
        };
    };
}
