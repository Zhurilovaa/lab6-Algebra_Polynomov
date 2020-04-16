# Лабораторная работа "Алгебра полиномов"
____
## Техническое задание
____
- Разработать программную систему для выполнения алгебраических операций над полиномами от трех переменных. Полиномы хранятся в виде кольцевого списка с фиктивным звеном. Полиномы хранятся в таблицах. Ключом является имя полинома.
- Разработать 6 видов таблиц, в которых будут храниться полиномы:
    - линейная на массиве;
    - линейная на списке;
    - упорядоченная на массиве;
    - дерево (АВЛ или красно-черное);
    - две хэш-таблицы.
- Реализовать арифметические операции над полиномами: +, -, *, /. Для реализации арифметики полиномов будет использована постфиксная форма вычисления выражений.
- Реализовать гугл-тесты, которые будут проверять корректность операций, объектов: полином и постфикс.
- Разработать интерфейс для взаимодействия с программной системой.

##Структура проекта:

  - `gtest` — библиотека Google Test.
  - `base` — каталог с основным проектом ЛР.
  - `base_test` — каталог с проектом с модульными тестами.
  - `README.md` — информация о проекте.
  - `mp2-lab6-algebra.sln` - файл с решением (solution) для Microsoft Visual Studio 2010.
  - Служебные файлы
    - `.gitignore` — перечень расширений файлов, игнорируемых Git при добавлении файлов в репозиторий.

## Описание объектов.
### 1. Постфикс.
#### 1.1 Класс «TStack».

Реализация работы специальной структуры данных «СТЕК», которая хранит временные данные и промежуточные значения.

Данные:

-	T *pMem – массив символов, которые хранятся в стеке;
-	int size – размер стека;
-	int top – вершина стека.

Ниже приведена талица методов.

| LEFT | LEFT |
|----------------|:------------------------------------------------:|
| TStack(int _size) | конструктор создания объектов класса | 
| ~TStack() | деструктор | 
| void PUSH_El(T el)| метод, заносящий элемент в стек | 
| void POP_El() | метод, берущий элемент из стека | 
| bool Empty() | метод проверки на пустоту | 
| bool Full() | метод проверки на полноту |

Ниже приведен список тестов для данного класса.

| LEFT | LEFT |
|-------------------------------------------|:---------------------------------------------------------:|
| can_create_stack_with_positive_length | создание стека с правильной длинной |
| cant_create_too_large_size_of_stack | создание стека с отрицательной длинной |
| throws_when_create_stack_with_negative_length | создание стека со слишком большой длинной |
| not_can_pop_if_stack_empty | невозможность взятие элемента из пустого стека |
| not_can_push_if_stack_full | невозможность положить элемент в полный стек |
| can_push_and_pop_element | возможность взять или положить элемент в стек |
| full_is_correct_1 | корректность проверки на полноту 1 |
| full_is_correct_2 | корректность проверки на полноту 2 |
| empty_is_correct_1 | корректность проверки на пустоту 1 |
| empty_is_correct_2 | корректность проверки на пустоту 2 |
| get_top_is_correct | корректность получения вершины |
| get_size_is_correct | корректность получения размера |
| get_val_top_is_correct | корректность проверки вершины |

#### 1.2 Класс «TPostfix»

Реализует работу метода преобразования арифметического выражения в постфиксную форму. 

Данные:

-	string infix – строка исходного арифметического выражения в обычной форме;
-	string postfix – строка арифметического выражения в постфиксной форме;
-	string* var - массив имен переменных;
-	size_t sizevar - предполагаемый размер массива переменных;
-	TablFunc operat - таблица с операциями ;
-	double res - результат.

Ниже представлен список методов для данного класса.

