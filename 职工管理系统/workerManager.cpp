#include"workerManager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"

WorkerManager::WorkerManager() {
	//初始化数据

	//1,文件不存在的情况
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "文件不存在" << endl;
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArry = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在,但为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空!" << endl;
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArry = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在且不为空
	int num = this->get_EmpNum();
	cout << "职工人数为:" << num << endl;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArry = new Worker * [this->m_EmpNum];
	//将文件中的数据写入到数组中
	this->init_Emp();

	//测试是否写入成功
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "职工编号为: " << this->m_EmpArry[i]->m_Id
	//		<< "姓名 :" << this->m_EmpArry[i]->m_Name
	//		<< "部门编号为:" << this->m_EmpArry[i]->m_DeptId << endl;
	//}
};



//菜单显示功能
void WorkerManager::Show_Menu() {
	cout << "**************************************" << endl;
	cout << "*********欢迎使用职工管理系统*********" << endl;
	cout << "**********  0.退出管理程序  **********" << endl;
	cout << "**********  1.增加职工信息  **********" << endl;
	cout << "**********  2.显示职工信息  **********" << endl;
	cout << "**********  3.删除离职职工  **********" << endl;
	cout << "**********  4.修改职工信息  **********" << endl;
	cout << "**********  5.查找职工信息  **********" << endl;
	cout << "**********  6.按照编号排序  **********" << endl;
	cout << "**********  7.清空所有文档  **********" << endl;
	cout << "**************************************" << endl;
	cout << endl;
}

//退出功能
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//添加职工
void WorkerManager::AddEmp()
{
	cout << "请输入你要添加员工的数量" << endl;
	int addNum = 0; //保存用户的输入
	cin >> addNum;
	
	if (addNum > 0) {
		//添加操作
		//计算添加的空间大小
		int newSize = this->m_EmpNum + addNum;	//新空间人数 = 原来空间 + 新增空间
		
		//给新空间分配地址
		Worker** newSpace = new Worker * [newSize];

		if (this->m_EmpArry != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArry[i];
			}
		}

		//批量添加
		for (int i = 0; i < addNum; i++) {
			//职工编号
			int id;
			//职工姓名
			string name;
			//职工岗位
			int dSelect;

			cout << "请输入第" << i + 1 << "新员工编号 : " << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "新员工姓名 : " << endl;
			cin >> name;
			cout << "请选择该员工岗位 : " << endl;
			cout << "1,普通员工" << endl;
			cout << "2,经理" << endl;
			cout << "3,老板" << endl;
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
			///将创建职工职责,保存到数组中
			newSpace[this->m_EmpNum + i] = worker;

		}
		//释放旧空间内存
		delete[] this->m_EmpArry;

		//跟新新空间指向
		this->m_EmpArry = newSpace;

		//更新新职工人数
		this->m_EmpNum = newSize;

		//提示添加成功
		cout << "添加成功" << addNum << "位职工" << endl;

		//标志文件不为空
		this->m_FileIsEmpty = false;

		//保存数据到文件中
		this->save();

	}
	else {
		cout << "输入有误" << endl;
	}
	//按任意键清屏回到上级目录
	system("pause");
	system("cls");
}

//把数据保存到文本中
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

//统计文件中的人数
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

//初始化员工
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
		if (dId == 1) {//普通职工
			worker = new Employee(id, name, dId);
		}
		else if(dId == 2) {//经理
			worker = new Manager(id, name, dId);
		}
		else {//老板
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArry[index] = worker;
		index++;
	}
	ifs.close();
}

//显示员工
void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或文件为空" << endl;
	}
	else {
		for (int i = 0; i < m_EmpNum; i++) {
			this->m_EmpArry[i]->ShowInfo();
		}
	}
	system("pause");
	system("cls");
}

//删除职工
void WorkerManager::Del_Emp() {
	//先判断文件是否存在
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或文件为空" << endl;
	}
	else {
		//让用户输入想要删除的员工编号
		cout << "请输入想要删除的员工的编号" << endl;
		int id = -1;
		cin >> id;
		int index = this->Is_Exist(id);
		if (index != -1) { //说明员工存在
			//数据前移
			for (int i = index; i < this->m_EmpNum - 1; i++) {
								   //(this->m_EmpNum - 1)数据下标最后一个为最后的一个人数减1
				this->m_EmpArry[i] = this->m_EmpArry[i + 1];
			}
			this->m_EmpNum--;//更新数组中记录的人员个数
			this->save();//同步到文件中
			cout << "删除成功" << endl;
		}
		else {
			cout << "删除失败,未找到该员工" << endl;
		}

	}
	system("pause");
	system("cls");
}

