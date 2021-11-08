//
// Created by peter on 2021-11-07.
//

#include "User.h"
#include <iostream>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>
#include <fstream>
#include <memory>

//FUNCTION: User() default constructor
//DESCRIPTION: default constructor creates user object as unactivated user (no related data)
//PARAMETERS:
//none
//RETURN:
//none, type is void
User::User()
{
    is_activated = false;
}

//FUNCTION: User() data constructor
//DESCRIPTION:  constructor creates user object as activated user (has related data)
//PARAMETERS:
//std::string user_file: string with file path of user
//Json::Value object: the json object representing the user data
//RETURN:
//User object of activated user
User::User(std::string user_file, Json::Value object)
{
    is_activated = true;
    file = user_file;
    user_json = object;
    username = object["username"].asString();
    password = object["password"].asString();
    admin = object["admin"].asBool();
}

//FUNCTION: ~User destructor
//DESCRIPTION: destructor method for user object, save the user
//PARAMETERS:
//none
//RETURN:
//none, type is void
User::~User()
{
    save();
}

//FUNCTION: print
//DESCRIPTION: print out data of user in readable way to standard output, for testing
//PARAMETERS:
//none
//RETURN:
//none, type is void
void User::print()
{
    std::cout << "Username: " + username << std::endl;
    std::cout << "Password: " + password << std::endl;
    std::cout << "Admin: " + admin << std::endl;
}

//FUNCTION: isActivated
//DESCRIPTION: returns whether or not the user object is an actual activated user (has username password data etc)
//PARAMETERS:
//none
//RETURN:
//boolean representing whether or not user object is activated
bool User::isActivated()
{
    return is_activated;
}

//FUNCTION: getUsername
//DESCRIPTION: get username of user
//PARAMETERS:
//none
//RETURN:
//std::string with usernames of user
std::string User::getUsername()
{
    return username;
}

//FUNCTION: authenticate
//DESCRIPTION: authenticate a user with their password
//PARAMETERS:
//std::string pwd: password of user
//RETURN:
//bool, true if password correct, false otherwise
bool User::authenticate(std::string pwd)
{
    if (password == pwd)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//FUNCTION: changePassword
//DESCRIPTION: changePassword of user
//PARAMETERS:
//std::string old_password: old / current password of user
//std::string new_password: new password for user
//RETURN:
//bool, true if password successfully changed, false otherwise
bool User::changePassword(std::string old_password, std::string new_password)
{
    if(password == old_password)
    {
        password = new_password;
        save();
        return true;
    }

    return false;

}

//FUNCTION: changeUsername
//DESCRIPTION: changeUsername of user
//PARAMETERS:
//std::string new_username: new username for user
//RETURN:
//none, function is void
void User::changeUsername(std::string new_username)
{
    username = new_username;
    save();
}

//FUNCTION: isAdmin
//DESCRIPTION: returns admin status of user
//PARAMETERS:
//none
//RETURN:
//boolean representing whether or not user is admin (true for admin, false for not)
bool User::isAdmin()
{
    return admin;
}

//FUNCTION: setAdmin
//DESCRIPTION: set admin status of user
//PARAMETERS:
//bool, true for admin, false for not admin
//RETURN:
//none, function is void
void User::setAdmin(bool val)
{
    admin = val;
    save();
}

//FUNCTION: update_json
//DESCRIPTION: update the Json::Value object holding user data
//PARAMETERS:
//none
//RETURN:
//none, function is void
void User::update_json()
{
    user_json["username"] = username;
    user_json["password"] = password;
    user_json["admin"] = admin;
}

//FUNCTION: save
//DESCRIPTION: save the Json::Value data of user object to the user json file
//PARAMETERS:
//none
//RETURN:
//none, function is void
void User::save()
{
    //make sure json is updated
    update_json();

    //create output file stream for user file
    std::ofstream file_id;
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "   ";
    std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    std::ofstream outputFileStream(file);
    //write the json object to the user file with updated data
    writer -> write(user_json, &outputFileStream);

}