| LEFT | LEFT |
|---------------------------------------------------------------|:-------------------------------------------------------------------------:|
| can_create_postfix1 | возможность создание постфикса (1) |
| can_create_postfix2 | возможность создание постфикса (2) |
| can_not_create_postfix_with_wrong_symbol | создание стека с недопустимыми символами |
| can_not_create_postfix_with_wrong_var_and_operation_pos | создание стека с ошибочным количеством операций относительно переменных |
| can_create_postfix_with_right_var_and_operation_pos1 | возможность перевести в постфиксную форму правильные строки |
| can_create_postfix_with_right_var_and_operation_pos2 | возможность перевести в постфиксную форму правильные строки |
| can_create_postfix_with_right_var_and_operation_pos3 | возможность перевести в постфиксную форму правильные строки |
| can_create_postfix_with_right_var_and_operation_pos4 | возможность перевести в постфиксную форму правильные строки |
| can_not_create_postfix_with_wrong_brackets1 | невозможность перевода в посфтикс выражения с неправильно расставленными скобками |
| can_not_create_postfix_with_wrong_brackets2 | невозможность перевода в посфтикс выражения с неправильно расставленными скобками |
| can_not_create_postfix_with_wrong_brackets3 | невозможность перевода в посфтикс выражения с неправильно расставленными скобками |
| can_not_create_postfix_with_wrong_brackets4 | невозможность перевода в посфтикс выражения с неправильно расставленными скобками |
| can_not_create_postfix_with_wrong_brackets5 | невозможность перевода в посфтикс выражения с неправильно расставленными скобками |
| can_not_create_postfix_with_wrong_brackets6 | невозможность перевода в посфтикс выражения с неправильно расставленными скобками |
| can_not_create_postfix_with_oper_as_first_sym | невозможность перевода в постфик выражения с операцией в начале выражения |
| can_not_create_postfix_with_oper_as_last_sym | невозможность перевода в постфик выражения с операцией в конце выражения |
| add_var_mas_is_correct | выделение переменных из инфикса |
| del_spase_is_correct | удаление лишних пробелов |
| convert_infix_to_postfix | возможность преобразования в постфикс |
| can_get_infix | возможность получения изначальной строки |
| can_get_postfix | возможность получения постфиксной формы |
| can_get_varsize | получение количества переменных из постфикса |

Ниже приведена список тестов для данного класса.

| LEFT | LEFT |
|---------------------------------|:------------------------------------------------:|
| can_create_postfix | возможность создания в постфиксной форме |
| convert_infix_to_postfix | возможность преобразования в постфиксную форму |
| convert_equal_expression | преобразование одинаковых выражений |
| calculation_accuary | корректность вычислений |
| convert_infix_with_brackets | преобразование уравнения со скобками |

### 1. Полином.
#### 1.1 Класс «TMonom».
Моном это объект типа ax^(i)y^(j)z^(k), хранящий коеффициент типа double и степени трёх переменных типа int.

Данные:

-	int index[3] - массив степеней(свертка степней);
-	double coeff - коэффициент монома.

Ниже приведен список методов для данного класса.

| LEFT | LEFT |
|------------------------------------------------------------------------------|:------------------------------------------------:|
| TMonom(double Mcoeff = 1, int Xindex = 0, int Yindex = 0, int Zindex = 0) | конструктор создания объектов класса | 
| TMonom(const TMonom& Mon)| конструктор копирования |
| ~TMonom()) | деструктор | 
| void SetCoeff(double Mcoeff)| установка коэффициент |
| double GetCoeff() | получение коэффициента |
| int GetIndexX() | получение индекса X |
| int GetIndexY() | получение индекса Y | 
| int GetIndexZ() | получение индекса Z |  
| TMonom& operator=(const TMonom &Mon) | оператор присваивания | 
| bool operator==(const TMonom &Mon) | оператор сравнения(равно) | 
| bool operator<(const TMonom &Mon) | оператор сравнения(меньше) |
| bool operator>(const TMonom& Mon) | оператор сравнения(больше) |
| bool operator<=(const TMonom& Mon) | оператор сравнения(меньше или равно) |
| bool operator>=(const TMonom &Mon) | оператор сравнения(больше или равно) | 
| bool Similar(const TMonom& Mon) | проверка на подобие мономов |  
| TMonom operator+(const TMonom& Mon) | сложение мономов | 
| TMonom operator*(const TMonom& Mon) | умножение мономов | 
| void MiltConst(const double& val) | умножение на константу |
| double CalcPoint(const double& x, const double& y, const double& z) | вычисление в точке |
| friend ostream& operator<<(ostream& out, const TMonom& Mon) | вывод монома |

К данному классу были реализованы следующие тесты.

