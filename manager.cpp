#include"manager.h"

//构造函数
Manager::Manager(int id,string name,int dId) {
    this->m_id=id;
    this->m_Name=name;
    this->m_DeptId=dId;
}
//显示个人信息
 void Manager::showInfo() {
    cout<<"职工编号："<<this->m_id
     <<"\t职工姓名:"<<this->m_Name
     <<"\t岗位:"<<this->getDeptName()
     <<"\t岗位职责：完成上级交给的任务,并且给普通员工下发任务"<<endl;

 }
//获取岗位
 string Manager::getDeptName(){
     return string("经理");
 }