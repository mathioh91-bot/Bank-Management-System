#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

class clsCurrencyCalculatorScreen :protected clsScreen

{
private:

    static double _Read_Amount()
    {
        cout << "\nEnter Amount to Exchange: ";
        double Amount = 0;

        Amount = clsInputValidate::Read_Number<double>();
        return Amount;
    }

    static clsCurrency _Get_Currency(string Message)
    {

        string CurrencyCode;
        cout << Message << endl;

        CurrencyCode = clsInputValidate::Read_String();

        while (!clsCurrency::Is_Currency_Exist(CurrencyCode))
        {
            cout << "\nCurrency is not found, choose another one: ";
            CurrencyCode = clsInputValidate::Read_String();
        }

        clsCurrency Currency = clsCurrency::Find_By_Code(CurrencyCode);
        return Currency;

    }


    static  void _Print_Currency_Card(clsCurrency Currency, string Title = "Currency Card:")
    {

        cout << "\n" << Title << "\n";
        cout << "_____________________________\n";
        cout << "\nCountry       : " << Currency.Country();
        cout << "\nCode          : " << Currency.Currency_Code();
        cout << "\nName          : " << Currency.Currency_Name();
        cout << "\nRate(1$) =    : " << Currency.Rate();
        cout << "\n_____________________________\n\n";

    }

    static void _Print_Calculations_Results(double Amount, clsCurrency Currency1, clsCurrency Currency2)
    {

        _Print_Currency_Card(Currency1, "Convert From:");

        double AmountInUSD = Currency1.Convert_To_USD(Amount);

        cout << Amount << " " << Currency1.Currency_Code() << " = " << AmountInUSD << " USD\n";

        if (Currency2.Currency_Code() == "USD")
        {
            return;
        }

        cout << "\nConverting from USD to:\n";

        _Print_Currency_Card(Currency2, "To:");

        double AmountInCurrrency2 = Currency1.Convert_To_Other_Currency(Amount, Currency2);

        cout << Amount << " " << Currency1.Currency_Code()
            << " = " << AmountInCurrrency2 << " " << Currency2.Currency_Code();

    }


public:

    static void ShowCurrencyCalculatorScreen()
    {
        char Continue = 'y';

        while (Continue == 'y' || Continue == 'Y')
        {
            system("cls");

            _Draw_Screen_Header("\tUpdate Currency Screen");

            clsCurrency CurrencyFrom = _Get_Currency("\nPlease Enter Currency1 Code: ");
            clsCurrency CurrencyTo = _Get_Currency("\nPlease Enter Currency2 Code: ");
            float Amount = _Read_Amount();

            _Print_Calculations_Results(Amount, CurrencyFrom, CurrencyTo);

            cout << "\n\nDo you want to perform another calculation? y/n ? ";
            cin >> Continue;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }


    }
};
