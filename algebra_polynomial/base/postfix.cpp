#include "postfix.h"
#include "stack.h"

bool TPostfix::ProvWrongSymb()              //проверка на недопустимые символы
{
	string can_use = "()+_*1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.";
	size_t size= infix.size();
	for (size_t i = 0; i < size; i++)
	{
		if (can_use.find(infix[i]) == string::npos) //символ в infix не нашелся среди допустимых
		{
			throw "Wrong symbol in infix!";
		}
	}
	return true;
}
bool TPostfix::ProvCountVarOp()            //проверка соответсвия количества переменных и операций
{
	string infTemp = " " + infix + " ";
	string oper = "+-*";
	string namevar = "1234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	size_t size = infTemp.length();
	for (size_t i = 0; i < size; i++)
	{
		if ((oper.find(infTemp[i])!=string::npos))//символ операция
		{
			if ((namevar.find(infTemp[i - 1]) != string::npos) && (namevar.find(infTemp[i + 1]) != string::npos))
			{
				continue; //var oper var
			}
			else if ((infTemp[i - 1] == ')') && (infTemp[i + 1] == '('))
			{
				continue; // ) oper (
			}
			else if ((namevar.find(infTemp[i - 1]) != string::npos) && (infTemp[i + 1] == '('))
			{
				continue; // var oper (
			}
			else if ((infTemp[i - 1] == ')') &&(namevar.find(infTemp[i + 1]) != string::npos))
			{
				continue; // ) oper var
			}
			else
			{
				throw "Mistake with operations and var!";
			}
		}
	}
	return true;
}
bool TPostfix::ProvCountSk()               //проверка скобок
{
	string Inftemp = infix;
	if ((Inftemp.find('(') == string::npos) && (Inftemp.find(')') == string::npos))
	{
		return true;
	}
	else {
		if ((Inftemp.find("()")) >= 0 && (Inftemp.find("()") <= Inftemp.length()))
		{
			throw "Find is ''()'' (empty skob)";
		}
		while ((Inftemp.find('(') != std::string::npos) || (Inftemp.find(')') != std::string::npos))
		{
			if (Inftemp.find('(') >= 0 && Inftemp.find('(') <= Inftemp.length())
			{
				if (Inftemp.find(')') == std::string::npos)
				{
					throw "Incorrect number of brackets";
				}
				else
				{
					Inftemp[Inftemp.find('(')] = ' ';
					Inftemp[Inftemp.find(')')] = ' ';
				}
			}
			else
			{
				throw "Incorrect number of brackets";				
			}
		}
		return true;
	}
}
bool TPostfix::ProvInfix()                //общая проверка инфиксной формы
{
	ProvWrongSymb();
	ProvCountVarOp();
	ProvCountSk();
	string wrong0 = ")*-+";
	string wrongS = "(*-+";
	int size = infix.size();
	if (wrong0.find(infix[0]) != string::npos)    //инфикс начинается с символа(операции)
	{
		throw "First symbol is operations";
	}
	if (wrongS.find(infix[size - 1]) != string::npos)
	{
		throw "Last symbol is operations";
	}
	return true;
}
void TPostfix::AddVarMas()                //выделение переменных и добавление в массив
{
	string Itemp = infix;
	size_t size = 0;
	ProvInfix();  //проверка на недопустимые символы, на правильность выражения и на правильность скобок и другое
	Itemp = Itemp + "=";
	string op = "+-*=";
	for (int i = 0; i < Itemp.size(); i++)
	{
		if (op.find(Itemp[i]) != string::npos)
		{
			size++;
		}
	}
	var = new string[size];
	for (int i = 0; i < size; i++)
	{
		var[i] = "";
	}
	sizevar = size;
	int k = 0;
	for (int i = 0; i < Itemp.size(); i++)
	{
		if (op.find(Itemp[i]) != string::npos)
		{
			Itemp[i] = ' ';
		}
	}
	while ((Itemp.find('(') != string::npos) || (Itemp.find(')') != string::npos))
	{
		if (Itemp.find('(') != string::npos)
		{
			Itemp.erase(Itemp.find('('), 1);
		}
		if (Itemp.find(')') != string::npos)
		{
			Itemp.erase(Itemp.find(')'), 1);
		}
	}
	while (Itemp.size() != 0)
	{
		if (Itemp.find(' ') != string::npos)
		{
			size_t pos = Itemp.find(' ');
			for (int j = 0; j < pos; j++)
			{
				var[k] = var[k] + Itemp[j];
			}
			Itemp.erase(0, pos + 1);
			k++;
		}
	}
}
void TPostfix::DeleteSpaces(string& s)   //удаление пробелов
{
	for (size_t i = 0; i < s.size(); i++)
	{
		while (s[i] == ' ')
		{
			s.erase(i, 1);
		}
	}
}
TPostfix::TPostfix(string inf)   //Конструктор
{
	DeleteSpaces(inf);
	infix = inf;
	ProvInfix();
	AddVarMas();
}

