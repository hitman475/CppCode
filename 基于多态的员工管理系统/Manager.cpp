#include "Manager.h"


//构造函数
Manager::Manager(int id, string name, int did) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_depId = did;
}

//显示个人信息
void Manager::showInfo() {
    cout << "--------输出经理信息--------" << endl;
    cout << "职工姓名:" << this->m_Name << endl;
    cout << "职工编号:" << this->m_Id << endl;
    cout << "部门编号:" << this->getDeptName() << endl;
    cout << "员工任务：管理人员" << endl;
}

//获取岗位信息
string Manager::getDeptName() {
	return string("经理");
}