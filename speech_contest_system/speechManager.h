#pragma once
#include<iostream>
using namespace std;
#include<limits>
#include<vector>
#include<map>
#include"speaker.h"

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

  //初始化容器和属性
  void initSpeech();

  //成员属性
  //保存第一轮比赛选手编号
  vector<int>v1;
  //第一轮晋级选手编号容器
  vector<int>v2;
  //前三名选手编号容器
  vector<int>vVictory;
  //存放编号和队员选手名称容器
  map<int,Speaker>m_Speaker;
  //比赛轮数
  int m_Index;
};