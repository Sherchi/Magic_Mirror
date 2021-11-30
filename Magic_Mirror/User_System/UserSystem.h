//
// Created by peter on 2021-11-07.
//

#ifndef UNTITLED2_USERSYSTEM_H
#define UNTITLED2_USERSYSTEM_H

#include <filesystem>
#include <string>
#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>
#include <fstream>
#include <typeinfo>
#include <sstream>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <vector>
#include <string>
#include "User.h"

class UserSystem {
private:
    bool users_loaded;
    std::vector<User*> users;
    User* active_user;
    UserSystem(const UserSystem& other) {};
    UserSystem& operator=(const UserSystem& other){ return *this;};
    static UserSystem* _instance;

protected:
    UserSystem();

public:
    virtual ~UserSystem();
    static UserSystem& instance();

    void loadUsers();
    std::vector<std::string> getUsers();
    int login(std::string username, std::string password);
    bool logout();
    int changePassword(std::string old_password, std::string new_password);
    bool changeUsername(std::string new_username);
    int createUser(std::string username, std::string password, bool admin);
    int makeAdmin(std::string username);
    int removeAdmin(std::string username);
    User* getActiveUser();

};


#endif //UNTITLED2_USERSYSTEM_H
