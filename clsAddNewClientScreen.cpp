#include "clsAddNewClientScreen.h"

 void clsAddNewClientScreen::Read_Client_Info(clsBankClient& Client)
{
	cout << "\nEnter FirstName: ";
	Client.FirstName = clsInputValidate::Read_String();

	cout << "\nEnter LastName: ";
	Client.LastName = clsInputValidate::Read_String();

	cout << "\nEnter Email: ";
	Client.Email = clsInputValidate::Read_String();

	cout << "\nEnter Phone: ";
	Client.Phone = clsInputValidate::Read_String();

	cout << "\nEnter PinCode: ";
	Client.Pin_Code = clsInputValidate::Read_String();

	cout << "\nEnter Account Balance: ";
	Client.Account_Balance = clsInputValidate::Read_Number<float>();
}

 void clsAddNewClientScreen::_Print_Client(clsBankClient Client)
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
 void clsAddNewClientScreen::Add_new() {
	if (!Check_Access_Rights(clsUser::en_Permissions::pAddNewClient))
	{
		return;// this will exit the function and it will not continue
	}
	_Draw_Screen_Header("\t	Add New Client Screen");
	string account_number = "";

	cout << "\nPlease Enter client Account Number: ";
	account_number = clsInputValidate::Read_String();

	while (clsBankClient::Is_Client_Exist(account_number)) {
		cout << "\nAccount number is exist, choose another one: ";
		account_number = clsInputValidate::Read_String();
	}
	clsBankClient client = clsBankClient::Get_Add_New_Client_Object(account_number);
	Read_Client_Info(client);

	clsBankClient::en_Save_Results save;
	save = client.save();
	switch (save)
	{
	case  clsBankClient::en_Save_Results::svSucceeded:
	{
		cout << "\nAccount Addeded Successfully :-)\n";
		_Print_Client(client);
		break;
	}
	case clsBankClient::en_Save_Results::svFaildEmptyObject:
	{
		cout << "\nError account was not saved because it's Empty";
		break;
	}
	case clsBankClient::en_Save_Results::svFaildAccountNumberExists:
	{
		cout << "\nError account was not saved because account number is used!\n";
		break;
	}
	}
}