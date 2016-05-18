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
			mainMenuPrint();
			cin >> mode;

			switch (mode)
			{
			case 1: // 쿼리입력모드
				printInputQueryMenu();
				cin >> querySentence;
				break;
			case 2: // 번호선택모드
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
					case 5: // JOIN
						JOIN();
						break;
					} // switch (입력된 번호에 따라)

					SQLCloseCursor(hStmt);
					SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
				}
				break;
			case 3:
				return;
				break;
			} // switch (MODE SWITCH)
		}
		// Disconnect from the SQL Server
		DBDisconnect(&hEnv, &hDbc);
	} // if (DBConnect = true)
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

	switch (selectTableNum)
	{
	case 1: // BROADCASTING
		printTitle("BROADCASTING RESULT");
		sprintf((char*)query, "SELECT * FROM BROADCASTING_STATION");
		SQLExecDirect(hStmt, query, SQL_NTS);

		SQLBindCol(hStmt, 1, SQL_INTEGER, &BNO, 4, NULL);
		SQLBindCol(hStmt, 2, SQL_C_CHAR, BROADNAME, 20, NULL);
		SQLBindCol(hStmt, 3, SQL_C_CHAR, BROADLOCATION, 70, NULL);

		cout << "BNO	BROADNAME		BROADLOCATION" << endl;

		while (SQLFetch(hStmt) != SQL_NO_DATA)
		{
			cout << BNO << "\t" << BROADNAME << "\t" << BROADLOCATION << endl;
		}
		system("pause");
		break;
	case 2: // TV PROGRAM
		printTitle("TV PROGRAM RESULT");
		sprintf((char*)query, "SELECT * FROM TVPROGRAM");
		SQLExecDirect(hStmt, query, SQL_NTS);

		SQLBindCol(hStmt, 1, SQL_INTEGER, &TVPNO, 8, NULL);
		SQLBindCol(hStmt, 2, SQL_C_CHAR, TVPNAME, 20, NULL);
		SQLBindCol(hStmt, 3, SQL_DOUBLE, &RATING, 3, NULL);
		SQLBindCol(hStmt, 4, SQL_C_CHAR, TVPTIME, 24, NULL);
		SQLBindCol(hStmt, 5, SQL_INTEGER, &F_BNO_TV, 8, NULL);
		
		cout << "TVPNO	TVPNAME				RATING		TVPTIME				F_BNO_TV" << endl;

		while (SQLFetch(hStmt) != SQL_NO_DATA)
		{
			cout << TVPNO << "\t" << TVPNAME << "\t\t" << RATING << "\t\t" << TVPTIME << "\t\t" << F_BNO_TV << endl;
		}
		system("pause");
		break;
	case 3: // ENTERTAINMENT
		printTitle("ENTERTAINMENT RESULT");
		sprintf((char*)query, "SELECT * FROM ENTERTAINMENT");
		SQLExecDirect(hStmt, query, SQL_NTS);

		SQLBindCol(hStmt, 1, SQL_INTEGER, &ENTNO, 4, NULL);
		SQLBindCol(hStmt, 2, SQL_C_CHAR, ENTNAME, 20, NULL);
		SQLBindCol(hStmt, 3, SQL_C_CHAR, ENTLOCATION, 70, NULL);

		cout << "ENTNO	ENTNAME			ENTLOCATION" << endl;

		while (SQLFetch(hStmt) != SQL_NO_DATA)
		{
			cout << ENTNO << "\t" << ENTNAME << "\t" << ENTLOCATION << endl;
		}
		system("pause");
		break;
	case 4: // CAST
		printTitle("CAST RESULT");
		sprintf((char*)query, "SELECT * FROM CAST_");
		SQLExecDirect(hStmt, query, SQL_NTS);

		SQLBindCol(hStmt, 1, SQL_INTEGER, &CASTNO, 8, NULL);
		SQLBindCol(hStmt, 2, SQL_C_CHAR, CASTJOB, 8, NULL);
		SQLBindCol(hStmt, 3, SQL_C_CHAR, CASTNAME, 8, NULL);
		SQLBindCol(hStmt, 4, SQL_INTEGER, &CASTAGE, 4, NULL);

		cout << "CASTNO		CASTJOB		CASTNAME	CASTANGE" << endl;

		while (SQLFetch(hStmt) != SQL_NO_DATA)
		{
			cout << CASTNO << "\t\t" << CASTJOB << "\t\t" << CASTNAME << "\t\t" << CASTAGE << endl;
		}
		system("pause");
		break;
	case 5: // EMPLOYEE
		printTitle("EMPLOYEE RESULT");
		sprintf((char*)query, "SELECT * FROM EMPLOYEE");
		SQLExecDirect(hStmt, query, SQL_NTS);

		SQLBindCol(hStmt, 1, SQL_INTEGER, &EMPNO, 8, NULL);
		SQLBindCol(hStmt, 2, SQL_C_CHAR, EMPNAME, 8, NULL);
		SQLBindCol(hStmt, 3, SQL_INTEGER, &SALARY, 10, NULL);
		SQLBindCol(hStmt, 4, SQL_INTEGER, &F_BNO_EMP, 4, NULL);

		cout << "EMPNO		EMPNAME		SALARY		F_BNO_EMP" << endl;

		while (SQLFetch(hStmt) != SQL_NO_DATA)
		{
			cout << EMPNO << "\t\t" << EMPNAME << "\t\t" << SALARY << "\t\t" << F_BNO_EMP << endl;
		}
		system("pause");
		break;
	case 6: // DEPENDENT
		printTitle("DEPENDENT RESULT");
		sprintf((char*)query, "SELECT * FROM DEPENDENT_");
		SQLExecDirect(hStmt, query, SQL_NTS);

		SQLBindCol(hStmt, 1, SQL_C_CHAR, DEPNAME, 8, NULL);
		SQLBindCol(hStmt, 2, SQL_C_CHAR, WEDDINGANNVIERSARY, 10, NULL);
		SQLBindCol(hStmt, 3, SQL_INTEGER, &F_EMPNO, 4, NULL);

		cout << "DEPNAME		WEDDINGANNVIERSARY		F_EMPNO" << endl;

		while (SQLFetch(hStmt) != SQL_NO_DATA)
		{
			cout << DEPNAME << "\t\t" << WEDDINGANNVIERSARY << "\t\t\t\t" << F_EMPNO << endl;
		}
		system("pause");
		break;
	} // switch ( 모드에 따라서 )
} // SELECT

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
