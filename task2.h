#pragma once
#include "include.h"

class Car
{
private:
	std::string company;
	std::string model;
public:
	Car() = default;
	Car(std::string& company, std::string &model): company(company), model(model)
	{
		std::cout << "Car company - "<< this->company<<" model " <<  this->model << std::endl;
	}
	virtual ~Car()
	{
		std::cout << "Kill Car" << std::endl;
	}
};

class PassengerCar :virtual public Car
{
public:
	PassengerCar(std::string& company, std::string& model) : Car(company, model)
	{
		std::cout << "PassengerCar company - " << company << " model " << model << std::endl;
	}
};


class Bus : virtual public Car
{
public:
	Bus(std::string &company, std::string &model) : Car(company, model)
	{
		std::cout << "Bus company - " << company << " model " << model << std::endl;
	}
	virtual ~Bus()
	{
		std::cout << "Kill Bus" << std::endl;
	}
};

class Minivan : public PassengerCar, Bus
{
public:
	Minivan(std::string &company, std::string &model) : PassengerCar(company, model), Bus(company, model)
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
	//Car *car = new Car("������", "�������");
	std::string nameCar = "�����";
	std::string modelCar = "�� ���� ��������";

	std::string nameBus = "������";
	std::string modelBus = "�� ������";
	Minivan* minivan = new Minivan(nameCar, modelCar);

	Bus *bus = new Bus(nameBus, modelBus);
	//Bus* bus = new Bus("fdsa","adsfa");
	delete minivan;
	delete bus;



}
