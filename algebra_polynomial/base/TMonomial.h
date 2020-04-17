#ifndef __TMONOMIAL_H__
#define __TMONOMIAL_H__

#include <iostream>
using namespace std;

#define MinIndex 0
#define MaxIndex 99

//КЛАСС МОНОМ (СОСТАВЛЯЮЩАЯ ПОЛИНОМА)
class TMonom
{
protected:
	double coeff;      //коэффициент монома
	int index[3];      //массив степеней(свертка степней)
public:
	//Конструктор
	TMonom(double Mcoeff = 1, int Xindex = 0, int Yindex = 0, int Zindex = 0)
	{ 
		if ((Xindex >= MinIndex) && (Xindex <= MaxIndex) && (Yindex >= MinIndex) && (Yindex <= MaxIndex) && (Zindex >= MinIndex) && (Zindex <= MaxIndex))
		{
			coeff = Mcoeff;
			index[0] = Xindex;
			index[1] = Yindex;
			index[2] = Zindex;
		}
		else throw "Wrong Monom's Degree!";
	}
	//Конструктор копирования
	TMonom(const TMonom& Mon)
	{
		coeff = Mon.coeff;
		index[0] = Mon.index[0];
		index[1] = Mon.index[1];
		index[2] = Mon.index[2];
	} 
	//Деструктор
	~TMonom()
	{
		coeff = 0;
		index[0] = 0;
		index[1] = 0;
		index[2] = 0;
	}
	//Установить коэффициент
	void SetCoeff(double Mcoeff)                 
	{ 
		coeff = Mcoeff;
	}
	//Получить коэффициент
	double GetCoeff() 
	{ 
		return coeff;
	} 
	//Получить индекс X
	int GetIndexX() 
	{ 
		return index[0];
	} 
	//Получить индекс Y
	int GetIndexY()
	{
		return index[1];
	}
	//Получить индекс Z
	int GetIndexZ()
	{
		return index[2];
	}
	//Оператор присваивания
	TMonom& operator=(const TMonom &Mon) 
	{
		coeff = Mon.coeff;
		index[0] = Mon.index[0];
		index[1] = Mon.index[1];
		index[2] = Mon.index[2];
		return *this;
	} 
	//Оператор сравнения (равно)
	bool operator==(const TMonom &Mon) 
	{ 
		if ((coeff == Mon.coeff) && (index[0] == Mon.index[0]) && (index[1] == Mon.index[1]) && (index[2] == Mon.index[2]))
		{
			return true;
		}
		else return false;
	}
	//Оператор сравнения (меньше)
	bool operator<(const TMonom &Mon)
	{ 
		int ind = index[2] + index[1] * 100 + index[0] * 10000;
		int indM= Mon.index[2] + Mon.index[1] * 100 + Mon.index[0] * 10000;
		if (ind < indM)
		{
			return true;
		}
		else return false;
	} 
	//Оператор сравнения (больше)
	bool operator>(const TMonom& Mon)
	{
		if ((*this < Mon) || (*this == Mon))
		{
			return false;
		}
		else return true;
	}
	//Оператор сравнения (меньше или равно)
	bool operator<=(const TMonom& Mon)
	{
		if ((*this < Mon) || (*this == Mon))
		{
			return true;
		}
		else return false;
	}
	//Оператор сравнения (больше или равно)
	bool operator>=(const TMonom &Mon)
	{
		if ((*this > Mon) || (*this == Mon))
		{
			return true;
		}
		else return false;
	}
	//Подобные мономы
	bool Similar(const TMonom& Mon)
	{
		if ((index[0] == Mon.index[0]) && (index[1] == Mon.index[1]) && (index[2] == Mon.index[2]))
		{
			return true;
		}
		else return false;
	}
	//Сложение мономов
	TMonom operator+(const TMonom& Mon)
	{
		//До вызова этого оператора в коде должна быть проверка на подобие!!!!
		TMonom res(coeff, index[0], index[1], index[2]);
		res.coeff = res.coeff + Mon.coeff;
		return res;
	}
	//Умножение мономов
	TMonom operator*(const TMonom& Mon)
	{
		TMonom res(coeff, index[0], index[1], index[2]);
		res.coeff = res.coeff * Mon.coeff;
		res.index[0] = res.index[0] + Mon.index[0];
		res.index[1] = res.index[1] + Mon.index[1];
		res.index[2] = res.index[2] + Mon.index[2];
		return res;
	}
	//Умножение на константу
	void MiltConst(const double& val)
	{
		coeff = coeff * val;
	}
	//Вычисление в точке
	double CalcPoint(const double& x, const double& y, const double& z)
	{
		double res = 0;
		res = coeff * pow(x, index[0]) * pow(y, index[1]) * pow(z, index[2]);
		return res;
	}
	
	//Вывод монома (печать)
	friend ostream& operator<<(ostream& out, const TMonom& Mon)
	{
		out << Mon.coeff;
		if (Mon.index[0] != 0) { out << "x^" << Mon.index[0]; }
		if (Mon.index[1] != 0) { out << "y^" << Mon.index[1]; }
		if (Mon.index[2] != 0) { out << "z^" << Mon.index[2]; }		
		return out;
	}
	//Доступ полинома к методам своих составляющих
	friend class TPolinom;
};

#endif