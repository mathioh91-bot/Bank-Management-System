#include "clsInputValidate.h"
 bool clsInputValidate::Is_Number_Between(short Number, short From, short To)
{
	if (Number >= From && Number <= To)
		return true;
	else
		return false;
}

 bool clsInputValidate::Is_Number_Between(int Number, int From, int To)
{
	if (Number >= From && Number <= To)
		return true;
	else
		return false;
}

 bool clsInputValidate::Is_Number_Between(float Number, float From, float To)
{
	if (Number >= From && Number <= To)
		return true;
	else
		return false;
}

 bool clsInputValidate::Is_Number_Between(double Number, double From, double To)
{
	if (Number >= From && Number <= To)
		return true;
	else
		return false;
}

 bool clsInputValidate::Is_Date_Between(clsDate Date, clsDate From, clsDate To)
{
	//Date>=From && Date<=To
	if ((clsDate::Is_Date1_After_Date2(Date, From) || clsDate::Is_Date1_Equal_Date2(Date, From))
		&&
		(clsDate::Is_Date1_Before_Date2(Date, To) || clsDate::Is_Date1_Equal_Date2(Date, To))
		)
	{
		return true;
	}

	//Date>=To && Date<=From
	if ((clsDate::Is_Date1_After_Date2(Date, To) || clsDate::Is_Date1_Equal_Date2(Date, To))
		&&
		(clsDate::Is_Date1_Before_Date2(Date, From) || clsDate::Is_Date1_Equal_Date2(Date, From))
		)
	{
		return true;
	}

	return false;
}

 int clsInputValidate::Read_Int_Number(string ErrorMessage )
{
	int Number;
	while (!(cin >> Number)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << ErrorMessage;
	}
	return Number;
}

 short clsInputValidate::Read_Short_Number(string ErrorMessage )
{
	short Number;
	while (!(cin >> Number)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << ErrorMessage;
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	return Number;
}

 int clsInputValidate::Read_Int_Number_Between(int From, int To, string ErrorMessage )
{
	int Number = Read_Int_Number();

	while (!Is_Number_Between(Number, From, To))
	{
		cout << ErrorMessage;
		Number = Read_Int_Number();
	}
	return Number;
}

 short clsInputValidate::Read_Short_Number_Between(short From, short To, string ErrorMessage)
{
	short Number = Read_Short_Number();

	while (!Is_Number_Between(Number, From, To))
	{
		cout << ErrorMessage;
		Number = Read_Int_Number();
	}
	return Number;
}

 double clsInputValidate::Read_Dbl_Number(string ErrorMessage )
{
	double Number;
	while (!(cin >> Number)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << ErrorMessage;
	}
	return Number;
}

 float clsInputValidate::Read_Float_Number(string ErrorMessage)
{
	float Number;
	while (!(cin >> Number)) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << ErrorMessage;
	}
	return Number;
}

 double clsInputValidate::ReadDblNumberBetween(double From, double To, string ErrorMessage )
{
	double Number = Read_Dbl_Number();

	while (!Is_Number_Between(Number, From, To)) {
		cout << ErrorMessage;
		Number = Read_Dbl_Number();
	}
	return Number;

}

 bool clsInputValidate::Is_Valide_Date(clsDate Date)
{
	return	clsDate::Is_Valid_Date(Date);
}

 string clsInputValidate::Read_String() {
	string s;
	getline(cin, s);
	return s;
}