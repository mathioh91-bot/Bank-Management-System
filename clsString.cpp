#include "clsString.h"

clsString::clsString()
{
	_Value = "";
}

clsString::clsString(string Value)
{
	_Value = Value;
}

void clsString::Set_Value(string Value) {
	_Value = Value;
}

string clsString::Get_Value() {
	return _Value;
}


 short clsString::Length(string S1)
{
	return S1.length();
};

short clsString::Length()
{
	return _Value.length();
};

 short clsString::Count_Words(string S1)
{
	string delim = " "; // delimiter
	short Counter = 0;
	short pos = 0;
	string sWord; // define a string variable

	// use find() function to get the position of the delimiters
	while ((pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
		if (sWord != "")
		{
			Counter++;
		}

		//erase() until positon and move to next word.
		S1.erase(0, pos + delim.length());
	}

	if (S1 != "")
	{
		Counter++; // it counts the last word of the string.
	}

	return Counter;
}

short clsString::Count_Words()
{
	return Count_Words(_Value);
};

 string  clsString::Upper_First_Letter_Of_Each_Word(string S1)
{
	bool isFirstLetter = true;

	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && isFirstLetter)
		{
			S1[i] = toupper(S1[i]);
		}

		isFirstLetter = (S1[i] == ' ' ? true : false);
	}

	return S1;
}

void  clsString::Upper_First_Letter_Of_Each_Word()
{
	// no need to return value , this function will directly update the object value
	_Value = Upper_First_Letter_Of_Each_Word(_Value);
}

 string  clsString::Lower_First_Letter_Of_Each_Word(string S1)
{
	bool isFirstLetter = true;

	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ' && isFirstLetter)
		{
			S1[i] = tolower(S1[i]);
		}

		isFirstLetter = (S1[i] == ' ' ? true : false);
	}

	return S1;
}

void  clsString::Lower_First_Letter_Of_Each_Word()
{
	// no need to return value , this function will directly update the object value
	_Value = Lower_First_Letter_Of_Each_Word(_Value);
}

 string  clsString::Upper_All_String(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = toupper(S1[i]);
	}
	return S1;
}

void  clsString::Upper_All_String()
{
	_Value = Upper_All_String(_Value);
}

 string  clsString::Lower_All_String(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = tolower(S1[i]);
	}
	return S1;
}

void  clsString::Lower_All_String()
{
	_Value = Lower_All_String(_Value);
}

 char  clsString::Invert_Letter_Case(char char1)
{
	return isupper(char1) ? tolower(char1) : toupper(char1);
}

 string  clsString::Invert_All_Letters_Case(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		S1[i] = Invert_Letter_Case(S1[i]);
	}
	return S1;
}

void  clsString::Invert_All_Letters_Case()
{
	_Value = Invert_All_Letters_Case(_Value);
}

 short clsString::Count_Letters(string S1, en_What_To_Count WhatToCount )
{
	if (WhatToCount == en_What_To_Count::All)
	{
		return S1.length();
	}

	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (WhatToCount == en_What_To_Count::Capital_Letters && isupper(S1[i]))
			Counter++;

		if (WhatToCount == en_What_To_Count::Small_Letters && islower(S1[i]))
			Counter++;
	}

	return Counter;
}

 short  clsString::Count_Capital_Letters(string S1)
{
	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (isupper(S1[i]))
			Counter++;
	}

	return Counter;
}

short  clsString::Count_Capital_Letters()
{
	return Count_Capital_Letters(_Value);
}

 short clsString::Count_Small_Letters(string S1)
{
	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (islower(S1[i]))
			Counter++;
	}

	return Counter;
}

short  clsString::Count_Small_Letters()
{
	return Count_Small_Letters(_Value);
}

short  clsString::Count_Specific_Letter(string S1, char Letter, bool MatchCase )
{
	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (MatchCase)
		{
			if (S1[i] == Letter)
				Counter++;
		}
		else
		{
			if (tolower(S1[i]) == tolower(Letter))
				Counter++;
		}
	}

	return Counter;
}

