#include "Manager.h"


//���캯��
Manager::Manager(int id, string name, int did) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_depId = did;
}

//��ʾ������Ϣ
void Manager::showInfo() {
    cout << "--------���������Ϣ--------" << endl;
    cout << "ְ������:" << this->m_Name << endl;
    cout << "ְ�����:" << this->m_Id << endl;
    cout << "���ű��:" << this->getDeptName() << endl;
    cout << "Ա�����񣺹�����Ա" << endl;
}

//��ȡ��λ��Ϣ
string Manager::getDeptName() {
	return string("����");
}