//
// Created by peter on 2021-11-28.
//

#ifndef NEWEST8_EMAIL_H
#define NEWEST8_EMAIL_H

#include <string>


class Email {

public:
    Email(unsigned long uid_p, std::string sender_param, std::string subject_param,std::string body_param);
    ~Email();

    std::string getBody();
    std::string getSender();
    std::string getSubject();
    void print(bool print_body);
    unsigned long getUID();

private:
    unsigned long uid;
    std::string sender;
    std::string subject;
    std::string body;

};


#endif //NEWEST8_EMAIL_H
