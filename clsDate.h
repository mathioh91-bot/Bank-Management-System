#pragma once
#pragma warning(disable : 4996)



#include<iostream>
#include<string>
#include<vector>
#include "clsString.h"

using namespace std;

class clsDate
{
private:

	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;

public:

	clsDate();

	clsDate(string sDate);

	clsDate(short Day, short Month, short Year);

	clsDate(short DateOrderInYear, short Year);
	

	void Set_Day(short Day);
	short Get_Day();
	__declspec(property(get = Get_Day, put = Set_Day)) short Day;

	void Set_Month(short Month);

	short Get_Month();
	__declspec(property(get = Get_Month, put = Set_Month)) short Month;

	void Set_Year(short Year);

	short Get_Year();
	__declspec(property(get = Get_Year, put = Set_Year)) short Year;

	void Print();

	static clsDate Get_System_Date();

	static	bool Is_Valid_Date(clsDate Date);

	bool Is_Valid();

	static string Date_To_String(clsDate Date);

	string Date_To_String();

	static bool Is_Leap_Year(short Year);

	bool Is_Leap_Year();

	static short Number_Of_Days_In_A_Year(short Year);

	short Number_Of_Days_In_A_Year();

	static short Number_Of_Hours_In_A_Year(short Year);

	short Number_Of_Hours_In_A_Year();

	static int Number_Of_Minutes_In_A_Year(short Year);

	int Number_Of_Minutes_In_A_Year();

	static int Number_Of_Seconds_In_A_Year(short Year);

	int Number_Of_Seconds_In_A_Year();

	static short Number_Of_Days_In_A_Month(short Month, short Year);

	short Number_Of_Days_In_A_Month();

	static short Number_Of_Hours_In_A_Month(short Month, short Year);

	short Number_Of_Hours_In_A_Month();

	static int Number_Of_Minutes_In_A_Month(short Month, short Year);

	int Number_Of_Minutes_In_A_Month();

	static int Number_Of_Seconds_In_A_Month(short Month, short Year);

	int Number_Of_Seconds_In_A_Month();

	static short Day_Of_Week_Order(short Day, short Month, short Year);

	short Day_Of_Week_Order();

	static string Day_Short_Name(short Day_Of_Week_Order);

	static string Day_Short_Name(short Day, short Month, short Year);

	string Day_Short_Name();

	static string Month_Short_Name(short MonthNumber);

	string Month_Short_Name();

	static void Print_Month_Calendar(short Month, short Year);

	void Print_Month_Calendar();

	static void Print_Year_Calendar(int Year);

	void Print_Year_Calendar();

	static short Days_From_The_Begining_Of_The_Year(short Day, short Month, short Year);

	short Days_From_The_Begining_Of_The_Year();

	static clsDate Get_Date_From_Day_Order_In_Year(short DateOrderInYear, short Year);

	void Add_Days(short Days);

	static bool Is_Date1_Before_Date2(clsDate Date1, clsDate Date2);

	bool Is_Date_Before_Date2(clsDate Date2);

	static bool Is_Date1_Equal_Date2(clsDate Date1, clsDate Date2);

	bool Is_Date_Equal_Date2(clsDate Date2);

	static bool Is_Last_Day_In_Month(clsDate Date);

	bool Is_Last_Day_In_Month();

	static bool Is_Last_Month_In_Year(short Month);

	static clsDate Add_One_Day(clsDate Date);

	void Add_One_Day();

	static void Swap_Dates(clsDate& Date1, clsDate& Date2);

	static int Get_Difference_In_Days(clsDate Date1, clsDate Date2, bool IncludeEndDay = false);

	int Get_Difference_In_Days(clsDate Date2, bool IncludeEndDay = false);

	static short Calculate_My_Age_In_Days(clsDate DateOfBirth);
	
	static clsDate Increase_Date_By_One_Week(clsDate& Date);

	void Increase_Date_By_One_Week();

	clsDate Increase_Date_By_X_Weeks(short Weeks, clsDate& Date);

