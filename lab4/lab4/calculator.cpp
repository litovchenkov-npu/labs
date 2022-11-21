#include <iostream>
#include "calculator.h"

void User::Input()
{
	std::cout << "Enter First Number: ";
	std::cin >> ICalculator::num.a;
	std::cout << "Enter Second Number: ";
	std::cin >> ICalculator::num.b;
}

void User::ChooseOperation()
{
	char Operation;
	std::cout << "Choose an operation: ";
	std::cin >> Operation;
	switch (Operation)
	{
	case '+': User::Add();
		break;
	case '-': User::Sub();
		break;
	case '*': User::Mul();
		break;
	case '/': User::Div();
		break;
	default:
		break;
	}
}

void User::Output()
{
	std::cout << "Result: " << ICalculator::num.result;
}

double User::Add()
{
	num.result = num.a + num.b;
	return num.result;
}

double User::Sub()
{
	num.result = num.a - num.b;
	return num.result;
}

double User::Mul()
{
	num.result = num.a * num.b;
	return num.result;
}

double User::Div()
{
	if (num.b == 0)
	{
		std::cout << "Division by zero" <<
			std::endl;
		num.result = INFINITY;
		return num.result;
	}
	else
	{
		num.result = num.a / num.b;
		return num.result;
	}
}