#pragma once
#include<iostream>
#include "Worker.h"

class Employee : public Worker
{
public:

	//¹¹Ôìº¯Êý
	Employee(int id, string name, int did);

	virtual void showInfo();

	virtual string getDeptName();

};

