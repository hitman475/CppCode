#include "wokerManger.h"

wokerManger::wokerManger() 
{
	//1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2.文件存在，但是没有记录
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.文件存在，并且文件中记录有数据
	int num = this->get_EmpNum();
	cout << "职工人数为:" << num << endl;
	this->m_EmpNum = num;
	this->m_FileIsEmpty = false;
	this->m_EmpArray = NULL;

	//从文件中读取数据，初始化数组
	this->Init_Emp();
}

wokerManger::~wokerManger() 
{
	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

//清屏函数
void wokerManger::clear() {
	system("pause");
	system("cls");
}


//展示菜单
void wokerManger::Show_Menu()
{
	cout << "**************************************" << endl;
	cout << "********* 欢迎使用职工管理系统 *******" << endl;
	cout << "************ 0.退出管理程序 **********" << endl;
	cout << "************ 1.增加职工信息 **********" << endl;
	cout << "************ 2.显示职工信息 **********" << endl;
	cout << "************ 3.删除离职职工 **********" << endl;
	cout << "************ 4.修改职工信息 **********" << endl;
	cout << "************ 5.查找职工信息 **********" << endl;
	cout << "************ 6.按照编号排序 **********" << endl;
	cout << "************ 7.清空所有文档 **********" << endl;
	cout << "**************************************" << endl;
	cout << endl;

}

//退出系统
void wokerManger::exitSystem() {
	cout << "欢迎下次使用" << endl;
	clear();
	exit(0);
}

//添加员工
void wokerManger::add_Emp() {

	cout << "请输入添加的员工的人数:" << endl;

	int addNum = 0;	//保存用户的输入数量
	cin >> addNum;

	if (addNum > 0) 
	{
		//添加
		//计算添加新空间的大小
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		Worker ** newSpace = new Worker * [newSize];

		//将原来空间下的数据拷贝到newSpace中
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//批量添加新数据
		for (int i = 0; i < addNum; i++) {
			int id;	//职工编号
			string name;	//职工姓名
			int dSelect;	//部门选择

			cout << "---请添加第" << i + 1 << "号员工----" << endl;
			cout << "请输入职工编号:";
			cin >> id;
			cout << "请输入姓名:";
			cin >> name;
			cout << "请输入部门： 1.员工\t2.经理\t3.老板" << endl;
			cin >> dSelect;

			switch (dSelect) {
			case 1: 
				newSpace[this->m_EmpNum + i] = new Employee(id, name, 1);
				break;
			case 2:
				newSpace[this->m_EmpNum + i] = new Manager(id, name, 1);
				break;
			case 3:
				newSpace[this->m_EmpNum + i] = new Boss(id, name, 1);
				break;
			default:
				break;
			}
		}

		//释放原有的空间
		delete[] this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的职工人数
		this->m_EmpNum = newSize;

		//提示添加成功
		cout << "成功添加" << addNum << "新职工" << endl;

		//更行职工不为空的标志
		this->m_FileIsEmpty = false;

		//将内存中的数据存储到文件中
		save();

		clear();
		
	}
	else 
	{
		cout << "人数输入有误！" << endl;

		clear();

		return;
	}

}

//保存数据到文件
void wokerManger::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_depId << endl;
	}

	ofs.close();
}

int wokerManger::get_EmpNum() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);	//打开文件读取

	int id;
	string name;
	int dId;

	//统计人数变量
	int num = 0;

	//从文件中读取一行数据
	while (ifs >> id >> name >> dId) {
		num++;
	}

	return num;
}

void wokerManger::Init_Emp() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//在这里不需要这个错误检测，错误检测已经在构造函数中进行了
	//if (!ifs.is_open()) {
	//	cout << "文件打开失败" << endl;
	//	return;
	//}

	//if (this->m_EmpNum <= 1) {
	//	cout << this->m_EmpNum << endl;
	//	cout << "未查到员工信息" << endl;
	//	return;
	//}

	this->m_EmpArray = new Worker * [this->m_EmpNum];

	int id;
	string name;
	int dId;

	for (int i = 0; i < this->m_EmpNum; i++) {
		//ifs >> id && ifs >> name && ifs >> dId;
		ifs >> id >> name >> dId;

		//根据部门号创建不同的对象
		switch (dId) {
		case 1:
			this->m_EmpArray[i] = new Employee(id,name,dId);
			break;
		case 2:
			this->m_EmpArray[i] = new Manager(id, name, dId);
			break;
		case 3:
			this->m_EmpArray[i] = new Boss(id, name, dId);
			break;
		default :
			break;
		}
	}
	
	ifs.close();
}


