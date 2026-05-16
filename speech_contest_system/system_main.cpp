#include<iostream>
using namespace std;
#include "speechManager.h"
#include<string.h>

int main() {
  //创建管理类对象
  SpeechManager sm;
  //测试12名选手创建
  //for (map<int,Speaker>::iterator it=sm.m_Speaker.begin();it!=sm.m_Speaker.end();it++) {
    //cout<<"选手编号："<<it->first<<"，选手姓名："<<it->second.m_Name<<"，分数："<<it->second.m_Score[0]<<endl;
  //}
  while (true) {
    sm.showMenu();

    cout<<"请输入你的选择"<<endl;
    int choice;//存储用户输入
    cin>>choice;
    switch (choice) {
    case 1://开始比赛
      break;
    case 2://查看往届比赛
      break;
    case 3://清空比赛记录
      break;
    case 0://退出系统
      sm.existSystem();
      break;
    default:
      system("cls");//清屏
      break;

    }
  }




  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "请按enter键继续..." << endl;
  cin.get();
  return 0; //退出程序
}