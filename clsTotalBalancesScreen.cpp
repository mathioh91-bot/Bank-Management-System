#include "clsTotalBalancesScreen.h"

 void clsTotalBalancesScreen::PrintClientRecordBalanceLine(clsBankClient Client)
{
	cout << setw(25) << left << "" << "| " << setw(15) << left << Client.Account_Number;
	cout << "| " << setw(40) << left << Client.FullName();
	cout << "| " << setw(12) << left << Client.Account_Balance;
}


 void clsTotalBalancesScreen::ShowTotalBalances()
	{
		vector <clsBankClient> vClients = clsBankClient::Get_Clients_List();

		_Draw_Screen_Header("\t  Balances List Screen", "\t    (" + to_string(vClients.size()) + ") Client(s).");

		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(25) << left << "" << "\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		double TotalBalances = clsBankClient::Get_Total_Balances();

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClient Client : vClients)
			{
				PrintClientRecordBalanceLine(Client);
				cout << endl;
			}

		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(8) << left << "" << "\t\t\t\t\t\t\t     Total Balances = " << TotalBalances << endl;
		cout << setw(8) << left << "" << "\t\t\t\t  ( " << Cls_Util::Number_To_Text(TotalBalances) << ")";
	}