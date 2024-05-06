#pragma once
#include<iostream>
using namespace std;
#include"worker.h"

class Boss:public Worker {
public:
	//建立构建函数
	Boss(int id, string name, int dId);
	
	//显示个人信息
	void ShowInfo();
	//获取岗位信息
	string getDeptName();
	
};