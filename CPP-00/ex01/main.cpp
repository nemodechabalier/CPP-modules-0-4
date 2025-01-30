#include <iostream>
#include <string>
#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
    PhoneBook phone;
    std::string cmd;
    while (true)
    {
        if (phone.correct_input("Enter a cmd (ADD, SEARCH, EXIT) : ", &cmd) == false)
            return (phone.displayEnd(true), 1);
        if (cmd == "ADD" && phone.ADD(&phone) == false)
            return (phone.displayEnd(true), 1);
        if (cmd == "SEARCH" && phone.SEARCH(&phone) == false)
            return (phone.displayEnd(true), 1);
        if (cmd == "EXIT")
            return (phone.displayEnd(false), 0);
    }
    return (0);
}