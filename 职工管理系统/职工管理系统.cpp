#include<iostream>
#include"workerManager.h"
using namespace std;
#include "worker.h"
#include "employee.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"



int main()
{
	//测试
	//Worker* worker = new Employee(1, "张三", 1);
	//worker->ShowInfo();
	//worker->getDeptName();

	//worker = new Manager(2, "李四", 2);
	//worker->ShowInfo();
	//worker->getDeptName();

	//worker = new Boss(3, "王五", 3);
	//worker->ShowInfo();
	//worker->getDeptName();

	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		//展示菜单
		wm.Show_Menu();
		cout << "请输入你的选择" << endl;
		cin >> choice; //存储用户选择
		switch (choice)
		{
		case 0: //退出系统
			wm.ExitSystem();
			break;
		case 1://增加职工
			wm.AddEmp();
			break;
		case 2://显示职工
			wm.Show_Emp();
			break;
		case 3://删除职工
			wm.Del_Emp();
			break;
		case 4://修改职工
			wm.Mod_Emp();
			break;
		case 5://查找员工
			wm.Find_Emp();
			break;
		case 6://排序职工
			wm.Sort_Emp();
			break;
		case 7://清空文档
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}