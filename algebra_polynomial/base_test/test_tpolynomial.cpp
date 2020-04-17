#include"TListPoly.h"
#include "TListPoly.cpp"
#include "Polynomial.h"
#include "Polynomial.cpp"
#include <gtest.h>

TEST(Polynomial, can_create_polynom)
{
	ASSERT_NO_THROW(Polynomial p);
}
TEST(Polynomial, can_create_polynom_with_string)
{
	string s1 = "2x^2y^3z^4+3x^3y^4z^7";
	string s2="3x^3y^4z^7+2x^2y^3z^4";
	Polynomial p(s1);
	string ps = p.GetStrPol();
	EXPECT_EQ(ps, s2);
}
TEST(Polynomial, can_copy_polynomial)
{
	string s1 = "2x^2y^3z^4+3x^3y^4z^7";
	Polynomial p1(s1);
	Polynomial p2(p1);
	string ps1 = p1.GetStrPol();
	string ps2 = p2.GetStrPol();
	EXPECT_EQ(ps1, ps2);
}
TEST(Polynomial, operator_equel_is_correct1)
{
	string s1 = "2x^2y^3z^4+3x^3y^4z^7";
	Polynomial p1(s1);
	Polynomial p2(s1);
	EXPECT_TRUE(p1 == p2);
}
TEST(Polynomial, operator_equel_is_correct2)
{
	string s1 = "2x^2y^3z^4+3x^3y^4z^7";
	Polynomial p1(s1);
	string s2 = "2x^3y^5z^4+3x^3y^4z^7";
	Polynomial p2(s2);
	EXPECT_FALSE(p1 == p2);
}
TEST(Polynomial, operator_not_equel_is_correct1)
{
	string s1 = "2x^2y^3z^4+3x^3y^4z^7";
	Polynomial p1(s1);
	string s2 = "2x^3y^5z^4+3x^3y^4z^7";
	Polynomial p2(s2);
	EXPECT_TRUE(p1 != p2);	
}
TEST(Polynomial, operator_not_equel_is_correct2)
{
	string s1 = "2x^2y^3z^4+3x^3y^4z^7";
	Polynomial p1(s1);
	Polynomial p2(s1);
	EXPECT_FALSE(p1 != p2);
}
TEST(Polynomial, operator_assigning_is_correct)
{
	string s1 = "2x^2y^3z^4+3x^3y^4z^7";
	Polynomial p1(s1);
	Polynomial p2;
	p2 = p1;
	EXPECT_TRUE(p2 == p1);
}
TEST(Polynomial, operator_addition_is_correct)
{
	string s1 = "2x^2y^3z^4+3x^3y^4z^7";
	Polynomial p1(s1);
	string s2 = "2x^3y^5z^4+3x^3y^4z^7";
	Polynomial p2(s2);
	Polynomial p3;
	p3 = p2 + p1;
	string prov = "3x^3y^4z^7+2x^2y^3z^4+2x^3y^5z^4+3x^3y^4z^7";
	Polynomial pprov(prov);		
	EXPECT_TRUE(pprov == p3);
}
TEST(Polynomial, operator_multy_with_const_is_correct)
{
	string s1 = "2x^2y^3z^4+3x^3y^4z^7";
	Polynomial p1(s1);
	int i = -1;
	Polynomial p2;
	p2 = p1 * i;
	string provs = "-2x^2y^3z^4-3x^3y^4z^7";
	Polynomial pprov(provs);
	EXPECT_TRUE(pprov == p2);
}
TEST(Polynomial, operator_multy_with_polynom_is_correct)
{
	string s1 = "2x^2y^3z^4+5x^3y^2z^3";
	Polynomial p1(s1);
	string s2 = "4x^4y^2z^3+6x^1y^5z^4";
	Polynomial p2(s2);
	Polynomial p3;
	p3 = p1 * p2;
	string s4 = "30x^4y^7z^7+20x^7y^4z^6+12x^3y^8z^8+8x^6y^5z^7";
	Polynomial prov(s4);
	EXPECT_TRUE(prov == p3);
}
TEST(Polynomial, calculate_is_correct)
{
	string s1 = "2x^2y^3z^4+5x^3y^2z^3";
	Polynomial p1(s1);
	double x = 0.5;
	double y = 2;
	double z = 2.5;
	double res;
	res = p1.Calculate(x, y, z);
	double prov = 195.3125;
	EXPECT_EQ(res, prov);
}
