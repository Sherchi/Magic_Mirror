//
// Created by Peter on 2021-11-20.
//


#ifndef NEWEST8_INBOX_H
#define NEWEST8_INBOX_H

#include <string>
#include <vector>
#include <mailio/imap.hpp>
#include "Email.h"

using mailio::imaps;

class Inbox {
public:
    Inbox(std::string imap_server, std::string email_address, std::string password);
    Inbox();
    ~Inbox();
    std::vector<Email*> getEmails();
    int updateInbox();
    void print();



private:
    int retrieve();
    std::string imap_server;
    std::string email_address;
    std::string password;
    std::vector<Email*> emails;
    bool activated;

};


#endif //NEWEST8_INBOX_H
