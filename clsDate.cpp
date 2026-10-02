#include "clsDate.h"

clsDate::clsDate()
{
	time_t t = time(0);
	tm* now = localtime(&t);
	_Day = now->tm_mday;
	_Month = now->tm_mon + 1;
	_Year = now->tm_year + 1900;
}

clsDate::clsDate(string sDate)
{
	vector <string> vDate;
	vDate = clsString::Split(sDate, "/");

	_Day = stoi(vDate[0]);
	_Month = stoi(vDate[1]);
	_Year = stoi(vDate[2]);
}

clsDate::clsDate(short Day, short Month, short Year)
{
	_Day = Day;
	_Month = Month;
	_Year = Year;
}

clsDate::clsDate(short DateOrderInYear, short Year)
{
	//This will construct a date by date order in year
	clsDate Date1 = Get_Date_From_Day_Order_In_Year(DateOrderInYear, Year);
	_Day = Date1.Day;
	_Month = Date1.Month;
	_Year = Date1.Year;
}

void clsDate::Set_Day(short Day) {
	_Day = Day;
}

short clsDate::Get_Day() {
	return _Day;
}

void clsDate::Set_Month(short Month) {
	_Month = Month;
}

short clsDate::Get_Month() {
	return _Month;
}

void clsDate::Set_Year(short Year) {
	_Year = Year;
}

short clsDate::Get_Year() {
	return _Year;
}

void clsDate::Print()
{
	cout << Date_To_String() << endl;
}

clsDate clsDate::Get_System_Date()
{
	//system date
	time_t t = time(0);
	tm* now = localtime(&t);

	short Day, Month, Year;

	Year = now->tm_year + 1900;
	Month = now->tm_mon + 1;
	Day = now->tm_mday;

	return clsDate(Day, Month, Year);
}

	bool clsDate::Is_Valid_Date(clsDate Date)
{
	if (Date.Day < 1 || Date.Day>31)
		return false;

	if (Date.Month < 1 || Date.Month>12)
		return false;

	if (Date.Month == 2)
	{
		if (Is_Leap_Year(Date.Year))
		{
			if (Date.Day > 29)
				return false;
		}
		else
		{
			if (Date.Day > 28)
				return false;
		}
	}

	short Days_In_Month = Number_Of_Days_In_A_Month(Date.Month, Date.Year);

	if (Date.Day > Days_In_Month)
		return false;

	return true;
}

bool clsDate::Is_Valid()
{
	return Is_Valid_Date(*this);
}

 string clsDate::Date_To_String(clsDate Date)
{
	return  to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
}

