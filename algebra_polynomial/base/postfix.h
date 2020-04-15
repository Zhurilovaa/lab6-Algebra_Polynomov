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

struct TablFunc     //таблица операций
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
	string infix;      //инфиксная форма
	string postfix;    //постфиксная форма
	string* var;  //массив имен переменных
	size_t sizevar;    //предполагаемый размер массива переменных
	TablFunc operat;   //таблица с операциями
	double res;        //результат
	bool ProvWrongSymb();             //проверка на недопустимые символы
	bool ProvCountVarOp();            //проверка соответсвия количества переменных и операций
	bool ProvCountSk();               //проверка скобок
	bool ProvInfix();                 //общая проверка инфиксной формы
	void AddVarMas();                 //выделение переменных и добавление в массив
	void DeleteSpaces(string& s);   //удаление пробелов
public:
	//Констуртор
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

	//Ввод значений всех переменных (для double)
	double TPostfix::EnterValueandCalculate(); 
	//Вычисление (для полиномов) Хэш таблица
	Polynomial TPostfix::CalculatePolynomH(THashTable<Polynomial> TableOfPolynom);
	//Ввод значений всех переменных (для полиномов) Линейная таблица
	Polynomial TPostfix::CalculatePolynomL(TLMTable<Polynomial> TableOfPolynom);
	//Ввод значений всех переменных (для полиномов) Упорядоченная таблица
	Polynomial TPostfix::CalculatePolynomO(TOrderedTable<Polynomial> TableOfPolynom);
};

#endif