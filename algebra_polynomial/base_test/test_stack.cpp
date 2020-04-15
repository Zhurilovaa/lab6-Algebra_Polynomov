#include "stack.h"
#include <gtest.h>

using namespace std;
TEST(TStack, can_create_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> st(5));
}

TEST(TStack, cant_create_too_large_size_of_stack)
{
	ASSERT_ANY_THROW(TStack<int> st(MaxStackSize + 1));
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> st(-5));
}

TEST(TStack, not_can_pop_if_stack_empty)
{
	TStack<int> STACK(3);
	ASSERT_ANY_THROW(STACK.pop());
}

TEST(TStack, not_can_push_if_stack_full)
{
	TStack<int> STACK(3);
	for (int k = 0; k < 3; k++)
		STACK.push(1);
	ASSERT_ANY_THROW(STACK.push(4));
}

TEST(TStack, can_push_and_pop_element)
{
	TStack<int> STACK(4);
	STACK.push(1);
	EXPECT_EQ(STACK.pop(), 1);
}

TEST(TStack, full_is_correct_1)
{
	TStack<int> STACK(4);
	EXPECT_EQ(STACK.full(), false);
}

TEST(TStack, full_is_correct_2)
{
	TStack<int> STACK(1);
	STACK.push(5);
	EXPECT_EQ(STACK.full(), true);
}

TEST(TStack, empty_is_correct_1)
{
	TStack<int> STACK(4);
	EXPECT_EQ(STACK.empty(), true);
}

TEST(TStack, empty_is_correct_2)
{
	TStack<int> STACK(1);
	STACK.push(5);
	EXPECT_EQ(STACK.empty(), false);
}

TEST(TStack, get_top_is_correct)
{
	TStack<int> STACK(1);
	STACK.push(5);
	EXPECT_EQ(STACK.gettop(), 0);
}

TEST(TStack, get_size_is_correct)
{
	TStack<int> STACK(2);
	EXPECT_EQ(STACK.getsize(), 2);
}

TEST(TStack, get_val_top_is_correct)
{
	TStack<int> STACK(2);
	STACK.push(5);
	STACK.push(6);
	EXPECT_EQ(STACK.getvaltop(), 6);
}