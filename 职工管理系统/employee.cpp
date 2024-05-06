#include<iostream>
using namespace std;
#include"employee.h"

//构造函数
Employee::Employee(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
};

//显示个人信息
void Employee:: ShowInfo() {
	cout << "职工编号: " << this->m_Id
		<< "\t职工姓名: " << this->m_Name
		<< "\t职工岗位: " << this->getDeptName() 
		<<"\t岗位职责: " << "当牛做马"
		<< endl;
};
//显示岗位信息
string Employee:: getDeptName() {
	return "员工";
};