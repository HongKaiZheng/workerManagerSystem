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
	//����
	//Worker* worker = new Employee(1, "����", 1);
	//worker->ShowInfo();
	//worker->getDeptName();

	//worker = new Manager(2, "����", 2);
	//worker->ShowInfo();
	//worker->getDeptName();

	//worker = new Boss(3, "����", 3);
	//worker->ShowInfo();
	//worker->getDeptName();

	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		//չʾ�˵�
		wm.Show_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice; //�洢�û�ѡ��
		switch (choice)
		{
		case 0: //�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1://����ְ��
			wm.AddEmp();
			break;
		case 2://��ʾְ��
			wm.Show_Emp();
			break;
		case 3://ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4://�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5://����Ա��
			wm.Find_Emp();
			break;
		case 6://����ְ��
			wm.Sort_Emp();
			break;
		case 7://����ĵ�
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