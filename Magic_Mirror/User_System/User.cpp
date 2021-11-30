/*
 * @brief This class defines the class object implementation of User, as defined in User.h
 *
 * @authors Peter Meijer
 * */


#include "User.h"

/*
 * @brief User constructor, set up blank user with blank inbox, unactivated
 *
 * @param No parameters.
 *
 * @return No return
 *
 * @authors Peter Meijer.
 * */
User::User()
{
    is_activated = false;
    has_inbox = false;
    inbox = new Inbox();
}


/*
 * @brief User() data constructor constructor creates user object as activated user (has related data)
 *
 * @param std::string user_file: string with file path of user
 * @param Json::Value object: the json object representing the user data
 *
 * @return No return
 *
 * @authors Peter Meijer.
 * */
User::User(std::string user_file, Json::Value object)
{
    //set objects vars
    is_activated = true;
    file = user_file;
    user_json = object;
    username = object["username"].asString();
    password = object["password"].asString();
    admin = object["admin"].asBool();
    has_inbox = object["has_inbox"].asBool();
    calendar_file_path = object["calendar_file_path"].asString();

    //setup inbox if exists
    if(has_inbox)
    {
        std::cout << username << " has inbox." << std::endl;
        email = object["email"].asString();
        email_password = object["email_password"].asString();
        email_imap_server = object["email_imap_server"].asString();
        inbox = new Inbox(email_imap_server,email,email_password);
    }
    else
    {
        std::cout << username << " NO inbox." << std::endl;
        inbox = new Inbox();
    }

}

/*
* @brief User() destructor
*
* @param None
*
* @return No return
*
* @authors Peter Meijer.
* */
User::~User()
{
    save();
    delete inbox;
}

/*
 * @brief print the user data
 *
 * @param None
 *
 * @return No return
 *
 * @authors Peter Meijer.
 * */
void User::print()
{
    std::cout << "Username: " + username << std::endl;
    std::cout << "Password: " + password << std::endl;

    inbox->print();
}

/*
 * @brief Getter for if user is an activated user account
 *
 * @param None
 *
 * @return bool is user activated
 *
 * @authors Peter Meijer.
 * */
bool User::isActivated()
{
    return is_activated;
}

/*
 * @brief Getter for username
 *
 * @param None
 *
 * @return string username
 *
 * @authors Peter Meijer.
 * */
std::string User::getUsername()
{
    return username;
}

/*
 * @brief Getter for password
 *
 * @param None
 *
 * @return string password
 *
 * @authors Peter Meijer.
 * */
std::string User::getPassword() {
    return password;
}

/*
 * @brief authenticate the user against a password
 *
 * @param pwd password of user account
 *
 * @return boolean, whether or not login succeeded
 *
 * @authors Peter Meijer.
 * */
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

/*
 * @brief method to change user password
 *
 * @param old_password old password for account
 * @param new_password to be set for account
 *
 * @return boolean, whether or not change password succeeded
 *
 * @authors Peter Meijer.
 * */
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

/*
 * @brief method to change user username
 *
 * @param new_username for user
 *
 * @return No return.
 *
 * @authors Peter Meijer.
 * */
void User::changeUsername(std::string new_username)
{
    username = new_username;
    save();
}

/*
 * @brief method to get whether or not user is admin
 *
 * @param No params.
 *
 * @return bool representing if admin or not
 *
 * @authors Peter Meijer.
 * */
bool User::isAdmin()
{
    return admin;
}

/*
 * @brief method to set user as admin
 *
 * @param bool representing admin
 *
 * @return No return.
 *
 * @authors Peter Meijer.
 * */
void User::setAdmin(bool val)
{
    admin = val;
    save();
}

/*
 * @brief method to update the json object of the user
 *
 * @param No params.
 *
 * @return No return
 *
 * @authors Peter Meijer.
 * */
void User::update_json()
{
    user_json["username"] = username;
    user_json["password"] = password;
    user_json["admin"] = admin;
    user_json["has_inbox"] = has_inbox;
    user_json["email"] = email;
    user_json["email_imap_server"] = email_imap_server;
    user_json["email_password"] = email_password;
    user_json["calendar_file_path"] = calendar_file_path;


}

/*
 * @brief method to save the json object of the user in the file
 *
 * @param No params.
 *
 * @return No return
 *
 * @authors Peter Meijer.
 * */
void User::save()
{
    //make sure json is updated
    update_json();

    //create output file stream for user file
    std::ofstream file_id;

    //builder
    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "   ";

    std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    std::ofstream outputFileStream(file);

    //write the json object to the user file with updated data
    writer -> write(user_json, &outputFileStream);

}

/*
 * @brief method to configure an inbox to a user account
 *
 * @param imap_server imap_server
 * @param email_address email_address
 *  @param email_password email_password
 *
 * @return return 0 for success
 * @return return -1 for no active user
 *
 * @authors Peter Meijer.
 * */
int User::configureInbox(std::string imap_server, std::string email_address, std::string email_password)
{
    if(isActivated()) {
        has_inbox = true;
        email = email_address;
        this->email_password = email_password;
        email_imap_server = imap_server;
        inbox = new Inbox(email_imap_server, email, email_password);
        save();
        return 0;
    }
    return -1;
}


/*
 * @brief method to get the inbox
 *
 * @param No params.
 *
 * @return Inbox inbox object of user
 *
 * @authors Peter Meijer.
 * */
Inbox* User::getInbox() {
    return inbox;
}

/*
 * @brief method to check if user has inbox
 *
 * @param No params.
 *
 * @return Inbox inbox object of user
 *
 * @authors Peter Meijer.
 * */
bool User::hasInbox()
{
    return has_inbox;
}

/*
 * @brief method to get File path of calendar file
 *
 * @param No params.
 *
 * @return string representation of file path
 *
 * @authors Peter Meijer.
 * */
std::string User::getCalendarFilePath()
{
    return calendar_file_path;
}

/*
 * @brief method to set File path of calendar file
 *
 * @param string representation of file path
 *
 * @return No returns.
 *
 * @authors Peter Meijer.
 * */
void User::setCalendarFilePath(std::string calendar_file_path)
{
    this->calendar_file_path = calendar_file_path;
    save();
}
