//
// Created by peter on 2021-11-07.
//

#ifndef UNTITLED2_USER_H
#define UNTITLED2_USER_H

#include <iostream>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>
#include <fstream>
#include <memory>
#include <jsoncpp/json/value.h>
#include <stdio.h>
#include <fstream>
#include "../MailClient/Inbox.h"

class User {
    private:
        bool is_activated;
        Json::Value user_json;
        std::string file;
        std::string username;
        std::string password;
        bool admin;
        Inbox* inbox;
        bool has_inbox;
        std::string email;
        std::string email_password;
        std::string email_imap_server;
        std::string calendar_file_path;
        std::fstream calendar_file;

    public:
        User();
        User(std::string user_file, Json::Value object);
        ~User();

        void print();
        bool isActivated();
        std::string getUsername();
        std::string getPassword();
        bool authenticate(std::string password);
        bool changePassword(std::string old_password, std::string new_password);
        void changeUsername(std::string new_username);
        bool isAdmin();
        void setAdmin(bool val);
        void update_json();
        void save();
        int configureInbox(std::string imap_server, std::string email_address, std::string email_password);
        Inbox* getInbox();
        bool hasInbox();
        std::string getCalendarFilePath();
        void setCalendarFilePath(std::string calendar_file_path);


};


#endif //UNTITLED2_USER_H
