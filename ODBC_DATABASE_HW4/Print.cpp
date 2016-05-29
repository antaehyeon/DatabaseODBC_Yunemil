#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

void printTitle(char * s);
void centerString(char * s);

void mainMenuPrint()
{
	printTitle("반갑습니다! 방송국 데이터베이스에 오신것을 환영합니다 :D");
	cout << " 1. ENTER QUERY" << endl;
	cout << " 2. SELECT NUMBER" << endl;
	cout << " 3. EXIT" << endl;
	cout << " → ";
}

void printInputQueryMenu()
{
	printTitle("실행할 쿼리문을 입력하세요");
	cout << " → ";
}

void printSelectNumber()
{
	printTitle("수행할 기능을 입력하세요");
	cout << " 1.SELECT" << endl;
	cout << " 2.INSERT" << endl;
	cout << " 3.DELETE" << endl;
	cout << " 4.UPDATE" << endl;
	cout << " 5.EXIT" << endl;
	cout << "  → ";
}

/*						SELECT							*/

void printSelectTable()
{
	system("cls");
	printTitle("Please enter the number");
	cout << " 1. Search TV program rating" << endl;
	cout << " 2. Search actor age and job" << endl;
	cout << " 3. Search employees' salary of broadcasting" << endl;
	cout << " 4. Search Broadcasting station corresponding to the TV program" << endl;
	cout << "  → ";
}

void pirntSalarySelectTable()
{
	system("cls");
	printTitle("Please enter the number");
	cout << " 1. Employee name" << endl;
	cout << " 2. Standard salary or more" << endl;
	cout << " 3. Standard salary below " << endl;
	cout << "  → ";
}

void enterTvProgramName()
{
	cout << "Enter the TV Program Name" << endl;
	cout << "  → ";
}

void enterCastName()
{
	cout << "Enter the Cast Name" << endl;
	cout << "  → ";
}

void enterSalary()
{
	cout << "Enter the Salary" << endl;
	cout << "  → ";
}

void enterEmployeeName()
{
	cout << "Enter the Employee Name" << endl;
	cout << "  → ";
}

/*						INSERT							*/
void insertTable()
{
	system("cls");
	printTitle("어느 테이블에 데이터를 INSERT 하시겠습니까?");
	cout << " 1. BROADCASTING STATION" << endl;
	cout << " 2. TV PROGRAM" << endl;
	cout << " 3. ENTERTAINMENT" << endl;
	cout << " 4. CAST" << endl;
	cout << " 5. EMPLOYEE" << endl;
	cout << " 6. DEPENDENT" << endl;
	cout << "  → ";
}


/*						JOIN							*/

void printJoinList()
{
	system("cls");
	printTitle("JOIN 할 목록을 선택하세요");
	cout << " 1. TVPNAME - BROADNAME" << endl;
	cout << "  → ";
}

/*						PRINT							*/

void printCurrentTable()
{

}


void printTitle(char * string)
{
	system("cls");
	cout << "────────────────────────────────────────────────────────────";
	centerString(string);
	cout << "────────────────────────────────────────────────────────────" << endl;
}

void centerString(char * s)
{
	int l = strlen(s);
	int pos = (int)((120 - l) / 2);
	for (int i = 0; i < pos; i++)
		cout << " ";

	cout << s << endl;
}

void noExistData()
{
	system("cls");
	cout << endl << endl << endl << "────────────────────────────────────────────────────────────";
	centerString("데이터가 존재하지 않습니다");
	cout << "────────────────────────────────────────────────────────────" << endl;
}

void divisionLine()
{
	cout << "────────────────────────────────────────────────────────────" << endl;
}
