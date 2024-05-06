#include<iostream>
using namespace std;
#include"boss.h"

Boss::Boss(int id,string name,int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

//显示个人信息
void Boss::ShowInfo()
{
	cout << "职工编号: " << this->m_Id
		<< "\t职工姓名: " << this->m_Name
		<< "\t职工岗位: " << this->getDeptName()
		<< "\t岗位职责: " << "俺说了算"
		<< endl;
}
//获取岗位
string Boss::getDeptName()
{
	return "老板";
}