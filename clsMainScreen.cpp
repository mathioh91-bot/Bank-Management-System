#include "clsMainScreen.h"
short clsMainScreen::_Read_Main_Menue_Option()
{
	cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 9]? ";
	short Choice = clsInputValidate::Read_Short_Number_Between(1, 9, "Enter Number between 1 to 9? ");
	return Choice;
}

void clsMainScreen::_Go_Back_To_Main_Menue()
{
	cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

	//system("pause>0");
	//Show_Main_Menue();
}

void clsMainScreen::_Show_All_Clients_Screen()
{
	clsClientListScreen::Show_Clients_List();
}

void clsMainScreen::_Show_Add_New_Clients_Screen()
{
	clsAddNewClientScreen::Add_new();
}

void clsMainScreen::_Show_Delete_Client_Screen()
{
	clsDeleteClientScreen::Delete_Client();
}

void clsMainScreen::_Show_Update_Client_Screen()
{
	clsUpdateClientScreen::update_client();
}

void clsMainScreen::_Show_Find_Client_Screen()
{
	clsFindClientScreen::Show_Find_Client_Screen();
}

void clsMainScreen::_Show_Transactions_Menue()
{
	clsTransactionsScreen::Show_Main_Menue();
}

void clsMainScreen::_Show_Manage_Users_Menue()
{
	clsManageUsersScreen::ShowManageUsersMenue();
}

void clsMainScreen::_Show_Login_Register() {
	clsLoginRegisterScreen::Show_Login_Register_Screen();

}
void clsMainScreen::_Logout()
{
	Current_User._Get_Empty_User_Object();
	cout << "\nprogram ends\n";
}

void clsMainScreen::_Perfrom_Main_Menue_Option(en_Main_Menue_Options MainMenueOption)
{
	switch (MainMenueOption)
	{
	case en_Main_Menue_Options::eListClients:
	{
		system("cls");
		_Show_All_Clients_Screen();
		_Go_Back_To_Main_Menue();
		break;
	}
	case en_Main_Menue_Options::eAddNewClient:
		system("cls");
		_Show_Add_New_Clients_Screen();
		_Go_Back_To_Main_Menue();
		break;

	case en_Main_Menue_Options::eDeleteClient:
		system("cls");
		_Show_Delete_Client_Screen();
		_Go_Back_To_Main_Menue();
		break;

	case en_Main_Menue_Options::eUpdateClient:
		system("cls");
		_Show_Update_Client_Screen();
		_Go_Back_To_Main_Menue();
		break;

	case en_Main_Menue_Options::eFindClient:
		system("cls");
		_Show_Find_Client_Screen();
		_Go_Back_To_Main_Menue();
		break;

	case en_Main_Menue_Options::eShowTransactionsMenue:
		system("cls");
		_Show_Transactions_Menue();
		break;

	case en_Main_Menue_Options::eManageUsers:
		system("cls");
		_Show_Manage_Users_Menue();
		break;
	case en_Main_Menue_Options::eLoginRedister:
		system("cls");
		_Show_Login_Register();
		break;
	case en_Main_Menue_Options::eExit:
		system("cls");
		_Logout();
		//Login();

		break;
	}
}

void clsMainScreen::Show_Main_Menue()
{
	while (true)
	{
		system("cls");
		_Draw_Screen_Header("\t\tMain Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transactions.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Logout.\n";
		cout << setw(37) << left << "" << "===========================================\n";

		en_Main_Menue_Options choice = (en_Main_Menue_Options)_Read_Main_Menue_Option();

		if (choice == en_Main_Menue_Options::eExit)
		{
			system("cls");
			_Logout();
			break;
		}

		_Perfrom_Main_Menue_Option(choice);

		cout << "\n\nPress any key to go back to Main Menue...";
		system("pause>0");
	}
}