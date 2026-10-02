#pragma once
#include <iostream>
#include "clsScreen.h"
#include "Global.h"
#include "clsUser.h"
#include "clsMainScreen.h"
using namespace std;
class clsLoginScreen :protected clsScreen
{
private:
	static bool _Login();
public:
	static bool ShowLoginScreen();
};

