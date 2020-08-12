#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

#include "User.h"
#include "XMLFile.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UsersFile :public XMLFile {

public:
    UsersFile(string fileNameWithUsers) : XMLFile(fileNameWithUsers) {};
    void writeUserToFile(User user);
    vector <User> loadUsersFromFile();
    void changePasswordLoggedUserInFile(string newPassword, int loggedUserId);
};

#endif USERFILE_H
