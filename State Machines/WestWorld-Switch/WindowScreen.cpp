#include "WindowScreen.h"
#include "WestWorld.h"
#include "Test.h"


using namespace System;
using namespace System::Windows::Forms;
using namespace System::Threading;

void hum()
{

	for (int i = 0; i < 50; i++)
	{
		if (i == 50)
		{
			int a = 2;
		}
	}
}
[STAThread]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	WestWorldSwitch::WindowScreen windowScreen;

	Test^ oh = Test::getInstance();
	oh->setScreen(%windowScreen);
	oh->printeee("hidfhsadhh");

	WestWorld* westWorld = new WestWorld();
	westWorld->init();
	

	Thread^ workerthread = gcnew Thread(gcnew ThreadStart(hum));
	workerthread->Start();

	Application::Run(%windowScreen);
}