void  TPostfix::ToPostfix()
{
	string itemp = infix;
	postfix = "";
	itemp = itemp + "=";
	TStack<char> opStack(MaxStackSize);
	int i = 0;
	while (itemp.size() != 0)
	{
		while (i < sizevar)
		{
			if (itemp.find(var[i]) == 0)
			{
				postfix = postfix + var[i] + ' ';
				itemp.erase(0, var[i].size());
				i++;
				break;
			}
			else break;
			i++;
		}
		if (itemp[0] == '(')
		{
			opStack.push('(');
			itemp.erase(0, 1);
		}
		if ((itemp[0] == operat.func[2]) || (itemp[0] == operat.func[3]) || (itemp[0] == operat.func[4]))
		{
			while (true)
			{
				if (opStack.empty() == true)
				{
					opStack.push(itemp[0]);
					break;
				}
				int iIn = 2;
				int iSt = 2;
				while (iIn < 5)
				{
					if (itemp[0] == operat.func[iIn])
						break;
					else
						iIn++;
				}
				while (iSt < 5)
				{
					if (opStack.getvaltop() == operat.func[iSt])
						break;
					else
						iSt++;
				}
				if (operat.priority[iIn] <= operat.priority[iSt])
				{
					postfix = postfix + opStack.pop() + ' ';
				}
				else
				{
					opStack.push(itemp[0]);
					break;
				}

			}
			itemp.erase(0, 1);
		}
		if (itemp[0] == ')')
		{
			while (opStack.getvaltop() != '(')
			{
				postfix = postfix + opStack.pop() + ' ';
			}
			opStack.pop();
			itemp.erase(0, 1);
		}
		if (itemp[0] == '=')
		{
			while (opStack.empty() != true)
			{
				postfix = postfix + opStack.pop() + ' ';
			}
			itemp.erase(0, 1);
		}
	}
}
double TPostfix::EnterValueandCalculate() //Ввод значений всех переменных (для double)
{
	cout << "Enter the arguments:" << endl;
	double* varV = new double[sizevar];
	for (int i = 0; i < sizevar; i++)
	{

		string ce = "0123456789.";
		int j = 0;
		while (j < var[i].length())
		{
			if (ce.find(var[i][j]) != std::string::npos)
				j++;
			else
				break;
		}
		if (j == var[i].length())
		{
			std::stringstream temp(var[i]);
			temp >> varV[i];
		}
		else
		{
			size_t k = 0;
			while (k < i && i != 0)
				if (var[i] == var[k])
				{
					varV[i] = varV[k];
					break;
				}
				else
					k++;
			if (k == i || i == 0)
			{
				cout << var[i] << " = ";
				cin >> varV[i];
				string vT = std::to_string(varV[i]);
				string c = "0123456789.";
				if (c.find(vT) != std::string::npos)
					throw "Permission incorrect value";
				cout << endl;
			}
			else
				continue;
		}
	}
	string post = postfix;
	for (int i = 0; i < post.size(); i++)
	{
		if (post[i] == ' ')
		{
			post.erase(i, 1);
		}
	}
	double tempResult = 0;
	double result = 0;
	int z = 0;
	TStack<double> varStack(sizevar);
	while (post.length() != 0)
	{
		while (z < sizevar)
		{
			if (post.find(var[z]) == 0)
			{
				varStack.push(varV[z]);
				post.erase(0, var[z].length());
				z++;
				break;
			}
			else
				break;
		}
		if (post[0] == '*')
		{
			double temp = varStack.pop();
			tempResult = varStack.pop() * temp;
			varStack.push(tempResult);
			post.erase(0, 1);
		}
		if (post[0] == '+')
		{
			double temp = varStack.pop();
			tempResult = varStack.pop() + temp;
			varStack.push(tempResult);
			post.erase(0, 1);
		}

		if (post[0] == '-')
		{
			double temp = varStack.pop();
			tempResult = varStack.pop() - temp;
			varStack.push(tempResult);
			post.erase(0, 1);
		}
	}
	result = varStack.pop();
	res = result;
	return res;
}
Polynomial TPostfix::CalculatePolynomH(THashTable<Polynomial> TableOfPolynom) 
{
	THashTable<Polynomial> varP = TableOfPolynom;
	for (int i = 0; i < sizevar; i++)
	{

		string ce = "0123456789.";
		int j = 0;
		while (j < var[i].length())
		{
			if (ce.find(var[i][j]) != std::string::npos)
				j++;
			else
				break;
		}
		if (j == var[i].length())
		{
			Polynomial p;
			varP.GetPolinominal(var[i]) = p;
		}
		else
		{
			size_t k = 0;
			while (k < i && i != 0)
				if (var[i] == var[k])
				{
					varP.GetPolinominal(var[i]) = varP.GetPolinominal(var[k]);
					break;
				}
				else
					k++;
			if (k == i || i == 0)
			{
				Polynomial _p;
				varP.GetPolinominal(var[i]) = _p;
			}
			else
				continue;
		}
	}
	string post = postfix;
	for (int i = 0; i < post.size(); i++)
	{
		if (post[i] == ' ')
		{
			post.erase(i, 1);
		}
	}
	Polynomial tempResult;
	Polynomial result;
	TStack<Polynomial> varStack(sizevar);
	int i = 0;
	while (post.length() != 0)
	{
		while (i < sizevar)
		{
			if (post.find(var[i]) == 0)
			{
				varStack.push(varP.GetPolinominal(var[i]));
				post.erase(0, var[i].length());
				i++;
				break;
			}
			else
				break;
		}

		if (post[0] == '*')
		{
			Polynomial temp = varStack.pop();
			tempResult = varStack.pop() * temp;
			varStack.push(tempResult);
			post.erase(0, 1);
		}

		if (post[0] == '+')
		{
			Polynomial temp = varStack.pop();
			tempResult = varStack.pop() + temp;
			varStack.push(tempResult);
			post.erase(0, 1);
		}

		if (post[0] == '-')
		{
			Polynomial temp = varStack.pop();
			tempResult = varStack.pop() - temp;
			varStack.push(tempResult);
			post.erase(0, 1);
		}
	}
	result = varStack.pop();
	return result;
}
Polynomial TPostfix::CalculatePolynomL(TLMTable<Polynomial> TableOfPolynom)  //Ввод значений всех переменных (для полиномов) Линейная таблица
{
	TLMTable<Polynomial> varP = TableOfPolynom;
	for (int i = 0; i < sizevar; i++)
	{

		string ce = "0123456789.";
		int j = 0;
		while (j < var[i].length())
		{
			if (ce.find(var[i][j]) != std::string::npos)
				j++;
			else
				break;
		}
		if (j == var[i].length())
		{
			Polynomial p;
			varP.get_value(var[i]) = p;
		}
		else
		{
			size_t k = 0;
			while (k < i && i != 0)
				if (var[i] == var[k])
				{
					varP.get_value(var[i]) = varP.get_value(var[k]);
					break;
				}
				else
					k++;
			if (k == i || i == 0)
			{
				Polynomial _p;
				varP.get_value(var[i]) = _p;
			}
			else
				continue;
		}
	}
	string post = postfix;
	for (int i = 0; i < post.size(); i++)
	{
		if (post[i] == ' ')
		{
			post.erase(i, 1);
		}
	}
	Polynomial tempResult;
	Polynomial result;
	TStack<Polynomial> varStack(sizevar);
	int i = 0;
	while (post.length() != 0)
	{
		while (i < sizevar)
		{
			if (post.find(var[i]) == 0)
			{
				varStack.push(varP.get_value(var[i]));
				post.erase(0, var[i].length());
				i++;
				break;
			}
			else
				break;
		}

		if (post[0] == '*')
		{
			Polynomial temp = varStack.pop();
			tempResult = varStack.pop() * temp;
			varStack.push(tempResult);
			post.erase(0, 1);
		}

		if (post[0] == '+')
		{
			Polynomial temp = varStack.pop();
			tempResult = varStack.pop() + temp;
			varStack.push(tempResult);
			post.erase(0, 1);
		}

		if (post[0] == '-')
		{
			Polynomial temp = varStack.pop();
			tempResult = varStack.pop() - temp;
			varStack.push(tempResult);
			post.erase(0, 1);
		}
	}
	result = varStack.pop();
	return result;
}
Polynomial TPostfix::CalculatePolynomO(TOrderedTable<Polynomial> TableOfPolynom)  //Ввод значений всех переменных (для полиномов) Упорядоченная таблица
{
	TOrderedTable<Polynomial> varP = TableOfPolynom;
	for (int i = 0; i < sizevar; i++)
	{

		string ce = "0123456789.";
		int j = 0;
		while (j < var[i].length())
		{
			if (ce.find(var[i][j]) != std::string::npos)
				j++;
			else
				break;
		}
		if (j == var[i].length())
		{
			Polynomial p;
			varP.GetValue(var[i]) = p;
		}
		else
		{
			size_t k = 0;
			while (k < i && i != 0)
				if (var[i] == var[k])
				{
					varP.GetValue(var[i]) = varP.GetValue(var[k]);
					break;
				}
				else
					k++;
			if (k == i || i == 0)
			{
				Polynomial _p;
				varP.GetValue(var[i]) = _p;
			}
			else
				continue;
		}
	}
	string post = postfix;
	for (int i = 0; i < post.size(); i++)
	{
		if (post[i] == ' ')
		{
			post.erase(i, 1);
		}
	}
	Polynomial tempResult;
	Polynomial result;
	TStack<Polynomial> varStack(sizevar);
	int i = 0;
	while (post.length() != 0)
	{
		while (i < sizevar)
		{
			if (post.find(var[i]) == 0)
			{
				varStack.push(varP.GetValue(var[i]));
				post.erase(0, var[i].length());
				i++;
				break;
			}
			else
				break;
		}

		if (post[0] == '*')
		{
			Polynomial temp = varStack.pop();
			tempResult = varStack.pop() * temp;
			varStack.push(tempResult);
			post.erase(0, 1);
		}

		if (post[0] == '+')
		{
			Polynomial temp = varStack.pop();
			tempResult = varStack.pop() + temp;
			varStack.push(tempResult);
			post.erase(0, 1);
		}

		if (post[0] == '-')
		{
			Polynomial temp = varStack.pop();
			tempResult = varStack.pop() - temp;
			varStack.push(tempResult);
			post.erase(0, 1);
		}
	}
	result = varStack.pop();
	return result;
}
