
#include "Main.h"


/*������������ ���� ��� ������ � ������*/
using namespace System;
using namespace System::Windows::Forms;

/* ������� ����� main() */
[STAThreadAttribute]
void main(array<String^>^ args) {

	Application::EnableVisualStyles(); // ������ ��������� ��������� ����������
	Application::SetCompatibleTextRenderingDefault(false); // ������ ��������� ��������� ����������

	matrix::Main form;  // ��������� ������������ ���� ������� ��� ������ � ������ � ��������� �������� ����� ������� ����� ����������� ������
	Application::Run(% form);  // ��������� ������� �����

}


