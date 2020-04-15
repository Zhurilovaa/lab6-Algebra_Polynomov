#pragma once //линейная хэш-табл

#include <string>
#include "Polynomial.h"
#include <iostream>

using namespace std;

struct Data {
	string key;
	string SPolynom;
	Polynomial Polynom;
};

class HTableL {
	Data* Table[1000];
public:
	HTableL() {							//конструктор
		for (int i = 0; i < 1000; i++)
			Table[i] = nullptr;
	}
	~HTableL() {						//деструктор
		for (int i = 0; i < 1000; i++) {
			while (Table[i] != nullptr) {
				delete Table[i];
			}
		}
	}

	Data* Search(string& _key) {
		int search = Hashing(_key);
		if (Table[search] != nullptr) {
			if (Table[search]->key != _key) {
				for (int i = 0; i < 10; i++) {
					search = (7 + search) % 1000;
					if (Table[search] != nullptr)
						if (Table[search]->key == _key) return Table[search];
				}
				return nullptr;
			}
			else return Table[search];
		}
	}
	void Add(Data& _data) {
		if (Search(_data.key) != nullptr)
			throw "Такой ключ есть";
		int added = Hashing(_data.key);
		if (Table[added] != nullptr) {
			if (Table[added]->SPolynom == _data.SPolynom)
				throw "Такой ключ есть";
			for (int i = 0; i < 10; i++) {
				added = (7 + added) % 1000;
				if (Table[added] != nullptr) {
					if (Table[added]->SPolynom == _data.SPolynom)
						throw "Такой ключ есть";
				}
				else {
					Table[added] = new Data;
					Table[added]->key = _data.key;
					Table[added]->SPolynom = _data.SPolynom;
					Table[added]->Polynom = _data.Polynom;
					return;
				}
			}
			throw "нет места";
		}
		else {
			Table[added] = new Data;
			Table[added]->key = _data.key;
			Table[added]->SPolynom = _data.SPolynom;
			Table[added]->Polynom = _data.Polynom;
			return;
		}
	}
	void Delete(string& _key) {
		if (Search(_key) == nullptr)
			throw "Пусто!";
		Data* p = Search(_key);
		int deleting = Hashing(p->key);
		delete Table[deleting];
		Table[deleting] = nullptr;
	}
	void Print() {
		cout << "\t Линейная хэш-таблица" << endl;
		for (int i = 0; i < 1000; i++)
			if (Table[i] != nullptr)
				cout << Table[i]->key << "\t" << Table[i]->SPolynom << endl;
	}

	int Hashing(string _key) {//кодирование
		int tmp = 0;
		for (int i = 0; i < _key.size(); i++)
			tmp = tmp + (int)_key[i];
		tmp = (tmp * _key.size()) % 1000);
		return tmp;
	}
};

