#pragma once
#include <iostream>
#include "Global.h"
#include "clsUser.h"
#include "clsDate.h"
using namespace std;
class clsScreen
{
protected:
	static void _Draw_Screen_Header(string Title, string SubTitle = "");

	static bool Check_Access_Rights(clsUser::en_Permissions Permission);
};
