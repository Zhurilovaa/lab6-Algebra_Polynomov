#include "HTable1.h"
#include "Polynomial.h"
#include <gtest.h>

TEST(THashTable, can_create_table)
{
	ASSERT_NO_THROW(THashTable<Polynomial> T);
}
TEST(THashTable, can_use_IsFull)
{
	THashTable<int> table;
	ASSERT_NO_THROW(table.Is_Full());
}
TEST(THashTable, can_correct_use_IsFull)
{
	THashTable<Polynomial> table;
	EXPECT_FALSE(table.Is_Full());
}
TEST(THashTable, can_use_IsEmpty)
{
	THashTable<Polynomial> table;
	ASSERT_NO_THROW(table.Is_Empty());
}
TEST(THashTable, can_use_Search_In_Table_By_Name)
{
	THashTable<Polynomial> table;
	ASSERT_NO_THROW(table.Search_In_Table_By_Name("P"));
}
TEST(THashTable, can_correct_use_Is_Empty_1)
{
	THashTable<Polynomial> table;
	EXPECT_TRUE(table.Is_Empty());
}

TEST(THashTable, can_correct_use_Is_Empty_2)
{
	THashTable<Polynomial> table;
	Polynomial pol;
	table.InsertLine("A", pol);
	EXPECT_FALSE(table.Is_Empty());
}
TEST(THashTable, can_correct_use_Search_In_Table_By_Name_1)
{
	THashTable<Polynomial> table;
	Polynomial pol;
	table.InsertLine("A", pol);
	table.InsertLine("A1", pol);
	EXPECT_TRUE(table.Search_In_Table_By_Name("A"));
}
TEST(THashTable, can_correct_use_Search_In_Table_By_Name_2)
{
	THashTable<Polynomial> table;
	Polynomial _pol;
	table.InsertLine("A", _pol);
	table.InsertLine("A1", _pol);
	EXPECT_TRUE(table.Search_In_Table_By_Name("A1"));
}
TEST(THashTable, can_correct_use_Search_In_Table_By_Name_3)
{
	THashTable<Polynomial> table;
	Polynomial _pol;
	table.InsertLine("A", _pol);
	table.InsertLine("A1", _pol);
	EXPECT_EQ(table.Search_In_Table_By_Name("B"), false);
}
TEST(THashTable, can_use_Insert_Line)
{
	THashTable<Polynomial> table;
	Polynomial _pol;
	ASSERT_NO_THROW(table.InsertLine("P", _pol));
}
TEST(THashTable, can_use_DeleteLine)
{
	THashTable<Polynomial> table;
	Polynomial _pol;
	table.InsertLine("P", _pol);
	ASSERT_NO_THROW(table.DeleteLine("P"));
}
TEST(THashTable, can_not_use_DeleteLine_when_IsEmpty)
{
	THashTable<Polynomial> table;
	ASSERT_ANY_THROW(table.DeleteLine("P"));
}
TEST(THashTable, can_use_Get)
{
	THashTable<Polynomial> table;
	Polynomial _pol;
	table.InsertLine("P", _pol);
	ASSERT_NO_THROW(table.GetPolinominal("P"));
}
TEST(THashTable, can_correct_use_Get)
{
	THashTable<int> table;
	int _pol = 10;
	table.InsertLine("P", _pol);
	EXPECT_EQ(table.GetPolinominal("P"), _pol);
}
TEST(THashTable, can_correct_use__Get)
{
	THashTable<int> table;
	int _pol = 10;
	int __pol = 12;
	table.InsertLine("P", _pol);
	table.InsertLine("P1", __pol);
	EXPECT_EQ(table.GetPolinominal("P1"), __pol);
}
TEST(THashTable, can_not_use_Get_when_IsEmpty)
{
	THashTable<Polynomial> table;
	ASSERT_ANY_THROW(table.GetPolinominal("P"));
}
TEST(THashTable, can_correct_use_Add_and_Delete_Line)
{
	THashTable<Polynomial> table;
	Polynomial _pol;
	table.InsertLine("A", _pol);
	table.DeleteLine("A");
	EXPECT_TRUE(table.Is_Empty());
}