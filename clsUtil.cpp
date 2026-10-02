#include "clsUtil.h"
 void  Cls_Util::Srand()
{
	//Seeds the random number generator in C++, called only once
	srand((unsigned)time(NULL));
}

  int  Cls_Util::Random_Number(int From, int To)
{
	//Function to generate a random number
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

 char Cls_Util::Get_Random_Character(Cls_Util::En_Char_Type CharType)
{
	//updated this method to accept mixchars
	if (CharType == Mix_Chars)
	{
		//Capital/Samll/Digits only
		CharType = (En_Char_Type)Random_Number(1, 3);
	}

	switch (CharType)
	{
	case En_Char_Type::Samall_Letter:
	{
		return char(Random_Number(97, 122));
		break;
	}
	case En_Char_Type::Capital_Letter:
	{
		return char(Random_Number(65, 90));
		break;
	}
	case En_Char_Type::Special_Character:
	{
		return char(Random_Number(33, 47));
		break;
	}
	case En_Char_Type::Digit:
	{
		return char(Random_Number(48, 57));
		break;
	}
	default:
	{
		return char(Random_Number(65, 90));
		break;
	}
	}
}

  string Cls_Util::Generate_Word(Cls_Util::En_Char_Type CharType, short Length)

{
	string Word;

	for (int i = 1; i <= Length; i++)

	{
		Word = Word + Get_Random_Character(CharType);
	}
	return Word;
}

 string Cls_Util::Generate_Key(Cls_Util::En_Char_Type CharType )
{
	string Key = "";

	Key = Generate_Word(CharType, 4) + "-";
	Key = Key + Generate_Word(CharType, 4) + "-";
	Key = Key + Generate_Word(CharType, 4) + "-";
	Key = Key + Generate_Word(CharType, 4);

	return Key;
}

 void Cls_Util::Generate_Keys(short NumberOfKeys, En_Char_Type CharType)
{
	for (int i = 1; i <= NumberOfKeys; i++)

	{
		cout << "Key [" << i << "] : ";
		cout << Generate_Key(CharType) << endl;
	}
}

 void Cls_Util::Fill_Array_With_Random_Numbers(int arr[100], int arrLength, int From, int To)
{
	for (int i = 0; i < arrLength; i++)
		arr[i] = Random_Number(From, To);
}
 void Cls_Util::Fill_Array_With_Random_Words(string arr[100], int arrLength, En_Char_Type CharType, short Wordlength)
{
	for (int i = 0; i < arrLength; i++)
		arr[i] = Generate_Word(CharType, Wordlength);
}

 void Cls_Util::Fill_Array_With_Random_Keys(string arr[100], int arrLength, En_Char_Type CharType)
{
	for (int i = 0; i < arrLength; i++)
		arr[i] = Generate_Key(CharType);
}

  void Cls_Util::Swap(int& A, int& B)
{
	int Temp;

	Temp = A;
	A = B;
	B = Temp;
}

  void Cls_Util::Swap(double& A, double& B)
{
	double Temp;

	Temp = A;
	A = B;
	B = Temp;
}

  void Cls_Util::Swap(bool& A, bool& B)
{
	bool Temp;

	Temp = A;
	A = B;
	B = Temp;
}

  void Cls_Util::Swap(char& A, char& B)
{
	char Temp;

	Temp = A;
	A = B;
	B = Temp;
}

  void Cls_Util::Swap(string& A, string& B)
{
	string Temp;

	Temp = A;
	A = B;
	B = Temp;
}

  void Cls_Util::Swap(clsDate& A, clsDate& B)
{
	clsDate::Swap_Dates(A, B);
}

  void Cls_Util::Shuffle_Array(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		Swap(arr[Random_Number(1, arrLength) - 1], arr[Random_Number(1, arrLength) - 1]);
	}
}

  void Cls_Util::Shuffle_Array(string arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		Swap(arr[Random_Number(1, arrLength) - 1], arr[Random_Number(1, arrLength) - 1]);
	}
}

 string  Cls_Util::Tabs(short NumberOfTabs)
{
	string t = "";

	for (int i = 1; i < NumberOfTabs; i++)
	{
		t = t + "\t";
		cout << t;
	}
	return t;
}

 string  Cls_Util::EncryptText(string Text, short EncryptionKey)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = char((int)Text[i] + EncryptionKey);
	}

	return Text;
}

 string  Cls_Util::DecryptText(string Text, short EncryptionKey)
{
	for (int i = 0; i < Text.length(); i++)
	{
		Text[i] = char((int)Text[i] - EncryptionKey);
	}
	return Text;
}

 string Cls_Util::Number_To_Text(double Number)
{
	if (Number == 0)
		return "Zero";

	vector<string> Ones = {
		"", "One", "Two", "Three", "Four",
		"Five", "Six", "Seven", "Eight", "Nine",
		"Ten", "Eleven", "Twelve", "Thirteen",
		"Fourteen", "Fifteen", "Sixteen", "Seventeen",
		"Eighteen", "Nineteen"
	};

	vector<string> Tens = {
		"", "", "Twenty", "Thirty", "Forty",
		"Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
	};

	std::function<string(long long)> NumberToText = [&](long long N) -> string
		{
			if (N < 20)
				return Ones[N];

			if (N < 100)
				return Tens[N / 10] + (N % 10 ? " " + Ones[N % 10] : "");

			if (N < 1000)
				return Ones[N / 100] + " Hundred" +
				(N % 100 ? " " + NumberToText(N % 100) : "");

			if (N < 1000000)
				return NumberToText(N / 1000) + " Thousand" +
				(N % 1000 ? " " + NumberToText(N % 1000) : "");

			if (N < 1000000000)
				return NumberToText(N / 1000000) + " Million" +
				(N % 1000000 ? " " + NumberToText(N % 1000000) : "");

			return NumberToText(N / 1000000000) + " Billion" +
				(N % 1000000000 ? " " + NumberToText(N % 1000000000) : "");
		};

	long long IntegerPart = (long long)Number;
	double FractionPart = Number - IntegerPart;

	string Result = NumberToText(IntegerPart);

	if (FractionPart > 0)
	{
		Result += " Point";

		string FractionText = to_string(FractionPart);

		for (int i = 2; i < FractionText.size(); i++)
		{
			if (FractionText[i] == '0')
				Result += " Zero";
			else
				Result += " " + Ones[FractionText[i] - '0'];
		}
	}

	return Result;
}