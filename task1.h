#pragma once
#include "include.h"



class Figure
{
protected:
	std::string nameFigure;
public:
	Figure() = default;
	Figure(std::string& str) :nameFigure(str) {}
	virtual double Arey() = 0;
	virtual ~Figure() {}
	virtual std::string & GetNameClass()
	{
		return nameFigure;
	}
	
};


class Parallelogramf :  virtual public Figure
{
private:
	double side_a;
	double side_b;
	double angle_ab;
	
public:
	Parallelogramf() = default;
	Parallelogramf (double a, double b, double angle, std::string figName ="Parallelogramf"):Figure(figName),
		side_a(a), side_b(b), angle_ab(angle){}

	double Arey() override
	{
		return  (side_a * side_b) * sin(angle_ab * constants::GRADRAD);
	}
};

class Circle : virtual public Figure
{
private:
	double diameter;
	
public:
    explicit Circle(double D, std::string figName = "Circle") : Figure(figName), diameter(D) {}
	double Arey() override
	{
		return   (constants::PI * (diameter * diameter))/4;
	}

	virtual std::string & GetNameClass()
	{
		return nameFigure;
	}
};

class Square : virtual public Parallelogramf
{
private:
	double side;
	
public:
	explicit Square(double side, std::string figName = "Square") :Figure(figName), side(side) {}
	double Arey() override
	{
		return side * side;
	}
};

class Rhombus :virtual public Parallelogramf
{
private:
	double side_a;
	double side_b;


public:
	explicit Rhombus(double side_a, double side_b, std::string figName = "Rhombus") :Figure(figName), side_a(side_a), side_b(side_b) {}
	double Arey() override
	{
		return (side_a * side_b) / 2;
	}

};



class PrintFigure
{
private:
	Figure *m_figure;

public:
	PrintFigure(Figure * figure):m_figure (figure)
	{
		print();
	}

	void print()
	{
		std::cout << "площадь " << m_figure->GetNameClass() << " = " << m_figure->Arey() << std::endl;
	}
	~PrintFigure()
	{
		delete m_figure;
	}
};



void task1()
{
	
	PrintFigure(new Parallelogramf(33.0, 66, 45));
	
	

	PrintFigure(new Circle(44.0));
	PrintFigure(new Square(44.0));
	PrintFigure(new Rhombus(44.0, 23));



}



