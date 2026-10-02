#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;

class clsAddNewClientScreen :protected clsScreen
{
private:
	static void Read_Client_Info(clsBankClient& Client);

	static void _Print_Client(clsBankClient Client);


public:
	static void Add_new();
};
