#pragma once

#include <iostream>

using namespace std;
//подключение таблиц
//подключение необходимых классов, если нужно

class Interface {

public:
	Interface() {

	}
	void Menu();					//вызов меню
	int Print_Table();				//печатает выбор доступных таблиц
	void Print_Menu();				//печать меню на экран
	void Print_Operation();			//печать выбора операций 
	char Exit();					//подтвердить выход
	void Add_Pol(int tab);					//добавление полинома
	void Del_Pol(int tab);					//удаление полинома
	void Print_All_Pol(int tab);			//вывод всех полиномов
	void Calculation_Pol(int tab);			//вычисление полинома

};