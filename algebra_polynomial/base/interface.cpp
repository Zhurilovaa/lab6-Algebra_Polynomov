#include "interface.h"

void Interface::Menu(){
	cout << "�������� ������������ �������: " << endl;
	//������� ������ �������
	int tab;
	tab = Print_Table();
	switch (tab)
	{
	case 1:
	{
		//������� �������
	}
	case 2:
	{
		//������� �������
	}
	case 3:
	{
		//������� �������
	}
	case 4:
	{
		//������� �������
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
		//������� ���������� ��������
			Add_Pol(tab); break;
		case 2:
		//������� �������� ��������	
			Del_Pol(tab); break;
		case 3:
		//������� ������ ������ ���� ���������
			Print_All_Pol(tab); break;
		case 4:
		//������� ���������� ��������� �� ���������
			Calculation_Pol(tab); break;
		}
	} while (point != 5); //����� ��� ������� 5

}

int Interface::Print_Table()
{
	cout << "1.�������� �� �������\n2.������������� �� �������\n3.������\n4.���-������� �� ������\n"<<endl;
	int tab;
	cin >> tab;
	while ((tab < 1) || (tab > 4))
	{
		cout << "������� ��� ����� ������� �� ����������!!! ���������� ��� ���:" << endl;
		cin >> tab;
	}
	return tab;
}

void Interface::Print_Menu()
{
	cout << "\t\t ����\n";
	cout << "����� ������� �����, ������� ��������������� �����\n";
	cout << "1. �������� ����� �������\n";
	cout << "2. ������� ������������ �������\n";
	cout << "3. ������� ������ ���������\n";
	cout << "4. ��������� ���������\n";
	cout << "5. �����\n";
}

void Interface::Print_Operation()
{
	cout << "1. ��������� �������\n";
	cout << "2. ������� ������������ �������\n";
	cout << "3. �����\n";
}

char Interface::Exit()
{
	char a;
	cout << "�����? (Y/N)" << endl;
	cin >> a;
	return a;
}

void Interface::Add_Pol(int tab)
{
	switch (tab)
	{
	case 1:
	{
		//������� �������
	}
	case 2:
	{
		//������� �������
	}
	case 3:
	{
		//������� �������
	}
	case 4:
	{
		//������� �������
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
		//������� �������
	}
	case 2:
	{
		//������� �������
	}
	case 3:
	{
		//������� �������
	}
	case 4:
	{
		//������� �������
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
		//������� �������
	}
	case 2:
	{
		//������� �������
	}
	case 3:
	{
		//������� �������
	}
	case 4:
	{
		//������� �������
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
		//������� �������
	}
	case 2:
	{
		//������� �������
	}
	case 3:
	{
		//������� �������
	}
	case 4:
	{
		//������� �������
	}
	default:
		break;
	}
}
