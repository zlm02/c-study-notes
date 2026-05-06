
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
#include<stdlib.h>

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
    //判断文件是否为空 标志
    bool m_FileIsEmpty;
    //统计文件中人数
    int get_EmpNum();
    //初始化职工数组
    void init_Emp();

    //显示职工信息
    void Show_Emp();

    //析构函数
    ~WorkerManager();
};