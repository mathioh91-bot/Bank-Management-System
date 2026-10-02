#include "clsFindUserScreen.h"
 void clsFindUserScreen::_Print_User(clsUser User)
{
    cout << "\nUser Card:";
    cout << "\n___________________";
    cout << "\nFirstName   : " << User.FirstName;
    cout << "\nLastName    : " << User.LastName;
    cout << "\nFull Name   : " << User.FullName();
    cout << "\nEmail       : " << User.Email;
    cout << "\nPhone       : " << User.Phone;
    cout << "\nUserName    : " << User.UserName;
    cout << "\nPassword    : " << User.Password;
    cout << "\nPermissions : " << User.Permissions;
    cout << "\n___________________\n";

}


     void clsFindUserScreen::Show_Find_User_Screen()
    {

        _Draw_Screen_Header("\t  Find User Screen");

        string UserName;
        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::Read_String();
        while (!clsUser::Is_User_Exist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::Read_String();
        }

        clsUser User1 = clsUser::Find(UserName);

        if (!User1.Is_Empty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }

        _Print_User(User1);

    }