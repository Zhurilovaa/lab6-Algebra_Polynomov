#pragma once

#include <iostream>

using namespace std;
//����������� ������
//����������� ����������� �������, ���� �����

class Interface {

public:
	Interface() {

	}
	void Menu();					//����� ����
	int Print_Table();				//�������� ����� ��������� ������
	void Print_Menu();				//������ ���� �� �����
	void Print_Operation();			//������ ������ �������� 
	char Exit();					//����������� �����
	void Add_Pol(int tab);					//���������� ��������
	void Del_Pol(int tab);					//�������� ��������
	void Print_All_Pol(int tab);			//����� ���� ���������
	void Calculation_Pol(int tab);			//���������� ��������

};