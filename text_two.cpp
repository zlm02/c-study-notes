/*
职工管理系统可以用来管理公司内所有员工的信息
本教程主要利用C++来实现一个基于多态的职工管理系统
公司中职工分为三类：普通员工、经理、老板，显示信息时，需要显示职工编号、职工姓名、职工岗位、以及职责
普通员工职责：完成经理交给的任务
经理职责：完成老板交给的任务，并下发任务给员工
老板职责：管理公司所有事务
管理系统中需要实现的功能如下：
退出管理程序：退出当前管理系统
增加职工信息：实现批量添加职工功能，将信息录入到文件中，职工信息为：职工编号、姓名、部门编号
显示职工信息：显示公司内部所有职工的信息
删除离职职工：按照编号删除指定的职工
修改职工信息：按照编号修改职工个人信息
查找职工信息：按照职工的编号或者职工的姓名进行查找相关的人员信息
按照编号排序：按照职工编号，进行排序，排序规则由用户指定
清空所有文档：清空文件中记录的所有职工信息 （清空前需要再次确认，防止误删）
 */
#include"text_two.h"

WorkerManager::WorkerManager() {
 //1\文件不存在
 ifstream ifs;
 ifs.open("FILENAME",ios::in);//打开文件，判断文件是否存在
 if (!ifs.is_open()) {
  cout<<"文件不存在"<<endl;
  //初始化属性
  //初始化职工人数为0
  this->m_EmpNum=0;
  //初始化职工数组指针为空NULL
  this->m_EmpArray=NULL;
  //初始化文件是否为空为true
  this->m_FileIsEmpty=true;
  ifs.close();
  return;
 }

}
//展示菜单
 void WorkerManager::Show_Menu()
 {
  cout << "********************************************" << endl;
  cout << "*********  欢迎使用职工管理系统！ **********" << endl;
  cout << "*************  0.退出管理程序  *************" << endl;
  cout << "*************  1.增加职工信息  *************" << endl;
  cout << "*************  2.显示职工信息  *************" << endl;
  cout << "*************  3.删除离职职工  *************" << endl;
  cout << "*************  4.修改职工信息  *************" << endl;
  cout << "*************  5.查找职工信息  *************" << endl;
  cout << "*************  6.按照编号排序  *************" << endl;
  cout << "*************  7.清空所有文档  *************" << endl;
  cout << "********************************************" << endl;
  cout << endl;
 }
//退出系统
void WorkerManager::ExitSystem() {
 cout<<"欢迎下次使用"<<endl;
 cin.ignore(numeric_limits<streamsize>::max(), '\n');
 cout << "请按enter键继续..." << endl;
 cin.get();
 exit(0);//退出程序
}
//添加职工
void WorkerManager::Add_Emp() {
 cout<<"请输入添加职工数量："<<endl;
 int addNum=0;
 cin>>addNum;
 if (addNum>0) {
  //添加职工
  //计算添加空间大小
  int newSize=this->m_EmpNum+addNum;//新空间人数=原来记录人数+新添加人数。
  //申请新空间
  Worker **newSpace= new Worker*[newSize];
  //将原来空间下的数据，拷贝到新空间
  if (this->m_EmpArray!=NULL) {
   for (int i=0;i<this->m_EmpNum;i++) {
    newSpace[i]=this->m_EmpArray[i];
   }
  }
  //添加新数据
  for (int i=0;i<addNum;i++) {
   int id;
   string name;
   int dSelect;//部门选择
   cout<<"请输入第"<<i+1<<"个职工编号:"<<endl;
   cin>>id;
   cout<<"请输入第"<<i+1<<"个职工姓名:"<<endl;
   cin>>name;
   cout<<"请输入第"<<i+1<<"个职工部门编号:"<<endl<<endl;
   cout<<"1.普通员工"<<endl;
   cout<<"2.经理"<<endl;
   cout<<"3.老板"<<endl;
   cin>>dSelect;
   Worker *worker=NULL;
   switch (dSelect){
    case 1:
     worker=new Employee(id,name,1);
     break;
    case 2:
     worker=new Manager(id,name,2);
     break;
    case 3:
     worker=new Boss(id,name,3);
     break;
    default:
     cout<<"部门编号输入错误"<<endl;
     break;
   }
   //将新添加的职工，添加到职工数组中
   newSpace[this->m_EmpNum+i]=worker;
  }
  //释放原来空间
  delete[] this->m_EmpArray;
  //将新空间赋值给职工数组指针
  this->m_EmpArray=newSpace;
  //更新职工人数
  this->m_EmpNum=newSize;
  //提示添加成功
  cout<<"成功添加"<<addNum<<"个职工"<<endl;
  //保存数据到文件中
  this->save();

 }
 else {
  cout<<"添加职工数量输入错误"<<endl;
 }
 cin.ignore(numeric_limits<streamsize>::max(), '\n');
 cout << "请按enter键返回菜单" << endl;
 cin.get();
}

//保存文件
void WorkerManager::save() {
 ofstream ofs;
 ofs.open(FILENAME,ios::out);//输出方式打开文件--写文件
 //将每个数据写入文件
 for (int i=0;i<this->m_EmpNum;i++) {
  ofs<<this->m_EmpArray[i]->m_id<<" "
     <<this->m_EmpArray[i]->m_Name<<" "
     <<this->m_EmpArray[i]->m_DeptId<<endl;
 }
 //关闭文件
 ofs.close();
}

WorkerManager::~WorkerManager(){
 //释放职工数组
 if (this->m_EmpArray!=NULL) {
  delete[] this->m_EmpArray;
  this->m_EmpArray=NULL;
 }
};