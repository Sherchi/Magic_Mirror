/*
 * @brief This class defines the class object implementation of Email, as defined in Email.h
 *
 * @authors Peter Meijer
 * */


#include <iostream>

#include "Email.h"

/*
 * @brief Constructor for the class. Initializes the Email with the params passed that represent the email.
 *
 * @param uid_p inbox uid of string
 *
 * @param sender_param sender of email
 *
 * @param subject_param subject line of email
 *
 * @param body_param body of email
 *
 * @return No returns.
 *
 * @authors Peter Meijer.
 * */
Email::Email(unsigned long uid_p, std::string sender_param, std::string subject_param,std::string body_param)
{
    uid = uid_p;
    sender = sender_param;
    subject = subject_param;
    body = body_param;

}

/*
 * @brief Destructor for email
 *
 * @params No Params
 *
 * @return No returns
 *
 * @authors Peter Meijer
 */
Email::~Email()
{

}

/*
 * @brief Getter for body
 *
 * @param No parameters.
 *
 * @return body of email html as string
 *
 * @authors Peter Meijer.
 * */
std::string Email::getBody() {
    return body;
}

/*
 * @brief Getter for sender
 *
 * @param No parameters.
 *
 * @return sender of email as string
 *
 * @authors Peter Meijer.
 * */
std::string Email::getSender() {
    return sender;
}

/*
 * @brief Getter for subject
 *
 * @param No parameters.
 *
 * @return subject of email as string
 *
 * @authors Peter Meijer.
 * */
std::string Email::getSubject() {
    return subject;
}

/*
 * @brief Getter for uid
 *
 * @param No parameters.
 *
 * @return email uid unsigned long
 *
 * @authors Peter Meijer.
 * */
unsigned long Email::getUID() {
    return uid;
}

/*
 * @brief print email to std out
 *
 * @param No parameters.
 *
 * @return No return
 *
 * @authors Peter Meijer.
 * */
void Email::print(bool print_body)
{
    std::cout << "id: " << uid << std::endl;
    std::cout << "sender: " << sender << std::endl;
    std::cout << "subject: " << subject << std::endl;

    if (print_body)
        std::cout << "body: " << body << std::endl;
}
