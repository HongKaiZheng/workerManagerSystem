#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

WorkerManager::WorkerManager() {
	//��ʼ������

	//1,�ļ������ڵ����
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArry = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ�����,��Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��!" << endl;
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArry = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ������Ҳ�Ϊ��
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ:" << num << endl;
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArry = new Worker * [this->m_EmpNum];
	//���ļ��е�����д�뵽������
	this->init_Emp();

	//�����Ƿ�д��ɹ�
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "ְ�����Ϊ: " << this->m_EmpArry[i]->m_Id
	//		<< "���� :" << this->m_EmpArry[i]->m_Name
	//		<< "���ű��Ϊ:" << this->m_EmpArry[i]->m_DeptId << endl;
	//}
};



//�˵���ʾ����
void WorkerManager::Show_Menu() {
	cout << "**************************************" << endl;
	cout << "*********��ӭʹ��ְ������ϵͳ*********" << endl;
	cout << "**********  0.�˳��������  **********" << endl;
	cout << "**********  1.����ְ����Ϣ  **********" << endl;
	cout << "**********  2.��ʾְ����Ϣ  **********" << endl;
	cout << "**********  3.ɾ����ְְ��  **********" << endl;
	cout << "**********  4.�޸�ְ����Ϣ  **********" << endl;
	cout << "**********  5.����ְ����Ϣ  **********" << endl;
	cout << "**********  6.���ձ������  **********" << endl;
	cout << "**********  7.��������ĵ�  **********" << endl;
	cout << "**************************************" << endl;
	cout << endl;
}

//�˳�����
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//���ְ��
void WorkerManager::AddEmp()
{
	cout << "��������Ҫ���Ա��������" << endl;
	int addNum = 0; //�����û�������
	cin >> addNum;
	
	if (addNum > 0) {
		//��Ӳ���
		//������ӵĿռ��С
		int newSize = this->m_EmpNum + addNum;	//�¿ռ����� = ԭ���ռ� + �����ռ�
		
		//���¿ռ�����ַ
		Worker** newSpace = new Worker * [newSize];

		if (this->m_EmpArry != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArry[i];
			}
		}

		//�������
		for (int i = 0; i < addNum; i++) {
			//ְ�����
			int id;
			//ְ������
			string name;
			//ְ����λ
			int dSelect;

			cout << "�������" << i + 1 << "��Ա����� : " << endl;
			cin >> id;
			cout << "�������" << i + 1 << "��Ա������ : " << endl;
			cin >> name;
			cout << "��ѡ���Ա����λ : " << endl;
			cout << "1,��ͨԱ��" << endl;
			cout << "2,����" << endl;
			cout << "3,�ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			///������ְ��ְ��,���浽������
			newSpace[this->m_EmpNum + i] = worker;

		}
		//�ͷžɿռ��ڴ�
		delete[] this->m_EmpArry;

		//�����¿ռ�ָ��
		this->m_EmpArry = newSpace;

		//������ְ������
		this->m_EmpNum = newSize;

		//��ʾ��ӳɹ�
		cout << "��ӳɹ�" << addNum << "λְ��" << endl;

		//��־�ļ���Ϊ��
		this->m_FileIsEmpty = false;

		//�������ݵ��ļ���
		this->save();

	}
	else {
		cout << "��������" << endl;
	}
	//������������ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

//�����ݱ��浽�ı���
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArry[i]->m_Id << " "
			<< this->m_EmpArry[i]->m_Name << " "
			<< this->m_EmpArry[i]->m_DeptId << endl;
	}
	ofs.close();
}

//ͳ���ļ��е�����
int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		num++;
	}
	return num;
}

//��ʼ��Ա��
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;
		if (dId == 1) {//��ְͨ��
			worker = new Employee(id, name, dId);
		}
		else if(dId == 2) {//����
			worker = new Manager(id, name, dId);
		}
		else {//�ϰ�
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArry[index] = worker;
		index++;
	}
	ifs.close();
}

