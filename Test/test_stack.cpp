#include "..\Lab3\TStack.h"

#include "gtest.h"

TEST(TStack, can_create_stack_with_positive_size)
{
	ASSERT_NO_THROW(TStack<int> s(15));
}

TEST(TStack, cant_create_stack_with_negative_size)
{
	ASSERT_ANY_THROW(TStack<int> s(-7));
}

TEST(TStack, can_push_and_pop)
{
	TStack<int> s1(5);

	ASSERT_NO_THROW(s1.push(2));
	ASSERT_NO_THROW(s1.push(5));
	ASSERT_NO_THROW(s1.push(-7));

	int tmp;
	ASSERT_NO_THROW(tmp = s1.pop());
	EXPECT_EQ(-7, tmp);
	ASSERT_NO_THROW(tmp = s1.pop());
	EXPECT_EQ(5, tmp);
	ASSERT_NO_THROW(tmp = s1.pop());
	EXPECT_EQ(2, tmp);
}

TEST(TStack, can_top)
{
	TStack<int> s1(5);

	ASSERT_NO_THROW(s1.push(0));
	ASSERT_NO_THROW(s1.push(-13));
	ASSERT_NO_THROW(s1.push(2));

	int tmp;
	ASSERT_NO_THROW(tmp = s1.top());
	EXPECT_EQ(2, tmp);
}

TEST(TStack, cant_push_when_stack_is_full)
{
	TStack<int> s(5);
	for (int i = 0; i < 5; ++i)
		s.push(3 * i + 2);

	ASSERT_TRUE(s.isFull());
	ASSERT_ANY_THROW(s.push(4));
}

TEST(TStack, cant_pop_when_stack_is_empty)
{
	TStack<int> s(5);

	ASSERT_TRUE(s.isEmpty());
	ASSERT_ANY_THROW(s.pop());
}

TEST(TStack, cant_top_when_stack_is_empty)
{
	TStack<int> s(5);

	ASSERT_TRUE(s.isEmpty());
	ASSERT_ANY_THROW(s.top());
}

TEST(TStack, can_clear_stack)
{
	TStack<int> s(5);
	for (int i = 0; i < 5; ++i)
		s.push(3 * i + 2);

	s.clear();
	ASSERT_TRUE(s.isEmpty());
}

TEST(TStack, can_create_copied_stack)
{
	TStack<int> s1(10);
	for (int i = 0; i < 10; ++i)
		s1.push(3 * i + 2);

	ASSERT_NO_THROW(TStack<int>(s1));
	TStack<int> s2(s1);
	EXPECT_EQ(s2, s1);
}

TEST(TStack, can_assign_stacks_of_equal_size)
{
	TStack<int> s1(10), s2(10);
	for (int i = 0; i < 10; ++i) {
		s1.push(3 * i + 2);
		s2.push(2 * i + 1);
	}

	ASSERT_NO_THROW(s2 = s1);
	EXPECT_EQ(s2, s1);
}

TEST(TStack, can_assign_stacks_of_different_size)
{
	TStack<int> s1(10), s2(5);
	for (int i = 0; i < 10; ++i)
		s1.push(3 * i + 2);
	for (int i = 0; i < 5; ++i)
		s2.push(2 * i + 1);

	ASSERT_NO_THROW(s2 = s1);
	EXPECT_EQ(s2, s1);
}

TEST(TStack, can_assign_stack_to_itself)
{
	TStack<int> s1(10);
	for (int i = 0; i < 10; ++i)
		s1.push(3 * i + 2);

	ASSERT_NO_THROW(s1 = s1);
}