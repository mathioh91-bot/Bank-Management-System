#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <cstdlib>
#include <ctime>
#include "clsDate.h"

using namespace std;

class Cls_Util
{
public:
	enum En_Char_Type {
		Samall_Letter = 1, Capital_Letter = 2,
		Digit = 3, Mix_Chars = 4, Special_Character = 5
	};

	static void  Srand();

	static  int Random_Number(int From, int To);

	static char Get_Random_Character(En_Char_Type CharType);

	static  string Generate_Word(En_Char_Type CharType, short Length);

	static string  Generate_Key(En_Char_Type CharType = Capital_Letter);

	static void Generate_Keys(short NumberOfKeys, En_Char_Type CharType);

	static void Fill_Array_With_Random_Numbers(int arr[100], int arrLength, int From, int To);

	static void Fill_Array_With_Random_Words(string arr[100], int arrLength, En_Char_Type CharType, short Wordlength);

	static void Fill_Array_With_Random_Keys(string arr[100], int arrLength, En_Char_Type CharType);

	static  void Swap(int& A, int& B);

	static  void Swap(double& A, double& B);

	static  void Swap(bool& A, bool& B);

	static  void Swap(char& A, char& B);

	static  void Swap(string& A, string& B);

	static  void Swap(clsDate& A, clsDate& B);

	static  void Shuffle_Array(int arr[100], int arrLength);

	static  void Shuffle_Array(string arr[100], int arrLength);

	static string  Tabs(short NumberOfTabs);

	static string  EncryptText(string Text, short EncryptionKey = 2);

	static string  DecryptText(string Text, short EncryptionKey = 2);

	static string Number_To_Text(double Number);

};
