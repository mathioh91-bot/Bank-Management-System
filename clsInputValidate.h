#pragma once
#include <iostream>
#include <string>
#include <limits>
#include "clsString.h"
#include "clsDate.h"

using namespace std;

class clsInputValidate
{
public:

    template <typename T>
    static bool Is_Number_Between(T Number, T From, T To)
    {
        return Number >= From && Number <= To;
    }

    static bool Is_Date_Between(clsDate Date, clsDate From, clsDate To);

    template <typename T>
    static T Read_Number(string ErrorMessage = "Invalid Number, Enter again\n")
    {
        T Number;

        while (!(cin >> Number))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << ErrorMessage;
        }

        return Number;
    }

    template <typename T>
    static T Read_Number_Between(
        T From,
        T To,
        string ErrorMessage = "Number is not within range, Enter again:\n")
    {
        T Number = Read_Number<T>();

        while (!Is_Number_Between(Number, From, To))
        {
            cout << ErrorMessage;
            Number = Read_Number<T>();
        }

        return Number;
    }

    static bool Is_Valide_Date(clsDate Date);

    static string Read_String();
};