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
	worker = new Employee(1, "����", 1);
	worker->showInfo();
	delete worker;
	worker = NULL;

	worker = new Manager(2, "��˹", 2);
	worker->showInfo();
	delete worker;
	worker = NULL;

	worker = new Boss(3, "����", 3);
	worker->showInfo();
	delete worker;
	worker = NULL;
}


void runSystem() {
	wokerManger wm;
	int choice = 0;
	while (true) {
		wm.Show_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;

		switch (choice) {
		case 0:	//�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1:	//���ְ��
			wm.add_Emp();
			break;
		case 2: //��ʾְ��
			wm.showEmpInfo();
			break;
		case 3: //ɾ��ְ��
			wm.Del_Emp();
			break; 
		case 4: //�޸�ְ��
			wm.Change_Emp();
			break;
		case 5: //����ְ��
			wm.Search_Emp();
			break;
		case 6:	//ְ������
			wm.SortEmpById();
			break;
		case 7:	//����ĵ�
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