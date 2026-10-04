#pragma once
#include<iostream>
#include <vector>
#include <fstream>
#include"clsPerson.h"
#include"clsString.h"
#include "clsDate.h"
class clsBankClient :public clsPerson
{
private:
	string _Account_Number;
	string _Pin_Code;
	double _Account_Balance;
	enum en_Mode {
		Empty_Mode = 0, Update_Mode = 1, Add_New = 2
	};
	bool _Mark_For_Delete = false;
	en_Mode _Mode;

	string _Convert_Client_Object_To_Line(clsBankClient Client, string Seperator = "#//#");

	static vector<clsBankClient> _Load_Clients_Data_From_File();

	void _Save_Cleints_Data_To_File(vector <clsBankClient> vClients);

	void _Update();

	void _Add_Data_Line_To_File(string  stDataLine);

	void _Add_New();

	static clsBankClient _Convert_Line_to_Client_Object(string line, string dele = "#//#");

	static clsBankClient _Get_Empty_Client_Object();

	string _Prepare_Transfer_Log_Record(double Amount, clsBankClient DestinationClient, string UserName, string Seperator = "#//#");


	void _Register_Transfer_Log(double Amount, clsBankClient DestinationClient, string UserName);
	struct st_Trnsfer_Log_Record;

	static st_Trnsfer_Log_Record _Convert_Transfer_Log_Line_To_Record(string Line, string Seperator = "#//#");

public:

	struct st_Trnsfer_Log_Record
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		float Amount;
		float srcBalanceAfter;
		float destBalanceAfter;
		string UserName;

	};

	clsBankClient(en_Mode Mode, string First_Name, string Last_Name, string Email, string Phone, string Account_Number, string Pin_Code, double Account_Balance);

	bool Is_Empty();
	
	void Set_Account_Balance(double Account_Balance);

	double Get_Account_Balance();

	__declspec(property(get = Get_Account_Balance, put = Set_Account_Balance)) double Account_Balance;

	void Set_Pin_Code(string Pin_Code);

	string Get_Pin_Code();

	__declspec(property(get = Get_Pin_Code, put = Set_Pin_Code)) string Pin_Code;

	void Set_Account_Number(string Account_Number);

	string Get_Account_Number();

	__declspec(property(get = Get_Account_Number, put = Set_Account_Number)) string Account_Number;

	static clsBankClient Find_client(string Account_Number, string Pin_code, bool pin);

	static clsBankClient Find(string Account_Number);

	static clsBankClient Find(string Account_Number, string pin);

	static bool Is_Client_Exist(string Account_Num);

	enum en_Save_Results {
		svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2
	};

	en_Save_Results save();

	bool Delete();

	static	vector<clsBankClient> Get_Clients_List();

	static clsBankClient Get_Add_New_Client_Object(string account_number);

	static double Get_Total_Balances();

	void Deposit(double Amount);

	bool Withdraw(double Amount);
	bool Transfer(double Amount, clsBankClient& DestinationClient,string user_name);

	static  vector <st_Trnsfer_Log_Record> Get_Transfers_Log_List();
};
 