| LEFT | LEFT |
|-----------------------------------------------------|:---------------------------------------------------------:|
| can_create_monom | создание монома |
| can_not_create_wrong_monom | невозможность создания монома с некорректными данными |
| can_get_coeff | получить коэффициенты монома |
| can_create_with_no_parameters | возможность создания монома без параметров |
| can_create_with_parameters | возможность создания монома с параметрами |
| can_copy_monom | возможность копирования |
| can_set_coeff | возможность установить коэффициенты |
| operator_equel_is_correct1 | корректность работы оператора равно (1) |
| operator_equel_is_correct2 | корректность работы оператора равно (2) |
| operator_assigning_is_correct | корректность работы оператора присваивания |
| operator_less_is_correct1 | корректность работы оператора меньше (1) |
| operator_less_is_correct2 | корректность работы оператора меньше (2) |
| operator_more_is_correct1 | корректность работы оператора больше (1) |
| operator_more_is_correct2 | корректность работы оператора больше (2) |
| operator_less_and_equel_is_correct1 | корректность работы оператора меньше или равно (1) |
| operator_less_and_equel_is_correct2 | корректность работы оператора меньше или равно (2) |
| operator_more_and_equel_is_correct1 | корректность работы оператора больше или равно (1) |
| operator_more_and_equel_is_correct2 | корректность работы оператора больше или равно (2) |  
| function_similar_is_correct1 | корректность проверки мономов на подобные (1) |
| function_similar_is_correct2 | корректность проверки мономов на подобные (2) |
| operator_addition_is_correct | корректность работы оператора сложения |
| operator_multiplying_two_monoms_is_correct | корректность работы умножения двух мономов |
| operator_multiplying_monom_and_const_is_correct | корректность работы умножения монома на константу |

#### 1.2 Класс «TPLink» 

Данные и методы:

-	TPLink* pNext - указатель на следующее звено;
-	TMonom m; – моном;
-	TPLink() – конструктор;
-	~TPLink() – деструктор.

#### 1.3 Класс «TPList»

Данные:

-	TPLink* pFirst – указатель на начало;
-	int size_list – размер списка.

Ниже приведен списов методов для данного класса.

| LEFT | LEFT |
|-------------------------------------------------------|:-------------------------------------------------:|
| TPList() | конструктор |
| TPList(const TPList& Plist) | конструктор копирования |
| ~TPList() | деструктор |
| TPLink* GetpFirst() | получить первый элемент |
| void SetSizeL(const int& s) | ввести размер списка |
| int GetSizeL() | получить размер списка |
| void TPList::InsertLast(const TMonom& mon) | вставка в конец |
| void TPList::TakeFirst() | удаление сначала |
| TPLink* TPList::Find(const int& pos) | поиск элемента |
| TMonom TPList::GetMonPos(const int pos) | получение данных(монома) по позиции |
| TPList& TPList::operator=(const TPList& Plist) | оператор присваивания |
| bool TPList::operator==(const TPList& Plist) const | оператор сравнения(равно) |
| bool TPList::operator!=(const TPList& Plist) const | оператор сравнения(не равно) |
| TPLink* TPList::DeleteTheLink(TPLink* p) | удаление звена |

К данному классу были реализованы следующие тесты.

| LEFT | LEFT |
|-------------------------------------------|:---------------------------------------------------------:|
| can_create_list | возможность создания списка |
| set_size_list | возможность установить размер списка |
| get_size_list | возможность получить размер списка |
| can_insert | возможность вставки |
| can_take | возможность взять первый элемент |
| can_get_monom_pos | возможность получить позицию монома |
| operator_equel_is_correct1 | корректность работы оператора равно (1) |
| operator_equel_is_correct2 | корректность работы оператора равно (2) |
| operator_not_equel_is_correct1 | корректность работы оператора не равно (1) |
| operator_not_equel_is_correct2 | корректность работы оператора не равно (2) |
| operator_assigning_is_correct | корректность работы присваивания |

#### 1.4 Класс «Polynomial»
Полином - объект, представляющий из себя совокупность мономов, хранит список мономов и строку, соответствующую этому списку.

Данные:

-	TPList Polynom;
-	string Pstr.

Ниже приведен список методов для данного класса.

