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

		if (abs(m_denominator) == abs(two_denominator))
		{
			return Fraction(diff(m_numerator, two_numerator), m_denominator);
		}
		else
		{
			int num1 = m_numerator * two_denominator;
			int num2 = m_denominator * two_numerator;
			int num3 = diff(num1, num2);
			return Fraction(num3, m_denominator * two_denominator);
		}
	}
	
	double Division(const int &a, const int &b)
	{
		return (double)a / b;
	}


public:
	Fraction(int numerator, int denominator)
	{
		SetFraction(numerator, denominator);
	}
	Fraction() {};

	bool SetFraction(int numerator, int denominator)
	{
		if (denominator == 0)
			throw std::exception("çíàìåíàòåëü ğàâåí íóëş");

		m_numerator = numerator;
		m_denominator = denominator;
		return true;
	}

	Fraction operator + (Fraction &a)
	{
		return Ñalculation(a.m_numerator, a.m_denominator, numerators_addition);
	}

	Fraction operator - (Fraction &a)
	{
		return Ñalculation(a.m_numerator, a.m_denominator, subtract_numerators);
	}

	bool operator < (const Fraction &a)
	{
		double result1 = Division( m_numerator , m_denominator);
		double result2 = Division( a.m_numerator , a.m_denominator);

		if (result1 < result2)
			return true;

		return false;
	}

	bool operator >=(Fraction &a)
	{
		return a < *this;
	}

	bool operator > (const Fraction &a)
	{
		double result1 = Division(m_numerator, m_denominator);
		double result2 = Division(a.m_numerator, a.m_denominator);

		if (result1 > result2)
			return true;

		return false;
	}

	bool operator <=(Fraction &a)
	{
		return a > *this;
	}



	bool operator ==(Fraction &a)
	{
		if (m_numerator == a.m_numerator and m_denominator == a.m_denominator)
		{
			return true;
		}
		
		return false;
	}

	bool operator !=(Fraction &a)
	{
		if (m_numerator == a.m_numerator and m_denominator == a.m_denominator)
		{
			return false;
		}
		
		return true;
	}

	Fraction operator - ()
	{
		return Fraction(-m_numerator, -m_denominator);
	}

	Fraction operator * (Fraction &a)
	{
		return Fraction(m_numerator * a.m_numerator, m_denominator * a.m_denominator);
	}
	Fraction operator / (Fraction &a)
	{
		return Fraction(m_numerator * a.m_denominator, m_denominator * a.m_numerator);
	}

	friend std::ostream& operator << (std::ostream& out, Fraction& b);


};

std::ostream& operator << (std::ostream& out, Fraction& b)
{

	if (b.m_denominator < 0 or b.m_numerator < 0)
		out << "-(" << abs(b.m_numerator) << "/" << abs( b.m_denominator) << ")";
	else
		out << b.m_numerator << "/" << b.m_denominator;
	return out;
}


void task3()
{
	Fraction g(5, 7);
	Fraction h(8, 7);
	Fraction h3(-8, 7);
	Fraction h1;

	try
	{
		h1.SetFraction(6, 0);
	}
	catch (const std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}

	h = -h;
	h1 = -h1;


	Fraction s1 = g + h;
	Fraction s2 = g - h;
	Fraction s3 = g * h;
	Fraction s4 = g / h;

	std::cout << std::boolalpha << (h >= g) << std::endl;

	std::cout << "s1 = " << s1 << "\n" << "s2 = " << s2 << "\n" << "s3 =" << s3 << "\n" << "s4" << s4 << "\n" << h3 << "\n";

	Fraction d1(-8, 7);
	Fraction d2(-8, 7);

	std::cout << (d1 != d2) << std::endl;


}
