#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Data.h"

using namespace std;

// select - 1
void main(int argc, char *argv[])
{
	if (DBConnect(&hEnv, &hDbc) == true)
	{
		while (true)
		{
			printSelectNumber();
			cin >> selectFunctionNumber;

			if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS)
			{
				switch (selectFunctionNumber)
				{
				case 1: // SELECT
					SELECT();
					break;
				case 2: // INSERT
					break;
				case 3: // DELETE
					break;
				case 4: // UPDATE
					break;
				case 5: // EXIT
					return;
				} // switch (입력된 번호에 따라)
				SQLCloseCursor(hStmt);
				SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
			}
		} // While
		  // Disconnect from the SQL Server
		DBDisconnect(&hEnv, &hDbc);
	}
	else
	{
		cout << "Fail to Connect!!" << endl;
	}
	return;
}

void SELECT()
{
	printSelectTable();
	cin >> selectTableNum;
	string str;
	char s[50];
	char * ch;

	switch (selectTableNum)
	{
	case 1: // TV 프로그램의 시청률 조회
		printTitle("RESULT");
		enterTvProgramName();
		getchar();

		// TV 프로그램명을 입력받음
		getline(cin, str);
		ch = (char*)str.c_str();
		cin.clear();

		sprintf((char*)query, "SELECT TVPNAME, RATING FROM TVPROGRAM WHERE TVPNAME = '%s'", ch);
		SQLExecDirect(hStmt, query, SQL_NTS);
		SQLBindCol(hStmt, 1, SQL_C_CHAR, TVPNAME, 20, NULL);
		SQLBindCol(hStmt, 2, SQL_C_DOUBLE, &RATING, 3, NULL);

		// 결과의 ROW를 뽑아서 데이터가 없을 경우 메세지를 따로 출력해주려 했으나 실패..
		// 결과의 COL 뽑는 함수는 있는데 ROW는 왜 없는지 의문..
		// 조금 더 알아보고 다시 적용해야 하는 부분

		//SELECT ROW_NUMBER() OVER (ORDER BY EMPNO) AS COUNTROW FROM EMPLOYEE WHERE EMPNO = '211212'
		//sprintf((char*)query, "SELECT ROW_NUMBER() OVER (ORDER BY TVPNAME) AS COUNTROW FROM TVPROGRAM WHERE TVPNAME = '%s'", ch);
		//SQLExecDirect(hStmt, query, SQL_NTS);
		//SQLBindCol(hStmt, 1, SQL_INTEGER, &COUNTROW, 2, NULL);
		
		// 데이터가 존재하지 않을 시
		//if (printNoExistMessage(rowsNum)) { break; }

		cout << endl;
		divisionLine();
		while (SQLFetch(hStmt) != SQL_NO_DATA)
		{
			cout << "TV Program Name : " << TVPNAME << endl;
			cout << "Rating : " << RATING << endl;
			divisionLine();
		}
		system("pause");
		break;
	case 2: // 배우의 직업과 나이 조회
		printTitle("RESULT");
		enterCastName();
		
		getchar();
		getline(cin, str);
		ch = (char*)str.c_str();
		cin.clear();

		sprintf((char*)query, "SELECT CASTNAME, CASTJOB, CASTAGE FROM CAST_ WHERE CASTNAME = '%s'", ch);
		SQLExecDirect(hStmt, query, SQL_NTS);
		SQLBindCol(hStmt, 1, SQL_C_CHAR, CASTNAME, 8, NULL);
		SQLBindCol(hStmt, 2, SQL_C_CHAR, CASTJOB, 8, NULL);
		SQLBindCol(hStmt, 3, SQL_INTEGER, &CASTAGE, 4, NULL);

		// 데이터가 존재하지 않을 시

		cout << endl;
		divisionLine();
		while (SQLFetch(hStmt) != SQL_NO_DATA)
		{
			cout << "Cast Name : " << CASTNAME << endl;
			cout << "Cast Job : " << CASTJOB << endl;
			cout << "Cast Age : " << CASTAGE << endl;
			divisionLine();
		}
		system("pause");

		break;
	case 3: // 방송국 직원의 월급 조회
		printTitle("RESULT");

		pirntSalarySelectTable();
		cin >> selectNumber;
		switch (selectNumber)
		{
		case 1: // 급여 검색
			enterSalary();

			getchar();
			getline(cin, str);
			ch = (char*)str.c_str();
			cin.clear();

			sprintf((char*)query, "SELECT EMPNAME, SALARY FROM EMPLOYEE WHERE EMPNAME = '%s'", ch);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLBindCol(hStmt, 1, SQL_C_CHAR, EMPNAME, 8, NULL);
			SQLBindCol(hStmt, 2, SQL_INTEGER, &SALARY, 10, NULL);

			printTitle("RESULT");
			cout << endl;
			divisionLine();
			while (SQLFetch(hStmt) != SQL_NO_DATA)
			{
				cout << "Employee Name : " << EMPNAME << endl;
				cout << "Employee Salary : " << SALARY << endl;
				divisionLine();
			}
			system("pause");
			break;
		case 2: // 입력된 값 이상 급여 검색
			enterSalary();

			getchar();
			getline(cin, str);
			ch = (char*)str.c_str();
			cin.clear();

			sprintf((char*)query, "SELECT EMPNAME, SALARY FROM EMPLOYEE WHERE SALARY >= %s", ch);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLBindCol(hStmt, 1, SQL_C_CHAR, EMPNAME, 8, NULL);
			SQLBindCol(hStmt, 2, SQL_INTEGER, &SALARY, 10, NULL);

			printTitle("RESULT");
			cout << endl;
			divisionLine();
			while (SQLFetch(hStmt) != SQL_NO_DATA)
			{
				cout << "Employee Name : " << EMPNAME << endl;
				cout << "Employee Salary : " << SALARY << endl;
				divisionLine();
			}
			system("pause");
			break;
		case 3: // 입력된 값 이하 급여 검색
			enterSalary();

			getchar();
			getline(cin, str);
			ch = (char*)str.c_str();
			cin.clear();

			sprintf((char*)query, "SELECT EMPNAME, SALARY FROM EMPLOYEE WHERE SALARY <= %s", ch);
			SQLExecDirect(hStmt, query, SQL_NTS);
			SQLBindCol(hStmt, 1, SQL_C_CHAR, EMPNAME, 8, NULL);
			SQLBindCol(hStmt, 2, SQL_INTEGER, &SALARY, 10, NULL);

			printTitle("RESULT");
			cout << endl;
			divisionLine();
			while (SQLFetch(hStmt) != SQL_NO_DATA)
			{
				cout << "Employee Name : " << EMPNAME << endl;
				cout << "Employee Salary : " << SALARY << endl;
				divisionLine();
			}
			system("pause");
			break;
		default:
			break;
		}
	case 4: // 중첩질의
		/*
		SELECT	 BROADNAME
		FROM	 BROADCASTING_STATION
		WHERE	 BNO = ( SELECT F_BNO_TV
						 FROM TVPROGRAM
						 WHERE TVPNAME = 'TV프로그램 이름');
		*/
		enterTvProgramName();
	
		getchar();
		getline(cin, str);
		ch = (char*)str.c_str();
		cin.clear();

		sprintf((char*)query, "SELECT BROADNAME FROM BROADCASTING_STATION WHERE BNO = (SELECT F_BNO_TV FROM TVPROGRAM WHERE TVPNAME = '%s'", ch);
		SQLExecDirect(hStmt, query, SQL_NTS);
		SQLBindCol(hStmt, 1, SQL_C_CHAR, BROADNAME, 20, NULL);

		printTitle("RESULT");
		cout << endl;
		divisionLine();
		while (SQLFetch(hStmt) != SQL_NO_DATA)
		{
			cout << "Broadcasting station corresponding to the " << ch << endl;
			cout << "Broadcasting station Name : " << BROADNAME << endl;
			divisionLine();
		}
		system("pause");
		break;
	case 5:
		/*
		SELECT EMPNAME, DEPNAME, WEDDINGANNVIERSARY
		FROM EMPLOYEE AS E, DEPENDENT_ AS D
		WHERE E.EMPNO = D.F_EMPNO AND (E.EMPNAME = '직원이름');
		*/
		enterEmployeeName();

		getchar();
		getline(cin, str);
		ch = (char*)str.c_str();
		cin.clear();

		sprintf((char*)query, "SELECT EMPNAME, DEPNAME, WEDDINGANNVIERSARY FROM EMPLOYEE AS E, DEPENDENT_ AS D WHERE E.EMPNO = D.F_EMPNO AND (E.EMPNAME = '%s');", ch);
		SQLExecDirect(hStmt, query, SQL_NTS);
		SQLBindCol(hStmt, 1, SQL_C_CHAR, EMPNAME, 8, NULL);
		SQLBindCol(hStmt, 2, SQL_C_CHAR, DEPNAME, 8, NULL);
		SQLBindCol(hStmt, 3, SQL_C_CHAR, WEDDINGANNVIERSARY, 10, NULL);

		printTitle("RESULT");
		cout << endl;
		divisionLine();
		while (SQLFetch(hStmt) != SQL_NO_DATA)
		{
			cout << EMPNAME << " husband is " << DEPNAME << endl;
			cout << "The wedding anniversary of the couple :  " << WEDDINGANNVIERSARY << endl;
			divisionLine();
		}
		system("pause");

		break;
	case 6:
		break;
	default:
		break;
	} // switch ( 모드에 따라서 )
} // SELECT

void INSERT()
{

}

void JOIN()
{
	printJoinList();
	cin >> selectNumber;

	switch (selectNumber)
	{
	case 1:
		printTitle("TVPNAME - BROADNAME JOIN");
		sprintf((char*)query, "SELECT	 TVPNAME, BROADNAME\nFROM	 BROADCASTING_STATION AS E, TVPROGRAM AS D\nWHERE	 E.BNO = D.F_BNO_TV; ");
		SQLExecDirect(hStmt, query, SQL_NTS);

		SQLBindCol(hStmt, 1, SQL_C_CHAR, TVPNAME, 20, NULL);
		SQLBindCol(hStmt, 2, SQL_C_CHAR, BROADNAME, 20, NULL);

		cout << "TVPNAME				BROADNAME" << endl;

		while (SQLFetch(hStmt) != SQL_NO_DATA)
		{
			cout << TVPNAME << "\t\t" << BROADNAME << endl;
		}
		system("pause");
		break;
	}

}

bool printNoExistMessage(int param)
{
	if (param == 0)
	{
		noExistData();
		getchar();
		system("pause");
		return true;
	}
}
