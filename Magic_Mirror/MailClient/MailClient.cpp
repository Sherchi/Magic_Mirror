/*
 * @brief This class defines the singleton of the MailClient
 *
 * @authors Peter Meijer
 * */

#include "MailClient.h"

//static  variable of usersystem object
MailClient* MailClient::_instance = NULL;

/*
 * @brief Singleton instance access method for static Mailclient instance
 *
 * @param No Params
 *
 * @return MailClient instance singleton
 *
 * @authors Peter Meijer.
 * */
MailClient& MailClient::instance()
{
    if(_instance == NULL)
    {
        _instance = new MailClient();
    }
    return *_instance;
}

/*
 * @brief Constructor for the class. Initializes the MailClient
 *
 * @param No params.
 *
 * @return No returns.
 *
 * @authors Peter Meijer.
 * */
MailClient::MailClient()
{
    MailClient::u = &UserSystem::instance();
    active_inbox = u->getActiveUser()->getInbox();
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
MailClient::~MailClient()
{

}

/*
 * @brief Method to update the active user, called externally as signal
 *
 * @param No params.
 *
 * @return No returns.
 *
 * @authors Peter Meijer.
 * */
void MailClient::updateUser()
{
    active_inbox = u->getActiveUser()->getInbox();
}

/*
 * @brief Method to get email list of active inbox
 *
 * @param No params.
 *
 * @return vector<Email*> list of email pointers of inbox emails
 *
 * @authors Peter Meijer.
 * */
std::vector<Email*> MailClient::getEmails()
{
    return active_inbox->getEmails();
};

