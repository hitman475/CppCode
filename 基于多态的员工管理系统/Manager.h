#pragma once
#include "Worker.h"

//������
class Manager : public Worker
{
public:
	//���캯��
	Manager(int id, string name, int did);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ�����λ��Ϣ
	virtual string getDeptName();

};

