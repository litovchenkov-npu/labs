#pragma once

struct Numbers
{
public:
    double a, b, result;
};


class ICalculator
{
protected:
	Numbers num;
public:
    virtual double Add() = 0;
    virtual double Sub() = 0;
    virtual double Mul() = 0;
	virtual double Div() = 0;
};

class User: public ICalculator
{
public:
	void Input();
	void ChooseOperation();
	void Output();

	virtual double Add() override;
	virtual double Sub() override;
	virtual double Mul() override;
	virtual double Div() override;
};