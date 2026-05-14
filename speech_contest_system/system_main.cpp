#include<iostream>
using namespace std;
#include "speechManager.h"

int main() {
  SpeechManager sm;
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