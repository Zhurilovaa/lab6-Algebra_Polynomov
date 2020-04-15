#include "TMonomial.h"
#include <gtest.h>

TEST(TMonom, can_create_monom)
{
	ASSERT_NO_THROW(TMonom m);
}
TEST(TMonom, can_not_create_wrong_monom)
{
	ASSERT_ANY_THROW(TMonom m(2, -1, 101, 22));
}
TEST(TMonom, can_get_coeff)
{
	TMonom m;
	EXPECT_EQ(m.GetCoeff(), 1);
}
TEST(TMonom, can_get_index)
{
	TMonom m;
	EXPECT_EQ(m.GetIndexX(), 0);
	EXPECT_EQ(m.GetIndexY(), 0);
	EXPECT_EQ(m.GetIndexZ(), 0);
}
TEST(TMonom, can_create_with_no_parameters)
{
	TMonom m;
	EXPECT_EQ(m.GetCoeff(), 1);
	EXPECT_EQ(m.GetIndexX(), 0);
	EXPECT_EQ(m.GetIndexY(), 0);
	EXPECT_EQ(m.GetIndexZ(), 0);
}
TEST(TMonom, can_create_with_parameters)
{
	//положительные параметры
	TMonom m1(5, 2, 3, 4);
	EXPECT_EQ(m1.GetCoeff(), 5);
	EXPECT_EQ(m1.GetIndexX(), 2);
	EXPECT_EQ(m1.GetIndexY(), 3);
	EXPECT_EQ(m1.GetIndexZ(), 4);
	//отрицательный коэффициент
	TMonom m2(-5, 2, 3, 4);
	EXPECT_EQ(-5, m2.GetCoeff());
}
TEST(TMonom, can_copy_monom)
{
	TMonom m1(2, 3, 4, 5);
	TMonom m2(m1);
	EXPECT_EQ(m2.GetCoeff(), 2);
	EXPECT_EQ(m2.GetIndexX(), 3);
	EXPECT_EQ(m2.GetIndexY(), 4);
	EXPECT_EQ(m2.GetIndexZ(), 5);
}
TEST(TMonom, can_set_coeff)
{
	TMonom m(5, 2, 3, 4);
	m.SetCoeff(10);
	EXPECT_EQ(m.GetCoeff(), 10);
}

TEST(TMonom, operator_equel_is_correct1)
{
	TMonom m1(2, 3, 4, 5);
	TMonom m2(2, 3, 4, 5);
	EXPECT_TRUE(m1 == m2);
}
TEST(TMonom, operator_equel_is_correct2)
{
	TMonom m1(2, 3, 4, 5);
	TMonom m2(3, 3, 4, 5);
	EXPECT_FALSE(m1 == m2);
}

TEST(TMonom, operator_assigning_is_correct)
{
	TMonom m1(2, 3, 4, 5);
	TMonom m2;
	m2 = m1;
	EXPECT_TRUE(m1 == m2);
}

TEST(TMonom, operator_less_is_correct1)
{
	TMonom m1(2, 3, 4, 5);
	TMonom m2(2, 3, 4, 6);
	EXPECT_TRUE(m1 < m2);
}
TEST(TMonom, operator_less_is_correct2)
{
	TMonom m1(2, 3, 4, 5);
	TMonom m2(2, 3, 4, 6);
	EXPECT_FALSE(m2 < m1);
}
TEST(TMonom, operator_more_is_correct1)
{
	TMonom m1(2, 3, 4, 5);
	TMonom m2(2, 4, 5, 6);
	EXPECT_TRUE(m2 > m1);
}
TEST(TMonom, operator_more_is_correct2)
{
	TMonom m1(2, 3, 4, 5);
	TMonom m2(2, 4, 5, 6);
	EXPECT_FALSE(m1 > m2);
}
TEST(TMonom, operator_less_and_equel_is_correct1)
{
	TMonom m1(2, 3, 4, 5);
	TMonom m2(2, 4, 5, 6);
	TMonom m3(m1);
	EXPECT_TRUE(m1 <= m2);
	EXPECT_TRUE(m1 <= m3);
}
TEST(TMonom, operator_less_and_equel_is_correct2)
{
	TMonom m1(2, 3, 4, 5);
	TMonom m2(2, 4, 5, 6);
	TMonom m3(m1);
	EXPECT_FALSE(m2 <= m1);
	EXPECT_FALSE(m2 <= m3);
}
TEST(TMonom, operator_more_and_equel_is_correct1)
{
	TMonom m1(2, 3, 4, 5);
	TMonom m2(2, 4, 5, 6);
	TMonom m3(m1);
	EXPECT_TRUE(m2 >= m1);
	EXPECT_TRUE(m1 >= m3);
}
TEST(TMonom, operator_more_and_equel_is_correct2)
{
	TMonom m1(2, 3, 4, 5);
	TMonom m2(2, 4, 5, 6);
	TMonom m3(m1);
	EXPECT_FALSE(m1 >= m2);
	EXPECT_FALSE(m3 >= m2);
}
TEST(TMonom, function_similar_is_correct1)
{
	TMonom m1(2, 3, 4, 5);
	TMonom m2(5, 3, 4, 5);
	EXPECT_TRUE(m1.Similar(m2));
}
TEST(TMonom, function_similar_is_correct2)
{
	TMonom m1(2, 3, 4, 5);
	TMonom m2(2, 2, 4, 5);
	EXPECT_FALSE(m1.Similar(m2));
}

TEST(TMonom, operator_addition_is_correct)
{
	TMonom m1(2, 3, 4, 5);
	TMonom m2(7, 3, 4, 5);
	TMonom m3;
	m3 = m1 + m2;
	EXPECT_EQ(m3.GetCoeff(), 9);
	m2.SetCoeff(-1);
	m3 = m1 + m2;
	EXPECT_EQ(m3.GetCoeff(), 1);
}
TEST(TMonom, operator_multiplying_two_monoms_is_correct)
{
	TMonom m1(2, 3, 4, 5);
	TMonom m2(7, 3, 4, 5);
	TMonom m3;
	m3 = m1 * m2;
	EXPECT_EQ(m3.GetCoeff(), 14);
	EXPECT_EQ(m3.GetIndexX(), 6);
	EXPECT_EQ(m3.GetIndexY(), 8);
	EXPECT_EQ(m3.GetIndexZ(), 10);
}
TEST(TMonom, operator_multiplying_monom_and_const_is_correct)
{
	TMonom m1(2, 3, 4, 5);
	int i = 6;
	m1.MiltConst(i);
	EXPECT_EQ(m1.GetCoeff(), 12);
	EXPECT_EQ(m1.GetIndexX(), 3);
	EXPECT_EQ(m1.GetIndexY(), 4);
	EXPECT_EQ(m1.GetIndexZ(), 5);
}
