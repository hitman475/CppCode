#include "Employee.h"

Employee::Employee(int id, string name, int did) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_depId = did; 
}

void Employee::showInfo() {
    cout << "--------���Ա����Ϣ--------" << endl;
    cout << "ְ������:" << this->m_Name << endl;
    cout << "ְ�����:" << this->m_Id << endl;
    cout << "���ű��:" << this->getDeptName() << endl;
    cout << "Ա�����񣺰�ʱ��ɷ�������" << endl;
}

 string Employee::getDeptName() {
     return "Ա��";
}