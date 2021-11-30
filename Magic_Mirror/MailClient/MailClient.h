//
// Created by peter on 2021-11-28.
//

#ifndef NEWEST8_MAILCLIENT_H
#define NEWEST8_MAILCLIENT_H

#include "Email.h"
#include "Inbox.h"
#include "../User_System/UserSystem.h"

class MailClient {
    public:
        virtual ~MailClient();
        static MailClient& instance();
        void updateUser();
        std::vector<Email*> getEmails();

    protected:
        MailClient(); //prevent instantiation of this

    private:
        UserSystem *u;
        MailClient(const MailClient& other) {};
        MailClient& operator=(const MailClient& other) { return *this;};
        static MailClient* _instance;
        Inbox* active_inbox;


};


#endif //NEWEST8_MAILCLIENT_H
