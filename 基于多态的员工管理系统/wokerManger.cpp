#include "wokerManger.h"

wokerManger::wokerManger() 
{
	//1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2.�ļ����ڣ�����û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.�ļ����ڣ������ļ��м�¼������
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ:" << num << endl;
	this->m_EmpNum = num;
	this->m_FileIsEmpty = false;
	this->m_EmpArray = NULL;

	//���ļ��ж�ȡ���ݣ���ʼ������
	this->Init_Emp();
}

wokerManger::~wokerManger() 
{
	if (this->m_EmpArray != NULL) {
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

//��������
void wokerManger::clear() {
	system("pause");
	system("cls");
}


//չʾ�˵�
void wokerManger::Show_Menu()
{
	cout << "**************************************" << endl;
	cout << "********* ��ӭʹ��ְ������ϵͳ *******" << endl;
	cout << "************ 0.�˳�������� **********" << endl;
	cout << "************ 1.����ְ����Ϣ **********" << endl;
	cout << "************ 2.��ʾְ����Ϣ **********" << endl;
	cout << "************ 3.ɾ����ְְ�� **********" << endl;
	cout << "************ 4.�޸�ְ����Ϣ **********" << endl;
	cout << "************ 5.����ְ����Ϣ **********" << endl;
	cout << "************ 6.���ձ������ **********" << endl;
	cout << "************ 7.��������ĵ� **********" << endl;
	cout << "**************************************" << endl;
	cout << endl;

}

//�˳�ϵͳ
void wokerManger::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	clear();
	exit(0);
}

//���Ա��
void wokerManger::add_Emp() {

	cout << "��������ӵ�Ա��������:" << endl;

	int addNum = 0;	//�����û�����������
	cin >> addNum;

	if (addNum > 0) 
	{
		//���
		//��������¿ռ�Ĵ�С
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker ** newSpace = new Worker * [newSize];

		//��ԭ���ռ��µ����ݿ�����newSpace��
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//�������������
		for (int i = 0; i < addNum; i++) {
			int id;	//ְ�����
			string name;	//ְ������
			int dSelect;	//����ѡ��

			cout << "---����ӵ�" << i + 1 << "��Ա��----" << endl;
			cout << "������ְ�����:";
			cin >> id;
			cout << "����������:";
			cin >> name;
			cout << "�����벿�ţ� 1.Ա��\t2.����\t3.�ϰ�" << endl;
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

		//�ͷ�ԭ�еĿռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "��ְ��" << endl;

		//����ְ����Ϊ�յı�־
		this->m_FileIsEmpty = false;

		//���ڴ��е����ݴ洢���ļ���
		save();

		clear();
		
	}
	else 
	{
		cout << "������������" << endl;

		clear();

		return;
	}

}

//�������ݵ��ļ�
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
	ifs.open(FILENAME, ios::in);	//���ļ���ȡ

	int id;
	string name;
	int dId;

	//ͳ����������
	int num = 0;

	//���ļ��ж�ȡһ������
	while (ifs >> id >> name >> dId) {
		num++;
	}

	return num;
}

void wokerManger::Init_Emp() {

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	//�����ﲻ��Ҫ��������⣬�������Ѿ��ڹ��캯���н�����
	//if (!ifs.is_open()) {
	//	cout << "�ļ���ʧ��" << endl;
	//	return;
	//}

	//if (this->m_EmpNum <= 1) {
	//	cout << this->m_EmpNum << endl;
	//	cout << "δ�鵽Ա����Ϣ" << endl;
	//	return;
	//}

	this->m_EmpArray = new Worker * [this->m_EmpNum];

	int id;
	string name;
	int dId;

	for (int i = 0; i < this->m_EmpNum; i++) {
		//ifs >> id && ifs >> name && ifs >> dId;
		ifs >> id >> name >> dId;

		//���ݲ��źŴ�����ͬ�Ķ���
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


//��ʾ�ļ������е�Ա������Ϣ
void wokerManger::showEmpInfo() {

	//�쳣��⣬����ļ��б�Ϊ�գ���ֱ���˳�
	if (this->m_EmpNum == 0) {
		cout << "���޼�¼�ڰ���Ա����Ϣ...." << endl;
		clear();
		return;
	}

	for (int i = 0; i < this->get_EmpNum(); i++) {
		this->m_EmpArray[i]->showInfo();
	}
	clear();
}


//�ж�ְ���Ƿ����
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

//ɾ��ְ��
void wokerManger::Del_Emp() 
{
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ���Ϊ�� " << endl;
		return;
	}

	int del_num;
	cout << "������Ҫɾ����Ա��Id:";
	cin >> del_num;

	int ret = IsExit(del_num);
	if (ret == -1)
	{
		cout << "��Ա��������...." << endl;
	}
	else 
	{
		//ɾ��Ա��

		for (int i = ret; i < this->m_EmpNum - 1; i++)
		{
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}
		this->m_EmpNum--;


		//��ɾ������ʣ���Ա������д���ļ�����
		save();

		cout << "ɾ���ɹ�" << endl;
	}

	clear();
}

//�޸�ְ��
void wokerManger::Change_Emp() {
	
	int index;
	cout << "������Ҫ�޸ĵ�Ա����Id:" << endl;
	cin >> index;
	//�жϸ�Ա���Ƿ����
	int ret = IsExit(index);
	if (ret == -1) 
	{
		cout << "��Ա��������!" << endl;
		clear();
	}
	else
	{
		int id;
		string name;
		int dId;

		cout << "��������ĺ�Ա��������:" << endl;
		cin >> name;

		cout << "��������ĺ�Ա�����������ź�:" << endl;
		cin >> dId;

		id = this->m_EmpArray[ret]->m_Id;

		//ɾ��ԭ���洢����Ϣ��������Ա�������������´���һ������
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

//����ְ��
void wokerManger::Search_Emp()
{
	int index;
	cout << "������Ҫ���ҵ�Ա����Id:" << endl;
	cin >> index;

	int ret = IsExit(index);
	if (ret == -1) 
	{
		cout << "��Ա��������!" << endl;
		clear();
	}
	else
	{
		this->m_EmpArray[ret]->showInfo();
		clear();
	}

}

//ְ������
void wokerManger::SortEmpById() 
{
	cout << "����Ա��Id��Ա������������..." << endl;
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
	cout << "�Ѿ��ɹ�������м�¼" << endl;
	clear();
}