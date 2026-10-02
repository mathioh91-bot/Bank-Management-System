#include "clsDepositScreen.h"

void clsDepositScreen::_PrintClient(clsBankClient Client)
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

 string clsDepositScreen::_ReadAccountNumber()
{
	string AccountNumber = "";
	cout << "\nPlease enter AccountNumber? ";
	cin >> AccountNumber;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return AccountNumber;
}


	 void clsDepositScreen::ShowDepositScreen()
	{
		_Draw_Screen_Header("\t   Deposit Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::Is_Client_Exist(AccountNumber))
		{
			cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		double Amount = 0;
		cout << "\nPlease enter deposit amount? ";
		Amount = clsInputValidate::Read_Dbl_Number();

		cout << "\nAre you sure you want to perform this transaction? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			Client1.Deposit(Amount);
			cout << "\nAmount Deposited Successfully.\n";
			cout << "\nNew Balance Is: " << Client1.Account_Balance;
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}
	}