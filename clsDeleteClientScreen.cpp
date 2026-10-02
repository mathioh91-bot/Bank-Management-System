#include "clsDeleteClientScreen.h"
void clsDeleteClientScreen::_Print_Client(clsBankClient Client)
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
void  clsDeleteClientScreen::Delete_Client()
{
	if (!Check_Access_Rights(clsUser::en_Permissions::pDeleteClient))
	{
		return;// this will exit the function and it will not continue
	}
	_Draw_Screen_Header("\tDelete Client Screen");

	string account_number = "";
	cout << "\nPlease Enter client Account Number: ";
	account_number = clsInputValidate::Read_String();

	while (!clsBankClient::Is_Client_Exist(account_number)) {
		cout << "\nAccount number is not exist, choose another one: ";
		account_number = clsInputValidate::Read_String();
	}
	clsBankClient client = clsBankClient::Find(account_number);

	_Print_Client(client);
	cout << "\nAre you sure you want to delete this client y/n? ";

	char Answer = 'n';
	cin >> Answer;
	if (Answer == 'y' || Answer == 'Y') {
		if (client.Delete())
		{
			cout << "\nClient Deleted Successfully :-)\n";

			_Print_Client(client);
		}
		else
		{
			cout << "\nError Client Was not Deleted\n";
		}
	}
}