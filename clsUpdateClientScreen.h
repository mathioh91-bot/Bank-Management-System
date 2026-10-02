#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsUpdateClientScreen :protected clsScreen
{
private:

	static void Read_Client_Info(clsBankClient& Client);

	static void _Print_Client(clsBankClient Client);
public:
	static void update_client();
};
