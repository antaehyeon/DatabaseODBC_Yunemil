#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "Data.h"

using namespace std;

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
					INSERT();
					break;
				case 3: // DELETE
					break;
				case 4: // UPDATE
					break;
				case 5: // EXIT
					return;
				} // switch (�Էµ� ��ȣ�� ����)
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

/*						SELECT						*/

void SELECT()
{
	printSelectTable();
	cin >> selectTableNum;

	switch (selectTableNum)
	{
	case 1: // TV ���α׷��� ��û�� ��ȸ
		printTitle("RESULT");
		enterTvProgramName();
		getchar();

		// TV ���α׷����� �Է¹���
		getline(cin, str);
		ch = (char*)str.c_str();
		cin.clear();

		sprintf((char*)query, "SELECT TVPNAME, RATING FROM TVPROGRAM WHERE TVPNAME = '%s'", ch);
		SQLExecDirect(hStmt, query, SQL_NTS);
		SQLBindCol(hStmt, 1, SQL_C_CHAR, TVPNAME, 20, NULL);
		SQLBindCol(hStmt, 2, SQL_C_DOUBLE, &RATING, 3, NULL);

		// ����� ROW�� �̾Ƽ� �����Ͱ� ���� ��� �޼����� ���� ������ַ� ������ ����..
		// ����� COL �̴� �Լ��� �ִµ� ROW�� �� ������ �ǹ�..
		// ���� �� �˾ƺ��� �ٽ� �����ؾ� �ϴ� �κ�

		//SELECT ROW_NUMBER() OVER (ORDER BY EMPNO) AS COUNTROW FROM EMPLOYEE WHERE EMPNO = '211212'
		//sprintf((char*)query, "SELECT ROW_NUMBER() OVER (ORDER BY TVPNAME) AS COUNTROW FROM TVPROGRAM WHERE TVPNAME = '%s'", ch);
		//SQLExecDirect(hStmt, query, SQL_NTS);
		//SQLBindCol(hStmt, 1, SQL_INTEGER, &COUNTROW, 2, NULL);
		
		// �����Ͱ� �������� ���� ��
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
	case 2: // ����� ������ ���� ��ȸ
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

		// �����Ͱ� �������� ���� ��

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
	case 3: // ��۱� ������ ���� ��ȸ
		printTitle("RESULT");

		pirntSalarySelectTable();
		cin >> selectNumber;
		switch (selectNumber)
		{
		case 1: // �޿� �˻�
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
		case 2: // �Էµ� �� �̻� �޿� �˻�
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
		case 3: // �Էµ� �� ���� �޿� �˻�
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
		break;
	case 4: // ��ø����
		/*
		SELECT	 BROADNAME
		FROM	 BROADCASTING_STATION
		WHERE	 BNO = ( SELECT F_BNO_TV
						 FROM TVPROGRAM
						 WHERE TVPNAME = 'TV���α׷� �̸�');
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
		WHERE E.EMPNO = D.F_EMPNO AND (E.EMPNAME = '�����̸�');
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
	} // switch ( ��忡 ���� )
} // SELECT

  /*						INSERT						*/

void INSERT()
{
	insertTable();

	cin >> selectTableNum;

	switch (selectTableNum)
	{
	case 1: // BROADCASTING_STATION
		printBCSExample();

		getchar();
		enterNo();
		getline(cin, sNo);
		cNo = (char*)sNo.c_str();

		enterName();
		getline(cin, sName);
		cName = (char*)sName.c_str();

		enterLocation();
		getline(cin, sLocation);
		cLocation = (char*)sLocation.c_str();

		sprintf((char*)query, "INSERT INTO BROADCASTING_STATION VALUES(%s, '%s', '%s');", cNo, cName, cLocation);
		SQLExecDirect(hStmt, query, SQL_NTS);

		successMessage();
		system("pause");
		break;
	case 2: // TV PROGRAM
		printTvProgramExample();

		getchar();
		enterNo();
		getline(cin, sNo);
		cNo = (char*)sNo.c_str();

		enterName();
		getline(cin, sName);
		cName = (char*)sName.c_str();

		enterRating();
		getline(cin, sRating);
		cRating = (char*)sRating.c_str();

		enterTime();
		getline(cin, sTime);
		cTime = (char*)sTime.c_str();

		enterLocation();
		getline(cin, sFno);
		cFno = (char*)sFno.c_str();
		
		sprintf((char*)query, "INSERT INTO TVPROGRAM VALUES(%s, '%s', %s, '%s', %s);", cNo, cName, cRating, cTime, cFno);
		SQLExecDirect(hStmt, query, SQL_NTS);

		successMessage();
		system("pause");
		break;
	case 3: // ENTERTAINMENT
		printEntExample();

		getchar();
		enterNo();
		getline(cin, sNo);
		cNo = (char*)sNo.c_str();

		enterName();
		getline(cin, sName);
		cName = (char*)sName.c_str();

		enterLocation();
		getline(cin, sLocation);
		cLocation = (char*)sLocation.c_str();

		sprintf((char*)query, "INSERT INTO ENTERTAINMENT VALUES(%s, '%s', '%s');", cNo, cName, cLocation);
		SQLExecDirect(hStmt, query, SQL_NTS);

		successMessage();
		system("pause");
		break;
	case 4: // CAST
		printCastExample();

		getchar();
		enterNo();
		getline(cin, sNo);
		cNo = (char*)sNo.c_str();

		enterJob();
		getline(cin, sJob);
		cJob = (char*)sJob.c_str();

		enterName();
		getline(cin, sName);
		cName = (char*)sName.c_str();

		enterRating();
		getline(cin, sAge);
		cAge = (char*)sAge.c_str();

		enterNo();
		getline(cin, sFno);
		cFno = (char*)sFno.c_str();

		enterNo();
		getline(cin, sFno2);
		cFno2 = (char*)sFno2.c_str();

		sprintf((char*)query, "INSERT INTO CAST_ VALUES(%s, '%s', '%s', %s, %s, %s);", cNo, cJob, cName, cAge, cFno, cFno2);
		SQLExecDirect(hStmt, query, SQL_NTS);

		successMessage();
		system("pause");
		break;
	case 5: // EMPLOYEE
		printEmployeeExample();

		getchar();
		enterNo();
		getline(cin, sNo);
		cNo = (char*)sNo.c_str();

		enterName();
		getline(cin, sName);
		cName = (char*)sName.c_str();

		enterSalaryData();
		getline(cin, sSalary);
		cSalary = (char*)sSalary.c_str();

		enterNo();
		getline(cin, sFno);
		cFno = (char*)sFno.c_str();

		sprintf((char*)query, "INSERT INTO EMPLOYEE VALUES(%s, '%s', %s, %s);", cNo, cName, cSalary, cFno);
		SQLExecDirect(hStmt, query, SQL_NTS);

		successMessage();
		system("pause");
		break;
	case 6: // DEPENDENT
		printDependentExample();

		getchar();
		enterNo();
		getline(cin, sFno);
		cFno = (char*)sFno.c_str();

		enterName();
		getline(cin, sName);
		cName = (char*)sName.c_str();

		enterWeddingDate();
		getline(cin, sWedding);
		cWedding = (char*)sWedding.c_str();

		// 0 �����Ǵ°� üũ�ϱ�
		sprintf((char*)query, "INSERT INTO DEPENDENT_ VALUES('%s', %s, %s);", cName, cWedding, cFno);
		SQLExecDirect(hStmt, query, SQL_NTS);

		successMessage();
		system("pause");
		break;
	}
}

void DELETE_TABLE()
{

}

void UPDATE()
{

}

// ��� ���� �������� ������� Error Message
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
