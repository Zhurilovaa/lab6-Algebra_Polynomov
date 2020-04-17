#ifndef __POSTFIX_H__
#define __POSTFIX_H__

#include <string>
#include <iostream>
#include <sstream>
#include "stack.h"
#include "HTable1.h"
#include "LTableM.h"
#include "YTable.h"
#include "Polynomial.h"

#define MaxSizeString 100

using namespace std;

struct TablFunc     //������� ��������
{
	char func[6];
	int priority[6];
	int count;
	TablFunc()
	{
		func[0] = ')';	count = 2;
		func[1] = '(';	priority[1] = 0;
		func[2] = '+';	priority[2] = 1;
		func[3] = '-';	priority[3] = 1;
		func[4] = '*';	priority[4] = 2;
		func[5] = '=';	priority[5] = 0;
	}
}; 

class TPostfix
{
	string infix;      //��������� �����
	string postfix;    //����������� �����
	string* var;  //������ ���� ����������
	size_t sizevar;    //�������������� ������ ������� ����������
	TablFunc operat;   //������� � ����������
	double res;        //���������
	bool ProvWrongSymb();             //�������� �� ������������ �������
	bool ProvCountVarOp();            //�������� ����������� ���������� ���������� � ��������
	bool ProvCountSk();               //�������� ������
	bool ProvInfix();                 //����� �������� ��������� �����
	void AddVarMas();                 //��������� ���������� � ���������� � ������
	void DeleteSpaces(string& s);   //�������� ��������
public:
	//����������
	TPostfix(string inf);
	void ToPostfix();
	string GetInfix() { return infix; }
	string GetPostfix() { return postfix; }
	string GetArrVarPos(size_t pos) {
		if (pos >= 0 && pos < sizevar)
		{
			return var[pos];
		}
		else throw "Wrong pos of var!";
	}
	size_t GetCountOfVar() { return sizevar; }

	//���� �������� ���� ���������� (��� double)
	double TPostfix::EnterValueandCalculate(); 
	//���������� (��� ���������) ��� �������
	Polynomial TPostfix::CalculatePolynomH(THashTable<Polynomial> TableOfPolynom);
	//���� �������� ���� ���������� (��� ���������) �������� �������
	Polynomial TPostfix::CalculatePolynomL(TLMTable<Polynomial> TableOfPolynom);
	//���� �������� ���� ���������� (��� ���������) ������������� �������
	Polynomial TPostfix::CalculatePolynomO(TOrderedTable<Polynomial> TableOfPolynom);
};

#endif