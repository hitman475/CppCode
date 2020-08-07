#pragma once
#include "Worker.h"

//经理类
class Manager : public Worker
{
public:
	//构造函数
	Manager(int id, string name, int did);

	//显示经理信息
	virtual void showInfo();

	//获取经理岗位信息
	virtual string getDeptName();

};

