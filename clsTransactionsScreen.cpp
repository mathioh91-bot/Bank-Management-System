#include "clsTransactionsScreen.h"
 short clsTransactionsScreen::_Read_Transactions_Menue_Option()
{
	cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
	short Choice = clsInputValidate::Read_Number_Between<short>(1,6, "Enter Number between 1 to 6? ");
	return Choice;
}
 void clsTransactionsScreen::_ShowDepositScreen()
{
	clsDepositScreen::ShowDepositScreen();
}

 void clsTransactionsScreen::_ShowWithdrawScreen()
{
	clsWithdrawScreen::ShowWithdrawScreen();
}

 void clsTransactionsScreen::_ShowTotalBalancesScreen()
{
	clsTotalBalancesScreen::ShowTotalBalances();
}
 void clsTransactionsScreen::_Show_Transfer_Screen() {

	 clsTransferScreen::ShowTransferScreen();
 }
  void clsTransactionsScreen::_ShowTransferLogScreen()
 {

	 clsTransferLogScreen::ShowTransferLogScreen();

 }


 void clsTransactionsScreen::_Go_Back_To_Transactions_Menue()
{
	cout << "\n\nPress any key to go back to Transactions Menue...";
}

 void  clsTransactionsScreen::_Perform_Transactions_Menue_Option(en_Transactions_Menue_Options TransactionsMenueOption)
{
	switch (TransactionsMenueOption)
	{
	case en_Transactions_Menue_Options::eDeposit:
	{
		system("cls");
		_ShowDepositScreen();
		_Go_Back_To_Transactions_Menue();
		break;
	}

	case en_Transactions_Menue_Options::eWithdraw:
	{
		system("cls");
		_ShowWithdrawScreen();
		_Go_Back_To_Transactions_Menue();
		break;
	}

	case en_Transactions_Menue_Options::eShowTotalBalance:
	{
		system("cls");
		_ShowTotalBalancesScreen();
		_Go_Back_To_Transactions_Menue();
		break;
	}
	case en_Transactions_Menue_Options::eTransfer:
	{
		system("cls");
		_Show_Transfer_Screen();
		_Go_Back_To_Transactions_Menue();
		break;
	}
	case en_Transactions_Menue_Options::eTransferLog:
	{
		system("cls");
		_ShowTransferLogScreen();
		_Go_Back_To_Transactions_Menue();
		break;
	}
	case en_Transactions_Menue_Options::eShowMainMenue:
	{
		//do nothing here the main screen will handle it :-) ;
	}
	}
}
	
 void  clsTransactionsScreen::Show_Main_Menue()
	{
	 if (!Check_Access_Rights(clsUser::en_Permissions::pTranactions))
	 {
		 return;
	 }
		while (true)
		{
			system("cls");
			_Draw_Screen_Header("\t  Transactions Screen");

			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t\t  Transactions Menue\n";
			cout << setw(37) << left << "" << "===========================================\n";
			cout << setw(37) << left << "" << "\t[1] Deposit.\n";
			cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
			cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
			cout << setw(37) << left << "" << "\t[4] Transfer.\n";
			cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
			cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
			cout << setw(37) << left << "" << "===========================================\n";	

			en_Transactions_Menue_Options choice = (en_Transactions_Menue_Options)_Read_Transactions_Menue_Option();

			if (choice == en_Transactions_Menue_Options::eShowMainMenue)
			{
				system("cls");
				break;
			}

			_Perform_Transactions_Menue_Option(choice);

			system("pause>0");
		}
	}