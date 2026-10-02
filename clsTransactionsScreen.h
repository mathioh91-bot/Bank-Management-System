#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
using namespace std;

class clsTransactionsScreen :protected clsScreen
{
private:
	enum en_Transactions_Menue_Options {
		eDeposit = 1, eWithdraw = 2,
		eShowTotalBalance = 3, eTransfer = 4, eTransferLog = 5,eShowMainMenue = 6
	};
	static short _Read_Transactions_Menue_Option();

	static void _ShowDepositScreen();

	static void _ShowWithdrawScreen();

	static void _ShowTotalBalancesScreen();

	static void _Show_Transfer_Screen();

	static void _ShowTransferLogScreen();


	static void _Go_Back_To_Transactions_Menue();

	static void _Perform_Transactions_Menue_Option(en_Transactions_Menue_Options TransactionsMenueOption);

public:
	static void Show_Main_Menue();
};
