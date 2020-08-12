#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "UsersFile.h"

using namespace std;

class UserManager {
    int loggedUserId;
    vector <User> users;
    UsersFile usersFile;

    User giveNewUserDetails();
    int getNewUserId();
    bool isLoginExist(string login);

public:
    UserManager(string fileNameOfUseres) : usersFile(fileNameOfUseres) {
        loggedUserId = 0;
        users = usersFile.loadUsersFromFile();
    };
    void userRegistration();
    void userLogging();
    void changePasswordLoggedUser();
    void userLogout();
    bool isUserLoggedIn();
    int getLoggedUserId();
};

#endif
