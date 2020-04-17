#include "TListPoly.h"

//Конструктор
TPList::TPList()
{
	pFirst = nullptr;
	size_list = 0;
}
//Конструктор копирования
TPList::TPList(const TPList& Plist)
{
	size_list = 0;
	pFirst = nullptr;
	if (Plist.pFirst != nullptr)
	{
		TPLink* p = Plist.pFirst;
		InsertLast(p->m);
		while (p->pNext != nullptr)
		{
			p = p->pNext;
			InsertLast(p->m);
		}
	}
}
//Деструктор
TPList::~TPList()
{
	if (pFirst != nullptr)
	{
		TPLink* p = pFirst;
		while (pFirst->pNext != nullptr)
		{
			p = pFirst;
			pFirst = pFirst->pNext;
			delete p;
			size_list = size_list - 1;
		}
		p = pFirst;
		delete p;
		size_list = size_list - 1;
	}
}
//Вставка в конц
void TPList::InsertLast(const TMonom& mon)
{
	if (pFirst == nullptr)
	{
		pFirst = new TPLink;
		pFirst->m = mon;
		size_list = size_list + 1;
	}
	else
	{
		TPLink* p = pFirst;
		while (p->pNext != nullptr)
		{
			p = p->pNext;
		}
		p->pNext = new TPLink;
		p->pNext->m = mon;
		size_list = size_list + 1;
	}
}
//Удаление с начала
void TPList::TakeFirst()
{
	if (pFirst!= nullptr)
	{
		TPLink* p = pFirst;
		if (pFirst->pNext != nullptr)
		{
			pFirst = pFirst->pNext;
		}
		else
		{
			pFirst = nullptr;
		}
		delete p;
		size_list = size_list - 1;
	}
	else 
	{
		throw  "Wrong with takefirst!";
	}
}
//Поиск элемента(звена)
TPLink* TPList::Find(const int& pos)
{
	if ((pos < 0) || (pos > (size_list - 1)))
	{
		throw "There is no link with this pos!";
	}
	int i = 0;
	TPLink* p = pFirst;
	if ((pos == 0) && (p != nullptr))
	{
		return p;
	}
	else if ((pos != 0) && (p != nullptr))
	{
		while ((p->pNext != nullptr) && (i != pos))
		{
			p = p->pNext;
			i++;
		}
	}
	return p;
}
//Получение данных(монома) по позиции
TMonom TPList::GetMonPos(const int pos)
{
	if ((pos < 0) || (pos > (size_list - 1)))
	{
		throw "There is no link with this pos!";
	}
	int i = 0;
	TPLink* p = pFirst;
	if (pos == 0)
	{		
		TMonom res = p->m;
		return res;
	}
	while ((p->pNext != nullptr) && (i != pos))
	{
		p = p->pNext;
		i++;
	}	
	TMonom res = p->m;
	return res;
}
//Оператор присваивания
TPList& TPList::operator=(const TPList& Plist) 
{
	if (this != &Plist)
	{		
		while (pFirst != nullptr)
		{
			TakeFirst();
		}		
		TPLink* p = Plist.pFirst;
		if (p != nullptr)
		{
			InsertLast(p->m);
			while (p->pNext != nullptr)
			{
				p = p->pNext;
				InsertLast(p->m);
			}
		}
	}
	return *this;
}
//Оператор сравнения (равно)
bool TPList::operator==(const TPList& Plist) const 
{
	if (size_list != Plist.size_list)
	{
		return false;
	}
	else
	{
		if ((pFirst != nullptr) && (Plist.pFirst != nullptr))
		{
			TPLink* p = pFirst;
			TPLink* pP = Plist.pFirst;
			if ((p->m == pP->m) == false)
			{
				return false;
			}
			while ((p->pNext != nullptr) && (pP->pNext != nullptr))
			{
				p = p->pNext;
				pP = pP->pNext;
				if ((p->m == pP->m) == false)
				{
					return false;
				}
			}
			return true;
		}
		return true;
	}
}
//Оператор сравнения (неравно)
bool TPList::operator!=(const TPList& Plist) const 
{
	if (*this == Plist)
	{
		return false;
	}
	else
	{
		return true;
	}
}
TPLink* TPList::DeleteTheLink(TPLink* p) 
{
	if (p == pFirst)
	{
		if (pFirst->pNext == nullptr)
		{
			delete p;
			size_list = size_list - 1;
			return nullptr;
		}
		else
		{
			pFirst = pFirst->pNext;
			delete p;
			size_list = size_list - 1;
			return pFirst;
		}
	}
	TPLink* pC = pFirst;
	while (pC->pNext != p)
	{
		pC = pC->pNext;
	}
	if (p->pNext == nullptr)
	{
		pC->pNext = nullptr;
		delete p;
		size_list = size_list - 1;
		return pC;
	}
	else 
	{
		pC->pNext = p->pNext;
		delete p;
		size_list = size_list - 1;
		return pC;
	}
}
//Сортировка списка мономов
void TPList::SortPList() 
{
	if (pFirst != nullptr)
	{
		if (pFirst->pNext != nullptr)
		{
			for (int i = 1; i < size_list; i++)
			{
				TPLink* pC = Find(i);
				int ibef = i - 1;
				while ((ibef > (-1)) && (pC->m < this->GetMonPos(ibef)))
				{
					TPLink* pN;
					TPLink* pB;
					TPLink* pBB;
					TPLink* pNow;
					if (ibef > 0)
					{
						pB = Find(ibef);
						pBB = Find(ibef - 1);
						pNow = pC;
						pBB->pNext = pNow;
						pN = pNow->pNext;
						pNow->pNext = pB;
						pB->pNext = pN;
						ibef--;
					}
					else if (ibef == 0)
					{
						pB = Find(ibef);
						pNow = pC;
						pN = pNow->pNext;
						pNow->pNext = pB;
						pB->pNext = pN;
						ibef--;
					}
				}
				if (pC->m < pFirst->m)
				{
					pFirst = pC;
				}
			}
		}
	}
}