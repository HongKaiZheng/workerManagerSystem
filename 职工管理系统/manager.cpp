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
	cout << "ְ�����: " << this->m_Id
		<< "\tְ������: " << this->m_Name
		<< "\tְ����λ: " << this->getDeptName()
		<< "\t��λְ��: " << "���ϰ嵱ţ����"
		<< endl;
}

string Manager::getDeptName()
{
	return "����";
}