
#include "Main.h"


/*Пространства имен для работы с формой*/
using namespace System;
using namespace System::Windows::Forms;

/* Функция входа main() */
[STAThreadAttribute]
void main(array<String^>^ args) {

	Application::EnableVisualStyles(); // Задаем параметры отрисовки приложения
	Application::SetCompatibleTextRenderingDefault(false); // Задаем параметры отрисовки приложения

	matrix::Main form;  // Указываем пространство имен проекта для работы с формой и указываем название формы которая будет запускаться первой
	Application::Run(% form);  // Запускаем главную форму

}


