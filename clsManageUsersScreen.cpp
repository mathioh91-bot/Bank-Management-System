#include "clsManageUsersScreen.h"
 short clsManageUsersScreen::ReadManageUsersMenueOption()
{
	cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
	short Choice = clsInputValidate::Read_Number_Between<short>(1, 6, "Enter Number between 1 to 6? ");
	return Choice;
}

 void clsManageUsersScreen::_GoBackToManageUsersMenue()
{
	cout << "\n\nPress any key to go back to Manage Users Menue...";
}

 void clsManageUsersScreen::_ShowListUsersScreen()
{
	clsListUsersScreen::Show_Users_List();
}

 void clsManageUsersScreen::_ShowAddNewUserScreen()
{
	clsAddNewUserScreen::ShowAddNewUserScreen();
}

 void clsManageUsersScreen::_ShowDeleteUserScreen()
{
	clsDeleteUserScreen::Show_Delete_User_Screen();
}

 void clsManageUsersScreen::_ShowUpdateUserScreen()
{
	clsUpdateUserScreen::Update_User();
}

 void clsManageUsersScreen::_ShowFindUserScreen()
{
	clsFindUserScreen::Show_Find_User_Screen();
}

 void clsManageUsersScreen::_PerformManageUsersMenueOption(enManageUsersMenueOptions ManageUsersMenueOption)
{
	switch (ManageUsersMenueOption)
	{
	case enManageUsersMenueOptions::eListUsers:
	{
		system("cls");
		_ShowListUsersScreen();
		break;
	}

	case enManageUsersMenueOptions::eAddNewUser:
	{
		system("cls");
		_ShowAddNewUserScreen();
		break;
	}

	case enManageUsersMenueOptions::eDeleteUser:
	{
		system("cls");
		_ShowDeleteUserScreen();
		break;
	}

	case enManageUsersMenueOptions::eUpdateUser:
	{
		system("cls");
		_ShowUpdateUserScreen();
		break;
	}

	case enManageUsersMenueOptions::eFindUser:
	{
		system("cls");

		_ShowFindUserScreen();
		break;
	}

	case enManageUsersMenueOptions::eMainMenue:
	{
		//do nothing here the main screen will handle it :-) ;
	}
	}
}