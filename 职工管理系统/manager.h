#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Manager :public Worker {
public:
	//建立构造函数
	Manager(int Id,string Name,int dId);

	//显示个人信息
	void ShowInfo();

	//获取岗位信息
	string getDeptName();
};