string clsDate::Date_To_String()
{
	return Date_To_String(*this);
}

 bool clsDate::Is_Leap_Year(short Year)
{
	// if year is divisible by 4 AND not divisible by 100
  // OR if year is divisible by 400
  // then it is a leap year
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

bool clsDate::Is_Leap_Year()
{
	return Is_Leap_Year(_Year);
}

 short clsDate::Number_Of_Days_In_A_Year(short Year)
{
	return  Is_Leap_Year(Year) ? 366 : 365;
}

short clsDate::Number_Of_Days_In_A_Year()
{
	return  Number_Of_Days_In_A_Year(_Year);
}

 short clsDate::Number_Of_Hours_In_A_Year(short Year)
{
	return  Number_Of_Days_In_A_Year(Year) * 24;
}

short clsDate::Number_Of_Hours_In_A_Year()
{
	return  Number_Of_Hours_In_A_Year(_Year);
}

  int clsDate::Number_Of_Minutes_In_A_Year(short Year)
{
	return  Number_Of_Hours_In_A_Year(Year) * 60;
}

int clsDate::Number_Of_Minutes_In_A_Year()
{
	return  Number_Of_Minutes_In_A_Year(_Year);
}

 int clsDate::Number_Of_Seconds_In_A_Year(short Year)
{
	return  Number_Of_Minutes_In_A_Year(Year) * 60;
}

int clsDate::Number_Of_Seconds_In_A_Year()
{
	return  Number_Of_Seconds_In_A_Year(_Year);
}

 short clsDate::Number_Of_Days_In_A_Month(short Month, short Year)
{
	if (Month < 1 || Month>12)
		return  0;

	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (Month == 2) ? (Is_Leap_Year(Year) ? 29 : 28) : days[Month - 1];
}

short clsDate::Number_Of_Days_In_A_Month()
{
	return Number_Of_Days_In_A_Month(_Month, _Year);
}

 short clsDate::Number_Of_Hours_In_A_Month(short Month, short Year)
{
	return  Number_Of_Days_In_A_Month(Month, Year) * 24;
}

short clsDate::Number_Of_Hours_In_A_Month()
{
	return  Number_Of_Days_In_A_Month(_Month, _Year) * 24;
}

int clsDate::Number_Of_Minutes_In_A_Month(short Month, short Year)
{
	return  Number_Of_Hours_In_A_Month(Month, Year) * 60;
}

int clsDate::Number_Of_Minutes_In_A_Month()
{
	return  Number_Of_Hours_In_A_Month(_Month, _Year) * 60;
}

 int clsDate::Number_Of_Seconds_In_A_Month(short Month, short Year)
{
	return  Number_Of_Minutes_In_A_Month(Month, Year) * 60;
}

int clsDate::Number_Of_Seconds_In_A_Month()
{
	return  Number_Of_Minutes_In_A_Month(_Month, _Year) * 60;
}

 short clsDate::Day_Of_Week_Order(short Day, short Month, short Year)
{
	short a, y, m;
	a = (14 - Month) / 12;
	y = Year - a;
	m = Month + (12 * a) - 2;
	// Gregorian:
	//0:sun, 1:Mon, 2:Tue...etc
	return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}

short clsDate::Day_Of_Week_Order()
{
	return Day_Of_Week_Order(_Day, _Month, _Year);
}

string clsDate::Day_Short_Name(short Day_Of_Week_Order)
{
	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	return arrDayNames[Day_Of_Week_Order];
}

 string clsDate::Day_Short_Name(short Day, short Month, short Year)
{
	string arrDayNames[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	return arrDayNames[Day_Of_Week_Order(Day, Month, Year)];
}

string clsDate::Day_Short_Name()
{
	return Day_Short_Name(_Day, _Month, _Year);
}

 string clsDate::Month_Short_Name(short MonthNumber)
{
	string Months[12] = { "Jan", "Feb", "Mar",
					   "Apr", "May", "Jun",
					   "Jul", "Aug", "Sep",
					   "Oct", "Nov", "Dec"
	};

	return (Months[MonthNumber - 1]);
}

string clsDate::Month_Short_Name()
{
	return Month_Short_Name(_Month);
}

 void clsDate::Print_Month_Calendar(short Month, short Year)
{
	int NumberOfDays;

	// Index of the day from 0 to 6
	int current = Day_Of_Week_Order(1, Month, Year);

	NumberOfDays = Number_Of_Days_In_A_Month(Month, Year);

	// Print the current month name
	printf("\n  _______________%s_______________\n\n",
		Month_Short_Name(Month).c_str());

	// Print the columns
	printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

	// Print appropriate spaces
	int i;
	for (i = 0; i < current; i++)
		printf("     ");

	for (int j = 1; j <= NumberOfDays; j++)
	{
		printf("%5d", j);

		if (++i == 7)
		{
			i = 0;
			printf("\n");
		}
	}

	printf("\n  _________________________________\n");
}

void clsDate::Print_Month_Calendar()
{
	Print_Month_Calendar(_Month, _Year);
}

 void clsDate::Print_Year_Calendar(int Year)
{
	printf("\n  _________________________________\n\n");
	printf("           Calendar - %d\n", Year);
	printf("  _________________________________\n");

	for (int i = 1; i <= 12; i++)
	{
		Print_Month_Calendar(i, Year);
	}

	return;
}

void clsDate::Print_Year_Calendar()
{
	return Print_Year_Calendar(_Year);
}

 short clsDate::Days_From_The_Begining_Of_The_Year(short Day, short Month, short Year)
{
	short TotalDays = 0;

	for (int i = 1; i <= Month - 1; i++)
	{
		TotalDays += Number_Of_Days_In_A_Month(i, Year);
	}

	TotalDays += Day;

	return TotalDays;
}

short clsDate::Days_From_The_Begining_Of_The_Year()
{
	short TotalDays = 0;

	for (int i = 1; i <= _Month - 1; i++)
	{
		TotalDays += Number_Of_Days_In_A_Month(i, _Year);
	}

	TotalDays += _Day;

	return TotalDays;
}

 clsDate clsDate::Get_Date_From_Day_Order_In_Year(short DateOrderInYear, short Year)
{
	clsDate Date;
	short RemainingDays = DateOrderInYear;
	short MonthDays = 0;

	Date.Year = Year;
	Date.Month = 1;

	while (true)
	{
		MonthDays = Number_Of_Days_In_A_Month(Date.Month, Year);

		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			Date.Month++;
		}
		else
		{
			Date.Day = RemainingDays;
			break;
		}
	}

	return Date;
}

void clsDate::Add_Days(short Days)
{
	short RemainingDays = Days + Days_From_The_Begining_Of_The_Year(_Day, _Month, _Year);
	short MonthDays = 0;

	_Month = 1;

	while (true)
	{
		MonthDays = Number_Of_Days_In_A_Month(_Month, _Year);

		if (RemainingDays > MonthDays)
		{
			RemainingDays -= MonthDays;
			_Month++;

			if (_Month > 12)
			{
				_Month = 1;
				_Year++;
			}
		}
		else
		{
			_Day = RemainingDays;
			break;
		}
	}
}

 bool clsDate::Is_Date1_Before_Date2(clsDate Date1, clsDate Date2)
{
	return  (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
}

bool clsDate::Is_Date_Before_Date2(clsDate Date2)
{
	//note: *this sends the current object :-)
	return  Is_Date1_Before_Date2(*this, Date2);
}

 bool clsDate::Is_Date1_Equal_Date2(clsDate Date1, clsDate Date2)
{
	return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool clsDate::Is_Date_Equal_Date2(clsDate Date2)
{
	return  Is_Date1_Equal_Date2(*this, Date2);
}

 bool clsDate::Is_Last_Day_In_Month(clsDate Date)
{
	return (Date.Day == Number_Of_Days_In_A_Month(Date.Month, Date.Year));
}

bool clsDate::Is_Last_Day_In_Month()
{
	return Is_Last_Day_In_Month(*this);
}

 bool clsDate::Is_Last_Month_In_Year(short Month)
{
	return (Month == 12);
}

 clsDate clsDate::Add_One_Day(clsDate Date)
{
	if (Is_Last_Day_In_Month(Date))
	{
		if (Is_Last_Month_In_Year(Date.Month))
		{
			Date.Month = 1;
			Date.Day = 1;
			Date.Year++;
		}
		else
		{
			Date.Day = 1;
			Date.Month++;
		}
	}
	else
	{
		Date.Day++;
	}

	return Date;
}

void clsDate::Add_One_Day()

{
	*this = Add_One_Day(*this);
}

 void clsDate::Swap_Dates(clsDate& Date1, clsDate& Date2)
{
	clsDate TempDate;
	TempDate = Date1;
	Date1 = Date2;
	Date2 = TempDate;
}

 int clsDate::Get_Difference_In_Days(clsDate Date1, clsDate Date2, bool IncludeEndDay )
{
	//this will take care of negative diff
	int Days = 0;
	short SawpFlagValue = 1;

	if (!Is_Date1_Before_Date2(Date1, Date2))
	{
		//Swap Dates
		Swap_Dates(Date1, Date2);
		SawpFlagValue = -1;
	}

	while (Is_Date1_Before_Date2(Date1, Date2))
	{
		Days++;
		Date1 = Add_One_Day(Date1);
	}

	return IncludeEndDay ? ++Days * SawpFlagValue : Days * SawpFlagValue;
}

int clsDate::Get_Difference_In_Days(clsDate Date2, bool IncludeEndDay )
{
	return Get_Difference_In_Days(*this, Date2, IncludeEndDay);
}

 short clsDate::Calculate_My_Age_In_Days(clsDate DateOfBirth)
{
	return Get_Difference_In_Days(DateOfBirth, clsDate::Get_System_Date(), true);
}
//above no need to have nonstatic function for the object because it does not depend on any data from it.

 clsDate clsDate::Increase_Date_By_One_Week(clsDate& Date)
{
	for (int i = 1; i <= 7; i++)
	{
		Date = Add_One_Day(Date);
	}

	return Date;
}

void clsDate::Increase_Date_By_One_Week()
{
	Increase_Date_By_One_Week(*this);
}

clsDate clsDate::Increase_Date_By_X_Weeks(short Weeks, clsDate& Date)
{
	for (short i = 1; i <= Weeks; i++)
	{
		Date = Increase_Date_By_One_Week(Date);
	}
	return Date;
}

void clsDate::Increase_Date_By_X_Weeks(short Weeks)
{
	Increase_Date_By_X_Weeks(Weeks, *this);
}

clsDate clsDate::Increase_Date_By_One_Month(clsDate& Date)
{
	if (Date.Month == 12)
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
	{
		Date.Month++;
	}

	//last check day in date should not exceed max days in the current month
	// example if date is 31/1/2022 increasing one month should not be 31/2/2022, it should
	// be 28/2/2022
	short NumberOfDaysInCurrentMonth = Number_Of_Days_In_A_Month(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}

void clsDate::Increase_Date_By_One_Month()
{
	Increase_Date_By_One_Month(*this);
}

clsDate clsDate::Increase_Date_By_X_Days(short Days, clsDate& Date)
{
	for (short i = 1; i <= Days; i++)
	{
		Date = Add_One_Day(Date);
	}
	return Date;
}

void clsDate::Increase_Date_By_X_Days(short Days)
{
	Increase_Date_By_X_Days(Days, *this);
}

clsDate clsDate::Increase_Date_By_X_Months(short Months, clsDate& Date)
{
	for (short i = 1; i <= Months; i++)
	{
		Date = Increase_Date_By_One_Month(Date);
	}
	return Date;
}

void clsDate::Increase_Date_By_X_Months(short Months)
{
	Increase_Date_By_X_Months(Months, *this);
}

 clsDate clsDate::Increase_Date_By_One_Year(clsDate& Date)
{
	Date.Year++;
	return Date;
}

void clsDate::Increase_Date_By_One_Year()
{
	Increase_Date_By_One_Year(*this);
}

clsDate clsDate::Increase_Date_By_X_Years(short Years, clsDate& Date)
{
	Date.Year += Years;
	return Date;
}

void clsDate::Increase_Date_By_X_Years(short Years)
{
	Increase_Date_By_X_Years(Years,*this);
}

clsDate clsDate::Increase_Date_By_One_Decade(clsDate& Date)
{
	//Period of 10 years
	Date.Year += 10;
	return Date;
}

void clsDate::Increase_Date_By_One_Decade()
{
	Increase_Date_By_One_Decade(*this);
}

clsDate clsDate::Increase_Date_By_X_Decades(short Decade, clsDate& Date)
{
	Date.Year += Decade * 10;
	return Date;
}

void clsDate::Increase_Date_By_X_Decades(short Decade)
{
	Increase_Date_By_X_Decades(Decade, *this);
}

clsDate clsDate::Increase_Date_By_One_Century(clsDate& Date)
{
	//Period of 100 years
	Date.Year += 100;
	return Date;
}

void clsDate::Increase_Date_By_One_Century()
{
	Increase_Date_By_One_Century(*this);
}

clsDate clsDate::Increase_Date_By_One_Millennium(clsDate& Date)
{
	//Period of 1000 years
	Date.Year += 1000;
	return Date;
}

clsDate clsDate::Increase_Date_By_One_Millennium()
{
	return Increase_Date_By_One_Millennium(*this);
}

 clsDate clsDate::Decrease_Date_By_One_Day(clsDate Date)
{
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Day = 31;
			Date.Year--;
		}
		else
		{
			Date.Month--;
			Date.Day = Number_Of_Days_In_A_Month(Date.Month, Date.Year);
		}
	}
	else
	{
		Date.Day--;
	}

	return Date;
}

void clsDate::Decrease_Date_By_One_Day()
{
	Decrease_Date_By_One_Day(*this);
}

 clsDate clsDate::Decrease_Date_By_One_Week(clsDate& Date)
{
	for (int i = 1; i <= 7; i++)
	{
		Date = Decrease_Date_By_One_Day(Date);
	}

	return Date;
}

void clsDate::Decrease_Date_By_One_Week()
{
	Decrease_Date_By_One_Week(*this);
}

 clsDate clsDate::Decrease_Date_By_X_Weeks(short Weeks, clsDate& Date)
{
	for (short i = 1; i <= Weeks; i++)
	{
		Date = Decrease_Date_By_One_Week(Date);
	}
	return Date;
}

void clsDate::Decrease_Date_By_X_Weeks(short Weeks)
{
	Decrease_Date_By_X_Weeks(Weeks, *this);
}

 clsDate clsDate::Decrease_Date_By_One_Month(clsDate& Date)
{
	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
		Date.Month--;

	//last check day in date should not exceed max days in the current month
   // example if date is 31/3/2022 decreasing one month should not be 31/2/2022, it should
   // be 28/2/2022
	short NumberOfDaysInCurrentMonth = Number_Of_Days_In_A_Month(Date.Month, Date.Year);
	if (Date.Day > NumberOfDaysInCurrentMonth)
	{
		Date.Day = NumberOfDaysInCurrentMonth;
	}

	return Date;
}

void clsDate::Decrease_Date_By_One_Month()
{
	Decrease_Date_By_One_Month(*this);
}

 clsDate clsDate::Decrease_Date_By_X_Days(short Days, clsDate& Date)
{
	for (short i = 1; i <= Days; i++)
	{
		Date = Decrease_Date_By_One_Day(Date);
	}
	return Date;
}

void clsDate::Decrease_Date_By_X_Days(short Days)
{
	Decrease_Date_By_X_Days(Days, *this);
}

 clsDate clsDate::Decrease_Date_By_X_Months(short Months, clsDate& Date)
{
	for (short i = 1; i <= Months; i++)
	{
		Date = Decrease_Date_By_One_Month(Date);
	}
	return Date;
}

void clsDate::Decrease_Date_By_X_Months(short Months)
{
	Decrease_Date_By_X_Months(Months, *this);
}

 clsDate clsDate::Decrease_Date_By_One_Year(clsDate& Date)
{
	Date.Year--;
	return Date;
}

void clsDate::Decrease_Date_By_One_Year()
{
	Decrease_Date_By_One_Year(*this);
}

 clsDate clsDate::Decrease_Date_By_X_Years(short Years, clsDate& Date)
{
	Date.Year -= Years;
	return Date;
}

void clsDate::Decrease_Date_By_X_Years(short Years)
{
	Decrease_Date_By_X_Years(Years, *this);
}

 clsDate clsDate::Decrease_Date_By_One_Decade(clsDate& Date)
{
	//Period of 10 years
	Date.Year -= 10;
	return Date;
}

void clsDate::Decrease_Date_By_One_Decade()
{
	Decrease_Date_By_One_Decade(*this);
}

 clsDate clsDate::Decrease_Date_By_X_Decades(short Decades, clsDate& Date)
{
	Date.Year -= Decades * 10;
	return Date;
}

void clsDate::Decrease_Date_By_X_Decades(short Decades)
{
	Decrease_Date_By_X_Decades(Decades, *this);
}

 clsDate clsDate::Decrease_Date_By_One_Century(clsDate& Date)
{
	//Period of 100 years
	Date.Year -= 100;
	return Date;
}

void clsDate::Decrease_Date_By_One_Century()
{
	Decrease_Date_By_One_Century(*this);
}

 clsDate clsDate::Decrease_Date_By_One_Millennium(clsDate& Date)
{
	//Period of 1000 years
	Date.Year -= 1000;
	return Date;
}

void clsDate::Decrease_Date_By_One_Millennium()
{
	Decrease_Date_By_One_Millennium(*this);
}

 short clsDate::Is_End_Of_Week(clsDate Date)
{
	return  Day_Of_Week_Order(Date.Day, Date.Month, Date.Year) == 6;
}

short clsDate::Is_End_Of_Week()
{
	return Is_End_Of_Week(*this);
}

 bool clsDate::Is_Week_End(clsDate Date)
{
	//Weekends are Fri and Sat
	short DayIndex = Day_Of_Week_Order(Date.Day, Date.Month, Date.Year);
	return  (DayIndex == 5 || DayIndex == 6);
}

bool clsDate::Is_Week_End()
{
	return  Is_Week_End(*this);
}

 bool clsDate::Is_Business_Day(clsDate Date)
{
	//Weekends are Sun,Mon,Tue,Wed and Thur

   /*
	short DayIndex = Day_Of_Week_Order(Date.Day, Date.Month, Date.Year);
	return  (DayIndex >= 5 && DayIndex <= 4);
   */

   //shorter method is to invert the Is_Week_End: this will save updating code.
	return !Is_Week_End(Date);
}

bool clsDate::Is_Business_Day()
{
	return  Is_Business_Day(*this);
}

 short clsDate::Days_Until_The_End_Of_Week(clsDate Date)
{
	return 6 - Day_Of_Week_Order(Date.Day, Date.Month, Date.Year);
}

short clsDate::Days_Until_The_End_Of_Week()
{
	return  Days_Until_The_End_Of_Week(*this);
}

 short clsDate::Days_Until_The_End_Of_Month(clsDate Date1)
{
	clsDate EndOfMontDate;
	EndOfMontDate.Day = Number_Of_Days_In_A_Month(Date1.Month, Date1.Year);
	EndOfMontDate.Month = Date1.Month;
	EndOfMontDate.Year = Date1.Year;

	return Get_Difference_In_Days(Date1, EndOfMontDate, true);
}

short clsDate::Days_Until_The_End_Of_Month()
{
	return Days_Until_The_End_Of_Month(*this);
}

 short clsDate::Days_Until_The_End_Of_Year(clsDate Date1)
{
	clsDate EndOfYearDate;
	EndOfYearDate.Day = 31;
	EndOfYearDate.Month = 12;
	EndOfYearDate.Year = Date1.Year;

	return Get_Difference_In_Days(Date1, EndOfYearDate, true);
}

short clsDate::Days_Until_The_End_Of_Year()
{
	return  Days_Until_The_End_Of_Year(*this);
}

//i added this method to calculate business days between 2 days
 short clsDate::Calculate_Business_Days(clsDate DateFrom, clsDate DateTo)
{
	short Days = 0;
	while (Is_Date1_Before_Date2(DateFrom, DateTo))
	{
		if (Is_Business_Day(DateFrom))
			Days++;

		DateFrom = Add_One_Day(DateFrom);
	}

	return Days;
}

 short clsDate::Calculate_Vacation_Days(clsDate DateFrom, clsDate DateTo)
{
	/*short Days = 0;
	while (Is_Date1_Before_Date2(DateFrom, DateTo))
	{
		if (Is_Business_Day(DateFrom))
			Days++;

		DateFrom = Add_One_Day(DateFrom);
	}*/

	return Calculate_Business_Days(DateFrom, DateTo);
}
//above method is eough , no need to have method for the object

 clsDate clsDate::Calculate_Vacation_Return_Date(clsDate DateFrom, short VacationDays)
{
	short WeekEndCounter = 0;

	for (short i = 1; i <= VacationDays; i++)
	{
		if (Is_Week_End(DateFrom))
			WeekEndCounter++;

		DateFrom = Add_One_Day(DateFrom);
	}
	//to add weekends
	for (short i = 1; i <= WeekEndCounter; i++)
		DateFrom = Add_One_Day(DateFrom);

	return DateFrom;
}

 bool clsDate::Is_Date1_After_Date2(clsDate Date1, clsDate Date2)
{
	return (!Is_Date1_Before_Date2(Date1, Date2) && !Is_Date1_Equal_Date2(Date1, Date2));
}

bool clsDate::Is_Date_After_Date2(clsDate Date2)
{
	return Is_Date1_After_Date2(*this, Date2);
}


clsDate::enDateCompare clsDate::Compare_Dates(clsDate Date1, clsDate Date2)
{
	if (Is_Date1_Before_Date2(Date1, Date2))
		return enDateCompare::Before;

	if (Is_Date1_Equal_Date2(Date1, Date2))
		return enDateCompare::Equal;

	/* if (Is_Date1_After_Date2(Date1,Date2))
		 return enDateCompare::After;*/

		 //this is faster
	return enDateCompare::After;
}

clsDate::enDateCompare clsDate::Compare_Dates(clsDate Date2)
{
	return Compare_Dates(*this, Date2);
}

 string clsDate::GetSystemDateTimeString()
{
	time_t t = time(0);
	tm* now = localtime(&t);

	short Day, Month, Year, Hour, Minute, Second;

	Year = now->tm_year + 1900;
	Month = now->tm_mon + 1;
	Day = now->tm_mday;
	Hour = now->tm_hour;
	Minute = now->tm_min;
	Second = now->tm_sec;

	return (to_string(Day) + "/" + to_string(Month) + "/" +
		to_string(Year) + " - " +
		to_string(Hour) + ":" + to_string(Minute) +
		":" + to_string(Second));
}