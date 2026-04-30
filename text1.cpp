#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
void showmenue()
{
	cout << "请输入相应数字进行操作" << endl;
	cout << "--------菜单----------" << endl;
	cout << "1：----添加联系人-----" << endl;
	cout << "2：----显示联系人-----" << endl;
	cout << "3：----删除联系人-----" << endl;
	cout << "4：----查找联系人-----" << endl;
	cout << "5：----修改联系人-----" << endl;
	cout << "6：----清空联系人-----" << endl;
	cout << "0：----退出通讯录-----" << endl;

}
struct Person
{
	string m_Name;
	int m_Age;
	int m_Sex;//1男，2女
	string m_Phonenumber;
	string m_Addr;
};
#define MAX 1000//列表最大容量为一千。
struct AddressBooks
{
	struct Person personarr[MAX];
	int m_Size;
};
void addperson(AddressBooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，添加失败。" << endl;
	}
	else {
		string name;
		cout << "请输入名字:" << endl;
		cin >> name;
		abs->personarr[abs->m_Size].m_Name = name;
		int age;
		cout << "请输入年龄:" << endl;
		cin >> age;
		abs->personarr[abs->m_Size].m_Age;
		int sex;
		cout << "请输入性别:" << endl;
		cout << "1------男:" << endl;
		cout << "2------女:" << endl;
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personarr[abs->m_Size].m_Sex = sex;
				break;
			}
			else { cout << "输入错误，请重新输入" << endl; }
		}
		cout << "请输入电话:" << endl;
		string phonenumber = "";
		cin >> phonenumber;
		abs->personarr[abs->m_Size].m_Phonenumber = phonenumber;
		cout << "请输入地址:" << endl;
		string addr = "";
		cin >> addr;
		abs->personarr[abs->m_Size].m_Addr= addr;
		abs->m_Size++;
		cout << "添加成功" << endl;
	}

	system("pause");
	system("cls");

}
void showperson(AddressBooks* abs) {
	if (abs->m_Size == 0) {
		cout << "当前目录为空" << endl;
	  }
	else {
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名" << abs->personarr[i].m_Name << endl;
			cout << "性别" << abs->personarr[i].m_Sex << endl;
			cout << "年龄" << abs->personarr[i].m_Age << endl;
			cout << "电话" << abs->personarr[i].m_Phonenumber << endl;
			cout << "地址" << abs->personarr[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}
int isexist(AddressBooks* abs,string name) {
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->personarr[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}
void deleteperson(AddressBooks* abs) {
	cout << "请输入你要删除的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret == -1) {
		cout << "未查到此人" << endl;
			}
	else {
		for (int i = ret; i < abs->m_Size-1; i++) {
			abs->personarr[i] = abs->personarr[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功" << endl;
	}
	system("pause");
	system("cls");
}
void findperson(AddressBooks* abs) {
	cout << "请输入你要查找的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret == -1) {
		cout << "未查到此人" << endl;
	}
	else {
		cout << "姓名" << abs->personarr[ret].m_Name << endl;
		cout << "性别" << abs->personarr[ret].m_Sex << endl;
		cout << "年龄" << abs->personarr[ret].m_Age << endl;
		cout << "电话" << abs->personarr[ret].m_Phonenumber << endl;
		cout << "地址" << abs->personarr[ret].m_Addr << endl;
	}
	system("pause");
	system("cls");
}
void modifyperson(AddressBooks* abs) {
	cout << "请输入你要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret = isexist(abs, name);
	if (ret == -1) {
		cout << "未查到此人" << endl;
	}
	else {
		string name;
		cout << "请输入名字:" << endl;
		cin >> name;
		abs->personarr[ret].m_Name = name;
		int age;
		cout << "请输入年龄:" << endl;
		cin >> age;
		abs->personarr[ret].m_Age;
		int sex;
		cout << "请输入性别:" << endl;
		cout << "1------男:" << endl;
		cout << "2------女:" << endl;
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personarr[ret].m_Sex = sex;
				break;
			}
			else { cout << "输入错误，请重新输入" << endl; }
		}
		cout << "请输入电话:" << endl;
		string phonenumber = "";
		cin >> phonenumber;
		abs->personarr[ret].m_Phonenumber = phonenumber;
		cout << "请输入地址:" << endl;
		string addr = "";
		cin >> addr;
		abs->personarr[ret].m_Addr = addr;
		cout << "修改成功" << endl;
		system("pause");
		system("cls");
	}
}
void clearperson(AddressBooks* abs) {
	abs->m_Size = 0;
	cout << "通讯录已经清空" << endl;
	system("pause");
	system("cls");
}

int main() {
	AddressBooks abs;
	abs.m_Size = 0;
	int select;
	while (true) {
		showmenue();
		cin >> select;
		switch (select) {
		case 1:addperson(&abs);
			break;
		case 2:showperson(&abs);
			break;
		case 3:deleteperson(&abs);
			break;
		case 4:findperson(&abs);
			break;
		case 5:modifyperson(&abs);
			break;
		case 6:clearperson(&abs);
			break;
		case 0:cout << "欢迎下次使用 " << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入错误，请重新输入" << endl;
			system("spause");
			system("cls");
			break;

		}

	}system("pause");
	return 0;

}