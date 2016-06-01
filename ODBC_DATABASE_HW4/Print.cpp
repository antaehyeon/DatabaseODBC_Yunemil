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

//void printInputQueryMenu()
//{
//	printTitle("실행할 쿼리문을 입력하세요");
//	cout << " → ";
//}

void printSelectNumber()
{
	printTitle("Please enter the number");
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
	// 1. TV프로그램의 시청률 조회
	// 2. 배우의 나이와 직업 조회
	// 3. 방송국 직원의 월급 조회 (이름, 해당급여보다 높은, 해당급여보다 낮은)
	// 4. TV프로그램 방송국 조회
	// 5. 직원의 결혼기념일 조회
	// 6. 방송국 모든 직원의 결혼기념일 조회
	system("cls");
	printTitle("Please enter the number");
	cout << " 1. Search TV program rating" << endl;
	cout << " 2. Search actor age and job" << endl;
	cout << " 3. Search employees' salary of broadcasting" << endl;
	cout << " 4. Search Broadcasting station corresponding to the TV program" << endl;
	cout << " 5. Search wedding anniversary of EMPLOYEE" << endl;
	cout << " 6. Search wedding anniversary of staff of the broadcasting station" << endl;
    cout << "  → ";
}

void pirntSalarySelectTable()
{
	system("cls");
	printTitle("Please enter the number");
	cout << " 1. Employee name" << endl;
	cout << " 2. Select all EMPLOYEE paid above specific salary" << endl;
	cout << " 3. Select all EMPLOYEE paid below specific salary " << endl;
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

void enterBroadcastingStationName()
{
	cout << "Enter the Broadcasting Station Name" << endl;
	cout << "  → ";
}

/*						INSERT							*/
void insertTable()
{
	system("cls");
	printTitle("Please select a table for insert");
	cout << " 1. BROADCASTING STATION" << endl;
	cout << " 2. TV PROGRAM" << endl;
	cout << " 3. ENTERTAINMENT" << endl;
	cout << " 4. CAST" << endl;
	cout << " 5. EMPLOYEE" << endl;
	cout << " 6. DEPENDENT" << endl;
	cout << "  → ";
}

void printBCSExample()
{
	system("cls");
	printTitle("INSERT MODE - BROADCASTING_STATION");
	cout << "-Example" << endl;
	cout << "No : 1" << endl;
	cout << "Name : SBS" << endl;
	cout << "Location : Yeouigongwon-ro, Yeongdeungpo-gu, Seoul, Korea" << endl << endl;
}

void printTvProgramExample()
{
	system("cls");
	printTitle("INSERT MODE - TV PROGRAM");
	cout << "-Example" << endl;
	cout << "No : 160224" << endl;
	cout << "Name : 태양의후예" << endl;
	cout << "Rating : 38.8" << endl;
	cout << "Tv Time : (수,목) 오후 10:00" << endl;
	cout << "BroadCasting Station No : 1" << endl << endl;
}

void printCastExample()
{
	system("cls");
	printTitle("INSERT MODE - CAST");
	cout << "-Example" << endl;
	cout << "No : 710217" << endl;
	cout << "Cast Job : 코미디언" << endl;
	cout << "Name : 신동엽" << endl;
	cout << "Cast Age : 46" << endl;
	cout << "Entertainment No : 5" << endl;
	cout << "In appearance TV Program : 30625" << endl << endl;
}

void printEntExample()
{
	system("cls");
	printTitle("INSERT MODE - ENTERTAINMENT");
	cout << "-Example" << endl;
	cout << "No : 1" << endl;
	cout << "Name : SM Ent" << endl;
	cout << "Location : 648, Samseong-ro, Gangnam-gu, Seoul, Korea" << endl << endl;
}

void printEmployeeExample()
{
	system("cls");
	printTitle("INSERT MODE - EMPLOYEE");
	cout << "-Example" << endl;
	cout << "No : 10295" << endl;
	cout << "Name : 홍길동" << endl;
	cout << "Salary : 3000000" << endl;
	cout << "Belong to Broadcasting Station No : " << endl << endl;
}

void printDependentExample()
{
	system("cls");
	printTitle("INSERT MODE - DEPENDENT");
	cout << "-Example" << endl;
	cout << "Employee No : 10295" << endl;
	cout << "Name : 김건모" << endl;
	cout << "Wedding anniversary : 081001" << endl << endl;
}

void enterNo()
{
	cout << "enter the No Data : ";
}

void enterName()
{
	cout << "enter the Name Data : ";
}

void enterLocation()
{
	cout << "enter the Location Data : ";
}

void enterRating()
{
	cout << "enter the Rating Data : ";
}

void enterTime()
{
	cout << "enter the Time Data : ";
}

void enterJob()
{
	cout << "enter the Job Data : ";
}

void enterAge()
{
	cout << "enter the Age Data : ";
}

void enterSalaryData()
{
	cout << "enter the Salary Data : ";
}

void enterWeddingDate()
{
	cout << "enter the Wedding Annviersary Data : ";
}

/*						DELETE							*/

void printDeleteMenu()
{
	system("cls");
	printTitle("Please enter the number");
	cout << " 1. Delete a Broadcasting Station" << endl;
	cout << " 2. Lay off Employee" << endl;
	cout << " 3. Delete a TV program" << endl;
	cout << "  → ";
}

void enterStationNameForDelete()
{
	cout << "Enter the Broadcasting Station Number : ";
}

void enterEmployeeNumForDelete()
{
	cout << "Enter the Employee Number : ";
}

void enterTvProgramNumForDelete()
{
	cout << "Enter the TV Program Number : ";
}

/*						UPDATE							*/
void printUpdateMenu()
{
	system("cls");
	printTitle("Please enter the number");
	cout << " 1. Update the all data of selected Table" << endl;
	cout << " 2. Update the Broadcasting Station name" << endl;
	cout << " 3. Update TV program rating" << endl;
	cout << " 4. Update Cast age" << endl;
	cout << "  → ";
}

void updateTable()
{
	system("cls");
	printTitle("Please select a table for update");
	cout << " 1. BROADCASTING STATION" << endl;
	cout << " 2. TV PROGRAM" << endl;
	cout << " 3. ENTERTAINMENT" << endl;
	cout << " 4. CAST" << endl;
	cout << " 5. EMPLOYEE" << endl;
	cout << " 6. DEPENDENT" << endl;
	cout << "  → ";
}

void enterStationNameForUpdate()
{
	cout << "Enter the Broadcasting Station Name : ";
}

void enterStationName()
{
	cout << "Enter the target(BROADNAME) to be Updated : ";
}

void whatReplacement()
{
	cout << "Enter the replacement : ";
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
	centerString("NO EXISTS DATA !!!");
	cout << "────────────────────────────────────────────────────────────" << endl;
}

void divisionLine()
{
	cout << "────────────────────────────────────────────────────────────";
}

void successMessage()
{
	system("cls");
	cout << endl << endl << endl;
	divisionLine();
	centerString("SUCCESS");
	divisionLine();
	cout << endl;
}

void errorMessage()
{
	system("cls");
	cout << endl << endl << endl;
	divisionLine();
	centerString("ERROR");

	divisionLine();
	cout << endl;
}

void damageErrorMessage()
{
	system("cls");
	cout << endl << endl << endl;
	divisionLine();
	centerString("DAMAGE ERROR !!! - Please Check your Program");
	divisionLine();
	cout << endl;
}