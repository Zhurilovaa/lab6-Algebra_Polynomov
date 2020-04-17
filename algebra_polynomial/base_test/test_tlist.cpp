#include "TListPoly.h"
#include <gtest.h>
TEST(TPList, can_create_list)
{
	ASSERT_NO_THROW(TPList p);
}
TEST(TPList, set_size_list)
{
	int i = 5;
	TPList p;
	ASSERT_NO_THROW(p.SetSizeL(i));
}
TEST(TPList, get_size_list)
{
	int i = 5;
	TPList p;
	p.SetSizeL(i);
	EXPECT_EQ(p.GetSizeL(), 5);
}
TEST(TPList, can_insert)
{
	TMonom m1(5, 2, 3, 4);
	TPList p;
	p.InsertLast(m1);
	EXPECT_EQ(p.GetSizeL(), 1);
}
TEST(TPList, can_take)
{
	TMonom m1(5, 2, 3, 4);
	TPList p;
	p.InsertLast(m1);
	p.TakeFirst();
	EXPECT_EQ(p.GetSizeL(), 0);
}
TEST(TPList, can_get_monom_pos)
{
	TMonom m1(5, 2, 3, 4);
	TPList p;
	p.InsertLast(m1);
	TMonom m2;
	int pos = 0;
	m2 = p.GetMonPos(pos);
	EXPECT_TRUE(m1 == m2);
}
TEST(TPList, operator_equel_is_correct1)
{
	TMonom m1(5, 2, 3, 4);
	TPList p;
	p.InsertLast(m1);
	TPList p2;
	p2.InsertLast(m1);
	EXPECT_TRUE(p == p2);
}
TEST(TPList, operator_equel_is_correct2)
{
	TMonom m1(5, 2, 3, 4);
	TPList p1;
	TMonom m2(2, 5, 7, 3);
	p1.InsertLast(m1);
	TPList p2;
	p2.InsertLast(m2);
	EXPECT_FALSE(p1 == p2);
}
TEST(TPList, operator_not_equel_is_correct1)
{
	TMonom m1(5, 2, 3, 4);
	TPList p;
	p.InsertLast(m1);
	TPList p2;
	p2.InsertLast(m1);
	EXPECT_FALSE(p != p2);
}
TEST(TPList, operator_not_equel_is_correct2)
{
	TMonom m1(5, 2, 3, 4);
	TPList p1;
	TMonom m2(2, 5, 7, 3);
	p1.InsertLast(m1);
	TPList p2;
	p2.InsertLast(m2);
	EXPECT_TRUE(p1 != p2);
}
TEST(TPList, operator_assigning_is_correct)
{
	TMonom m1(5, 2, 3, 4);
	TPList p1;
	TPList p2;
	p2 = p1;
	EXPECT_TRUE(p2 == p1);
}