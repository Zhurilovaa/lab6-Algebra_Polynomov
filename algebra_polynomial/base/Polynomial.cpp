#include "Polynomial.h"

void Polynomial::DeleteMistake(string& s)
{
	int i;
	i = s.find(" ");
	while (i != string::npos)
	{
		s.erase(i, 1);//удалили пробел
		i = s.find(" ");
	}
	i = s.find(".");
	while (i != string::npos)
	{
		s.replace(i, 1, ",");//заменяем точки на запятые (функция stod не видит '.', но видит ',')
		i = s.find(".");
	}
	for (int i = 0; i < s.size(); i++)
	{
		switch (s[i])
		{
		case 'X':
		{
			s.replace(i, 1, "x");
			break;
		}
		case 'Y':
		{
			s.replace(i, 1, "y");
			break;
		}
		case 'Z':
		{
			s.replace(i, 1, "z");
			break;
		}
		default:
			break;
		}
	}
	Pstr = s;
	if (s[0] != '-')
	{
		s.insert(0, "+");
	}
	int siz = s.size();
	s.insert(siz, "+");
}
int Polynomial::CreateInX(string& s, int& var, int& opSymbN)
{
	int inX = 0;
	if ((var < opSymbN))
	{
		int degSym = var + 1;
		if (degSym == opSymbN)
		{
			inX = 1;
		}
		switch (s[degSym])
		{
		case 'y':
		{
			var = degSym;
			inX = 1;
		}
		case 'z':
		{
			var = degSym;
			inX = 1;
		}
		case '^':
		{
			while ((degSym < opSymbN) && (s[degSym] != 'y') && (s[degSym] != 'z'))
			{
				degSym++;
			}
			string indexX = s.substr(var + 2, degSym - var - 2);
			inX = stoi(indexX);
			var = degSym;
		}
		default:
			break;
		}
		return inX;
	}
	return 0;
}
int Polynomial::CreateInY(string& s, int& var, int& opSymbN)
{
	int inY = 0;
	if ((var < opSymbN))
	{
		int degSym = var + 1;
		if (degSym == opSymbN)
		{
			inY = 1;
		}
		switch (s[degSym])
		{
		case 'x':
		{
			var = degSym;
			inY = 1;
		}
		case 'z':
		{
			var = degSym;
			inY = 1;
		}
		case '^':
		{
			while ((degSym < opSymbN) && (s[degSym] != 'x') && (s[degSym] != 'z'))
			{
				degSym++;
			}
			string indexY = s.substr(var + 2, degSym - var - 2);
			inY = stoi(indexY);
			var = degSym;
		}
		default:
			break;
		}
		return inY;
	}
	return 0;
}
int Polynomial::CreateInZ(string& s, int& var, int& opSymbN)
{
	int inZ = 0;
	if ((var < opSymbN))
	{
		int degSym = var + 1;
		if (degSym == opSymbN)
		{
			inZ = 1;
		}
		switch (s[degSym])
		{
		case 'x':
		{
			var = degSym;
			inZ = 1;
		}
		case 'y':
		{
			var = degSym;
			inZ = 1;
		}
		case '^':
		{
			while ((degSym < opSymbN) && (s[degSym] != 'x') && (s[degSym] != 'y'))
			{
				degSym++;
			}
			string indexX = s.substr(var + 2, degSym - var - 2);
			inZ = stoi(indexX);
			var = degSym;
		}
		default:
			break;
		}
		return inZ;
	}
	return 0;
}
void Polynomial::StrToP(string& s)
{
	string temps = s;
	if (temps.size() == 0)
	{
		TMonom mon(0, 0, 0, 0);
		Polynom.InsertLast(mon);
	}
	else if (temps.size() != 0)
	{
		DeleteMistake(temps);
		while (temps.size() != 1)
		{
			int opSymb = -1;
			int opSymbN = -1;
			int var = -1;
			double coeff;
			int inX = 0, inY = 0, inZ = 0;
			for (int i = 0; i < temps.size(); i++)
			{
				if ((temps[i] == '+') || (temps[i] == '-'))
				{
					opSymb = i;
					break;
				}
			}
			for (int i = opSymb + 1; i < temps.size(); i++)
			{
				if ((temps[i] == '+') || (temps[i] == '-'))
				{
					opSymbN = i;
					break;
				}
			}
			for (int i = opSymb + 1; i < opSymbN; i++)
			{
				if ((temps[i] == 'x') || (temps[i] == 'y') || (temps[i] == 'z'))
				{
					var = i;
					break;
				}
			}
			if (var == (-1)) //моном без переменных (просто константа)
			{
				string coef = temps.substr(opSymb + 1, opSymbN - opSymb - 1);
				coeff = stod(coef);
				if (temps[opSymb] == '-')
				{
					coeff = coeff * (-1);
				}
			}
			else 
			{
				if ((var - opSymb) == 1)
				{
					coeff = 1;
				}
				else
				{
					string coef = temps.substr(opSymb + 1, var - opSymb - 1);
					coeff = stod(coef);
				}
			}
			if (var == (-1))
			{
				TMonom mon(coeff, 0, 0, 0);
				Polynom.InsertLast(mon);
				temps.erase(opSymb, opSymbN - opSymb);
				continue;
			}
			bool createBeg = false;
			bool createEnd = false;
			switch (temps[var])
			{
			case 'x':
			{
				if (createBeg == false)
				{
					inX = CreateInX(temps, var, opSymbN);
					createBeg = true;
					switch (temps[var])
					{
					case 'y':
					{
						if (createEnd == false)
						{
							inY = CreateInY(temps, var, opSymbN);
							createEnd = true;
							if (temps[var] == 'z')
							{
								inZ = CreateInZ(temps, var, opSymbN);
							}
						}
					}
					case 'z':
					{
						if (createEnd == false)
						{
							inZ = CreateInZ(temps, var, opSymbN);
							createEnd = true;
							if (temps[var] == 'y')
							{
								inY = CreateInY(temps, var, opSymbN);
							}
						}
					}
					default:
						break;
					}						
				}
				break;
			}
			case 'y':
			{
				if (createBeg == false)
				{
					inY = CreateInY(temps, var, opSymbN);
					createBeg = true;
					switch (temps[var])
					{
					case 'x':
					{
						if (createEnd == false)
						{
							inX = CreateInX(temps, var, opSymbN);
							createEnd = true;
							if (temps[var] == 'z')
							{
								inZ = CreateInZ(temps, var, opSymbN);
							}
						}
					}
					case 'z':
					{
						if (createEnd == false)
						{
							inZ = CreateInZ(temps, var, opSymbN);
							createEnd = true;
							if (temps[var] == 'x')
							{
								inX = CreateInX(temps, var, opSymbN);
							}
						}
					}
					default:
						break;
					}
				}
				break;
			}
			case'z':
			{
				if (createBeg == false)
				{
					inZ = CreateInZ(temps, var, opSymbN);
					createBeg = true;
					switch (temps[var])
					{
					case 'x':
					{
						if (createEnd == false)
						{
							inX = CreateInX(temps, var, opSymbN);
							createEnd = true;
							if (temps[var] == 'y')
							{
								inY = CreateInY(temps, var, opSymbN);
							}
						}
					}
					case 'y':
					{
						if (createEnd == false)
						{
							inY = CreateInY(temps, var, opSymbN);
							createEnd = true;
							if (temps[var] == 'x')
							{
								inX = CreateInX(temps, var, opSymbN);
							}
						}
					}
					default:
						break;
					}
				}
				break;
			}
			default:
				break;
			}
			if (temps[opSymb] == '-')
			{
				coeff = coeff * (-1);
			}
			TMonom mon(coeff, inX, inY, inZ);
			Polynom.InsertLast(mon);
			temps.erase(opSymb, opSymbN - opSymb);
		}
		Polynom.SortPList();
		CastSimilar();
		ChangeStr();
	}
}
Polynomial& Polynomial::operator=(const Polynomial& Ppoly)
{
	if (this != &Ppoly)
	{
		Polynom = Ppoly.Polynom;
		Pstr = Ppoly.Pstr;
	}
	return *this;
}
bool Polynomial::operator==(const Polynomial& Ppoly) const
{
	if (Polynom == Ppoly.Polynom)
	{
		return true;
	}
	else return false;
}
bool Polynomial::operator!=(const Polynomial& Ppoly) const
{
	if (Polynom != Ppoly.Polynom)
	{
		return true;
	}
	else return false;
}
Polynomial Polynomial::operator+(Polynomial& Ppoly)
{
	Polynomial PolyRes(Ppoly);
	TPLink* p1 = Polynom.GetpFirst();
	if (p1 != nullptr)
	{
		if ((p1->pNext == nullptr) && (p1->m.GetCoeff() == 0))//один из полиномов - это 0
		{
			PolyRes.Polynom = Polynom;
			PolyRes.Pstr = Pstr;
			return PolyRes;
		}
		if (*this == (Ppoly * (-1)))
		{
			string s = "";
			Polynomial P(s);
			PolyRes = P;
			return PolyRes;
		}
		TMonom temp;
		for (int i = 0; i < Polynom.GetSizeL(); i++)
		{
			temp = Polynom.GetMonPos(i);
			PolyRes.Polynom.InsertLast(temp);
		}
		PolyRes.Polynom.SortPList();
		PolyRes.CastSimilar();
		PolyRes.ChangeStr();
		return PolyRes;
	}
	else throw "Can't add empty list!";
}
Polynomial Polynomial::operator-(Polynomial& Ppoly)
{
	Polynomial PolyRes;
	PolyRes = *this + Ppoly*(-1);
	PolyRes.ChangeStr();
	return PolyRes;
}
Polynomial& Polynomial::operator*(const double& val)
{
	TPLink* p = Polynom.GetpFirst();
	if (val == 0)
	{
		string s = "";
		Polynomial Res(s);
		*this = Res;
		return *this;
	}
	if (p != nullptr)
	{
		p->m.MiltConst(val);

		while (p->pNext != nullptr)
		{
			p = p->pNext;
			p->m.MiltConst(val);
		}
	}
	Polynom.SortPList();
	ChangeStr();
	return *this;
}
Polynomial Polynomial::operator*(Polynomial& Ppoly)
{
	TPLink* p1 = Polynom.GetpFirst();
	Polynomial Res;
	TPLink* p2 = Ppoly.Polynom.GetpFirst();
	TMonom mtemp;
	TMonom m1;
	TMonom m2;
	if (p2 == nullptr)
	{
		throw "Can't mult empty polynoms!";
	}
	else
	{
		if (p1 == nullptr)
		{
			throw "Can't mult empty polynoms!";
		}
		else if (p1 != nullptr)
		{
			while (p1 != nullptr)
			{
				p2 = Ppoly.Polynom.GetpFirst();
				m1 = p1->m;
				m2 = p2->m;
				mtemp = m1 * m2;
				Res.Polynom.InsertLast(mtemp);
				while (p2->pNext != nullptr)
				{
					p2 = p2->pNext;
					m1 = p1->m;
					m2 = p2->m;
					mtemp = m1 * m2;
					Res.Polynom.InsertLast(mtemp);
				}
				p1 = p1->pNext;
			}
			Res.Polynom.SortPList();
			Res.CastSimilar();
			Res.ChangeStr();
			return Res;
		}
	}
}
double Polynomial::Calculate(const double& x, const double& y, const double& z)
{
	double res = 0;
	TMonom m;
	for (int i = 0; i < Polynom.GetSizeL(); i++)
	{
		m = Polynom.GetMonPos(i);
		res = res + m.CalcPoint(x, y, z);
	}
	return res;
}
Polynomial::~Polynomial()
{}
void Polynomial::ChangeStr()
{
	Pstr = "";
	int size = Polynom.GetSizeL();	
	TMonom m = Polynom.GetMonPos(size - 1);
	string coe = "";
	string inX = "";
	string inY = "";
	string inZ = "";
	double c = 0;
	int ind[3] = { 0,0,0 };
	for (int i = size - 1; i > -1; i--)
	{
		m = Polynom.GetMonPos(i);
		c = m.GetCoeff();
		if (c != 0)//моном не ноль
		{
			coe = std::to_string(c);
			while ((coe[coe.size() - 1] == '0')||(coe[coe.size() - 1] == '.'))
			{
				coe.erase(coe.size() - 1, 1);//убираем нули в конце
			}
			ind[0] = m.GetIndexX();
			ind[1] = m.GetIndexY();
			ind[2] = m.GetIndexZ();
			inX = std::to_string(ind[0]);
			inY = std::to_string(ind[1]);
			inZ = std::to_string(ind[2]);
			if (i != size - 1)
			{
				if (c > 0)
				{
					Pstr = Pstr + "+";
				}
			}
			Pstr = Pstr + coe;
			if (ind[0] != 0)
			{
				Pstr = Pstr + "x^" + inX;
			}
			if (ind[1] != 0)
			{
				Pstr = Pstr + "y^" + inY;
			}
			if (ind[2] != 0)
			{
				Pstr = Pstr + "z^" + inZ;
			}
		}
	}
}
void Polynomial::CastSimilar()
{
	Polynomial temp;
	bool FindSim = false;
	if (Polynom.GetSizeL() != 0)
	{
		TMonom m = Polynom.GetMonPos(0);
		temp.Polynom.InsertLast(m);
		for (int i = 1; i < Polynom.GetSizeL(); i++)
		{
			FindSim = false;
			TPLink* pt = temp.Polynom.GetpFirst();
			m = Polynom.GetMonPos(i);
			while (pt != nullptr)
			{
				if (pt->m.Similar(m) == true)
				{
					double c1 = pt->m.GetCoeff();
					double c2 = m.GetCoeff();
					pt->m.SetCoeff(c1 + c2);
					FindSim = true;
				}
				pt = pt->pNext;
			}
			if (FindSim == false)
			{
				temp.Polynom.InsertLast(m);
			}
		}
		*this = temp;
	}
}