#include "clsScreen.h"
 void clsScreen::_Draw_Screen_Header(string Title, string SubTitle )
{
	cout << "\t\t\t\t\t______________________________________";
	cout << "\n\n\t\t\t\t\t  " << Title;
	if (SubTitle != "")
	{
		cout << "\n\t\t\t\t\t  " << SubTitle;
	}
	cout << "\n\t\t\t\t\t______________________________________\n\n";
	cout << "\n\t\t\t\t\tUser: " << Current_User.UserName << "\n";
	cout << "\t\t\t\t\tDate: " << clsDate::Date_To_String(clsDate()) << "\n\n";

}

 bool clsScreen::Check_Access_Rights(clsUser::en_Permissions Permission) {

	if (!Current_User.Check_Access_Permission(Permission))
	{
		cout << "\t\t\t\t\t______________________________________";
		cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
		cout << "\n\t\t\t\t\t______________________________________\n\n";
		return false;
	}
	else
	{
		return true;
	}

}