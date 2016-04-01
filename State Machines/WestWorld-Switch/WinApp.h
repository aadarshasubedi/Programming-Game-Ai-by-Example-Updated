#pragma once
#include "WindowScreen.h"
#include <iostream>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Threading;


// This class is a singleton tha have the function to add the menssage to windows form
public ref class WinApp
{
private:
	static WinApp^ instance;
	WestWorldSwitch::WindowScreen^ windowScreen;

public:
	WinApp();

	void setScreen(WestWorldSwitch::WindowScreen^ windowScreen);

	void addMensageToList(std::string text);

	void ajustHeightList();

	static WinApp^ getInstance();

};