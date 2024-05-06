#pragma once
#include<iostream>
using namespace std;
#include "worker.h"
#include<fstream>
#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	//构造函数
	WorkerManager();

	//展示菜单
	void Show_Menu();

	//退出功能
	void ExitSystem();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArry;

	//添加职工
	void AddEmp();

	//判断文件是否为空,空位ture ,不空位false
	bool m_FileIsEmpty;

	//统计文件中人数
	int get_EmpNum();

	//写入文件
	void save();

	//初始化职工
	void init_Emp();

	//显示员工
	void Show_Emp();

	//删除职工
	void Del_Emp();

	//判断员工是否存在,不存在为-1
	int Is_Exist(int id);

	//修改职工信息
	void Mod_Emp();

	//显示员工信息
	void Find_Emp();

	//实现员工编号排序
	void Sort_Emp();

	//清空文件
	void Clean_File();

	//析构函数
	~WorkerManager();

};