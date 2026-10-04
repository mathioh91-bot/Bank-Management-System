#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsCurrenciesListScreen.h";
#include "clsInputValidate.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"
using namespace std;
class clsCurrencyExchangeMainScreen :protected clsScreen
{

private:
    enum en_Currencies_Main_Menue_Options {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateCurrencyRate = 3,
        eCurrencyCalculator = 4, eMainMenue = 5
    };

    static short Read_Currencies_Main_Menue_Options()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::Read_Number_Between<short>(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _Go_Back_To_Currencies_Menue()
    {
        cout << "\n\nPress any key to go back to Currencies Menue...";
        system("pause>0");
    }

    static void _Show_Currencies_List_Screen()
    {
        clsCurrenciesListScreen::ShowCurrenciesListScreen();

    }

    static void _Show_Find_Currency_Screen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();

    }

    static void _Show_Update_Currency_Rate_Screen()
    {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }

    static void _Show_Currency_Calculator_Screen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();

    }

    static void _Perform_Currencies_Main_Menue_Options(en_Currencies_Main_Menue_Options CurrenciesMainMenueOptions)
    {

        switch (CurrenciesMainMenueOptions)
        {
        case en_Currencies_Main_Menue_Options::eListCurrencies:
        {
            system("cls");
            _Show_Currencies_List_Screen();
            
            break;
        }

        case en_Currencies_Main_Menue_Options::eFindCurrency:
        {
            system("cls");
            _Show_Find_Currency_Screen();
            break;
        }

        case en_Currencies_Main_Menue_Options::eUpdateCurrencyRate:
        {
            system("cls");
            _Show_Update_Currency_Rate_Screen();
            break;
        }

        case en_Currencies_Main_Menue_Options::eCurrencyCalculator:
        {
            system("cls");
            _Show_Currency_Calculator_Screen();
          
            break;
        }

        case en_Currencies_Main_Menue_Options::eMainMenue:
        {
            //do nothing here the main screen will handle it :-) ;
        }
        }

    }

public:

    static void Show_Currencies_Menue()
    {
        while (true)
        {
        system("cls");
        _Draw_Screen_Header("    Currancy Exhange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exhange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        en_Currencies_Main_Menue_Options choice = (en_Currencies_Main_Menue_Options)Read_Currencies_Main_Menue_Options();

        if (choice == en_Currencies_Main_Menue_Options::eMainMenue)
        {
            system("cls");
     
            break;
        }

        _Perform_Currencies_Main_Menue_Options(choice);

        cout << "\n\nPress any key to go back to Main Menue...";
        system("pause>0");
        }
    }

};
 