#pragma once
#include "Worker.h"

class Boss:public Worker
{
public:

	//构造函数
	Boss(int id, string name, int did);

	//显示个人信息
	virtual void showInfo();

	//获取岗位信息
	virtual string getDeptName();


};

