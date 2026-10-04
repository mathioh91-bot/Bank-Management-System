#include "clsUser.h"

clsUser::st_Login_Register_Record clsUser::_Convert_Login_Register_Line_To_Record(string Line, string Seperator)
{
	st_Login_Register_Record LoginRegisterRecord;

	vector <string> LoginRegisterDataLine = clsString::Split(Line, Seperator);
	LoginRegisterRecord.DateTime =LoginRegisterDataLine[0];
	LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
	LoginRegisterRecord.Password = LoginRegisterDataLine[2];
	LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);
	
	return LoginRegisterRecord;
}

clsUser clsUser::_Convert_Line_to_User_Object(string line, string dele) {
	vector<string> vClientData;
	vClientData = clsString::Split(line, dele);

	return clsUser(en_Mode::Update_Mode, vClientData[0], vClientData[1], vClientData[2],
		vClientData[3], vClientData[4], Cls_Util::DecryptText(vClientData[5]), stoi(vClientData[6]));
}

string clsUser::_Convert_User_Object_To_Line(clsUser user, string Seperator)
{
	string stClientRecord = "";
	stClientRecord += user.FirstName + Seperator;
	stClientRecord += user.LastName + Seperator;
	stClientRecord += user.Email + Seperator;
	stClientRecord += user.Phone + Seperator;
	stClientRecord += user._User_Name + Seperator;
	stClientRecord += Cls_Util::EncryptText(user._Password) + Seperator;
	stClientRecord += to_string(user._Permissions);
	return stClientRecord;
}

vector<clsUser> clsUser::_Load_User_Data_From_File() {
	fstream My_File;
	vector<clsUser> v;
	My_File.open("temp.txt", ios::in);
	if (My_File.is_open()) {
		string line;
		while (getline(My_File, line)) {
			clsUser user = _Convert_Line_to_User_Object(line);
			v.push_back(user);
		}
		My_File.close();
	}
	return v;
}

void clsUser::_Save_User_Data_To_File(vector <clsUser> vClients)
{
	fstream My_File;
	My_File.open("temp.txt", ios::out);
	if (My_File.is_open())
	{
		string Data_Line;
		for (clsUser C : vClients)
		{
			if (!C._Mark_For_Delete) {
				Data_Line = _Convert_User_Object_To_Line(C);
				My_File << Data_Line << endl;
			}
		}

		My_File.close();
	}
}

void clsUser::_Update()
{
	vector <clsUser> user;
	user = _Load_User_Data_From_File();

	for (clsUser& C : user)
	{
		if (C._User_Name == _User_Name)
		{
			C = *this;
			break;
		}
	}

	_Save_User_Data_To_File(user);
}

void clsUser::_Add_Data_Line_To_File(string  stDataLine) {
	fstream My_file;
	My_file.open("temp.txt", ios::out | ios::app);
	if (My_file.is_open()) {
		My_file << stDataLine << "\n";
		My_file.close();
	}
}

void clsUser::_Add_New() {
	_Add_Data_Line_To_File(_Convert_User_Object_To_Line(*this));
}

clsUser::clsUser(en_Mode mode, string first_name, string last_name, string email, string phone, string user_name, string password, int permissions) :clsPerson(first_name, last_name, email, phone) {
	_Mode = mode;
	_User_Name = user_name;
	_Password = password;
	_Permissions = permissions;
}

clsUser clsUser::_Get_Empty_User_Object()
{
	return clsUser(en_Mode::Empty_Mode, "", "", "", "", "", "", 0);
}

bool  clsUser::Is_Empty() {
	return (_Mode == en_Mode::Empty_Mode);
}

string clsUser::Get_User_Name()
{
	return _User_Name;
}

void clsUser::Set_User_Name(string UserName)
{
	_User_Name = UserName;
}

void clsUser::Set_Password(string Password)
{
	_Password = Password;
}

string clsUser::Get_Password()
{
	return _Password;
}

void clsUser::Set_Permissions(int Permissions)
{
	_Permissions = Permissions;
}

