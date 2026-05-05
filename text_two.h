
#pragma once//防止头文件重复包含。
#include <iostream>
#include <limits>
using namespace std;
#include"worker.h"
#include"manager.h"
#include"employee.h"
#include"boss.h"
#include<fstream>
#define FILENAME "empFile.txt"

class WorkerManager {
public:
    WorkerManager();
    //展示菜单
    void Show_Menu();
    //退出
    void ExitSystem();
    //记录职工人数
    int m_EmpNum;
    //职工数组指针
    Worker **m_EmpArray;
    //添加职工
    void Add_Emp();
    //保存文件
    void save();




    ~WorkerManager();
};