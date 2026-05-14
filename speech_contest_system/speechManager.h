#pragma once
#include<iostream>
using namespace std;
#include<limits>

//设计演讲管理类
class SpeechManager {
  public:
  //构造函数
  SpeechManager();

  //菜单功能
  void showMenu();

  //退出系统
  void existSystem();
  //析构函数
  ~SpeechManager();
};