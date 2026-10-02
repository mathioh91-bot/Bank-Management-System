#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include <iomanip>
#include "clsUtil.h"
class clsTotalBalancesScreen : protected clsScreen
{
private:

	static void PrintClientRecordBalanceLine(clsBankClient Client);

public:

	static void ShowTotalBalances();
};
