#include <iostream>
#include "UserSystem.h"

int main() {

    UserSystem *s = new UserSystem();
    std::vector<std::string> users = s->getUsers();


    std::cout << s->login("pmeij","webkinz1") << std::endl;
    std::cout << s->changeUsername("pmeij") << std::endl;

    User u = s->getActiveUser();
    u.print();


    return 0;
}
