#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
    int id;
    string name;
    string surname;
    string login;
    string password;

public:
    void setId(int newId);
    void setLogin(string newLogin);
    void setName(string newName);
    void setSurname(string newSurname);
    void setPassword(string newPassword);

    int getId();
    string getLogin();
    string getName();
    string getSurname();
    string getPassword();
};

#endif
