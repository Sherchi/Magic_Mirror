//
// Created by peter on 2021-11-07.
//

#ifndef UNTITLED2_USERSYSTEM_H
#define UNTITLED2_USERSYSTEM_H

#include <vector>
#include <string>
#include "User.h"

class UserSystem {
private:
    bool users_loaded;
    std::vector<User> users;
    User active_user;


public:
    UserSystem();
    ~UserSystem();

    void loadUsers();
    std::vector<std::string> getUsers();
    int login(std::string username, std::string password);
    bool logout();
    int changePassword(std::string old_password, std::string new_password);
    bool changeUsername(std::string new_username);
    int createUser(std::string username, std::string password, bool admin);
    int makeAdmin(std::string username);
    int removeAdmin(std::string username);
    User getActiveUser();





};


#endif //UNTITLED2_USERSYSTEM_H