int clsUser::Get_Permissions()
{
	return _Permissions;
}

clsUser clsUser::Find_User(string user_name, string password, bool pin) {
	fstream My_File;
	//vector<clsUser> v;
	My_File.open("temp.txt", ios::in); //read Mode
	if (My_File.is_open()) {
		string line;

		while (getline(My_File, line)) {
			clsUser User = _Convert_Line_to_User_Object(line);
			if (User._User_Name == user_name && (!pin || User._Password == password)) {
				My_File.close();
				return User;
			}
		}

		My_File.close();
	}
	return _Get_Empty_User_Object();
}

clsUser clsUser::Find(string user_name) {
	return	Find_User(user_name, "", 0);
}

clsUser clsUser::Find(string user_name, string password) {
	return Find_User(user_name, password, 1);
}

bool clsUser::Is_User_Exist(string user_name) {
	clsUser client = clsUser::Find(user_name);
	return (!client.Is_Empty());
}

clsUser::en_Save_Results clsUser::Save()
{
	switch (_Mode)
	{
	case en_Mode::Empty_Mode:
	{
		if (Is_Empty())
		{
			return en_Save_Results::svFaildEmptyObject;
		}
	}

	case en_Mode::Update_Mode:
	{
		_Update();
		return en_Save_Results::svSucceeded;

		break;
	}

	case en_Mode::Add_New:
	{
		//This will add new record to file or database
		if (clsUser::Is_User_Exist(_User_Name))
		{
			return en_Save_Results::svFaildUserExists;
		}
		else
		{
			_Add_New();
			//We need to set the mode to update after add new
			_Mode = en_Mode::Update_Mode;
			return en_Save_Results::svSucceeded;
		}

		break;
	}
	}
}

bool clsUser::Delete()
{
	vector <clsUser> V;
	V = _Load_User_Data_From_File();

	for (clsUser& C : V)
	{
		if (C._User_Name == _User_Name)
		{
			C._Mark_For_Delete = true;
			break;
		}
	}

	_Save_User_Data_To_File(V);

	*this = _Get_Empty_User_Object();
	return true;
}

clsUser clsUser::Get_Add_New_User_Object(string UserName)
{
	return clsUser(en_Mode::Add_New, "", "", "", "", UserName, "", 0);
}

vector <clsUser> clsUser::Get_Users_List()
{
	return _Load_User_Data_From_File();
}

bool clsUser::Check_Access_Permission(en_Permissions permissions) {
	if (this->Permissions == en_Permissions::eAll) {
		return true;
	}
	if ((this->Permissions & permissions) == permissions) {
		return true;
	}
	else {
		return false;
	}
}

string clsUser::_Prepare_Log_In_Record(string Seperator)
{
	string LoginRecord = "";
	LoginRecord += clsDate::GetSystemDateTimeString() + Seperator;
	LoginRecord += UserName + Seperator;
	LoginRecord += Password + Seperator;
	LoginRecord += to_string(Permissions);
	return LoginRecord;
}

void clsUser::Register_LogIn()
{
	string stDataLine = _Prepare_Log_In_Record();

	fstream MyFile;
	MyFile.open("log.txt", ios::out | ios::app);

	if (MyFile.is_open())
	{
		MyFile << stDataLine << endl;

		MyFile.close();
	}
}

vector<clsUser::st_Login_Register_Record> clsUser::Get_Login_Register_List()
{
	vector <st_Login_Register_Record> vLoginRegisterRecord;

	fstream MyFile;
	MyFile.open("log.txt", ios::in);//read Mode

	if (MyFile.is_open())
	{
		string Line;

		st_Login_Register_Record LoginRegisterRecord;

		while (getline(MyFile, Line))
		{
			LoginRegisterRecord = _Convert_Login_Register_Line_To_Record(Line);

			vLoginRegisterRecord.push_back(LoginRegisterRecord);
		}

		MyFile.close();
	}

	return vLoginRegisterRecord;
}