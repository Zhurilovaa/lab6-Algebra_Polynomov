#include "postfix.h"
#include "postfix.cpp"
#include <gtest.h>

TEST(TPostfix, can_create_postfix1)
{
	string s = "a+b";
	ASSERT_NO_THROW(TPostfix p(s));
}
TEST(TPostfix, can_create_postfix2)
{
	string s = "(a+b)";
	ASSERT_NO_THROW(TPostfix p(s));
}
TEST(TPostfix, can_not_create_postfix_with_wrong_symbol)
{
	string s = "a+b/";
	ASSERT_ANY_THROW(TPostfix p(s));
}
TEST(TPostfix, can_not_create_postfix_with_wrong_var_and_operation_pos)
{
	string s = "a+*b";
	ASSERT_ANY_THROW(TPostfix p(s));
}
TEST(TPostfix, can_create_postfix_with_right_var_and_operation_pos1)
{
	string s = "a+b";
	ASSERT_NO_THROW(TPostfix p(s));
}
TEST(TPostfix, can_create_postfix_with_right_var_and_operation_pos2)
{
	string s = "(a+b)*v";
	ASSERT_NO_THROW(TPostfix p(s));
}
TEST(TPostfix, can_create_postfix_with_right_var_and_operation_pos3)
{
	string s = "(s+v)*(a+b)";
	ASSERT_NO_THROW(TPostfix p(s));
}
TEST(TPostfix, can_create_postfix_with_right_var_and_operation_pos4)
{
	string s = "v*(a+b)";
	ASSERT_NO_THROW(TPostfix p(s));
}
TEST(TPostfix, can_not_create_postfix_with_wrong_brackets1)
{
	string s = "(v*a+b";
	ASSERT_ANY_THROW(TPostfix p(s));
}
TEST(TPostfix, can_not_create_postfix_with_wrong_brackets2)
{
	string s = "v*a+b)";
	ASSERT_ANY_THROW(TPostfix p(s));
}
TEST(TPostfix, can_not_create_postfix_with_wrong_brackets3)
{
	string s = "v*(a+b";
	ASSERT_ANY_THROW(TPostfix p(s));
}
TEST(TPostfix, can_not_create_postfix_with_wrong_brackets4)
{
	string s = "v*a)+b";
	ASSERT_ANY_THROW(TPostfix p(s));
}
TEST(TPostfix, can_not_create_postfix_with_wrong_brackets5)
{
	string s = "((v*a)+b-x";
	ASSERT_ANY_THROW(TPostfix p(s));
}
TEST(TPostfix, can_not_create_postfix_with_wrong_brackets6)
{
	string s = "v*a()+b";
	ASSERT_ANY_THROW(TPostfix p(s));
}
TEST(TPostfix, can_not_create_postfix_with_oper_as_first_sym)
{
	string s = "+v*a+b";
	ASSERT_ANY_THROW(TPostfix p(s));
}
TEST(TPostfix, can_not_create_postfix_with_oper_as_last_sym)
{
	string s = "v*a+b+";
	ASSERT_ANY_THROW(TPostfix p(s));
}
TEST(TPostfix, add_var_mas_is_correct)
{
	string s = "v*a+b";
	TPostfix p(s);
	size_t Size = p.GetCountOfVar();
	string* prov;
	prov = new string[Size];
	for (size_t i = 0; i < Size; i++)
	{
		prov[i] = p.GetArrVarPos(i);
	}
	EXPECT_EQ(prov[0], "v");
	EXPECT_EQ(prov[1], "a");
	EXPECT_EQ(prov[2], "b");
}
TEST(TPostfix, del_spase_is_correct)
{
	string s = " v+  a* b ";
	TPostfix p(s);
	string s2 = "v+a*b";
	string s3 = p.GetInfix();
	EXPECT_EQ(s3, s2);
}
TEST(TPostfix, convert_infix_to_postfix)		//преобразование
{
	TPostfix v("a*b+c");
	v.ToPostfix();
	string post = v.GetPostfix();
	string prov = "a b * c + ";
	EXPECT_EQ(post, prov);
}
TEST(TPostfix, can_get_infix)
{
	string s = "a+b";
	TPostfix p(s);
	EXPECT_EQ(p.GetInfix(), "a+b");
}
TEST(TPostfix, can_get_postfix)
{
	string s = "a+b";
	TPostfix p(s);
	p.ToPostfix();
	EXPECT_EQ(p.GetPostfix(), "a b + ");
}
TEST(TPostfix, can_get_varsize)
{
	string s = "a+b";
	TPostfix p(s);
	size_t S = p.GetCountOfVar();
	EXPECT_EQ(S, 2);
}