| LEFT | LEFT |
|------------------------------------------------------------------------|:--------------------------------------------------:|
| Polynomial() | конструктор |
| Polynomial(string& s) | конструктор создания объекта |
| Polynomial(const Polynomial& Ppol) | конструктор копирования |
| ~Polynomial() | деструктор |
| void DeleteMistake(string& s) | удаление ошибок |
| int CreateInX(string& s, int& var, int& opSymbN) | создание степеней относительно x |
| int CreateInY(string& s, int& var, int& opSymbN) | создание степеней относительно y |
| int CreateInZ(string& s, int& var, int& opSymbN) | создание степеней относительно z |
| void StrToP(string& s) | преобразование строки в полином |
| void ChangeStr() | обновление строки после изменения полинома |
| string GetStrPol() | возврат строки полинома |
| Polynomial& operator=(const Polynomial& polyOut) | оператор присваивания |
| bool operator==(const Polynomial& polyOut) const | оператор сравнения(равно) |
| bool operator!=(const Polynomial& polyOut) const | оператор сравнения(не равно) |
| Polynomial operator+(Polynomial& Ppoly) | сложение полиномов |
| Polynomial operator-(Polynomial& Ppoly) | вычитание полиномов |
| Polynomial& operator*(const double& val) | умножение на константу |
| Polynomial operator*(Polynomial& Ppoly) | умножение между полиномами |
| double Calculate(const double& x, const double& y, const double& z) | вычисление в точке |
| friend ostream& operator<<(ostream& out, const Polynomial& Pol) | вывод полинома |

К данному классу были реализованы следующие тесты.

| LEFT | LEFT |
|-------------------------------------------|:---------------------------------------------------------:|
| can_create_polynom | возможность создания полинома |
| can_create_polynom_with_string | возможность создания полинома со строкой |
| can_copy_polynomial | возможность копирования полинома |
| operator_equel_is_correct1 | корректность работы оператора равно (1) |
| operator_equel_is_correct2 | корректность работы оператора равно (2) |
| operator_not_equel_is_correct1| корректность работы оператора не равно (1) |
| operator_not_equel_is_correct2 | корректность работы оператора не равно (2) |
| operator_assigning_is_correct | корректность работы оператора присваивания |
| operator_addition_is_correct | корректность работы оператора сложения |
| operator_multy_with_const_is_correct | корректность умножения полинома на константу |
| operator_multy_with_polynom_is_correct | корректность умножения полиномов |
| calculate_is_correct | корректность вычисления |

### 3. Таблицы.
Полиномы хранятся в таблицах. Для этого будут написаны 6 классов различных таблиц. Пользователю будет дана возможность выбрать, в какой таблице он хочет хранить созданные полиномы.

#### 3.1 Линейная таблица на массиве.
##### Класс «TLMTable»