short  clsString::Count_Specific_Letter(char Letter, bool MatchCase )
{
	return Count_Specific_Letter(_Value, Letter, MatchCase);
}

 bool clsString::Is_Vowel(char Ch1)
{
	Ch1 = tolower(Ch1);

	return ((Ch1 == 'a') || (Ch1 == 'e') || (Ch1 == 'i') || (Ch1 == 'o') || (Ch1 == 'u'));
}

 short  clsString::Count_Vowels(string S1)
{
	short Counter = 0;

	for (short i = 0; i < S1.length(); i++)
	{
		if (Is_Vowel(S1[i]))
			Counter++;
	}

	return Counter;
}

short  clsString::Count_Vowels()
{
	return Count_Vowels(_Value);
}

 vector<string> clsString::Split(string S1, string Delim)
{
	vector<string> vString;

	short pos = 0;
	string sWord; // define a string variable

	// use find() function to get the position of the delimiters
	while ((pos = S1.find(Delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos); // store the word
		/* if (sWord != "")
		 {*/
		vString.push_back(sWord);
		//}

		S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
	}

	if (S1 != "")
	{
		vString.push_back(S1); // it adds last word of the string.
	}

	return vString;
}

vector<string> clsString::Split(string Delim)
{
	return Split(_Value, Delim);
}

 string clsString::Trim_Left(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(i, S1.length() - i);
		}
	}
	return "";
}

void clsString::Trim_Left()
{
	_Value = Trim_Left(_Value);
}

 string clsString::Trim_Right(string S1)
{
	for (short i = S1.length() - 1; i >= 0; i--)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(0, i + 1);
		}
	}
	return "";
}

void clsString::Trim_Right()
{
	_Value = Trim_Right(_Value);
}

 string clsString::Trim(string S1)
{
	return (Trim_Left(Trim_Right(S1)));
}

void clsString::Trim()
{
	_Value = Trim(_Value);
}

 string clsString::Join_String(vector<string> vString, string Delim)
{
	string S1 = "";

	for (string& s : vString)
	{
		S1 = S1 + s + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());
}

 string clsString::Join_String(string arrString[], short Length, string Delim)
{
	string S1 = "";

	for (short i = 0; i < Length; i++)
	{
		S1 = S1 + arrString[i] + Delim;
	}

	return S1.substr(0, S1.length() - Delim.length());
}

 string clsString::Reverse_Words_In_String(string S1)
{
	vector<string> vString;
	string S2 = "";

	vString = Split(S1, " ");

	// declare iterator
	vector<string>::iterator iter = vString.end();

	while (iter != vString.begin())
	{
		--iter;

		S2 += *iter + " ";
	}

	S2 = S2.substr(0, S2.length() - 1); //remove last space.

	return S2;
}

void clsString::Reverse_Words_In_String()
{
	_Value = Reverse_Words_In_String(_Value);
}

 string clsString::Replace_Word(string S1, string StringToReplace, string sRepalceTo, bool MatchCase)
{
	vector<string> vString = Split(S1, " ");

	for (string& s : vString)
	{
		if (MatchCase)
		{
			if (s == StringToReplace)
			{
				s = sRepalceTo;
			}
		}
		else
		{
			if (Lower_All_String(s) == Lower_All_String(StringToReplace))
			{
				s = sRepalceTo;
			}
		}
	}

	return Join_String(vString, " ");
}

string clsString::Replace_Word(string StringToReplace, string sRepalceTo)
{
	return Replace_Word(_Value, StringToReplace, sRepalceTo);
}

 string clsString::Remove_Punctuations(string S1)
{
	string S2 = "";

	for (short i = 0; i < S1.length(); i++)
	{
		if (!ispunct(S1[i]))
		{
			S2 += S1[i];
		}
	}

	return S2;
}

void clsString::Remove_Punctuations()
{
	_Value = Remove_Punctuations(_Value);
}