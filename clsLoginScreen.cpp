#include "clsLoginScreen.h"
bool clsLoginScreen::_Login() {
	bool Login_Faild = false;
	short Faild_Login_Count = 0;

	do
	{
		if (Login_Faild)
		{
			Faild_Login_Count++;
			cout << "\nInvlaid Username/Password!";
			cout << "\nYou have " << (3 - Faild_Login_Count)
				<< " Trial(s) to login.\n\n";
		}

		if (Faild_Login_Count == 3) {
			cout << "\nYour are Locked after 3 faild trails \n\n";
			return false;
		}
		string  User_name, Password;
		cout << "Enter Username? ";
		cin >> User_name;

		cout << "Enter Password? ";
		cin >> Password;
		Current_User = clsUser::Find(User_name, Password);
		Login_Faild = Current_User.Is_Empty();
	} while (Login_Faild);
	Current_User.Register_LogIn();
	clsMainScreen::Show_Main_Menue();
	return true;
}

bool clsLoginScreen::ShowLoginScreen() {
	system("cls");
	_Draw_Screen_Header("\t  Login Screen");
	return 	_Login();
}