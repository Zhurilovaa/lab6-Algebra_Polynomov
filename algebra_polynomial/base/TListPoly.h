#ifndef _TLISTPOLY_H_
#define _TLISTPOLY_H_

#include "TMonomial.h"
#include <iostream>

//КЛАСС ЗВЕНО-МОНОМ
class TPLink
{
public:
	TMonom m;
	TPLink* pNext;
	TPLink() :pNext(nullptr) {}
	~TPLink()
	{
		if (pNext != nullptr)
		{
			pNext = nullptr;
		}
	}
};

//КЛАСС СПИСОК МОНОМОВ
class TPList
{
private:
	TPLink* pFirst;
	int size_list;
public:
	TPList();
	TPList(const TPList& Plist);
	~TPList();
	TPLink* GetpFirst()
	{
		return pFirst;
	}
	void SetSizeL(const int& s)
	{
		size_list = s;
	}
	int GetSizeL()
	{
		return size_list;
	}

	void InsertLast(const TMonom& mon);
	void TakeFirst();
	TMonom GetMonPos(const int pos);
	TPLink* Find(const int& pos);
	TPLink* DeleteTheLink(TPLink* p);
	
	TPList& operator=(const TPList& Plist);
	bool operator==(const TPList& Plist) const;
	bool operator!=(const TPList& Plist) const;	

	void SortPList();

};
#endif // !_TLISTPOLY_H_
