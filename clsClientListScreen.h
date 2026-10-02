#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
using namespace std;

class clsClientListScreen :protected clsScreen
{
private:
	static void Print_Client_Record_Line(clsBankClient Client);
public:
	static void Show_Clients_List();
};
