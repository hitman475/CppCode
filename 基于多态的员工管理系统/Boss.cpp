#include "Boss.h"

//���캯��
Boss::Boss(int id, string name, int did) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_depId = did;
}


//��ʾ������Ϣ
void Boss::showInfo() {
    cout << "--------����ϰ���Ϣ--------" << endl;
    cout << "ְ������:" << this->m_Name << endl;
    cout << "ְ�����:" << this->m_Id << endl;
    cout << "���ű��:" << this->getDeptName() << endl;
    cout << "Ա�����񣺰����ײ�Ա��" << endl;
}

//��ȡ��λ��Ϣ
string Boss::getDeptName() {
    return string("�ϰ�");
}
