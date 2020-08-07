#pragma once	//��ֹͷ�ļ��ظ�����
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
	//���캯��
	wokerManger();

	//��������
	~wokerManger();

	//��������
	void clear();

	//չʾ�˵�
	void Show_Menu();

	//�˳�����
	void exitSystem();

	//���Ա��
	void add_Emp();

	//�����ݱ��浽�ļ���
	void save();

	//ͳ���ļ��м�¼������
	int get_EmpNum();

	//��ȡ�ļ��е�Ա������Ϣ
	void Init_Emp();

	//��ʾԱ����Ϣ
	void showEmpInfo();

	//�ж�ְ���Ƿ����
	int IsExit(int id);

	//ɾ��ְ�������ݱ��ɾ��ְ��
	void Del_Emp();

	//�޸�ְ��
	void Change_Emp();

	//����ְ��
	void Search_Emp();

	//ְ������
	void SortEmpById();

	//����ļ�
	void DeleteAllEmp();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//��־�ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

};

