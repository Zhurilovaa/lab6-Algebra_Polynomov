#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

#include "TListPoly.h"
#include <iostream>
#include <string>

using namespace std;

//КЛАСС ПОЛИНОМ
class Polynomial
{
private:
	TPList Polynom;
	string Pstr;
public:
	Polynomial() {}
	Polynomial(string& s)
	{
		StrToP(s);
	}
	Polynomial(const Polynomial& Ppol)
	{
		Polynom = Ppol.Polynom;
		Pstr = Ppol.Pstr;
	}
	~Polynomial();
	void DeleteMistake(string& s);
	int CreateInX(string& s, int& var, int& opSymbN);
	int CreateInY(string& s, int& var, int& opSymbN);
	int CreateInZ(string& s, int& var, int& opSymbN);
	void StrToP(string& s);
	void ChangeStr();
	string GetStrPol() { return Pstr; }

	Polynomial& operator=(const Polynomial& polyOut);
	bool operator==(const Polynomial& polyOut) const;
	bool operator!=(const Polynomial& polyOut) const;
	Polynomial operator+(Polynomial& Ppoly);
	Polynomial operator-(Polynomial& Ppoly);
	Polynomial& operator*(const double& val);
	Polynomial operator*(Polynomial& Ppoly);
	double Calculate(const double& x, const double& y, const double& z);
	void CastSimilar();
	friend ostream& operator<<(ostream& out, const Polynomial& Pol)
	{
		TPList pol = Pol.Polynom;
		int size = pol.GetSizeL();
		TMonom mtemp = pol.GetMonPos(size - 1);
		out << mtemp;
		for (int i = size - 2; i > -1; i--)
		{
			mtemp = pol.GetMonPos(i);
			if (mtemp.GetCoeff() > 0)
			{
				out << '+';
			}
			double c = 0;
			if (mtemp.GetCoeff() != c)
			{
				out << mtemp;
			}
		}
		return out;
	}
};


#endif // !_POLYNOMIAL_H_
