#pragma once//防止头文件重复包含。
#include<iostream>
using namespace std;
#include"worker.h"

//老板
class Boss:public Worker {
public:
    //构造函数
    Boss(int id,string name,int dId);
    //显示个人信息
    virtual void showInfo();
    //获取岗位
    virtual string getDeptName();
};


