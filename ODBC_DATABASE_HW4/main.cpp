#include <stdio.h>
#include <iostream>
#include "Data.h"
#include "MsSQL.h"

using namespace std;

// select - 1
int main(int argc, char *argv[])
{
	int mode = 0;
	int selTable = 0;
	char* sentence;

	if (DBConnect(&hEnv, &hDbc) == true)
	{
		mainMenuPrint();
		cin >> mode;

		switch (mode)
		{
		case 1: // SELECT
			printf("SELECT 할 테이블을 입력하세요\n");
			printf("1. BROADCASTING	STATION	  2. TV PROGRAM	  3. ENTERTAINMENT  4. CAST  5. EMPLOYEE  6. DEPENDENT\n");
			printf(" → ");
			scanf("%d", &selTable);
			switch (selTable)
			{
			case 1: // BROADCASTING
				if (DBConnect(&hEnv, &hDbc) == 1)
				{
					if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS)
					{
						//sprintf((char*)query, "SELECT BNO, BROADNAME, LOCATION FROM BROADCASTING_STATION");
						sprintf((char*)query, "SELECT * FROM BROADCASTING_STATION");
						SQLExecDirect(hStmt, query, SQL_NTS);

						SQLBindCol(hStmt, 1, SQL_INTEGER, &BNO, NULL, NULL);
						SQLBindCol(hStmt, 2, SQL_C_CHAR, BROADNAME, 20, NULL);
						SQLBindCol(hStmt, 3, SQL_C_CHAR, BROADLOCATION, 50, NULL);

						printf("BNO	BROADNAME		BROADLOCATION\n");

						while (SQLFetch(hStmt) != SQL_NO_DATA)
						{
							printf("%d\t%s\t%s\n", BNO, BROADNAME, BROADLOCATION);
						}

						SQLCloseCursor(hStmt);
						SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
					}
				}
				break;
			case 2: // TV PROGRAM
				break;
			case 3: // ENTERTAINMENT
				break;
			case 4: // CAST
				break;
			case 5: // EMPLOYEE
				break;
			case 6: // DEPENDENT
				break;
			} // switch (SELECT TABLE SWITCH)
			break;
		case 2: // JOIN

			break;
		} // switch (MODE SWITCH)

		// Disconnect from the SQL Server
		DBDisconnect(&hEnv, &hDbc);
	}
	else
	{
		printf("Fail to Connect!!\n");
	}
	return 0;
}

