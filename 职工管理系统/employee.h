#pragma once
//普通员工文件
#include<iostream>
using namespace std;
#include "worker.h"

class Employee : public Worker
{
public:
	//构造函数
	Employee(int id ,string name,int dId);

	//显示个人信息
	void ShowInfo();
	//显示岗位信息
	string getDeptName();
};