//��ʾԱ��
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
	}
	else {
		for (int i = 0; i < m_EmpNum; i++) {
			this->m_EmpArry[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}

//ɾ��ְ��
void WorkerManager::Del_Emp() {
	//���ж��ļ��Ƿ����
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
	}
	else {
		//���û�������Ҫɾ����Ա�����
		cout << "��������Ҫɾ����Ա���ı��" << endl;
		int id = -1;
		cin >> id;
		int index = this->Is_Exist(id);
		if (index != -1) { //˵��Ա������
			//����ǰ��
			for (int i = index; i < this->m_EmpNum - 1; i++) {
								   //(this->m_EmpNum - 1)�����±����һ��Ϊ����һ��������1
				this->m_EmpArry[i] = this->m_EmpArry[i + 1];
			}
			this->m_EmpNum--;//���������м�¼����Ա����
			this->save();//ͬ�����ļ���
			cout << "ɾ���ɹ�" << endl;
		}
		else {
			cout << "ɾ��ʧ��,δ�ҵ���Ա��" << endl;
		}

	}
	system("pause");
	system("cls");
}

//ʹ��id���ж�Ա���Ƿ����
int WorkerManager::Is_Exist(int id) {

	int index = -1;
	//ʹ��ְ����Ž����ж�,�����򷵻�idֵ,�����ھͷ���-1
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArry[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//�޸�Ա����Ϣ(
void WorkerManager::Mod_Emp() {
	//���ж��ļ��Ƿ����
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��ļ�Ϊ��" << endl;
	}
	else {
		cout << "��������Ҫ�޸�Ա���ı��:" << endl;
		int id;
		cin >> id;
		int ret = this->Is_Exist(id);
		//Ա������
		if (ret != -1) {
			//�ͷ�ԭ���Ŀռ�
			delete this->m_EmpArry[ret];

			//��ʼ����Ҫ�޸ĵ�Ա��������
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			//����Ҫ�޸ĵ�Ա�������ݽ��и�ֵ
			cout << "�鵽id��Ϊ:" << id << "��Ա��,������Ա���µ�id:" << endl;
			cin >> newId;
			cout << "������Ա��������:" << endl;
			cin >> newName;

			cout << "�������¸�λ:" << endl;
			cout << "1,Ա��" << endl;
			cout << "2,����" << endl;
			cout << "3,�ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			//�������ݵ�������
			this->m_EmpArry[ret] = worker;

			cout << "�޸ĳɹ�" << endl;

			//д�뵽�ļ���
			this->save();

		}
		else {
			cout << "�޸�ʧ��,δ�ҵ���Ա��" << endl;
		}

	}
	system("pause");
	system("cls");
}

//��ʾԱ����Ϣ

void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else {
		cout << "��������Ҫ���ҵķ�ʽ" << endl;
		cout << "1,ʹ��id�Ž��в���" << endl;
		cout << "2,ʹ���������в���" << endl;
		int inp;
		cin >> inp;
		switch (inp)
		{
		case 1:
			{
				int f_id;
				cout << "��������Ҫ���ҵ�id" << endl;
				cin >> f_id;
				if (this->Is_Exist(f_id) != -1) {
					cout << "�û�idΪ:" << f_id << "��Ա����Ϣ����:" << endl;
					this->m_EmpArry[f_id-1]->ShowInfo();
				}
				else {
					cout << "��Ҫ���ҵ��û�������" << endl;
				}
				break;
			}
	
		case 2:
		{
			string f_name;
			cout << "��������Ҫ���ҵ�����" << endl;
			cin >> f_name;
			//ʹ��һ��������������Ϊ���ҵ��ı�ʶ
			bool Signal = false;
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArry[i]->m_Name == f_name) {
					cout << "���ҵ�ְ�����Ϊ:" << m_EmpArry[i]->m_Id << "\t��Ա����Ϣ����:" << endl;
					this->m_EmpArry[i]->ShowInfo();
					Signal = true;
				}
			}
			if (Signal == false) {
				cout << "δ�ҵ����û���Ϣ" << endl;
			}
			break;
		}
		default:
			cout << "��������" << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}

//ʵ��Ա���������
void WorkerManager::Sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "������Ҫ����ķ�ʽ" << endl;
		cout << "1,��ְ���Ž�����������" << endl;
		cout << "2,��ְ���Ž��н�������" << endl;
		int inSort;
		cin >> inSort;
		switch (inSort)
		{
		case 1:
		{for (int i = 0; i < m_EmpNum; i++) {
			int SortMax = i;
			for (int j = i + 1; j < m_EmpNum; j++) {
				if (this->m_EmpArry[SortMax]->m_Id > this->m_EmpArry[j]->m_Id) {
					SortMax = j;
				}
			}
			if (i != SortMax) {
				Worker* temp = this->m_EmpArry[i];
				this->m_EmpArry[i] = this->m_EmpArry[SortMax];
				this->m_EmpArry[SortMax] = temp;
			}
		}
		cout << "����ɹ�" << endl;
		this->save();
		this->Show_Emp();
		break; }
		case 2:
		{for (int i = 0; i < m_EmpNum; i++) {
			int SortMin = i;
			for (int j = i + 1; j < m_EmpNum; j++) {
				if (this->m_EmpArry[SortMin]->m_Id < this->m_EmpArry[j]->m_Id) {
					SortMin = j;
				}
			}
			if (i != SortMin) {
				Worker* temp = this->m_EmpArry[i];
				this->m_EmpArry[i] = this->m_EmpArry[SortMin];
				this->m_EmpArry[SortMin] = temp;
			}
		}
		cout << "����ɹ�" << endl;
		this->save();
		this->Show_Emp();
		break; }
		default:
			cout << "��������,����������" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//����ļ�����
void WorkerManager::Clean_File() {
	cout << "���ٴ�ȷ���Ƿ�����ļ�" << endl;
	cout << "��1ȷ��ɾ��" << endl;
	cout << "��2����" << endl;
	int select;
	cin >> select;

	if (select == 1) {
		//����ļ�
		ofstream ofs(FILENAME, ios::trunc); //ʹ��trunc��ʽ��,��������ļ�����,�ͻ�����ļ����´���
		ofs.close();
		//�Ѷ����Ŀռ��ͷŵ�
		if (this->m_EmpArry != NULL) {
			for (int i = 0; i < m_EmpNum; i++) {
					delete this->m_EmpArry[i];
					this->m_EmpArry[i] != NULL;
			}
			delete[] this->m_EmpArry;
			this->m_EmpArry = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "�ļ���ճɹ�" << endl;

	}
	system("pause");
	system("cls");

}



//��������
WorkerManager::~WorkerManager() {
	//�Ѷ����Ŀռ��ͷŵ�
	if (this->m_EmpArry != NULL) {
		for (int i = 0; i < m_EmpNum; i++) {
			if (this->m_EmpArry[i] != NULL) {
				delete this->m_EmpArry[i];
			}
		}
		delete[] this->m_EmpArry;
		this->m_EmpArry = NULL;
	}
};