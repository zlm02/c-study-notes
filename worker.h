
#pragma once//防止头文件重复包含。
#include<iostream>
using namespace std;
#include<string>

//职工抽象类
class Worker {
public:
    //显示个人信息
    virtual void showInfo()=0;
    //获取岗位
    virtual string getDeptName()=0;
    //职工编号
    int m_id;
    //员工姓名
    string m_Name;
    //部门编号
    int m_DeptId;
};