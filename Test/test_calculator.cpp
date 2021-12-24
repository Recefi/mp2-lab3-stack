#include "..\Lab3\Calculator.h"

#include "gtest.h"

TEST(Calculator, can_create_calculator)
{
	ASSERT_NO_THROW(Calculator calc);
}

TEST(Calculator, can_set_and_get_expression)
{
	Calculator calc;
	std::string input = "3.7 + 2";
	std::string output;

	ASSERT_NO_THROW(calc.setExpr(input));
	ASSERT_NO_THROW(output = calc.getExpr());

	EXPECT_EQ(output, input);
}

TEST(Calculator, can_check_brackets)
{
	Calculator calc;
	calc.setExpr("2 + 2");
	ASSERT_NO_THROW(calc.checkExpr());
}

TEST(Calculator, can_detect_correct_brackets)
{
	Calculator calc;
	calc.setExpr("(3)");
	ASSERT_TRUE(calc.checkExpr());
}

TEST(Calculator, can_detect_incorrect_brackets)
{
	Calculator calc;
	calc.setExpr("3)(");
	ASSERT_FALSE(calc.checkExpr());
}

TEST(Calculator, can_convert_to_postfix_1)
{
	Calculator calc;
	calc.setExpr("(1 + 3) * 2");

	ASSERT_NO_THROW(calc.toPostfix());
	EXPECT_EQ(calc.getPostfix(), "1 3 + 2 *");
}

TEST(Calculator, can_convert_to_postfix_2)
{
	Calculator calc;
	calc.setExpr("7 + (4 - 2) * 3 ^ 2");

	ASSERT_NO_THROW(calc.toPostfix());
	EXPECT_EQ(calc.getPostfix(), "7 4 2 - 3 2 ^ * +");
}

TEST(Calculator, can_add_1)
{
	Calculator calc;
	calc.setExpr("2 + 4");
	calc.toPostfix();

	EXPECT_EQ(calc.calcPostfix(), 2 + 4);
}

TEST(Calculator, can_add_2)
{
	Calculator calc;
	calc.setExpr("12.7 + 4");

	EXPECT_EQ(calc.modernCalc(), 12.7 + 4);
}

TEST(Calculator, can_substract_1)
{
	Calculator calc;
	calc.setExpr("5 - 2");
	calc.toPostfix();

	EXPECT_EQ(calc.calcPostfix(), 5 - 2);
}

TEST(Calculator, can_substract_2)
{
	Calculator calc;
	calc.setExpr("5 - 2.4");

	EXPECT_EQ(calc.modernCalc(), 5 - 2.4);
}

TEST(Calculator, can_multiply_1)
{
	Calculator calc;
	calc.setExpr("2 * 3");
	calc.toPostfix();

	EXPECT_EQ(calc.calcPostfix(), 2 * 3);
}

TEST(Calculator, can_multiply_2)
{
	Calculator calc;
	calc.setExpr("2.1 * 3");
	
	EXPECT_EQ(calc.modernCalc(), 2.1 * 3);
}

TEST(Calculator, can_divide_1)
{
	Calculator calc;
	calc.setExpr("9 / 5");
	calc.toPostfix();

	EXPECT_EQ(calc.calcPostfix(), 9.0 / 5);
}

TEST(Calculator, can_divide_2)
{
	Calculator calc;
	calc.setExpr("9.0 / 2.5");

	EXPECT_EQ(calc.modernCalc(), 9.0 / 2.5);
}

TEST(Calculator, can_raise_to_the_power)
{
	Calculator calc;
	calc.setExpr("2^3");
	calc.toPostfix();

	EXPECT_EQ(calc.calcPostfix(), pow(2, 3));
	EXPECT_EQ(calc.modernCalc(), pow(2, 3));
}

TEST(Calculator, can_calculate_complex_expression_1)
{
	Calculator calc;
	calc.setExpr("7 + (4 - 2) * 3^2");
	calc.toPostfix();

	EXPECT_EQ(calc.calcPostfix(), 7 + (4 - 2) * pow(3, 2));
}

TEST(Calculator, can_calculate_complex_expression_2)
{
	Calculator calc;
	calc.setExpr("(0.25 - 0.13) * (14 - 2) / 0.1^2");

	EXPECT_EQ(calc.modernCalc(), (0.25 - 0.13) * (14 - 2) / pow(0.1, 2));
}

TEST(Calculator, can_calculate_complex_expression_3)
{
	Calculator calc;
	calc.setExpr("13 - (8.7 + 7.3) / 2 + (0.2^2*10)");

	EXPECT_EQ(calc.modernCalc(), 13 - (8.7 + 7.3) / 2 + (pow(0.2, 2) * 10));
}