#pragma once
#include<iostream>
using namespace std;

//ְ��������
class Worker
{
public:
	//��ʾ������Ϣ
	virtual void ShowInfo() = 0;
	//��ȡ��λ����
	virtual string getDeptName() = 0;
	//Ա�����
	int m_Id;
	//Ա������
	string m_Name;
	//���ű��
	int m_DeptId;
};