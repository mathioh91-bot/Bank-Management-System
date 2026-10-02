#include "clsFindClientScreen.h"
void clsFindClientScreen::_Print_Client(clsBankClient Client)
{
	cout << "\nClient Card:";
	cout << "\n___________________";
	cout << "\nFirstName   : " << Client.FirstName;
	cout << "\nLastName    : " << Client.LastName;
	cout << "\nFull Name   : " << Client.FullName();
	cout << "\nEmail       : " << Client.Email;
	cout << "\nPhone       : " << Client.Phone;
	cout << "\nAcc. Number : " << Client.Account_Number;
	cout << "\nPassword    : " << Client.Pin_Code;
	cout << "\nBalance     : " << Client.Account_Balance;
	cout << "\n___________________\n";
}

void clsFindClientScreen::Show_Find_Client_Screen()
{
	if (!Check_Access_Rights(clsUser::en_Permissions::pFindClient))
	{
		return;// this will exit the function and it will not continue
	}
	_Draw_Screen_Header("\tFind Client Screen");

	string AccountNumber;
	cout << "\nPlease Enter Account Number: ";
	AccountNumber = clsInputValidate::Read_String();
	while (!clsBankClient::Is_Client_Exist(AccountNumber))
	{
		cout << "\nAccount number is not found, choose another one: ";
		AccountNumber = clsInputValidate::Read_String();
	}

	clsBankClient Client1 = clsBankClient::Find(AccountNumber);

	if (!Client1.Is_Empty())
	{
		cout << "\nClient Found :-)\n";
	}
	else
	{
		cout << "\nClient Was not Found :-(\n";
	}

	_Print_Client(Client1);
}