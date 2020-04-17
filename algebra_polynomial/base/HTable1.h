#ifndef _HTABLE1_H_ 
#define _HTABLE1_H_
#include "Polynomial.h"

#define MaxSizeOfTableH 36

template <class T>
struct THashLine
{
	size_t numOfLine;
	std::string nameOfLine;
	T value;

	THashLine<T>* pNextLine;
	THashLine()
	{
		numOfLine = NULL;
	}
};
template <class T>
class THashTable
{
	THashLine<T> line[MaxSizeOfTableH];
	size_t countOfLine;

	size_t Hash(std::string _nameOfLine)
	{
		return ((int)(_nameOfLine[0]) - 48);
	}
public:
	THashTable()
	{
		countOfLine = NULL;
	}
	bool Is_Full()
	{
		return (countOfLine == MaxSizeOfTableH);
	}
	bool Is_Empty()
	{
		return (countOfLine == NULL);
	}
	bool Search_In_Table_By_Name(std::string _nameOfLine)
	{
		size_t hashKey = Hash(_nameOfLine);
		if (line[hashKey].numOfLine == 0) return false;
		if (line[hashKey].nameOfLine == _nameOfLine)
		{
			return true;
		}
		else
		{
			THashLine<T>* p = new THashLine<T>;
			p = line[hashKey].pNextLine;
			for (size_t i = 0; i < line[hashKey].numOfLine - 1; i++)
			{
				if (p->nameOfLine == _nameOfLine)
					return true;
				p = p->pNextLine;
			}
		}
		return false;
	}
	void InsertLine(std::string _nameOfLine, T /*TPolynominal */ _polinom)
	{
		if (Is_Full())
			throw "Is Full";
		size_t hashKey = Hash(_nameOfLine);
		if (line[hashKey].numOfLine == 0)
		{
			line[hashKey].nameOfLine = _nameOfLine;
			line[hashKey].value = _polinom;
		}
		else
		{
			line[hashKey].pNextLine = new THashLine<T>;
			THashLine<T>* p = new THashLine<T>;
			p = line[hashKey].pNextLine;
			for (size_t i = 0; i < line[hashKey].numOfLine - 1; i++)
			{
				p->pNextLine = new THashLine<T>;
				p = p->pNextLine;
			}
			p->nameOfLine = _nameOfLine;
			p->value = _polinom;
		}
		line[hashKey].numOfLine++;
		countOfLine++;

	}
	void DeleteLine(std::string _nameOfLine)
	{
		if (Is_Empty())
			throw "Is Empty";
		if (Search_In_Table_By_Name(_nameOfLine) == false)
			throw "Is Not Found";
		size_t count = 0;
		size_t hashKey = Hash(_nameOfLine);
		if (line[hashKey].numOfLine == 1)
		{
			T _polinom;
			line[hashKey].nameOfLine = "";
			line[hashKey].value = _polinom;

		}
		else
		{
			THashLine<T>* p = new THashLine<T>;
			p = line[hashKey].pNextLine;
			while (p->nameOfLine != _nameOfLine)
			{
				p = p->pNextLine;
				count++;
			}
			THashLine<T>* pl = new THashLine<T>;
			pl = line[hashKey].pNextLine;
			for (size_t i = 0; i < count - 2; i++)
			{
				pl = pl->pNextLine;
			}
			pl->pNextLine = p->pNextLine;
			delete p;
		}
		line[hashKey].numOfLine--;
		countOfLine--;
	}
	T  GetPolinominal(std::string _nameOfLine)
	{
		if (Is_Empty())
			throw "Is Empty";
		if (Search_In_Table_By_Name(_nameOfLine) == false)
			throw "Is Not Found";
		size_t hashKey = Hash(_nameOfLine);
		if (line[hashKey].nameOfLine == _nameOfLine)
		{
			return line[hashKey].value;
		}
		else
		{
			THashLine<T>* p = new THashLine<T>;
			p = line[hashKey].pNextLine;

			for (size_t i = 0; i < line[hashKey].numOfLine - 1; i++)
			{
				if (p->nameOfLine == _nameOfLine)
					return p->value;
				p = p->pNextLine;
			}
		}
	}
};
#endif