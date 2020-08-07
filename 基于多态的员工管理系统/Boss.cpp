#include "Boss.h"

//构造函数
Boss::Boss(int id, string name, int did) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_depId = did;
}


//显示个人信息
void Boss::showInfo() {
    cout << "--------输出老板信息--------" << endl;
    cout << "职工姓名:" << this->m_Name << endl;
    cout << "职工编号:" << this->m_Id << endl;
    cout << "部门编号:" << this->getDeptName() << endl;
    cout << "员工任务：剥削底层员工" << endl;
}

//获取岗位信息
string Boss::getDeptName() {
    return string("老板");
}
