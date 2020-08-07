#pragma once	//防止头文件重复包含
#include <iostream>	
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
#include <fstream>
#define FILENAME "employee.txt"
using namespace std;

class wokerManger
{
public:
	//构造函数
	wokerManger();

	//析构函数
	~wokerManger();

	//清屏函数
	void clear();

	//展示菜单
	void Show_Menu();

	//退出功能
	void exitSystem();

	//添加员工
	void add_Emp();

	//将数据保存到文件中
	void save();

	//统计文件中记录的人数
	int get_EmpNum();

	//获取文件中的员工的信息
	void Init_Emp();

	//显示员工信息
	void showEmpInfo();

	//判断职工是否存在
	int IsExit(int id);

	//删除职工，根据编号删除职工
	void Del_Emp();

	//修改职工
	void Change_Emp();

	//查找职工
	void Search_Emp();

	//职工排序
	void SortEmpById();

	//清空文件
	void DeleteAllEmp();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//标志文件是否为空
	bool m_FileIsEmpty;

};

