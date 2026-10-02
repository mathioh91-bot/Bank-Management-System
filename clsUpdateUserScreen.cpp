#include "clsUpdateUserScreen.h"

 void clsUpdateUserScreen::_Read_User_Info(clsUser& User)
{
	cout << "\nEnter FirstName: ";
	User.FirstName = clsInputValidate::Read_String();

	cout << "\nEnter LastName: ";
	User.LastName = clsInputValidate::Read_String();

	cout << "\nEnter Email: ";
	User.Email = clsInputValidate::Read_String();

	cout << "\nEnter Phone: ";
	User.Phone = clsInputValidate::Read_String();

	cout << "\nEnter Password: ";
	User.Password = clsInputValidate::Read_String();

	cout << "\nEnter Permission: ";
	User.Permissions = _Read_Permissions_To_Set();
}

 int clsUpdateUserScreen::_Read_Permissions_To_Set()
{

	int Permissions = 0;
	char Answer = 'n';


	cout << "\nDo you want to give full access? y/n? ";
	cin >> Answer;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (Answer == 'y' || Answer == 'Y')
	{
		return -1;
	}

	cout << "\nDo you want to give access to : \n ";

	cout << "\nShow Client List? y/n? ";
	cin >> Answer;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (Answer == 'y' || Answer == 'Y')
	{


		Permissions += clsUser::en_Permissions::pListClients;
	}

	cout << "\nAdd New Client? y/n? ";
	cin >> Answer;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (Answer == 'y' || Answer == 'Y')
	{
		Permissions += clsUser::en_Permissions::pAddNewClient;
	}

	cout << "\nDelete Client? y/n? ";
	cin >> Answer;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (Answer == 'y' || Answer == 'Y')
	{
		Permissions += clsUser::en_Permissions::pDeleteClient;
	}

	cout << "\nUpdate Client? y/n? ";
	cin >> Answer;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (Answer == 'y' || Answer == 'Y')
	{
		Permissions += clsUser::en_Permissions::pUpdateClients;
	}

	cout << "\nFind Client? y/n? ";
	cin >> Answer;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (Answer == 'y' || Answer == 'Y')
	{
		Permissions += clsUser::en_Permissions::pFindClient;
	}

	cout << "\nTransactions? y/n? ";
	cin >> Answer;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (Answer == 'y' || Answer == 'Y')
	{
		Permissions += clsUser::en_Permissions::pTranactions;
	}

	cout << "\nManage Users? y/n? ";
	cin >> Answer;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (Answer == 'y' || Answer == 'Y')
	{
		Permissions += clsUser::en_Permissions::pManageUsers;
	}

	cout << "\nShow Login Register? y/n? ";
	cin >> Answer;
	if (Answer == 'y' || Answer == 'Y')
	{
		Permissions += clsUser::en_Permissions::pRegister;
	}

	return Permissions;

}

void clsUpdateUserScreen::_Print_User(clsUser User)
{
	cout << "\nUser Card:";
	cout << "\n___________________";
	cout << "\nFirstName   : " << User.FirstName;
	cout << "\nLastName    : " << User.LastName;
	cout << "\nFull Name   : " << User.FullName();
	cout << "\nEmail       : " << User.Email;
	cout << "\nPhone       : " << User.Phone;
	cout << "\nUser Name   : " << User.UserName;
	cout << "\nPassword    : " << User.Password;
	cout << "\nPermissions : " << User.Permissions;
	cout << "\n___________________\n";

}

void clsUpdateUserScreen::Update_User() {
			_Draw_Screen_Header("\tUpdate User Screen");
			string user_name = "";
			cout << "\nPlease Enter User Name: ";
			user_name = clsInputValidate::Read_String();
			while (!clsUser::Is_User_Exist(user_name)) {
				cout << "\nAccount number is not found, choose another one: ";
				user_name = clsInputValidate::Read_String();
			}

			clsUser User = clsUser::Find(user_name);
			_Print_User(User);

			cout << "\nAre you sure you want to update this client y/n? ";

			char Answer = 'n';
			cin >> Answer;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			if (Answer == 'y' || Answer == 'Y')
			{
				cout << "\n\nUpdate Client Info:";
				cout << "\n____________________\n";

				_Read_User_Info(User);

				clsUser::en_Save_Results save;
				save = User.Save();
				switch (save)
				{
				case  clsUser::en_Save_Results::svSucceeded:
				{
					cout << "\nUser Updated Successfully :-)\n";
					_Print_User(User);
					break;
				}
				case clsUser::en_Save_Results::svFaildEmptyObject:
				{

					cout << "\nError User was not saved because it's Empty";
					break;
				}

				}
			}

		}