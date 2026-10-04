#pragma once
#include<iostream>
#include <vector>
#include <fstream>
#include"clsPerson.h"
#include"clsDate.h"
#include"clsString.h"
#include "clsUtil.h"
class clsUser :public clsPerson
{
private:
	enum en_Mode {
		Empty_Mode = 0, Update_Mode = 1, Add_New = 2
	};

	
	string _Prepare_Log_In_Record(string Seperator = "#//#");

	string _User_Name;
	string _Password;
	int _Permissions;
	bool _Mark_For_Delete = false;
	en_Mode _Mode;
	bool _Marked_For_Delete = false;

	static clsUser _Convert_Line_to_User_Object(string line, string dele = "#//#");

	string _Convert_User_Object_To_Line(clsUser user, string Seperator = "#//#");

	static vector<clsUser> _Load_User_Data_From_File();

	void _Save_User_Data_To_File(vector <clsUser> vClients);

	void _Update();

	void _Add_Data_Line_To_File(string  stDataLine);

	void _Add_New();

public:

	struct st_Login_Register_Record
	{
		string DateTime;
		string UserName;
		string Password;
		int Permissions;
	};

	enum en_Permissions {
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64, pRegister = 128
	};

	static st_Login_Register_Record _Convert_Login_Register_Line_To_Record(string Line, string Seperator = "#//#");


	clsUser(en_Mode mode, string first_name, string last_name, string email, string phone, string user_name, string password, int permissions);

	static clsUser _Get_Empty_User_Object();

	bool  Is_Empty();

	string Get_User_Name();

	void Set_User_Name(string UserName);

	__declspec(property(get = Get_User_Name, put = Set_User_Name)) string UserName;

	void Set_Password(string Password);

	string Get_Password();

	__declspec(property(get = Get_Password, put = Set_Password)) string Password;

	void Set_Permissions(int Permissions);

	int Get_Permissions();

	__declspec(property(get = Get_Permissions, put = Set_Permissions)) int Permissions;

	static clsUser Find_User(string user_name, string password, bool pin);

	static clsUser Find(string user_name);

	static clsUser Find(string user_name, string password);

	static bool Is_User_Exist(string user_name);

	enum en_Save_Results { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

	en_Save_Results Save();

	bool Delete();

	static clsUser Get_Add_New_User_Object(string UserName);

	static vector <clsUser> Get_Users_List();

	bool Check_Access_Permission(en_Permissions permissions);

	void Register_LogIn();

	static  vector <st_Login_Register_Record> Get_Login_Register_List();
};
