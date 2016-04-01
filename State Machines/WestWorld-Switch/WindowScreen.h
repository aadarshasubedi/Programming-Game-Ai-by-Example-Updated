#pragma once


namespace WestWorldSwitch {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	
	/// <summary>
	/// Summary for WindowScreen
	/// </summary>
	public ref class WindowScreen : public System::Windows::Forms::Form
	{
	public:
		Thread^ demoThread;
		String^ lastMessage;
		System::Timers::Timer myTimer;
		delegate void AddTextDelegate(String^ text);
		delegate void AjustHeighListDelegate();
		WindowScreen(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~WindowScreen()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^  listBox1;
			 
	protected:
	
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(0, 1);
			this->listBox1->Name = L"listBox1";
			this->listBox1->ScrollAlwaysVisible = true;
			this->listBox1->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->listBox1->Size = System::Drawing::Size(404, 485);
			this->listBox1->TabIndex = 0;
			// 
			// WindowScreen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(596, 486);
			this->Controls->Add(this->listBox1);
			this->Name = L"WindowScreen";
			this->ShowIcon = false;
			this->Text = L"WestWorld-Switch";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &WindowScreen::WindowScreen_FormClosed);
			this->ResumeLayout(false);

		}

	public: 

		void addText(String^ text)
		{
			if (this->listBox1->InvokeRequired)
			{
				AddTextDelegate^ d =
					gcnew AddTextDelegate(this, &WindowScreen::addText);
				this->Invoke(d, gcnew array<Object^> { text });
			}
			else
			{ 
				this->listBox1->Items->Add(text);
				this->listBox1->TopIndex = this->listBox1->Items->Count - 1;
			}
		}

		void ajustHeighList()
		{
			if (this->listBox1->InvokeRequired)
			{
				AjustHeighListDelegate^ d =
					gcnew AjustHeighListDelegate(this, &WindowScreen::ajustHeighList);
				this->Invoke(d);
			}
			else
			{
				this->listBox1->Height = this->Height;
				this->listBox1->Width = this->Width * 0.7;
			}

		}
private: System::Void WindowScreen_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e) {
	Environment::Exit(Environment::ExitCode);
}
};
}
