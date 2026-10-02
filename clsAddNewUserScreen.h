#pragma once
#include <iostream>
#include <iomanip>
#include <limits>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
class clsAddNewUserScreen:protected clsScreen
{
private:
	static void _Read_User_Info(clsUser& User);

	static int _Read_Permissions_To_Set();

	static void _Print_User(clsUser User);


public:
	static void ShowAddNewUserScreen();
};
