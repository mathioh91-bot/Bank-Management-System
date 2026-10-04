#include "clsInputValidate.h"

bool clsInputValidate::Is_Date_Between(clsDate Date, clsDate From, clsDate To)
{
    // Date >= From && Date <= To
    if ((clsDate::Is_Date1_After_Date2(Date, From) ||
        clsDate::Is_Date1_Equal_Date2(Date, From))
        &&
        (clsDate::Is_Date1_Before_Date2(Date, To) ||
            clsDate::Is_Date1_Equal_Date2(Date, To)))
    {
        return true;
    }

    // Date >= To && Date <= From
    if ((clsDate::Is_Date1_After_Date2(Date, To) ||
        clsDate::Is_Date1_Equal_Date2(Date, To))
        &&
        (clsDate::Is_Date1_Before_Date2(Date, From) ||
            clsDate::Is_Date1_Equal_Date2(Date, From)))
    {
        return true;
    }

    return false;
}

bool clsInputValidate::Is_Valide_Date(clsDate Date)
{
    return clsDate::Is_Valid_Date(Date);
}

string clsInputValidate::Read_String()
{
    string s;
    getline(cin, s);

    return s;
}