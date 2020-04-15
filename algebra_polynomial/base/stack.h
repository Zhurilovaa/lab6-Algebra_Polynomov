#ifndef __STACK_H__
#define __STACK_H__
#include <iostream>
const int MaxStackSize = 100;

template <class T>
class TStack
{
private:
	T* pMem;
	int size;
	int top;
	TStack(const TStack& st) {}//������ �� �������� ����� �����
	TStack& operator=(const TStack& st) {}//������ �� ������������ 
public:
	//�����������
	TStack(int _size)
	{
		size = _size;
		top = -1;
		if ((size < 1) || (size > MaxStackSize))
		{
			throw "Error with Stack's size";
		}
		pMem = new T[size];
	}
	//�������� �� ������� �����
	bool empty()
	{
		if (top == (-1))//���� ����
			return true;
		else
			return false;
	}
	//�������� �� ������� �����
	bool full()
	{
		if (top == (size - 1))//���� ��������
			return true;
		else
			return false;
	}
	//����� ������� �� �����
	T pop()
	{
		if (empty() == true)//�������� �� ������� �����
		{
			throw "Error witn POP";
		}
		return pMem[top--];//������� pMem[top] � top--
	}
	//�������� ������� � �����
	void push(T Elem)
	{
		if (full() == true)//�������� �� ������������� �����
		{
			throw "Error witn PUSH";
		}
		pMem[++top] = Elem;//��������� top �� 1 � �������� ������� � pMem
	}
	//�������� ������� �������
	int gettop()
	{
		return top;
	}
	//�������� ������ �����
	int getsize()
	{
		return size;
	}
	//�������� ������ �������
	T getvaltop()
	{
		return pMem[top];
	}
	//����������
	~TStack()
	{
		delete[] pMem;
	}
};

#endif
