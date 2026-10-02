#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include <fstream>
#include "clsUser.h"
class clsLoginRegisterScreen :protected clsScreen
{

private:

    static void Print_Login_Register_Record_Line(clsUser::st_Login_Register_Record LoginRegisterRecord);

public:

    static void Show_Login_Register_Screen();

};
