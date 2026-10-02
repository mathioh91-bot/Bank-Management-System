#pragma once

#include <iostream>
#include <vector>

using namespace std;

class clsString
{
private:
	string _Value;

public:

	clsString();

	clsString(string Value);

	void Set_Value(string Value);

	string Get_Value();

	__declspec(property(get = Get_Value, put = Set_Value)) string Value;

	static short Length(string S1);

	short Length();

	static short Count_Words(string S1);

	short Count_Words();

	static string  Upper_First_Letter_Of_Each_Word(string S1);

	void  Upper_First_Letter_Of_Each_Word();

	static string  Lower_First_Letter_Of_Each_Word(string S1);

	void  Lower_First_Letter_Of_Each_Word();

	static string  Upper_All_String(string S1);

	void  Upper_All_String();

	static string  Lower_All_String(string S1);

	void  Lower_All_String();

	static char  Invert_Letter_Case(char char1);

	static string  Invert_All_Letters_Case(string S1);

	void  Invert_All_Letters_Case();

	enum en_What_To_Count { Small_Letters = 0, Capital_Letters = 1, All = 3 };

	static short Count_Letters(string S1, en_What_To_Count WhatToCount = en_What_To_Count::All);

	static short  Count_Capital_Letters(string S1);

	short  Count_Capital_Letters();

	static short  Count_Small_Letters(string S1);

	short  Count_Small_Letters();

	static short  Count_Specific_Letter(string S1, char Letter, bool MatchCase = true);

	short  Count_Specific_Letter(char Letter, bool MatchCase = true);

	static bool Is_Vowel(char Ch1);

	static short  Count_Vowels(string S1);

	short  Count_Vowels();

	static vector<string> Split(string S1, string Delim);

	vector<string> Split(string Delim);

	static string Trim_Left(string S1);

	void Trim_Left();

	static string Trim_Right(string S1);

	void Trim_Right();

	static string Trim(string S1);

	void Trim();

	static string Join_String(vector<string> vString, string Delim);

	static string Join_String(string arrString[], short Length, string Delim);

	static string Reverse_Words_In_String(string S1);

	void Reverse_Words_In_String();

	static string Replace_Word(string S1, string StringToReplace, string sRepalceTo, bool MatchCase = true);

	string Replace_Word(string StringToReplace, string sRepalceTo);

	static string Remove_Punctuations(string S1);

	void Remove_Punctuations();
};
