#pragma once
#include <iostream>
#include <string>
#include "clsString.h"
#include "clsDate.h"

class clsInputValidate
{
public:

	static bool Is_Number_Between(short Number, short From, short To);

	static bool Is_Number_Between(int Number, int From, int To);

	static bool Is_Number_Between(float Number, float From, float To);

	static bool Is_Number_Between(double Number, double From, double To);

	static bool Is_Date_Between(clsDate Date, clsDate From, clsDate To);

	static int Read_Int_Number(string ErrorMessage = "Invalid Number, Enter again\n");

	static short Read_Short_Number(string ErrorMessage = "Invalid Number, Enter again\n");

	static int Read_Int_Number_Between(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n");

	static short Read_Short_Number_Between(short From, short To, string ErrorMessage = "Number is not within range, Enter again:\n");

	static double Read_Dbl_Number(string ErrorMessage = "Invalid Number, Enter again\n");

	static float Read_Float_Number(string ErrorMessage = "Invalid Number, Enter again\n");

	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n");

	static bool Is_Valide_Date(clsDate Date);

	static string Read_String();
};