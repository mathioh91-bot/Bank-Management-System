#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsString.h"
using namespace std;

class clsCurrency
{
private:
	enum class _en_FindBy
	{
		_Currency_Code,
		_Country
	};

	string _Country,_Currency_Code, _Currency_Name;
	double _Rate;
	enum en_Mode {
		eEmpty = 0, eUpdate = 1
	};
	en_Mode _Mode;

	static clsCurrency _Convert_Line_to_Currency_Object(string Line, string Seperator = "#//#")
	{
		vector<string> v;
		 v = clsString::Split(Line, Seperator);
		return clsCurrency(en_Mode::eUpdate, v[0], v[1], v[2],stod(v[3]));

	}

	static string _Convert_Currency_Object_To_Line(clsCurrency Currency, string Seperator = "#//#"){
		string st_Currency_Record = "";
		st_Currency_Record += Currency._Country + Seperator;
		st_Currency_Record += Currency._Currency_Code + Seperator;
		st_Currency_Record += Currency._Currency_Name + Seperator;
		st_Currency_Record += to_string(Currency._Rate);
		return st_Currency_Record;
	
	}

	static vector<clsCurrency> _Load_Currencys_Data_From_File() {
		vector<clsCurrency> v;
		fstream my_file;
		string line;
		
		my_file.open("Currencies.txt",ios::in);
		if (my_file.is_open()) {
			while (getline(my_file, line)) {
				clsCurrency Currency = _Convert_Line_to_Currency_Object(line);
				v.push_back(Currency);
			}
			my_file.close();
		}
		return v;

	}

	static void _Save_Currency_Data_To_File (vector<clsCurrency> Currency){
		fstream my_file;
		my_file.open("Currencies.txt", ios::out);
		string line;
		if(my_file.is_open()){
			
			for (clsCurrency& c :	Currency) {
				line = _Convert_Currency_Object_To_Line(c);
				my_file << line << endl;
		    } 
		
		
			my_file.close();
		}

		}

	 void _Update (){
		vector<clsCurrency> v = _Load_Currencys_Data_From_File();
		for (clsCurrency& c : v) {
		 
			if ( c.Currency_Code() == Currency_Code()) {
			  
				c = *this;
				break;
			}
		
		}
		_Save_Currency_Data_To_File(v);
	
	}

	 static clsCurrency _Get_Empty_Currency_Object() {
		 return clsCurrency(en_Mode::eEmpty, "", "", "", 0);
	 }
public:

	clsCurrency(en_Mode Mode, string Country, string Currenty_Code, string Currency_Name, double Rate) {
		_Mode = Mode;
		_Country = Country;
		_Currency_Code = Currenty_Code;
		_Currency_Name = Currency_Name;
		_Rate = Rate;

	}

	bool Is_Empty()
	{
		return (_Mode == en_Mode::eEmpty);
	}

	string Country()
	{
		return _Country;
	}

	string Currency_Code()
	{
		return _Currency_Code;
	}

	string Currency_Name()
	{
		return _Currency_Name;
	}

	void Update_Rate(double NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	double Rate()
	{
		return _Rate;
	}

	static clsCurrency Find(string Currency_Code ="", string Country = "", _en_FindBy eFindBy = _en_FindBy::_Currency_Code) {

		Currency_Code = clsString::Upper_All_String(Currency_Code);
		Country = clsString::Upper_All_String(Country);

		vector<clsCurrency> v = _Load_Currencys_Data_From_File();
		for (clsCurrency& c : v) {
			if (eFindBy == _en_FindBy::_Country) {
				if (clsString::Upper_All_String(c.Currency_Name()) == Country)
				{
					return c;
				}
			}
			else {
					if (clsString::Upper_All_String(c.Currency_Code()) == Currency_Code) {
						return c;

					}

				}

		}
		return _Get_Empty_Currency_Object();
	}

	static clsCurrency Find_By_Code(string _Currency_Code) {
		return Find(_Currency_Code, "", _en_FindBy::_Currency_Code);
	}

	static clsCurrency Find_By_Country(string _Country) {
		return Find("", _Country, _en_FindBy::_Country);
	}

	static bool Is_Currency_Exist(string Currency_Code) {
		clsCurrency C1 = clsCurrency::Find_By_Code(Currency_Code);
		return (!C1.Is_Empty());
			
	}

	static vector<clsCurrency> Get_Currencies_List() {
		return _Load_Currencys_Data_From_File();
	}

	double Convert_To_USD(double Amount)
	{
		return (double)(Amount / Rate());
	}

	double Convert_To_Other_Currency(double Amount, clsCurrency Currency2)
	{
		double AmountInUSD = Convert_To_USD(Amount);

		if (Currency2.Currency_Code() == "USD")
		{
			return AmountInUSD;
		}

		return (double)(AmountInUSD * Currency2.Rate());

	}

};


