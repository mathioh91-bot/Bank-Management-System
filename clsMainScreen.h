#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h";
#include "clsTransactionsScreen.h";
#include "Global.h";
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
using namespace std;
class clsMainScreen : protected clsScreen
{
private:
	enum en_Main_Menue_Options {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
		eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
		eManageUsers = 7, eLoginRedister, eExit = 9
	};

	static short _Read_Main_Menue_Option();

	static  void _Go_Back_To_Main_Menue();

	static void _Show_All_Clients_Screen();

	static void _Show_Add_New_Clients_Screen();

	static void _Show_Delete_Client_Screen();

	static void _Show_Update_Client_Screen();

	static void _Show_Find_Client_Screen();

	static void _Show_Transactions_Menue();

	static void _Show_Manage_Users_Menue();

	static void _Show_Login_Register();

	static void _Logout();

	static void _Perfrom_Main_Menue_Option(en_Main_Menue_Options MainMenueOption);

public:

	static void Show_Main_Menue();
};
