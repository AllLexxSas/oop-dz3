#pragma once
#include "include.h"

class Car
{
private:
	std::string company;
	std::string model;
public:

	Car(std::string company, std::string model): company(company), model(model)
	{
		std::cout << "Car company - "<< this->company<<" model " <<  this->model << std::endl;
	}
	virtual ~Car()
	{
		std::cout << "Kill Car" << std::endl;
	}
};

class PassengerCar : public Car
{
public:
	PassengerCar(std::string company, std::string model) : Car(company, model)
	{
		std::cout << "PassengerCar company - " << company << " model " << model << std::endl;

	}
};


class Bus : public Car
{
public:
	Bus(std::string company, std::string model) : Car(company, model)
	{
		std::cout << "Bus company - " << company << " model " << model << std::endl;
	}

};

class Minivan : public PassengerCar, Bus
{
public:
	Minivan(std::string company, std::string model) : PassengerCar(company, model), Bus(company, model)
	{
		std::cout << "Minivan company - " << company << " model " << model << std::endl;
	}

	virtual ~Minivan() override
	{
		std::cout << "Kill Minivan" << std::endl;
	}
};



void task2()
{
	//Car *car = new Car("тайота", "авенсис");
	Minivan* minivan = new Minivan("нисан" , "не знаю название");
	//Bus* bus = new Bus("fdsa","adsfa");
	delete minivan;



}
