#include "MyForm.h"
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute] 
//^^ автоматическая очистка памяти

int main(array <String^>^ args) {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	KyrsachWin::MyForm form;
	Application::Run(% form);
}