//使用id号判断员工是否存在
int WorkerManager::Is_Exist(int id) {

	int index = -1;
	//使用职工编号进行判断,存在则返回id值,不存在就返回-1
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArry[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

//修改员工信息(
void WorkerManager::Mod_Emp() {
	//先判断文件是否存在
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或文件为空" << endl;
	}
	else {
		cout << "请输入需要修改员工的编号:" << endl;
		int id;
		cin >> id;
		int ret = this->Is_Exist(id);
		//员工存在
		if (ret != -1) {
			//释放原来的空间
			delete this->m_EmpArry[ret];

			//初始化想要修改的员工的数据
			int newId = 0;
			string newName = "";
			int dSelect = 0;

			//对想要修改的员工的数据进行赋值
			cout << "查到id号为:" << id << "的员工,请输入员工新的id:" << endl;
			cin >> newId;
			cout << "请输入员工新名字:" << endl;
			cin >> newName;

			cout << "请输入新岗位:" << endl;
			cout << "1,员工" << endl;
			cout << "2,经理" << endl;
			cout << "3,老板" << endl;
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
			//更新数据到数组中
			this->m_EmpArry[ret] = worker;

			cout << "修改成功" << endl;

			//写入到文件中
			this->save();

		}
		else {
			cout << "修改失败,未找到该员工" << endl;
		}

	}
	system("pause");
	system("cls");
}

//显示员工信息

void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		cout << "请输入你要查找的方式" << endl;
		cout << "1,使用id号进行查找" << endl;
		cout << "2,使用姓名进行查找" << endl;
		int inp;
		cin >> inp;
		switch (inp)
		{
		case 1:
			{
				int f_id;
				cout << "请输入你要查找的id" << endl;
				cin >> f_id;
				if (this->Is_Exist(f_id) != -1) {
					cout << "用户id为:" << f_id << "的员工信息如下:" << endl;
					this->m_EmpArry[f_id-1]->ShowInfo();
				}
				else {
					cout << "你要查找的用户不存在" << endl;
				}
				break;
			}
	
		case 2:
		{
			string f_name;
			cout << "请输入你要查找的姓名" << endl;
			cin >> f_name;
			//使用一个布尔类型来作为查找到的标识
			bool Signal = false;
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArry[i]->m_Name == f_name) {
					cout << "查找到职工编号为:" << m_EmpArry[i]->m_Id << "\t的员工信息如下:" << endl;
					this->m_EmpArry[i]->ShowInfo();
					Signal = true;
				}
			}
			if (Signal == false) {
				cout << "未找到该用户信息" << endl;
			}
			break;
		}
		default:
			cout << "输入有误" << endl;
			break;
		}
	}
	system("pause");
	system("cls");
}

//实现员工编号排序
void WorkerManager::Sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或记录为空" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "请输入要排序的方式" << endl;
		cout << "1,按职工号进行升序排序" << endl;
		cout << "2,按职工号进行降序排序" << endl;
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
		cout << "排序成功" << endl;
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
		cout << "排序成功" << endl;
		this->save();
		this->Show_Emp();
		break; }
		default:
			cout << "输入有误,请重新输入" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}

//清空文件操作
void WorkerManager::Clean_File() {
	cout << "请再次确认是否清空文件" << endl;
	cout << "按1确认删除" << endl;
	cout << "按2返回" << endl;
	int select;
	cin >> select;

	if (select == 1) {
		//清空文件
		ofstream ofs(FILENAME, ios::trunc); //使用trunc方式打开,就是如果文件存在,就会清空文件重新创建
		ofs.close();
		//把堆区的空间释放掉
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
		cout << "文件清空成功" << endl;

	}
	system("pause");
	system("cls");

}



//析构调用
WorkerManager::~WorkerManager() {
	//把堆区的空间释放掉
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