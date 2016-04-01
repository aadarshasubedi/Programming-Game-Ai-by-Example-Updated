#include "WindowScreen.h"
#include "WinApp.h"
#include "WestWorld.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;


void runWestWorld()
{
	WestWorld westWorld;
	westWorld.init();

	while (true)
	{
		westWorld.update();
		System::Threading::Thread::Sleep(1000);
	}
}

void ajustHeightList()
{	
	while (true)
	{
		WinApp::getInstance()->ajustHeightList();
		System::Threading::Thread::Sleep(50);
	}
}

[STAThread]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	WestWorldSwitch::WindowScreen windowScreen;

	WinApp^ winApp = WinApp::getInstance();
	winApp->setScreen(%windowScreen);


	Thread^ stateMachineThread = gcnew Thread(gcnew ThreadStart(runWestWorld));
	stateMachineThread->Start();

	Thread^ ajustHeightSthread = gcnew Thread(gcnew ThreadStart(ajustHeightList));
	ajustHeightSthread->Start();

	Application::Run(%windowScreen);
}


