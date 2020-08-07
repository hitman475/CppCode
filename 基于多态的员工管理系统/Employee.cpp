#include "Employee.h"

Employee::Employee(int id, string name, int did) {
    this->m_Id = id;
    this->m_Name = name;
    this->m_depId = did; 
}

void Employee::showInfo() {
    cout << "--------输出员工信息--------" << endl;
    cout << "职工姓名:" << this->m_Name << endl;
    cout << "职工编号:" << this->m_Id << endl;
    cout << "部门编号:" << this->getDeptName() << endl;
    cout << "员工任务：按时完成分配任务" << endl;
}

 string Employee::getDeptName() {
     return "员工";
}