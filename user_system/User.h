//
// Created by peter on 2021-11-07.
//

#ifndef UNTITLED2_USER_H
#define UNTITLED2_USER_H


#include <jsoncpp/json/value.h>

class User {
    private:
        bool is_activated;
        Json::Value user_json;
        std::string file;
        std::string username;
        std::string password;
        bool admin;

    public:
        User();
        User(std::string user_file, Json::Value object);
        ~User();

        void print();
        bool isActivated();
        std::string getUsername();
        bool authenticate(std::string password);
        bool changePassword(std::string old_password, std::string new_password);
        void changeUsername(std::string new_username);
        bool isAdmin();
        void setAdmin(bool val);
        void update_json();
        void save();


};


#endif //UNTITLED2_USER_H
