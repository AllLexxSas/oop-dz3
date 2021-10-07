#pragma once
#include "include.h"

int numerators_addition(int a, int b)
{
	return a + b;
}

int subtract_numerators(int a, int b)
{
	return a - b;
}

class Fraction
{
private:
	int m_numerator;
	int m_denominator;

	//std::function <int(int, int)> dff = qff;

	Fraction Ñalculation(int two_numerator, int two_denominator, std::function <int(int, int)> diff)
	{
		if (m_denominator == two_denominator)
		{
			return Fraction(diff(m_numerator , two_numerator), m_denominator);
		}
		else
		{
			int num1 = m_numerator * two_denominator;
			int num2 = m_denominator * two_numerator;
			int num3 = diff(num1, num2);
			return Fraction(num3, m_denominator * two_denominator);
		}
	}

public:
	Fraction(int numerator, int denominator) :m_numerator(numerator), m_denominator(denominator)
	{}

	Fraction operator + (Fraction a)
	{
		return Ñalculation(a.m_numerator, a.m_denominator, numerators_addition);
	}

	Fraction operator - (Fraction a)
	{
		return Ñalculation(a.m_numerator, a.m_denominator, subtract_numerators);
	}

	Fraction operator * (Fraction a)
	{
		return Fraction (m_numerator * a.m_numerator, m_denominator * a.m_denominator);
	}
	Fraction operator / (Fraction a)
	{
		return Fraction(m_numerator * a.m_denominator, m_denominator * a.m_numerator);
	}

	friend std::ostream& operator << (std::ostream& out, Fraction& b);


};

std::ostream& operator << (std::ostream& out, Fraction& b)
{
	out << b.m_numerator << "/" << b.m_denominator;
	return out;
}


void task3()
{
	Fraction g(5, 7);
	Fraction h(8, 7);

	Fraction s1 = g + h;
	Fraction s2 = g - h;
	Fraction s3 = g * h;
	Fraction s4 = g / h;

	std::cout << s1 << "   " << s2 << "   " << s3 << "   " << s4;
}
