#pragma once
#include <cmath>
#include <iostream>
#include <string>

constexpr auto GRADRAD = 0.01745329251994329576923690768489;
constexpr auto RADGRAD = 57.295779513082320876798154814105;
constexpr auto PI = 3.1415926535897932384626433832795;

class Figure
{
public:
	Figure() = default;
	virtual double Arey() = 0;
	//virtual double Arry(double a, double b, double angle) = 0;
};


class Parallelogramf : public Figure
{
private:
	double side_a;
	double side_b;
	double angle_ab;

public:
	Parallelogramf() = default;
	Parallelogramf (double a, double b, double angle):
		side_a(a), side_b(b), angle_ab(angle){}

	double Arey() override
	{
		return  (side_a * side_b) * sin(angle_ab * GRADRAD);
	}
};

class Circle : public Figure
{
private:
	double diameter;

public:
	Circle(double D) : diameter(D) {}
	double Arey() override
	{
		return   (PI * (diameter * diameter))/4;
	}
};

class Square : public Parallelogramf
{
private:
	double side;

public:
	Square(double side) : side(side) {}
	double Arey() override
	{
		return side * side;
	}
};

class Rhombus : public Parallelogramf
{
private:
	double side_a;
	double side_b;


public:
	Rhombus(double side_a, double side_b) : side_a(side_a), side_b(side_b) {}
	double Arey() override
	{
		return (side_a * side_b) / 2;
	}
};

void print(Figure* f)
{
	std::cout << "������� "  << " = " << f->Arey() << std::endl;
}



void task1()
{
	
	print(new Parallelogramf(33.0, 66, 45));

	print(new Circle(44.0));
	print(new Square(44.0));
	print(new Rhombus(44.0, 23));



}



