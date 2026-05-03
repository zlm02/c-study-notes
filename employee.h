//普通员工文件
#pragma once//防止头文件重复包含。
#include<iostream>
using namespace std;
#include"worker.h"

class Employee:public Worker {
public:
    Employee(int id,string name,int dId);
    //显示个人信息
    virtual void showInfo();
    //获取岗位
    virtual string getDeptName();

};