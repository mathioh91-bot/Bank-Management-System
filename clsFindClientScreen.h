#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsFindClientScreen :protected clsScreen
{
private:
	static void _Print_Client(clsBankClient Client);

public:

	static void Show_Find_Client_Screen();
};
