#include "clsClientListScreen.h"
 void clsClientListScreen::Print_Client_Record_Line(clsBankClient Client)
{
	cout << "| " << setw(15) << left << Client.Account_Number;
	cout << "| " << setw(20) << left << Client.FullName();
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(20) << left << Client.Email;
	cout << "| " << setw(10) << left << Client.Pin_Code;
	cout << "| " << setw(12) << left << Client.Account_Balance;
}
	 void clsClientListScreen::Show_Clients_List()
	{

		if (!Check_Access_Rights(clsUser::en_Permissions::pListClients))
		{
			return;// this will exit the function and it will not continue
		}
		vector <clsBankClient> vClients = clsBankClient::Get_Clients_List();
		string Title = "\t  Client List Screen";
		string SubTitle = "\t    (" + to_string(vClients.size()) + ") Client(s).";

		_Draw_Screen_Header(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Pin Code";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		if (vClients.size() == 0)
			cout << "\t\t\t\tNo Clients Available In the System!";
		else

			for (clsBankClient Client : vClients)
			{
				Print_Client_Record_Line(Client);
				cout << endl;
			}

		cout << "\n_______________________________________________________";
		cout << "_________________________________________\n" << endl;
	}
