#pragma once
#include<iostream>
#include "Worker.h"

class Employee : public Worker
{
public:

	//���캯��
	Employee(int id, string name, int did);

	virtual void showInfo();

	virtual string getDeptName();

};

