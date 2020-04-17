#include "interface.h"

void Interface::Menu(){
	cout << "Выберите используемую таблицу: " << endl;
	//функция выбора таблицы
	int tab;
	tab = Print_Table();
	switch (tab)
	{
	case 1:
	{
		//создать таблицу
	}
	case 2:
	{
		//создать таблицу
	}
	case 3:
	{
		//создать таблицу
	}
	case 4:
	{
		//создать таблицу
	}
	default:
		break;
	}
	int point = -1;
	do {
		Print_Menu();
		cin >> point;
		switch (point) {
		case 1:
		//функция добавления полинома
			Add_Pol(tab); break;
		case 2:
		//функция удаления полинома	
			Del_Pol(tab); break;
		case 3:
		//функция вывода списка всех полиномов
			Print_All_Pol(tab); break;
		case 4:
		//функция вычисления выражения из полиномов
			Calculation_Pol(tab); break;
		}
	} while (point != 5); //выход при нажатии 5

}

int Interface::Print_Table()
{
	cout << "1.Линейная на массиве\n2.Упорядоченная на массиве\n3.Дерево\n4.Хэш-таблица на списке\n"<<endl;
	int tab;
	cin >> tab;
	while ((tab < 1) || (tab > 4))
	{
		cout << "Таблицы под таким номером не существует!!! Попробуйте ещё раз:" << endl;
		cin >> tab;
	}
	return tab;
}

void Interface::Print_Menu()
{
	cout << "\t\t МЕНЮ\n";
	cout << "Чтобы выбрать пункт, введите соответствующую цифру\n";
	cout << "1. Добавить новый полином\n";
	cout << "2. Удалить существующий полином\n";
	cout << "3. Вывести список полиномов\n";
	cout << "4. Вычислить выражение\n";
	cout << "5. Выход\n";
}

void Interface::Print_Operation()
{
	cout << "1. Посчитать полином\n";
	cout << "2. Удалить существующий полином\n";
	cout << "3. Выход\n";
}

char Interface::Exit()
{
	char a;
	cout << "Выйти? (Y/N)" << endl;
	cin >> a;
	return a;
}

void Interface::Add_Pol(int tab)
{
	switch (tab)
	{
	case 1:
	{
		//создать таблицу
	}
	case 2:
	{
		//создать таблицу
	}
	case 3:
	{
		//создать таблицу
	}
	case 4:
	{
		//создать таблицу
	}
	default:
		break;
	}
}

void Interface::Del_Pol(int tab)
{
	switch (tab)
	{
	case 1:
	{
		//создать таблицу
	}
	case 2:
	{
		//создать таблицу
	}
	case 3:
	{
		//создать таблицу
	}
	case 4:
	{
		//создать таблицу
	}
	default:
		break;
	}
}

void Interface::Print_All_Pol(int tab)
{
	switch (tab)
	{
	case 1:
	{
		//создать таблицу
	}
	case 2:
	{
		//создать таблицу
	}
	case 3:
	{
		//создать таблицу
	}
	case 4:
	{
		//создать таблицу
	}
	default:
		break;
	}
}

void Interface::Calculation_Pol(int tab)
{
	switch (tab)
	{
	case 1:
	{
		//создать таблицу
	}
	case 2:
	{
		//создать таблицу
	}
	case 3:
	{
		//создать таблицу
	}
	case 4:
	{
		//создать таблицу
	}
	default:
		break;
	}
}
