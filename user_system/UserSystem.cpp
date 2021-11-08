//
// Created by peter on 2021-11-07.
//
//
// DEPENCENCY:
// sudo apt-get install libjsoncpp-dev


#include "UserSystem.h"
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


UserSystem::UserSystem()
{
    users_loaded = false;
    active_user;
    loadUsers();
}

UserSystem::~UserSystem() {

}

//FUNCTION: loadUsers
//DESCRIPTION: load user objects from json files into the system
//PARAMETERS:
//none
//RETURN:
//none, function is void
void UserSystem::loadUsers() {
    std::string path = "../useraccounts";
    //vector to store list of users in the useraccount directory
    std::vector<std::string> files_in_folder;

    //read the directory and save the filenames
    for(auto& entry : boost::make_iterator_range(boost::filesystem::directory_iterator(path), {})) {
        std::ostringstream file_str;
        file_str << entry;
        std::string p = file_str.str();
        files_in_folder.push_back(p);
    }

    //for each of the files, read the contents and create a user object
    for (std::string i: files_in_folder)
    {

        const std::string file_path = i.substr(1,i.length()-2);

        std::ifstream ifs;
        ifs.open(file_path);
        Json::Value user_json;
        ifs >> user_json;

        User *user = new User(file_path,user_json);
        users.push_back(*user);

        ifs.close();

    }

    users_loaded = true;

}

//FUNCTION: getUsers
//DESCRIPTION: get list of usernames for all the user accounts
//PARAMETERS:
//none
//RETURN:
//vector of std::string with usernames of all accounts
std::vector<std::string> UserSystem::getUsers() {
    std::vector<std::string> user_list;
    for(User u: users)
    {
        user_list.push_back(u.getUsername());
    }
    return user_list;
}

//FUNCTION: logout
//DESCRIPTION: logout of current logged-in user
//PARAMETERS:
//std::string username: username of user attempting to login
//std::string password: password of user attempting to login
//RETURN:
//returns 0 if successful
//returns -1 if username is wrong (does not exist)
//returns -2 if password is wrong
//return -3 if another user is already logged in
int UserSystem::login(std::string username, std::string password)
{
    if(!active_user.isActivated()) {
        for (User u: users) {
            if (username == u.getUsername()) {
                bool authenticated = u.authenticate(password);
                if (authenticated == true) {
                    active_user = u;
                    return 0;
                } else {
                    return -2;
                }
            }
        }
        return -1;
    }
    return -3;
}

//FUNCTION: logout
//DESCRIPTION: logout of current logged-in user
//PARAMETERS:
//none
//RETURN:
//return 0 if user logged in is successfully logged out
//return -1 if user cannot be logged out because no user is logged in
bool UserSystem::logout()
{
    if(active_user.isActivated()) {
        //create blank user as active user aka no user is active
        User *u = new User();
        active_user = *u;
        //return successful logout
        return 0;
    }
    else
    {
        return -1;
    }
}

//FUNCTION: changePassword
//DESCRIPTION: changes password of current logged-in user to the new_password
//PARAMETERS:
//std::string old_password: old password for user
//std::string new_password: new password for user
//RETURN:
//returns 0 if password of active user successfully changed
//returns -1 if password of active user not changed (e.g. old password is wrong)
//return -2 if there is no current active user to change password for
int UserSystem::changePassword(std::string old_password, std::string new_password) {
    if(active_user.isActivated())
    {
        bool change = active_user.changePassword(old_password,new_password);
        if(change)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -2;
    }
}

//FUNCTION: changeUsername
//DESCRIPTION: changes username of current logged-in user to the new_username
//PARAMETERS:
//std::string new_username: new username for the logged-in user
//RETURN:
//returns false if no user is active to change username for
//returns true if username changed
bool UserSystem::changeUsername(std::string new_username)
{
    if(!active_user.isActivated())
    {
        return false;
    }
    else
    {
        active_user.changeUsername(new_username);
        return true;
    }
}

//FUNCTION: createUser
//DESCRIPTION: create a new user with username and password and admin status
//PARAMETERS:
//std::string username:  username for new account
//std::string password: password for new account
//bool admin: admin status for new account, true or false
//RETURN:
//returns 0 if successful
//returns -1 if current active user not admin
//returns -2 if username is taken
// returns -3 if no active user
int UserSystem::createUser(std::string username, std::string password, bool admin)
{
    if(!active_user.isActivated())
    {
        return -3;
    }
    else
    {

        if(active_user.isAdmin())
        {
            bool username_taken = false;
            for(User u: users)
            {
                if(u.getUsername() == username)
                {
                    username_taken = true;
                }
            }

            if(username_taken)
            {
                return -2;
            }
            else
            {
                std::string file_path ="../useraccounts/"+username+".json";
                Json::Value object;
                object["username"] = username;
                object["password"] = password;
                object["admin"] = admin;

                User *user = new User(file_path,object);
                user->save();
                users.push_back(*user);
                return 0;
            }
        }
        else
        {
            return -1;
        }
    }
}

//FUNCTION: makeAdmin
//DESCRIPTION: set the admin status of user with username to true
//PARAMETERS:
//std::string username:  username for account to make admin
//RETURN:
//return 1 if user is already admin
//return 0 if successfully set the user with username to an admin
//return -1 if username does not correspond to a user
//return -2 if current user is not an admin
//return -3 if no user is currently active
int UserSystem::makeAdmin(std::string username)
{
    if(active_user.isActivated())
    {
        if(active_user.isAdmin()) {
            for (User u: users) {
                if (u.getUsername() == username) {
                    if(u.isAdmin())
                    {
                        return 1;
                    }
                    u.setAdmin(true);
                    return 0;
                }
            }
            return -1;
        }
        return -2;
    }
    return -3;
}

//FUNCTION: removeAdmin
//DESCRIPTION: set the admin status of user with username to false
//PARAMETERS:
//std::string username:  username for account to remove admin
//RETURN:
//return 1 if user is already not an admin
//return 0 if successfully set the user with username to an admin
//return -1 if username does not correspond to a user
//return -2 if current user is not an admin
//return -3 if no user is currently active
int UserSystem::removeAdmin(std::string username)
{
    if(active_user.isActivated())
    {
        if(active_user.isAdmin()) {
            for (User u: users) {
                if (u.getUsername() == username) {
                    if(!u.isAdmin())
                    {
                        return 1;
                    }
                    u.setAdmin(false);
                    return 0;
                }
            }
            return -1;
        }
        return -2;
    }
    return -3;
}

//FUNCTION: getActiveUser
//DESCRIPTION: get the user object of the current active user
//PARAMETERS:
//none
//RETURN:
//return User object of active user (logged-in)
User UserSystem::getActiveUser()
{
    return active_user;
}

