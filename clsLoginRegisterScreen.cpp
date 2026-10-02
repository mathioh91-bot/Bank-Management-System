#include "clsLoginRegisterScreen.h"

 void clsLoginRegisterScreen::Print_Login_Register_Record_Line(clsUser::st_Login_Register_Record LoginRegisterRecord)
{

    cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.DateTime;
    cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
    cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
    cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;
}

 void clsLoginRegisterScreen::Show_Login_Register_Screen()
{
     if (!Check_Access_Rights(clsUser::en_Permissions::pRegister))
     {
         return;// this will exit the function and it will not continue
     }

    vector <clsUser::st_Login_Register_Record> vLoginRegisterRecord = clsUser::Get_Login_Register_List();

    string Title = "\tLogin Register List Screen";
    string SubTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

    _Draw_Screen_Header(Title, SubTitle);

    cout << setw(8) << left << "" << "\n\t_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
    cout << "| " << left << setw(20) << "UserName";
    cout << "| " << left << setw(20) << "Password";
    cout << "| " << left << setw(10) << "Permissions";
    cout << setw(8) << left << "" << "\n\t_______________________________________________________";
    cout << "_________________________________________\n" << endl;

    if (vLoginRegisterRecord.size() == 0)
        cout << "\t\t\t\tNo Logins Available In the System!";
    else

        for (clsUser::st_Login_Register_Record Record : vLoginRegisterRecord)
        {

            Print_Login_Register_Record_Line(Record);
            cout << endl;
        }

    cout << setw(8) << left << "" << "\n\t_______________________________________________________";
    cout << "_________________________________________\n" << endl;

}