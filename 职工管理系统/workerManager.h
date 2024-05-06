#pragma once
#include<iostream>
using namespace std;
#include "worker.h"
#include<fstream>
#define FILENAME "empFile.txt"

class WorkerManager
{
public:
	//���캯��
	WorkerManager();

	//չʾ�˵�
	void Show_Menu();

	//�˳�����
	void ExitSystem();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArry;

	//���ְ��
	void AddEmp();

	//�ж��ļ��Ƿ�Ϊ��,��λture ,����λfalse
	bool m_FileIsEmpty;

	//ͳ���ļ�������
	int get_EmpNum();

	//д���ļ�
	void save();

	//��ʼ��ְ��
	void init_Emp();

	//��ʾԱ��
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//�ж�Ա���Ƿ����,������Ϊ-1
	int Is_Exist(int id);

	//�޸�ְ����Ϣ
	void Mod_Emp();

	//��ʾԱ����Ϣ
	void Find_Emp();

	//ʵ��Ա���������
	void Sort_Emp();

	//����ļ�
	void Clean_File();

	//��������
	~WorkerManager();

};