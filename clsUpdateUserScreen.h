#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsUpdateUserScreen : protected clsScreen 
{
private:
	static void _Read_User_Info(clsUser& User);
	static int _Read_Permissions_To_Set();

	static void _Print_User(clsUser User);

	public:
		static void Update_User();
		

};

