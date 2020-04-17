#include "YTable.h"
#include <gtest.h>


TEST(TOrderedTable, can_create_table)
{
	ASSERT_NO_THROW(TOrderedTable<int> table);
}
TEST(TOrderedTable, can_use_IsFull)
{
	TOrderedTable<int> table;
	ASSERT_NO_THROW(table.Is_Full());
}
TEST(TOrderedTable, can_correct_use_IsFull_1)
{
	TOrderedTable<int> table(26);
	int _pol = 0;
	for (size_t i = 65; i < 91; i++)
	{
		char* _ch = new char[2];
		_ch[0] = (char)(i);
		_ch[1] = '\0';
		std::string sstr(_ch);
		table.Insert_Line(sstr, _pol);
	}
	EXPECT_TRUE(table.Is_Full());
}
TEST(TOrderedTable, can_correct_use_IsFull_2)
{
	TOrderedTable<int> table(26);
	EXPECT_FALSE(table.Is_Full());
}
TEST(TOrderedTable, can_use_IsEmpty)
{
	TOrderedTable<int> table;
	ASSERT_NO_THROW(table.Is_Empty());
}
TEST(TOrderedTable, can_use_SearchOfLineByName)
{
	TOrderedTable<int> table;
	ASSERT_NO_THROW(table.Search_In_Table_By_Name("P"));
}
TEST(TOrderedTable, can_correct_use_IsEmpty_1)
{
	TOrderedTable<int> table;
	EXPECT_TRUE(table.Is_Empty());
}
TEST(TOrderedTable, can_correct_use_IsEmpty_2)
{
	TOrderedTable<int> table(1);
	int _pol = 0;
	table.Insert_Line("A", _pol);
	EXPECT_FALSE(table.Is_Empty());
}
TEST(TOrderedTable, can_correct_use_SearchOfLineByName_1)
{
	TOrderedTable<int> table(2);
	int _pol = 0;
	table.Insert_Line("A", _pol);
	table.Insert_Line("A1", _pol);
	EXPECT_EQ(table.Search_In_Table_By_Name("A"), 0);
}
TEST(TOrderedTable, can_correct_use_IsFound_2)
{
	TOrderedTable<int> table(2);
	int _pol = 0;
	table.Insert_Line("A", _pol);
	table.Insert_Line("A1", _pol);
	EXPECT_EQ(table.Search_In_Table_By_Name("A1"), 1);
}
TEST(TOrderedTable, can_correct_use_IsFound_3)
{
	TOrderedTable<int> table(2);
	int _pol = 0;
	table.Insert_Line("A", _pol);
	table.Insert_Line("A1", _pol);
	EXPECT_EQ(table.Search_In_Table_By_Name("B"), -1);
}
TEST(TOrderedTable, can_use_AddLine)
{
	TOrderedTable<int> table(1);
	int _pol = 0;
	ASSERT_NO_THROW(table.Insert_Line("P", _pol));
}
TEST(TOrderedTable, can_not_use_AddLine_when_IsFull)
{
	TOrderedTable<int> table(26);
	int _pol = 0;
	for (size_t i = 65; i < 91; i++)
	{
		char* _ch = new char[2];
		_ch[0] = (char)(i);
		_ch[1] = '\0';
		std::string sstr(_ch);
		table.Insert_Line(sstr, _pol);
	}
	ASSERT_ANY_THROW(table.Insert_Line("P", _pol));
}
TEST(TOrderedTable, can_use_DeleteLine)
{
	TOrderedTable<int> table(2);
	int _pol = 0;
	table.Insert_Line("P", _pol);
	ASSERT_NO_THROW(table.Delete_Line("P"));
}
TEST(TOrderedTable, can_not_use_DeleteLine_when_IsEmpty)
{
	TOrderedTable<int> table;
	ASSERT_ANY_THROW(table.Delete_Line("P"));
}
TEST(TOrderedTable, can_use_Get)
{
	TOrderedTable<int> table(1);
	int _pol = 0;
	table.Insert_Line("P", _pol);
	ASSERT_NO_THROW(table.GetValue("P"));
}
TEST(TOrderedTable, can_correct_use_Get)
{
	TOrderedTable<int> table(1);
	int _pol = 10;
	table.Insert_Line("P", _pol);
	EXPECT_EQ(table.GetValue("P"), _pol);
}
TEST(TOrderedTable, can_correct_use__Get)
{
	TOrderedTable<int> table(2);
	int _pol = 10;
	int __pol = 12;
	table.Insert_Line("P", _pol);
	table.Insert_Line("P1", __pol);
	EXPECT_EQ(table.GetValue("P1"), __pol);
}
TEST(TOrderedTable, can_not_use_Get_when_IsEmpty)
{
	TOrderedTable<int> table;
	ASSERT_ANY_THROW(table.GetValue("P"));
}
TEST(TOrderedTable, can_correct_use_Add_and_Delete_Line)
{
	TOrderedTable<int> table(2);
	int _pol = 0;
	table.Insert_Line("A", _pol);
	table.Delete_Line("A");
	EXPECT_TRUE(table.Is_Empty());
}