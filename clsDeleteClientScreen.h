#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;
class clsDeleteClientScreen :protected clsScreen
{
private:

	static void _Print_Client(clsBankClient Client);
public:
	static
		void  Delete_Client();
};
