#ifndef _LTABLEM_H_
#define _LTABLEM_H_


#include <string>
#define MAX_SIZELM 100

using namespace std;

template <class T>
struct TLMLine
{
	string key;
	T value;
};
template <class T>
class TLMTable
{
private:
	TLMLine<T>* line;
	unsigned int count;						// число строк
	unsigned int number_of_line;			// номер строки

public:

	TLMTable()
	{
		line = nullptr;
		count = 0;
		number_of_line = 0;
	}

	TLMTable(int _number_of_line)
	{
		if (_number_of_line < 0 || _number_of_line > MAX_SIZELM)
			throw "Number of line is not correct!";
		number_of_line = _number_of_line;
		line = new TLMLine<T>[_number_of_line];
		count = 0;
	}

	~TLMTable() {}

	bool is_empty()
	{
		if (count == 0)
			return true;
		else
			return false;
	}

	bool is_full()
	{
		if (count == number_of_line)
			return true;
		else
			return false;
	}

	int search_in_table_by_name(string _key)
	{
		if (is_empty() == true)
			return -1;
		for (int i = 0; i < count; i++)
		{
			if (line[i].key == _key)
				return i;
		}
		return -1;
	}

	void insert_line(string _key, T _value)
	{
		if (is_full() == true)
			throw "The table is full!";
		line[count].key = _key;
		line[count].value = _value;
		count++;
	}

	void delete_line(string _key)
	{
		if (is_empty() == true)
			throw "The table is empty!";
		int position = search_in_table_by_name(_key);
		if (position == -1)
			throw "This line does not exist!";

		line[position].key = line[count - 1].key;
		line[position].value = line[count - 1].value;
		line[count].key = '\0';
		count--;
	}

	T get_value(string _key)
	{
		if (is_empty() == true)
			throw "The table is empty!";
		int position = search_in_table_by_name(_key);
		if (position == -1)
			throw "This line does not exist!";
		return line[position].value;
	}
}; 
#endif // !_LTABLEM_H_