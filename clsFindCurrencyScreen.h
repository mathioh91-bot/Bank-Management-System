#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
class clsFindCurrencyScreen :protected clsScreen
{

private:
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

    static void _Show_Results(clsCurrency Currency)
    {
        if (!Currency.Is_Empty())
        {
            cout << "\nCurrency Found :-)\n";
            _Print_Currency(Currency);
        }
        else
        {
            cout << "\nCurrency Was not Found :-(\n";
        }
    }

public:

    static void ShowFindCurrencyScreen()
    {

        _Draw_Screen_Header("\t  Find Currency Screen");

        cout << "\nFind By: [1] Code or [2] Country ? ";
        short Answer = 1;

        cin >> Answer;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (Answer == 1)
        {
            string CurrencyCode;
            cout << "\nPlease Enter CurrencyCode: ";
            CurrencyCode = clsInputValidate::Read_String();
            clsCurrency Currency = clsCurrency::Find_By_Code(CurrencyCode);
            _Show_Results(Currency);
        }
        else
        {
            string Country;
            cout << "\nPlease Enter Country Name: ";
            Country = clsInputValidate::Read_String();
            clsCurrency Currency = clsCurrency::Find_By_Country(Country);
            _Show_Results(Currency);
        }






    }

};
