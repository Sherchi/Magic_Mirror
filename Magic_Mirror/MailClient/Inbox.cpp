/*
 * @brief This class defines the class object implementation of Inbox, as defined in Inbox.h
 *
 * @authors Peter Meijer
 * */


//libraries
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <mailio/imap.hpp>

//inclusions
#include "Inbox.h"

//name configuration
using mailio::message;
using mailio::codec;
using mailio::imaps;
using mailio::imap_error;
using mailio::mime_error;
using mailio::dialog_error;
using mailio::codec_error;
using std::cout;
using std::endl;
using std::for_each;
using std::list;
using std::string;

/*
 * @brief Constructor for the class. Initializes the Inbox with the params passed that define the imap connection.
 *
 * @param imap_server_param string representation of imap server
 *
 * @param email_address_param email address of imap inbox
 *
 * @param password_param password for email address
 *
 * @return No returns.
 *
 * @authors Peter Meijer.
 * */
Inbox::Inbox(std::string imap_server_param, std::string email_address_param, std::string password_param) {
    imap_server = imap_server_param;
    email_address = email_address_param;
    password = password_param;
    activated = true;

}

/*
 * @brief Default Constructor for the class. Initializes the Inbox as a non activated inbox
 *
 * @param No parameters.
 *
 * @return No returns.
 *
 * @authors Peter Meijer.
 * */
Inbox::Inbox()
{
    activated = false;
}

/*
 * @brief Destructor for the Inbox class
 *
 * @param No parameters.
 *
 * @return No returns.
 *
 * @authors Peter Meijer.
 * */
Inbox::~Inbox()
{

}

/*
 * @brief Method to get list of emails in inbox
 *
 * @param No parameters.
 *
 * @return vector<Email*> returns a vector of pointers to Email objects
 *
 * @authors Peter Meijer.
 * */
std::vector<Email*> Inbox::getEmails()
{
    return emails;
}

/*
 * @brief Method to make the inbox update itself (fetch emails from the server)
 *
 * @param No parameters.
 *
 * @return int returns -1 if there is no active inbox
 * @return int returns -2 for imap error
 * @return int returns -3 for mime error
 * @return int returns -4 for default error
 * @return int returns 0 for success
 *
 * @authors Peter Meijer.
 * */
int Inbox::updateInbox()
{
    if (activated) {
        return retrieve();
    }
    else
    {
        return -1;
    }
}

/*
 * @brief print method to print credentials of inbox
 *
 * @param No parameters.
 *
 * @return No returns.
 *
 * @authors Peter Meijer.
 * */
void Inbox::print()
{
    std::cout << "Printing Inbox" << std::endl;
    std::cout << imap_server << " " << email_address << " " << password << std::endl;

}

/*
 * @brief Private Method to make the inbox update itself (fetch emails from the server)
 *
 * @param No parameters.
 *
 * @return int returns -1 if there is no active inbox
 * @return int returns -2 for imap error
 * @return int returns -3 for mime error
 * @return int returns -4 for default error
 * @return int returns 0 for success
 *
 * @authors Peter Meijer.
 * */
int Inbox::retrieve()
{
    try {
        cout << imap_server << " " << email_address << " " << password << endl;
        imaps conn(imap_server, 993);
        // modify username/password to use real credentials
        conn.authenticate(email_address, password, imaps::auth_method_t::LOGIN);
        conn.select(list<string>({"Inbox"}));
        list<unsigned long> messages;
        list<imaps::search_condition_t> conds;
        conds.push_back(
                imaps::search_condition_t(imaps::search_condition_t::SINCE_DATE, boost::gregorian::date(2021, 11, 29)));
        conn.search(conds, messages, true);

        list<message> msgs;

        for_each(messages.begin(), messages.end(), [&conn, &msgs](unsigned int msg_uid) {
            cout << msg_uid << endl;
            message msg;
            // set the line policy to mandatory, so longer lines could be parsed
            msg.line_policy(codec::line_len_policy_t::NONE, codec::line_len_policy_t::NONE);
            //conn.fetch("Inbox",4886,msg,false);
            try {

                conn.fetch(msg_uid, msg, true, false);


            }
            catch (imap_error &exc) {
                cout << exc.what() << endl;
                cout << "error on attempt 1 for " << msg_uid << endl;
            }


        });

        cout << "attempt 2 loop " << endl;
        imaps conn2(imap_server, 993);
        // modify username/password to use real credentials
        conn2.authenticate(email_address, password, imaps::auth_method_t::LOGIN);
        conn2.select(list<string>({"Inbox"}));

        for_each(messages.begin(), messages.end(), [&conn2, &msgs, this](unsigned int msg_uid) {
            cout << msg_uid << endl;
            message msg;
            // set the line policy to mandatory, so longer lines could be parsed
            msg.line_policy(codec::line_len_policy_t::NONE, codec::line_len_policy_t::NONE);
            //conn.fetch("Inbox",4886,msg,false);
            try {

                conn2.fetch(msg_uid, msg, true, false);
                string test;
                try {
                    msg.format(test, true);
                    Email *email = new Email(msg_uid, msg.from_to_string(), msg.subject(), test);
                    emails.push_back(email);
                }
                catch (codec_error &exc) {
                    Email *email = new Email(msg_uid, msg.from_to_string(), msg.subject(), exc.what());
                    emails.push_back(email);
                }

            }
            catch (imap_error &exc) {

            }


        });
    }
    catch(imap_error &exc)
    {
        cout << "An error has occured. Your credentials or IMAP configuration are likely wrong." << endl;
        return -2;
    }
    catch(mime_error &exc)
    {
        cout << "A mime has occured. An email or header in your target inbox is corrupt or unsafe." << endl;
        return -3;
    }
    catch(...)
    {
        cout << "Default Exception" << endl;
        return -4;
    }

    return 0;


}

