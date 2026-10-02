#include "clsTransferLogScreen.h"

void clsTransferLogScreen::Print_Transfer_Log_Record_Line(clsBankClient::st_Trnsfer_Log_Record TransferLogRecord)
{
    cout << setw(8) << left << "" << setw(23) << left << TransferLogRecord.DateTime;
    cout << setw(10) << left << TransferLogRecord.SourceAccountNumber;
    cout << setw(10) << left << TransferLogRecord.DestinationAccountNumber;
    cout << setw(12) << left << TransferLogRecord.Amount;
    cout << setw(12) << left << TransferLogRecord.srcBalanceAfter;
    cout << setw(12) << left << TransferLogRecord.destBalanceAfter;
    cout << setw(15) << left << TransferLogRecord.UserName;
}

void clsTransferLogScreen::ShowTransferLogScreen()
{
    vector<clsBankClient::st_Trnsfer_Log_Record> vTransferLogRecord = clsBankClient::Get_Transfers_Log_List();

    string Title = "\t Transfer Log List Screen";
    string SubTitle = "\t    (" + to_string(vTransferLogRecord.size()) + ") Record(s).";

    _Draw_Screen_Header(Title, SubTitle);

    cout << setw(8) << left << "" << setw(23) << left << "Date/Time";
    cout << setw(10) << left << "s.Acc";
    cout << setw(10) << left << "d.Acc";
    cout << setw(12) << left << "Amount";
    cout << setw(12) << left << "s.Balance";
    cout << setw(12) << left << "d.Balance";
    cout << setw(15) << left << "User";
    cout << endl;

    cout << setw(8) << left << "" << setw(23) << left << string(23, '-');
    cout << setw(10) << left << string(10, '-');
    cout << setw(10) << left << string(10, '-');
    cout << setw(12) << left << string(12, '-');
    cout << setw(12) << left << string(12, '-');
    cout << setw(12) << left << string(12, '-');
    cout << setw(15) << left << string(15, '-');
    cout << endl;

    if (vTransferLogRecord.size() == 0)
    {
        cout << setw(37) << left << "" << "No Transfers Available In the System!";
    }
    else
    {
        for (clsBankClient::st_Trnsfer_Log_Record Record : vTransferLogRecord)
        {

            Print_Transfer_Log_Record_Line(Record);
            cout << endl;
        }
    }

}

