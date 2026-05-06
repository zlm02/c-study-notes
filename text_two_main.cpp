#include<iostream>
using namespace std;
#include"text_two.h"
#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
int main() {
    // //测试：
    // Worker *worker=NULL;
    // worker=new Employee(1,"张三",1);
    // worker->showInfo();
    // delete worker;
    // worker=new Manager(2,"李四",2);
    // worker->showInfo();
    // delete worker;
    // worker=new Boss(3,"王五",3);
    // worker->showInfo();
    // delete worker;


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
                wm.Add_Emp();
                break;
            case 2://显示职工信息
                wm.Show_Emp();
                break;
            case 3://删除离职职工
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