#pragma once
#include "WindowScreen.h"
#include <iostream>
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public ref class Test
{
private:
	static Test^ instance;
	//Windows::Forms::ListBox^ lista;
	WestWorldSwitch::WindowScreen^ windowScreen;
public:
	Test()
	{
		this->windowScreen = windowScreen;
	}

	void setScreen(WestWorldSwitch::WindowScreen^ windowScreen)
	{
		this->windowScreen = windowScreen;
	}


	void printeee(std::string text)
	{
		windowScreen->addText(gcnew String(text.c_str()));
		//lista->Items->Add(gcnew String(text.c_str()));
	}

	void printe()
	{
		std::string text = "sdonosnfonafona";
		windowScreen->addText(gcnew String(text.c_str()));
		//lista->Items->Add(gcnew String(text.c_str()));
	}

	static Test^ getInstance()
	{
		if (instance == nullptr)
		{
			instance = gcnew Test();
		}
		return instance;
	}

};