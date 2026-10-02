#include "clsDeleteUserScreen.h"
 void clsDeleteUserScreen::_Print_User(clsUser User)
{
    cout << "\nUser Card:";
    cout << "\n___________________";
    cout << "\nFirstName   : " << User.FirstName;
    cout << "\nLastName    : " << User.LastName;
    cout << "\nFull Name   : " << User.FullName();
    cout << "\nEmail       : " << User.Email;
    cout << "\nPhone       : " << User.Phone;
    cout << "\nUser Name   : " << User.UserName;
    cout << "\nPassword    : " << User.Password;
    cout << "\nPermissions : " << User.Permissions;
    cout << "\n___________________\n";

}
   void clsDeleteUserScreen::Show_Delete_User_Screen()
    {

        _Draw_Screen_Header("\tDelete User Screen");

        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::Read_String();
        while (!clsUser::Is_User_Exist(UserName))
        {
            cout << "\nUser is not found, choose another one: ";
            UserName = clsInputValidate::Read_String();
        }

        clsUser User1 = clsUser::Find(UserName);
        _Print_User(User1);

        cout << "\nAre you sure you want to delete this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            if (User1.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";
                _Print_User(User1);
            }
            else
            {
                cout << "\nError User Was not Deleted\n";
            }
        }
    }