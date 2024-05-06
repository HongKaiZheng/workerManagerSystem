#include<iostream>
using namespace std;
#include "manager.h"

Manager::Manager(int id,string name,int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Manager::ShowInfo()
{
	cout << "职工编号: " << this->m_Id
		<< "\t职工姓名: " << this->m_Name
		<< "\t职工岗位: " << this->getDeptName()
		<< "\t岗位职责: " << "给老板当牛做马"
		<< endl;
}

string Manager::getDeptName()
{
	return "经理";
}