	void Increase_Date_By_X_Weeks(short Weeks);

	clsDate Increase_Date_By_One_Month(clsDate& Date);

	void Increase_Date_By_One_Month();

	clsDate Increase_Date_By_X_Days(short Days, clsDate& Date);

	void Increase_Date_By_X_Days(short Days);

	clsDate Increase_Date_By_X_Months(short Months, clsDate& Date);

	void Increase_Date_By_X_Months(short Months);

	static clsDate Increase_Date_By_One_Year(clsDate& Date);

	void Increase_Date_By_One_Year();

	clsDate Increase_Date_By_X_Years(short Years, clsDate& Date);

	void Increase_Date_By_X_Years(short Years);

	clsDate Increase_Date_By_One_Decade(clsDate& Date);

	void Increase_Date_By_One_Decade();

	clsDate Increase_Date_By_X_Decades(short Decade, clsDate& Date);

	void Increase_Date_By_X_Decades(short Decade);

	clsDate Increase_Date_By_One_Century(clsDate& Date);

	void Increase_Date_By_One_Century();

	clsDate Increase_Date_By_One_Millennium(clsDate& Date);

	clsDate Increase_Date_By_One_Millennium();

	static clsDate Decrease_Date_By_One_Day(clsDate Date);

	void Decrease_Date_By_One_Day();

	static clsDate Decrease_Date_By_One_Week(clsDate& Date);

	void Decrease_Date_By_One_Week();

	static clsDate Decrease_Date_By_X_Weeks(short Weeks, clsDate& Date);

	void Decrease_Date_By_X_Weeks(short Weeks);

	static clsDate Decrease_Date_By_One_Month(clsDate& Date);

	void Decrease_Date_By_One_Month();

	static clsDate Decrease_Date_By_X_Days(short Days, clsDate& Date);

	void Decrease_Date_By_X_Days(short Days);

	static clsDate Decrease_Date_By_X_Months(short Months, clsDate& Date);

	void Decrease_Date_By_X_Months(short Months);

	static clsDate Decrease_Date_By_One_Year(clsDate& Date);

	void Decrease_Date_By_One_Year();

	static clsDate Decrease_Date_By_X_Years(short Years, clsDate& Date);

	void Decrease_Date_By_X_Years(short Years);

	static clsDate Decrease_Date_By_One_Decade(clsDate& Date);

	void Decrease_Date_By_One_Decade();

	static clsDate Decrease_Date_By_X_Decades(short Decades, clsDate& Date);

	void Decrease_Date_By_X_Decades(short Decades);

	static clsDate Decrease_Date_By_One_Century(clsDate& Date);

	void Decrease_Date_By_One_Century();

	static clsDate Decrease_Date_By_One_Millennium(clsDate& Date);

	void Decrease_Date_By_One_Millennium();

	static short Is_End_Of_Week(clsDate Date);

	short Is_End_Of_Week();

	static bool Is_Week_End(clsDate Date);

	bool Is_Week_End();

	static bool Is_Business_Day(clsDate Date);

	bool Is_Business_Day();

	static short Days_Until_The_End_Of_Week(clsDate Date);

	short Days_Until_The_End_Of_Week();

	static short Days_Until_The_End_Of_Month(clsDate Date1);

	short Days_Until_The_End_Of_Month();

	static short Days_Until_The_End_Of_Year(clsDate Date1);

	short Days_Until_The_End_Of_Year();

	static short Calculate_Business_Days(clsDate DateFrom, clsDate DateTo);

	static short Calculate_Vacation_Days(clsDate DateFrom, clsDate DateTo);

	static clsDate Calculate_Vacation_Return_Date(clsDate DateFrom, short VacationDays);

	static bool Is_Date1_After_Date2(clsDate Date1, clsDate Date2);

	bool Is_Date_After_Date2(clsDate Date2);

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare Compare_Dates(clsDate Date1, clsDate Date2);

	enDateCompare Compare_Dates(clsDate Date2);

	static string GetSystemDateTimeString();
};