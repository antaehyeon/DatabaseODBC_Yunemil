#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void printTitle(char * s);
void centerString(char * s);

void mainMenuPrint()
{
	printTitle("�ݰ����ϴ�! ��۱� �����ͺ��̽��� ���Ű��� ȯ���մϴ� :D");
	cout << " 1. ENTER QUERY" << endl;
	cout << " 2. SELECT NUMBER" << endl;
	cout << " 3. EXIT" << endl;
	cout << " �� ";
}

void printInputQueryMenu()
{
	printTitle("������ �������� �Է��ϼ���");
	cout << " �� ";
}

void printSelectNumber()
{
	printTitle("������ ����� �Է��ϼ���");
	cout << " 1.SELECT" << endl;
	cout << " 2.INSERT" << endl;
	cout << " 3.DELETE" << endl;
	cout << " 4.UPDATE" << endl;
	cout << " 5.JOIN" << endl;
	cout << "  �� ";
}

void printSelectTable()
{
	system("cls");
	printTitle("SELECT �� ���̺��� �Է��ϼ���");
	cout << " 1. BROADCASTING STATION" << endl;
	cout << " 2. TV PROGRAM" << endl;
	cout << " 3. ENTERTAINMENT" << endl;
	cout << " 4. CAST" << endl;
	cout << " 5. EMPLOYEE" << endl;
	cout << " 6. DEPENDENT" << endl;
	cout << "  �� ";
}

void printJoinList()
{
	system("cls");
	printTitle("JOIN �� ����� �����ϼ���");
	cout << " 1. TVPNAME - BROADNAME" << endl;
	cout << "  �� ";
}

void printTitle(char * string)
{
	system("cls");
	cout << "������������������������������������������������������������������������������������������������������������������������";
	centerString(string);
	cout << "������������������������������������������������������������������������������������������������������������������������" << endl;
}

void centerString(char * s)
{
	int l = strlen(s);
	int pos = (int)((120 - l) / 2);
	for (int i = 0; i < pos; i++)
		cout << " ";

	cout << s << endl;
}