//显示文件中已有的员工的信息
void wokerManger::showEmpInfo() {

	//异常检测，如果文件列表为空，则直接退出
	if (this->m_EmpNum == 0) {
		cout << "暂无记录在案的员工信息...." << endl;
		clear();
		return;
	}

	for (int i = 0; i < this->get_EmpNum(); i++) {
		this->m_EmpArray[i]->showInfo();
	}
	clear();
}


//判断职工是否存在
int wokerManger::IsExit(int Id) {

	int index = -1;
	
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (Id == this->m_EmpArray[i]->m_Id) 
		{
			index = i;
			break;
		}
	}

	return index;
	
}

//删除职工
void wokerManger::Del_Emp() 
{
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或者为空 " << endl;
		return;
	}

	int del_num;
	cout << "请输入要删除的员工Id:";
	cin >> del_num;

	int ret = IsExit(del_num);
	if (ret == -1)
	{
		cout << "该员工不存在...." << endl;
	}
	else 
	{
		//删除员工

		for (int i = ret; i < this->m_EmpNum - 1; i++)
		{
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}
		this->m_EmpNum--;


		//将删除过后剩余的员工重新写入文件当中
		save();

		cout << "删除成功" << endl;
	}

	clear();
}

//修改职工
void wokerManger::Change_Emp() {
	
	int index;
	cout << "请输入要修改的员工的Id:" << endl;
	cin >> index;
	//判断该员工是否存在
	int ret = IsExit(index);
	if (ret == -1) 
	{
		cout << "该员工不存在!" << endl;
		clear();
	}
	else
	{
		int id;
		string name;
		int dId;

		cout << "请输入更改后员工的姓名:" << endl;
		cin >> name;

		cout << "请输入更改后员工的所属部门号:" << endl;
		cin >> dId;

		id = this->m_EmpArray[ret]->m_Id;

		//删除原来存储的信息，并根据员工所属部门重新创建一个对象
		delete this->m_EmpArray[ret];
		switch (dId) 
		{
		case 1:
			this->m_EmpArray[ret] = new Employee(id, name, dId);
			break;
		case 2:
			this->m_EmpArray[ret] = new Manager(id, name, dId);
			break;
		case 3:
			this->m_EmpArray[ret] = new Boss(id, name, dId);
			break;
		default:
			break;
		}

		save();

		clear();
	}
}

//查找职工
void wokerManger::Search_Emp()
{
	int index;
	cout << "请输入要查找的员工的Id:" << endl;
	cin >> index;

	int ret = IsExit(index);
	if (ret == -1) 
	{
		cout << "该员工不存在!" << endl;
		clear();
	}
	else
	{
		this->m_EmpArray[ret]->showInfo();
		clear();
	}

}

//职工排序
void wokerManger::SortEmpById() 
{
	cout << "根据员工Id对员工进行排序中..." << endl;
	Worker* temp;

	for (int i = 0; i < this->m_EmpNum; i++) 
	{
		for (int j = 0; j<this->m_EmpNum - i - 1 ; j++)
		{
			if (this->m_EmpArray[j]->m_Id > this->m_EmpArray[j +1]->m_Id)
			{
				temp = this->m_EmpArray[j];
				this->m_EmpArray[j] = this->m_EmpArray[j + 1];
				this->m_EmpArray[j + 1] = temp;
			}

		}
	}
	save();

	clear();

}

void wokerManger::DeleteAllEmp() 
{
	delete[] this->m_EmpArray;
	this->m_EmpArray = NULL;
	this->m_EmpNum = 0;
	save();
	cout << "已经成功清空所有记录" << endl;
	clear();
}