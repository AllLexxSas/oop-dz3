#pragma once
#include "include.h"



class Figure
{
public:
	Figure() = default;
	virtual double Arey() = 0;
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
		return  (side_a * side_b) * sin(angle_ab * constants::GRADRAD);
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
		return   (constants::PI * (diameter * diameter))/4;
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
	std::cout << "площадь "  << " = " << f->Arey() << std::endl;
}



void task1()
{
	
	print(new Parallelogramf(33.0, 66, 45));

	print(new Circle(44.0));
	print(new Square(44.0));
	print(new Rhombus(44.0, 23));



}



