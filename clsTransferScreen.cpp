#include "clsTransferScreen.h"
 void clsTransferScreen::_Print_Client(clsBankClient Client)
{
    cout << "\nClient Card:";
    cout << "\n___________________\n";
    cout << "\nFull Name   : " << Client.FullName();
    cout << "\nAcc. Number : " << Client.Account_Number;
    cout << "\nBalance     : " << Client.Account_Balance;
    cout << "\n___________________\n";

}


 string clsTransferScreen::_ReadAccountNumber()
{
    string AccountNumber;
    cout << "\nPlease Enter Account Number to Transfer From: ";
    AccountNumber = clsInputValidate::Read_String();
    while (!clsBankClient::Is_Client_Exist(AccountNumber))
    {
        cout << "\nAccount number is not found, choose another one: ";
        AccountNumber = clsInputValidate::Read_String();
    }
    return AccountNumber;
}

double clsTransferScreen::ReadAmount(clsBankClient SourceClient)
{
    float Amount;

    cout << "\nEnter Transfer Amount? ";

    Amount = clsInputValidate::Read_Float_Number();

    while (Amount > SourceClient.Account_Balance)
    {
        cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
        Amount = clsInputValidate::Read_Float_Number();
    }
    return Amount;
}

 void clsTransferScreen::ShowTransferScreen()
    {

        _Draw_Screen_Header("\tTransfer Screen");

        clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

        _Print_Client(SourceClient);

        clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

        _Print_Client(DestinationClient);

        float Amount = ReadAmount(SourceClient);


        cout << "\nAre you sure you want to perform this operation? y/n? ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'Y' || Answer == 'y')
        {
            if (SourceClient.Transfer(Amount, DestinationClient,Current_User.UserName))
            {
                cout << "\nTransfer done successfully\n";
            }
            else
            {
                cout << "\nTransfer Faild \n";
            }
        }
        
        _Print_Client(SourceClient);
        _Print_Client(DestinationClient);
        
    }