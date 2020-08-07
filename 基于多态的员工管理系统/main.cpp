#pragma once
#include "wokerManger.h"
#include <iostream>
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
using namespace std;

void test01() {
	Worker* worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->showInfo();
	delete worker;
	worker = NULL;

	worker = new Manager(2, "李斯", 2);
	worker->showInfo();
	delete worker;
	worker = NULL;

	worker = new Boss(3, "王五", 3);
	worker->showInfo();
	delete worker;
	worker = NULL;
}


void runSystem() {
	wokerManger wm;
	int choice = 0;
	while (true) {
		wm.Show_Menu();
		cout << "请输入你的选择：" << endl;
		cin >> choice;

		switch (choice) {
		case 0:	//退出系统
			wm.exitSystem();
			break;
		case 1:	//添加职工
			wm.add_Emp();
			break;
		case 2: //显示职工
			wm.showEmpInfo();
			break;
		case 3: //删除职工
			wm.Del_Emp();
			break; 
		case 4: //修改职工
			wm.Change_Emp();
			break;
		case 5: //查找职工
			wm.Search_Emp();
			break;
		case 6:	//职工排序
			wm.SortEmpById();
			break;
		case 7:	//清空文档
			wm.DeleteAllEmp();
			break;
		default:
			break;
		}
		
		

	}
}

int main() {

	runSystem();

	system("pause");
	return 0;
}