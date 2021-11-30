/*
 * @brief This class defines the singleton of the UserSystem, this system manages the active user, user logins, user creation, etc.
 *
 * @authors Peter Meijer
 * */

#include "../MailClient/MailClient.h"
#include "UserSystem.h"

//static variable of usersystem object
UserSystem* UserSystem::_instance = NULL;

/*
 * @brief Singleton instance access method for static usersystem instance
 *
 * @param No Params
 *
 * @return UserSystem instance singleton
 *
 * @authors Peter Meijer.
 * */
UserSystem& UserSystem::instance()
{
    //creates instance if none exists
    if(_instance == NULL)
    {
        _instance = new UserSystem();
    }
    return *_instance;
}

/*
 * @brief Constructor for the class. Initializes the UserSystem
 *
 * @param No params.
 *
 * @return No returns.
 *
 * @authors Peter Meijer.
 * */
UserSystem::UserSystem()
{
    users_loaded = false;
    active_user = new User();
    loadUsers();
}

/*
 * @brief Destructor for the class.
 *
 * @param No params.
 *
 * @return No returns.
 *
 * @authors Peter Meijer.
 * */
UserSystem::~UserSystem() {

}

/*
 * @brief Method to load the users out of the json files in useraccounts folder
 *
 * @param No paramgs
 *
 * @return No returns.
 *
 * @authors Peter Meijer.
 * */
void UserSystem::loadUsers() {
    std::string currentPath = std::filesystem::current_path();
    std::string path = currentPath + "/useraccounts";
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
        users.push_back(user);

        ifs.close();

    }

    users_loaded = true;

}

/*
 * @brief Method to get list of all usernames of all users in system
 *
 * @param No params.
 *
 * @return vector list of string usernames of all users in the system
 *
 * @authors Peter Meijer.
 * */
std::vector<std::string> UserSystem::getUsers() {
    std::vector<std::string> user_list;
    for(User* u: users)
    {
        user_list.push_back(u->getUsername());
    }
    return user_list;
}


/*
 * @brief Method to login user
 *
 * @param string username of user to login
 *
 * @param string password of user to login
 *
 * @return int 0 on success
 *
 * @return int -1 if username invalid
 *
 * @return -2 if password is wrong
 *
 * @return -3 if another user is already logged in
 *
 * @authors Peter Meijer.
 * */
int UserSystem::login(std::string username, std::string password)
{
    if(!active_user->isActivated()) {
        for (User* u: users) {
            if (username == u->getUsername()) {
                bool authenticated = u->authenticate(password);
                if (authenticated == true) {
                    active_user = u;
                    MailClient::instance().updateUser();
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

/*
 * @brief Method to logout current logged in  user
 *
 * @param No params.
 *
 * @return int 0 on success
 *
 * @return int -1 if no user is logged in

 * @authors Peter Meijer.
 * */
bool UserSystem::logout()
{
    if(active_user->isActivated()) {
        //create blank user as active user aka no user is active
        User *u = new User();
        active_user = u;
        //return successful logout
        MailClient::instance().updateUser();
        return 0;
    }
    else
    {
        return -1;
    }
}



/*
 * @brief Method to change password of current user
 *
 * @param string old user password
 *
 * @param string new user password
 *
 * @return int 0 on success
 *
 * @return int -1 if old password is wrong
 *
 * @return int -2 if no active user logged in to change password for

 * @authors Peter Meijer.
 * */
int UserSystem::changePassword(std::string old_password, std::string new_password) {
    if(active_user->isActivated())
    {
        bool change = active_user->changePassword(old_password,new_password);
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

/*
 * @brief Method to change username of current user
 *
 * @param string new username
 *
 * @return bool true on success
 *
 * @return bool false if no active user to change username for

 * @authors Peter Meijer.
 * */
bool UserSystem::changeUsername(std::string new_username)
{
    if(!active_user->isActivated())
    {
        return false;
    }
    else
    {
        active_user->changeUsername(new_username);
        return true;
    }
}



/*
 * @brief Method to create a new user
 *
 * @param string username
 *
 * @param string password
 *
 * @param bool admin to designate if user is admin
 *
 * @return int 0 on success
 *
 * @return int -1 if current user is not admin and cannot create accounts
 *
 * @return int -2 if username is taken
 *
 * @return int -3 if no active user
 *
 * @authors Peter Meijer.
 * */
int UserSystem::createUser(std::string username, std::string password, bool admin)
{
    //check if a user is active
    if(!active_user->isActivated())
    {
        return -3;
    }
    else
    {
        //if they are admin,account can be created
        if(active_user->isAdmin())
        {
            //check if username is already taken
            bool username_taken = false;
            for(User *u: users)
            {
                if(u->getUsername() == username)
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
                //create user object and save it
                std::string file_path ="../useraccounts/"+username+".json";
                Json::Value object;
                object["username"] = username;
                object["password"] = password;
                object["admin"] = admin;

                User *user = new User(file_path,object);
                user->save();
                users.push_back(user);
                return 0;
            }
        }
        else
        {
            return -1;
        }
    }
}

/*
 * @brief Method to make a user an admin
 *
 * @param string username
 *
 * @return int 1  if user is already admin
 *
 * @return int 0 on success
 *
 * @return int -1 if username does not correspond to user
 *
 * @return int -2 if current user is not an admin
 *
 * @return -3 if no user is currently active
 *
 * @authors Peter Meijer.
 * */
int UserSystem::makeAdmin(std::string username)
{
    //check if active user exists
    if(active_user->isActivated())
    {
        //if they are admin attempt to set username user to admin
        if(active_user->isAdmin()) {
            for (User *u: users) {
                if (u->getUsername() == username) {
                    if(u->isAdmin())
                    {
                        return 1;
                    }
                    u->setAdmin(true);
                    return 0;
                }
            }
            return -1;
        }
        return -2;
    }
    return -3;
}


/*
 * @brief Method to remove an admin
 *
 * @param string username
 *
 * @return int 1  if user is already not admin
 *
 * @return int 0 on success
 *
 * @return int -1 if username does not correspond to user
 *
 * @return int -2 if current user is not an admin
 *
 * @return -3 if no user is currently active
 *
 * @authors Peter Meijer.
 * */
int UserSystem::removeAdmin(std::string username)
{
    if(active_user->isActivated())
    {
        if(active_user->isAdmin()) {
            for (User *u: users) {
                if (u->getUsername() == username) {
                    if(!u->isAdmin())
                    {
                        return 1;
                    }
                    u->setAdmin(false);
                    return 0;
                }
            }
            return -1;
        }
        return -2;
    }
    return -3;
}

/*
 * @brief Method to make a user an admin
 *
 * @param No params.
 *
 * @return User* pointer to active (logged in) user
 *
 * @authors Peter Meijer.
 * */
User* UserSystem::getActiveUser()
{
    return active_user;
}

