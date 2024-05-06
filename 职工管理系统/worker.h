#pragma once
#include<iostream>
using namespace std;

//职工抽象类
class Worker
{
public:
	//显示个人信息
	virtual void ShowInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;
	//员工编号
	int m_Id;
	//员工姓名
	string m_Name;
	//部门编号
	int m_DeptId;
};