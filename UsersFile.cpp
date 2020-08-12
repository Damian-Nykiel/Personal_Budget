#include "UsersFile.h"

void UsersFile::writeUserToFile(User user) {

    bool fileExsits = xml.Load(getFileName());

    if(!fileExsits) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("userId", user.getId());
    xml.AddElem("login", user.getLogin());
    xml.AddElem("password", user.getPassword());
    xml.AddElem("name", user.getName());
    xml.AddElem("surname", user.getSurname());
    xml.Save(getFileName());

}

vector <User> UsersFile::loadUsersFromFile() {
    vector <User> users;
    User user;

    xml.Load(getFileName());

    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("User") ) {
        xml.IntoElem();
        xml.FindElem( "userId" );
        user.setId(atoi(xml.GetData().c_str()));
        xml.FindElem( "login" );
        user.setLogin(xml.GetData());
        xml.FindElem( "password" );
        user.setPassword(xml.GetData());
        xml.FindElem( "name" );
        user.setName(xml.GetData());
        xml.FindElem( "surname" );
        user.setSurname(xml.GetData());
        xml.OutOfElem();

        users.push_back(user);
    }
    return users;
}

void UsersFile::changePasswordLoggedUserInFile(string newPassword, int loggedUserId) {
    bool fileExsits = xml.Load(getFileName());
    if(!fileExsits) {
        cout << "Plik " << getFileName() << " nie istnieje." << endl;
        system("pause");
    }

    xml.FindElem();
    xml.IntoElem();
    while(xml.FindElem("User")) {
        xml.IntoElem();
        xml.FindElem("userId");
        if (atoi(xml.GetData().c_str()) == loggedUserId) {
            xml.FindElem("password");
            xml.RemoveElem();
            xml.AddElem("password", newPassword);
            xml.Save(getFileName());
        } else
            xml.OutOfElem();
    }
}
