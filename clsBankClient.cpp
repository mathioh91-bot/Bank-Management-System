#include "clsBankClient.h"
string clsBankClient::_Convert_Client_Object_To_Line(clsBankClient Client, string Seperator )
{
	string stClientRecord = "";
	stClientRecord += Client.FirstName + Seperator;
	stClientRecord += Client.LastName + Seperator;
	stClientRecord += Client.Email + Seperator;
	stClientRecord += Client.Phone + Seperator;
	stClientRecord += Client.Account_Number + Seperator;
	stClientRecord += Client.Pin_Code + Seperator;
	stClientRecord += to_string(Client.Account_Balance);

	return stClientRecord;
}

 vector<clsBankClient> clsBankClient::_Load_Clients_Data_From_File() {
	fstream My_File;
	vector<clsBankClient> v;
	My_File.open("Clients.txt", ios::in);
	if (My_File.is_open()) {
		string line;
		while (getline(My_File, line)) {
			clsBankClient client = _Convert_Line_to_Client_Object(line);
			v.push_back(client);
		}
		My_File.close();
	}
	return v;
}

void clsBankClient::_Save_Cleints_Data_To_File(vector <clsBankClient> vClients)
{
	fstream My_File;
	My_File.open("Clients.txt", ios::out);
	if (My_File.is_open())
	{
		string Data_Line;
		for (clsBankClient C : vClients)
		{
			if (!C._Mark_For_Delete) {
				Data_Line = _Convert_Client_Object_To_Line(C);
				My_File << Data_Line << endl;
			}
		}

		My_File.close();
	}
}

void clsBankClient::_Update()
{
	vector <clsBankClient> _vClients;
	_vClients = _Load_Clients_Data_From_File();

	for (clsBankClient& C : _vClients)
	{
		if (C._Account_Number == _Account_Number)
		{
			C = *this;
			break;
		}
	}

	_Save_Cleints_Data_To_File(_vClients);
}

void clsBankClient::_Add_Data_Line_To_File(string  stDataLine) {
	fstream My_file;
	My_file.open("Clients.txt", ios::out | ios::app);
	if (My_file.is_open()) {
		My_file << stDataLine << "\n";
		My_file.close();
	}
}

