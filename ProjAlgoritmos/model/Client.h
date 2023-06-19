#pragma once

#include <iostream>
#include <utility>

using namespace std;

namespace drive_now_models {

    class UserInfo {
    public:
        string mail, phone;
        string pwd;

        UserInfo(string mail, string phone, string pwd) {
            this->mail = std::move(mail);
            this->phone = std::move(phone);
            this->pwd = std::move(pwd);
        }
    };

    class Client {
    public:
        string name;
        string lastname;
        UserInfo *info;

        Client(const string& name, const string& lastname, UserInfo* info) {
            this->name = name;
            this->lastname = lastname;
            this->info = info;

        }

    };
}
