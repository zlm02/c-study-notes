
#include "speechManager.h"


//构造函数
SpeechManager::SpeechManager() {
  //初始化容器和属性
  this->initSpeech();
}
//菜单功能
void SpeechManager::showMenu() {
  cout<<"************************************"<<endl;
  cout<<"*********** 欢迎参加演讲比赛 ***********"<<endl;
  cout<<"*********** 1.开始演讲比赛 ************"<<endl;
  cout<<"*********** 2.查看往届比赛 ************"<<endl;
  cout<<"*********** 3.清空比赛记录 ************"<<endl;
  cout<<"*********** 0.退出系统 ***************"<<endl;
  cout<<endl;


}

void SpeechManager::existSystem() {
  cout<<"欢迎下次使用"<<endl;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "请按enter键继续..." << endl;
  cin.get();
  exit(0);
}


void SpeechManager::initSpeech() {
  //容器置空
  this->v1.clear();
  this->v2.clear();
  this->vVictory.clear();
  this->m_Speaker.clear();

  //初始化比赛轮数
  this->m_Index = 1;
}
//析构函数
SpeechManager::~SpeechManager() {
}

