#include<iostream>
using namespace std;
#include<limits>
#include "speechManager.h"

int main() {
  SpeechManager sm;
  sm.showMenu();

  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "请按enter键继续..." << endl;
  cin.get();
  return 0; //退出程序
}