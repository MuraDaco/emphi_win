// CLR_win_test.cpp : file di progetto principale.

#include "stdafx.h"
#include "Form1.h"
#include "TestFrm1.h"

using namespace CLR_win_test;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Attivare gli effetti visivi di Windows XP prima di creare i controlli
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	TestFrm1^ prova = gcnew TestFrm1();

	// Creare la finestra principale ed eseguirla
	Application::Run(gcnew Form1());
	return 0;
}
