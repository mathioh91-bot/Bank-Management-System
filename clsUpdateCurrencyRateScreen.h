#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
class clsUpdateCurrencyRateScreen :protected clsScreen

{
private:

    static float _Read_Rate()
    {
        cout << "\nEnter New Rate: ";
        double NewRate = 0;
        NewRate = clsInputValidate::Read_Number<double>();
        return NewRate;
    }

    static void _Print_Currency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.Currency_Code();
        cout << "\nName       : " << Currency.Currency_Name();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }

public:

    static void ShowUpdateCurrencyRateScreen()
    {

        _Draw_Screen_Header("\tUpdate Currency Screen");

        string CurrencyCode = "";

        cout << "\nPlease Enter Currency Code: ";
        CurrencyCode = clsInputValidate::Read_String();

        while (!clsCurrency::Is_Currency_Exist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::Read_String();
        }

        clsCurrency Currency = clsCurrency::Find_By_Code(CurrencyCode);
        _Print_Currency(Currency);

        cout << "\nAre you sure you want to update the rate of this Currency y/n? ";

        char Answer = 'n';
        cin >> Answer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate Currency Rate:";
            cout << "\n____________________\n";

            Currency.Update_Rate(_Read_Rate());

            cout << "\nCurrency Rate Updated Successfully :-)\n";
            _Print_Currency(Currency);


        }

    }
};