![Alt-текст](https://sun9-8.userapi.com/c858420/v858420733/1cdb23/BjcEqQhxWMs.jpg)

Изначально вне класса была создана структура TLMLine, которая хранит ключ и значение.
- 	string key;
- 	T value;

Данные:

- 	TLMLine<T>* line - элемент структуры TLine;
- 	int count - число строк
- 	int number_of_line - номер строки

Ниже приведены методы, реализованные в данном классе.

| LEFT | LEFT |
|-----------------------------------------------|:------------------------------------------------:|
| TLMTable() | конструктор |
| TLMTable(int _number_of_line) | конструктор создания объектов класса | 
| ~TLMTable() | деструктор | 
| bool Is_Empty()| метод проверки на пустоту | 
| bool Is_Full() | метод проверки на полноту | 
| int Search_In_Table_By_Name(string _key) | поиск по ключу | 
| void Insert_Line(string _key, T _value) | вставка в конец |
| void Delete_Line(string _key) | удаление элемента |
| void Print_Table() | вывод таблицы |

К данному классу были реализованы следующие тесты.

| LEFT | LEFT |
|-------------------------------------------|:---------------------------------------------------------:|
| can_create_table | возможность создания таблицы |
| can_use_Is_Full | возможность проверки на полноту |
| can_correct_use_IsFull_1 | корректность проверки на полноту (1) |
| can_correct_use_IsFull_2 | корректность проверки на полноту (2) |
| can_use_IsEmpty | возможность проверки на пустоту |
| can_correct_use_IsEmpty_1 | корректность проверки на пустоту (1) |
| can_correct_use_IsEmpty_2 | корректность проверки на пустоту (2) |
| can_use_SearchOfLineByName | возможность использования поиска |
| can_correct_use_SearchOfLineByName_1 | корректность поиска (1) |
| can_correct_use_SearchOfLineByName_2 | корректность поиска (2) |
| can_correct_use_SearchOfLineByName_3 | корректность поиска (3) |
| can_use_AddLine | возможность добавления элемента |
| can_use_DeleteLine | возможность удаления элемента |
| can_not_use_DeleteLine_when_IsEmpty | невозможность удалить в пустой таблице |
| can_use_Get | возможность получить значение по ключу |
| can_correct_use_Get | корректность получения значения по ключу |

#### 3.2 Линейная таблица на списке.

----------------------------------------------------------------------------------------------------------

#### 3.3 Упорядоченная таблица на массиве.

##### Класс «TLineTable»

![Alt-текст](https://sun9-8.userapi.com/c858420/v858420733/1cdb23/BjcEqQhxWMs.jpg)

Изначально вне класса была создана структура TLine, которая хранит ключ и значение.
- 	string key;
- 	T value;

Данные:

- 	TLine<T>* line - элемент структуры TLine;
-	int count - число строк
- 	int number_of_line - номер строки

| LEFT | LEFT |
|-----------------------------------------------|:------------------------------------------------:|
| TOrderedTable() | конструктор |
| TOrderedTable(int _number_of_line) | конструктор создания объектов класса | 
| ~TOrderedTable() | деструктор | 
| bool Is_Empty()| метод проверки на пустоту | 
| bool Is_Full() | метод проверки на полноту | 
| int Search_In_Table_By_Name(string _key) | поиск по ключу | 
| void Insert_Line(string _key, T _value) | вставка в конец |
| void Delete_Line(string _key) | удаление элемента |
| void Print_Table() | вывод таблицы |

Ниже приведены методы, реализованные в данном классе.

| LEFT | LEFT |
|-------------------------------------------|:---------------------------------------------------------:|
| can_create_table | возможность создания таблицы |
| can_use_Is_Full | возможность проверки на полноту |
| can_correct_use_IsFull_1 | корректность проверки на полноту (1) |
| can_correct_use_IsFull_2 | корректность проверки на полноту (2) |
| can_use_IsEmpty | возможность проверки на пустоту |
| can_correct_use_IsEmpty_1 | корректность проверки на пустоту (1) |
| can_correct_use_IsEmpty_2 | корректность проверки на пустоту (2) |
| can_use_SearchOfLineByName | возможность использования поиска |
| can_correct_use_IsFound_1 | корректность поиска (1) |
| can_correct_use_IsFound_2 | корректность поиска (2) |
| can_correct_use_IsFound_3 | корректность поиска (3) |
| can_use_AddLine | возможность добавления элемента |
| can_not_use_AddLine_when_IsFull | невозможность добавления элемента в заполненную таблицу |
| can_use_DeleteLine | возможность удаления элемента |
| can_not_use_DeleteLine_when_IsEmpty | невозможность удалить в пустой таблице |
| can_use_Get | возможность получить значение по ключу |
| can_correct_use_Get | корректность получения значения по ключу |
| can_not_use_Get_when_IsEmpty | невозможность получения значения по ключу из пустой таблицы |
| can_correct_use_Add_and_Delete_Line | корректность добавления и удаления элемента |

#### 3.4 Дерево.

![Alt-текст](https://hsto.org/files/539/b1a/d28/539b1ad28be94202bf6ea191932d041e.png)

Данные:

- 	Key key - ключ;
-	Val value - значение;
-	int balance - баланс;
-	AvlTree <Key, Val>* left - указатель налево;
-	AvlTree <Key, Val>* right - указатель направо;
-	bool empty - переменная, отвечающая за полноту/пустоту;

Ниже приведены методы, реализованные в данном классе.

| LEFT | LEFT |
|-------------------------------------------------------|:-------------------------------------------------:|
| AvlTree() | конструктор |
| AvlTree(Key _key, Val _value) | конструктор создания объектов класса | 
| ~AvlTree() | деструктор | 
| bool Empty| метод проверки на пустоту | 
| bool is_full() | метод проверки на полноту | 
| void TurnAround() | нормализация баланса | 
| int Add(Key _key, Val _value) | добавление узла (возвращает, изменился ли баланс) |
| typename AvlTree<Key, Val>* searchNode(Key _key)  | поиск узла по ключу |
| int Delete(Key _key, AvlTree < Key, Val)* parent = nullptr) | удаление узла |
| void PrintTree(AvlTree <Key, Val>* _tree, int level) | вывод таблицы |

#### 3.5 Хеш таблица со списками(метод цепочек).

Для уменьшения количества элементов в хеш-таблице используют различные алгоритмы сжатия ключей. Однако в этом случае высока вероятность того, что несколько различных элементов получат одинаковый номер в хеш таблице. Одним из наиболее эффективных методов разрешения конфликтов состоит в том, что элементы, попадающие на одну и ту же позицию, размещаются в связанных списках.
![Alt-текст](https://3.bp.blogspot.com/-MUbdYSrJxdo/UPfIq9LDrXI/AAAAAAAAANk/Me2leZ3sN7k/s1600/цепочки.jpg)

##### Класс «THashTable»
Изначально вне класса была создана структура TLine, которая хранит ключ, значение, указатель на след звено и число звеньев.
- 	std::string nameOfLine;
-	T value;
- 	THashLine<T>* pNextLine;
- 	size_t numOfLine;

Данные:

- 	THashLine<T> line[MaxSizeOfTableH] - элемент структуры TLine;
- 	size_t countOfLine - число строк

Ниже приведены методы, реализованные в данном классе.

| LEFT | LEFT |
|---------------------------------------------|:------------------------------------------------:|
| THashTable() | конструктор |
| size_t Hash(string _key) | преобразование ключа в хеш-ключ | 
| bool Is_Empty()| метод проверки на пустоту | 
| bool Is_Full() | метод проверки на полноту |  
| void InsertLine(string _key, T _value) | вставка |
| int Search_In_Table_By_Name(string _key) | поиск по ключу |
| void DeleteLine(string _key) | удаление элемента |
| void Print_Table() | вывод таблицы |
| T  GetPolinominal() |получение данных строки |

К данному классу были реализованы следующие тесты.

| LEFT | LEFT |
|-------------------------------------------|:---------------------------------------------------------:|
| can_create_table | возможность создания таблицы |
| can_use_Is_Full | возможность проверки на полноту |
| can_correct_use_IsFull_1 | корректность проверки на полноту (1) |
| can_correct_use_IsFull_2 | корректность проверки на полноту (2) |
| can_use_IsEmpty | возможность проверки на пустоту |
| can_correct_use_IsEmpty_1 | корректность проверки на пустоту (1) |
| can_correct_use_IsEmpty_2 | корректность проверки на пустоту (2) |
| can_use_SearchOfLineByName | возможность использования поиска |
| can_correct_use_SearchOfLineByName_1 | корректность поиска (1) |
| can_correct_use_SearchOfLineByName_2 | корректность поиска (2) |
| can_correct_use_SearchOfLineByName_3 | корректность поиска (3) |
| can_use_Insert_Line | возможность добавления элемента |
| can_use_DeleteLine | возможность удаления элемента |
| can_not_use_DeleteLine_when_IsEmpty | невозможность удалить в пустой таблице |
| can_use_Get | возможность получить значение по ключу |
| can_correct_use_Get | корректность получения значения по ключу (1) |
| can_correct_use__Get | корректность получения значения по ключу (2) |
| can_not_use_Get_when_IsEmpty | невозможность использования метода получения значения из пустой таблицы |
| can_correct_use_Add_and_Delete_Line | корректность использования добавления и удаления элемента |

#### 3.6 Хеш таблица с открытым перемешиванием.

Изначально вне класса была создана структура Data.

- 	string key;
-	string SPolynom;
-	Polynomial Polynom.

Данные:

-	Data* Table[1000].

Ниже приведены методы, реализованные в данном классе.

| LEFT | LEFT |
|---------------------------------------|:------------------------------------------------:|
| HTableL() | конструктор |
| ~HTableL() | деструктор | 
| int Hashing(string _key) | преобразование ключа в хеш-ключ | 
| void Add(Data&_data) | вставка |
| Data* Search(string&_key) | поиск по ключу |
| void Delete(string&_key) | удаление элемента |
| void Print() | вывод таблицы |
