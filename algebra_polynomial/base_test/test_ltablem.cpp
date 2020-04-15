#include "LTableM.h"
#include "Polynomial.h"
#include <gtest.h>

TEST(TLMTable, can_create_table)
{
	ASSERT_NO_THROW(TLMTable<Polynomial> table);
}
TEST(TLMTable, can_use_Is_Full)
{
	TLMTable<Polynomial> table;
	ASSERT_NO_THROW(table.is_full());
}
TEST(TLMTable, can_correct_use_IsFull_1)
{
	TLMTable<Polynomial> table(26);
	string s = "3x ^ 2 + 4x ^ 5";
	Polynomial _pol(s);
	for (size_t i = 65; i < 91; i++)
	{
		char* _ch = new char[2];
		_ch[0] = (char)(i);
		_ch[1] = '\0';
		std::string sstr(_ch);
		table.insert_line(sstr, _pol);
	}
	EXPECT_TRUE(table.is_full());
}
TEST(TLMTable, can_correct_use_IsFull_2)
{
	TLMTable<Polynomial> table(26);
	EXPECT_FALSE(table.is_full());
}
TEST(TLMTable, can_use_IsEmpty)
{
	TLMTable<Polynomial> table;
	ASSERT_NO_THROW(table.is_empty());
}
TEST(TLMTable, can_use_SearchOfLineByName)
{
	TLMTable<Polynomial> table;
	ASSERT_NO_THROW(table.search_in_table_by_name("P"));
}
TEST(TLMTable, can_correct_use_IsEmpty_1)
{
	TLMTable<Polynomial> table;
	EXPECT_TRUE(table.is_empty());
}
TEST(TLMTable, can_correct_use_IsEmpty_2)
{
	TLMTable<Polynomial> table(1);
	Polynomial _pol;
	table.insert_line("A", _pol);
	EXPECT_FALSE(table.is_empty());
}
TEST(TLMTable, can_correct_use_SearchOfLineByName_1)
{
	TLMTable<Polynomial> table(2);
	Polynomial _pol;
	table.insert_line("A", _pol);
	table.insert_line("A1", _pol);
	EXPECT_EQ(table.search_in_table_by_name("A"), 0);
}
TEST(TLMTable, can_correct_use_SearchOfLineByName_2)
{
	TLMTable<Polynomial> table(2);
	Polynomial _pol;
	table.insert_line("A", _pol);
	table.insert_line("A1", _pol);
	EXPECT_EQ(table.search_in_table_by_name("A1"), 1);
}
TEST(TLMTable, can_correct_use_SearchOfLineByName_3)
{
	TLMTable<Polynomial> table(2);
	Polynomial _pol;
	table.insert_line("A", _pol);
	table.insert_line("A1", _pol);
	EXPECT_EQ(table.search_in_table_by_name("B"), -1);
}
TEST(TLMTable, can_use_AddLine)
{
	TLMTable<Polynomial> table(1);
	Polynomial _pol;
	ASSERT_NO_THROW(table.insert_line("P", _pol));
}
TEST(TLMTable, can_not_use_AddLine_when_IsFull)
{
	TLMTable<Polynomial> table(26);
	Polynomial _pol;
	for (size_t i = 65; i < 91; i++)
	{
		char* _ch = new char[2];
		_ch[0] = (char)(i);
		_ch[1] = '\0';
		std::string sstr(_ch);
		table.insert_line(sstr, _pol);
	}
	ASSERT_ANY_THROW(table.insert_line("P", _pol));
}
TEST(TLMTable, can_use_DeleteLine)
{
	TLMTable<Polynomial> table(2);
	Polynomial _pol;
	table.insert_line("P", _pol);
	ASSERT_NO_THROW(table.delete_line("P"));
}
TEST(TLMTable, can_not_use_DeleteLine_when_IsEmpty)
{
	TLMTable<Polynomial> table;
	ASSERT_ANY_THROW(table.delete_line("P"));
}
TEST(TLMTable, can_use_Get)
{
	TLMTable<Polynomial> table(1);
	Polynomial _pol;
	table.insert_line("P", _pol);
	ASSERT_NO_THROW(table.get_value("P"));
}
TEST(TLMTable, can_correct_use_Get)
{
	TLMTable<int> table(1);
	int _pol = 10;
	table.insert_line("P", _pol);
	EXPECT_EQ(table.get_value("P"), _pol);
}
TEST(TLMTable, can_correct_use__Get)
{
	TLMTable<int> table(2);
	int _pol = 10;
	int __pol = 12;
	table.insert_line("P", _pol);
	table.insert_line("P1", __pol);
	EXPECT_EQ(table.get_value("P1"), __pol);
}
TEST(TLMTable, can_not_use_Get_when_IsEmpty)
{
	TLMTable<Polynomial> table;
	ASSERT_ANY_THROW(table.get_value("P"));
}
TEST(TLMTable, can_correct_use_Add_and_Delete_Line)
{
	TLMTable<Polynomial> table(2);
	Polynomial _pol;
	table.insert_line("A", _pol);
	table.delete_line("A");
	EXPECT_TRUE(table.is_empty());
}