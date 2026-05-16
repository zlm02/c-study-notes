
#include "speechManager.h"


//构造函数
SpeechManager::SpeechManager() {
  //初始化容器和属性
  this->initSpeech();
  //创建12名选手
  this->createSpeaker();
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

//创建12名选手
void SpeechManager::createSpeaker() {
  string nameseed="abcdefghijkl";
  for (int i=0;i<nameseed.size();i++) {
    string name="选手";
    name += nameseed[i];
    Speaker sp;
    sp.m_Name = name;
    for (int j=0;j<2;j++) {
      sp.m_Score[j]=0;
    }
    //创建选手编号，放入v1容器
    this->v1.push_back(i+1);
    //选手编号和名称放入map容器
    this->m_Speaker.insert(make_pair(i+1,sp));
  }

}
//析构函数
SpeechManager::~SpeechManager() {
}

