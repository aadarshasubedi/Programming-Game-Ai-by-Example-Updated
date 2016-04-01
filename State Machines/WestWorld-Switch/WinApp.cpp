#include "WinApp.h"

WinApp::WinApp()
{}

void WinApp::setScreen(WestWorldSwitch::WindowScreen^ windowScreen)
{
	this->windowScreen = windowScreen;
}

void WinApp::addMensageToList(std::string text)
{
	windowScreen->addText(gcnew String(text.c_str()));
}

void WinApp::ajustHeightList()
{
	windowScreen->ajustHeighList();
}

WinApp^ WinApp::getInstance()
{
	if (instance == nullptr)
	{
		instance = gcnew WinApp;
	}
	return instance;
}
