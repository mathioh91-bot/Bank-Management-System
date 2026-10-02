#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsdate.h"
#include "Global.h"
class clsTransferScreen :protected clsScreen
{

private:
    static void _Print_Client(clsBankClient Client);

    static string _ReadAccountNumber();

    static double ReadAmount(clsBankClient SourceClient);

public:

    static void ShowTransferScreen();

};