void clsBankClient::_Add_New() {
	_Add_Data_Line_To_File(_Convert_Client_Object_To_Line(*this));
}

 clsBankClient clsBankClient::_Convert_Line_to_Client_Object(string line, string dele) {
	vector<string> vClientData;
	vClientData = clsString::Split(line, dele);

	return clsBankClient(en_Mode::Update_Mode, vClientData[0], vClientData[1], vClientData[2],
		vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
}

 clsBankClient clsBankClient::_Get_Empty_Client_Object()
{
	return clsBankClient(en_Mode::Empty_Mode, "", "", "", "", "", "", 0);
}

 clsBankClient::clsBankClient(en_Mode Mode, string First_Name, string Last_Name, string Email, string Phone, string Account_Number, string Pin_Code, double Account_Balance) :clsPerson(First_Name, Last_Name, Email, Phone) {
	 _Mode = Mode;
	 _Account_Number = Account_Number;
	 _Pin_Code = Pin_Code;
	 _Account_Balance = Account_Balance;
  }

 bool clsBankClient::Is_Empty()
 {
	 return (_Mode == en_Mode::Empty_Mode);
 }

 void clsBankClient::Set_Account_Balance(double Account_Balance) {
	_Account_Balance = Account_Balance;
 }

 double clsBankClient::Get_Account_Balance() {
	return _Account_Balance;
 }


 void clsBankClient::Set_Pin_Code(string Pin_Code)
 {
	 _Pin_Code = Pin_Code;
 }

 string clsBankClient::Get_Pin_Code()
 {
	 return _Pin_Code;
 }


 void clsBankClient::Set_Account_Number(string Account_Number) {
	 _Account_Number = Account_Number;
 }

 string clsBankClient::Get_Account_Number() {
	 return _Account_Number;
 }


  clsBankClient clsBankClient::Find_client(string Account_Number, string Pin_code, bool pin) {
	 fstream My_File;
	 vector<clsBankClient> v;
	 My_File.open("Clients.txt", ios::in); //read Mode
	 if (My_File.is_open()) {
		 string line;

		 while (getline(My_File, line)) {
			 clsBankClient Client = _Convert_Line_to_Client_Object(line);
			 if (Client.Account_Number == Account_Number && (!pin || Client.Pin_Code == Pin_code)) {
				 My_File.close();
				 return Client;
			 }
		 }

		 My_File.close();
	 }
	 return _Get_Empty_Client_Object();
 }

  clsBankClient clsBankClient::Find(string Account_Number) {
	 return	Find_client(Account_Number, "", 0);
 }

  clsBankClient clsBankClient::Find(string Account_Number, string pin) {
	 return Find_client(Account_Number, pin, 1);
 }

  bool clsBankClient::Is_Client_Exist(string Account_Num) {
	 clsBankClient client = clsBankClient::Find(Account_Num);
	 return (!client.Is_Empty());
 }



  clsBankClient::en_Save_Results clsBankClient::save() {
	 switch (_Mode) {
	 case en_Mode::Empty_Mode:
	 {
		 return en_Save_Results::svFaildEmptyObject;
	 }
	 case en_Mode::Add_New:
	 {
		 //This will add new record to file or database
		 if (clsBankClient::Is_Client_Exist(_Account_Number))
		 {
			 return en_Save_Results::svFaildAccountNumberExists;
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
	 case en_Mode::Update_Mode:
	 {
		 _Update();

		 return en_Save_Results::svSucceeded;

		 break;
	 }
	 }
 }

 bool  clsBankClient::Delete()
 {
	 vector <clsBankClient> _vClients;
	 _vClients = _Load_Clients_Data_From_File();

	 for (clsBankClient& C : _vClients)
	 {
		 if (C.Account_Number == _Account_Number)
		 {
			 C._Mark_For_Delete = true;
			 break;
		 }
	 }

	 _Save_Cleints_Data_To_File(_vClients);

	 *this = _Get_Empty_Client_Object();

	 return true;
 }

 	vector<clsBankClient>  clsBankClient::Get_Clients_List() {
	 return _Load_Clients_Data_From_File();
 }

  clsBankClient  clsBankClient::Get_Add_New_Client_Object(string account_number) {
	 return clsBankClient(Add_New, "", "", "", "", account_number, "", 0);
 }

  float  clsBankClient::Get_Total_Balances()
 {
	 vector <clsBankClient> vClients = clsBankClient::Get_Clients_List();

	 double TotalBalances = 0;

	 for (clsBankClient Client : vClients)
	 {
		 TotalBalances += Client.Account_Balance;
	 }

	 return TotalBalances;
 }

 void  clsBankClient::Deposit(double Amount)
 {
	 _Account_Balance += Amount;
	 save();
 }


 string  clsBankClient::_Prepare_Transfer_Log_Record(float Amount, clsBankClient DestinationClient, string UserName, string Seperator)
 {
	 string TransferLogRecord = "";
	 TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
	 TransferLogRecord += Account_Number + Seperator;
	 TransferLogRecord += DestinationClient.Account_Number + Seperator;
	 TransferLogRecord += to_string(Amount) + Seperator;
	 TransferLogRecord += to_string(Account_Balance) + Seperator;
	 TransferLogRecord += to_string(DestinationClient.Account_Balance) + Seperator;
	 TransferLogRecord += UserName; 
	 return TransferLogRecord;
 }



 bool  clsBankClient::Withdraw(double Amount)
 {
	 if (Amount > _Account_Balance)
	 {
		 return false;
	 }
	 _Account_Balance -= Amount;
	 save();
	 return true;
 }

 void clsBankClient::_Register_Transfer_Log(float Amount, clsBankClient DestinationClient, string UserName)
 {

	 string stDataLine = _Prepare_Transfer_Log_Record(Amount, DestinationClient, UserName);

	 fstream MyFile;
	 MyFile.open("Transfer.txt", ios::out | ios::app);

	 if (MyFile.is_open())
	 {

		 MyFile << stDataLine << endl;

		 MyFile.close();
	 }

 }
 bool clsBankClient::Transfer(double Amount, clsBankClient& DestinationClient,string User_name)
 {
	 if (Amount > Account_Balance)
	 {
		 return false;
	 }
	 
	 Withdraw(Amount);
	 DestinationClient.Deposit(Amount);
	 _Register_Transfer_Log(Amount, DestinationClient, User_name);
	 return true;
 }


 clsBankClient::st_Trnsfer_Log_Record clsBankClient::_Convert_Transfer_Log_Line_To_Record(string Line, string Seperator )
 {
	 clsBankClient::st_Trnsfer_Log_Record TrnsferLogRecord;

	 vector <string> vTrnsferLogRecordLine = clsString::Split(Line, Seperator);
	 TrnsferLogRecord.DateTime = vTrnsferLogRecordLine[0];
	 TrnsferLogRecord.SourceAccountNumber = vTrnsferLogRecordLine[1];
	 TrnsferLogRecord.DestinationAccountNumber = vTrnsferLogRecordLine[2];
	 TrnsferLogRecord.Amount = stod(vTrnsferLogRecordLine[3]);
	 TrnsferLogRecord.srcBalanceAfter = stod(vTrnsferLogRecordLine[4]);
	 TrnsferLogRecord.destBalanceAfter = stod(vTrnsferLogRecordLine[5]);
	 TrnsferLogRecord.UserName = vTrnsferLogRecordLine[6];

	 return TrnsferLogRecord;

 }


   vector <clsBankClient::st_Trnsfer_Log_Record> clsBankClient::Get_Transfers_Log_List()
 {
	 vector <clsBankClient::st_Trnsfer_Log_Record> vTransferLogRecord;

	 fstream MyFile;
	 MyFile.open("Transfer.txt", ios::in);//read Mode

	 if (MyFile.is_open())
	 {

		 string Line;

		 clsBankClient::st_Trnsfer_Log_Record TransferRecord;

		 while (getline(MyFile, Line))
		 {

			 TransferRecord = _Convert_Transfer_Log_Line_To_Record(Line);

			 vTransferLogRecord.push_back(TransferRecord);

		 }

		 MyFile.close();

	 }

	 return vTransferLogRecord;

 }

