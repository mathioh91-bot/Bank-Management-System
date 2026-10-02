#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsBankClient.h"
class clsTransferLogScreen :protected clsScreen
{

private:

    static void Print_Transfer_Log_Record_Line(clsBankClient::st_Trnsfer_Log_Record TransferLogRecord);

public:

    static void ShowTransferLogScreen();

};
