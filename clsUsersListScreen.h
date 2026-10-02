#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>

class clsListUsersScreen :protected clsScreen
{

private:
    static void _Print_User_Record_Line(clsUser User);
    

public:

    static void Show_Users_List();

};

