#include<iostream>
using namespace std;
#include"text_two.h"

int main() {
    //实例化对象
    WorkerManager wm;
    int choice=0;
    while (true) {
        wm.Show_Menu();
        cout<<"请输入你的选择："<<endl;
        cin>>choice;
        switch (choice) {
            case 0://退出管理程序
                wm.ExitSystem();
                break;
            case 1://增加职工信息
                break;
            case 2://显示职工信息
                break;
            case 3://增加职工信息
                break;
            case 4://修改职工信息
                break;
            case 5://查找职工信息
                break;
            case 6://按照编号排序
                break;
            case 7://清空所有文档
                break;
        }
    }

    return 0;

}