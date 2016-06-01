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
					DELETE_TABLE();
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

/*						SELECT						*/

void SELECT()
{
	bool dataExistCheck = false;
	printSelectTable();
	cin >> selectTableNum;

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

		// 데이터가 존재하지 않을시
		//if (SQLFetch(hStmt) == SQL_NO_DATA)
		//{
		//	noExistData();
		//	system("pause");
		//	break;
		//}

		while (SQLFetch(hStmt) != SQL_NO_DATA)
		{
			dataExistCheck = true; // 결과를 체크하기 위한 BOOL
			cout << "TV Program Name : " << TVPNAME << endl;
			cout << "Rating : " << RATING << endl;
			divisionLine();
		}

		// 결과가 없을 시 
		if (!dataExistCheck) { noExistData(); }


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

		cout << endl;
		divisionLine();
		while (SQLFetch(hStmt) != SQL_NO_DATA)
		{
			dataExistCheck = true; // 결과를 체크하기 위한 BOOL
			cout << "Cast Name : " << CASTNAME << endl;
			cout << "Cast Job : " << CASTJOB << endl;
			cout << "Cast Age : " << CASTAGE << endl;
			divisionLine();
		}

		// 결과가 없을 시 
		if (!dataExistCheck) { noExistData(); }
		
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
				dataExistCheck = true; // 결과를 체크하기 위한 BOOL
				cout << "Employee Name : " << EMPNAME << endl;
				cout << "Employee Salary : " << SALARY << endl;
				divisionLine();
			}

			// 결과가 없을 시 
			if (!dataExistCheck) { noExistData(); }
			
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
				dataExistCheck = true; // 결과를 체크하기 위한 BOOL
				cout << "Employee Name : " << EMPNAME << endl;
				cout << "Employee Salary : " << SALARY << endl;
				divisionLine();
			}

			// 결과가 없을 시 
			if (!dataExistCheck) { noExistData(); }
			
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
				dataExistCheck = true; // 결과를 체크하기 위한 BOOL
				cout << "Employee Name : " << EMPNAME << endl;
				cout << "Employee Salary : " << SALARY << endl;
				divisionLine();
			}

			// 결과가 없을 시 
			if (!dataExistCheck) { noExistData(); }
			
			system("pause");
			break;
		default:
			break;
		}
		break;
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
			dataExistCheck = true; // 결과를 체크하기 위한 BOOL
			cout << "Broadcasting station corresponding to the " << ch << endl;
			cout << "Broadcasting station Name : " << BROADNAME << endl;
			divisionLine();
		}

		// 결과가 없을 시 
		if (!dataExistCheck) { noExistData(); }

		system("pause");
		break;
	case 5: // 해당 직원의 배우자와 결혼기념일 출력
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
			dataExistCheck = true; // 결과를 체크하기 위한 BOOL
			cout << EMPNAME << " husband is " << DEPNAME << endl;
			cout << "The wedding anniversary of the couple :  " << WEDDINGANNVIERSARY << endl;
			divisionLine();
		}

		// 결과가 없을 시 
		if (!dataExistCheck) { noExistData(); }
		
		system("pause");
		break;
	case 6: // '어떤' 방송국의 직원의 배우자와 결혼기념일 조회
		/*
			SELECT BROADNAME, EMPNAME, DEPNAME, WEDDINGANNVIERSARY
			FROM BROADCASTING_STATION AS B, EMPLOYEE AS E, DEPENDENT_ AS D
			WHERE B.BNO = E.F_BNO_EMP AND E.EMPNO = D.F_EMPNO AND B.BROADNAME = '방송국 이름'
		*/
		enterBroadcastingStationName();

		getchar();
		getline(cin, str);
		ch = (char*)str.c_str();
		cin.clear();

		sprintf((char*)query, "SELECT BROADNAME, EMPNAME, DEPNAME, WEDDINGANNVIERSARY FROM BROADCASTING_STATION AS B, EMPLOYEE AS E, DEPENDENT_ AS D WHERE B.BNO = E.F_BNO_EMP AND E.EMPNO = D.F_EMPNO AND B.BROADNAME = '%s'", ch);

		SQLExecDirect(hStmt, query, SQL_NTS);
		SQLBindCol(hStmt, 1, SQL_C_CHAR, BROADNAME, 20, NULL);
		SQLBindCol(hStmt, 2, SQL_C_CHAR, EMPNAME, 8, NULL);
		SQLBindCol(hStmt, 3, SQL_C_CHAR, DEPNAME, 10, NULL);
		SQLBindCol(hStmt, 4, SQL_C_CHAR, WEDDINGANNVIERSARY, 10, NULL);

		printTitle("RESULT");
		cout << endl;
		divisionLine();

		cout << " List spouse and wedding annviersary of all employee worked in " << BROADNAME << endl;
		divisionLine();

		while (SQLFetch(hStmt) != SQL_NO_DATA)
		{
			dataExistCheck = true; // 결과를 체크하기 위한 BOOL

			cout << endl << " Employee : " << EMPNAME << endl;
			cout << " Spouse : " << DEPNAME << endl;
			cout << " Wedding Annviersary : " << WEDDINGANNVIERSARY << endl;

			divisionLine();
		}
		cout << endl;

		// 결과가 없을 시 
		if (!dataExistCheck) { noExistData(); }

		system("pause");
		break;
	default:
		break;
	} // switch ( 모드에 따라서 )
} // SELECT

  /*						INSERT						*/

void INSERT()
{
	int insertResultCode = 0;

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
		insertResultCode = SQLExecDirect(hStmt, query, SQL_NTS);

		// INSERT 결과에 따른 메세지 출력
		if (insertResultCode == 0) { successMessage(); }
		else if (insertResultCode == -1) { errorMessage(); }
		else { damageErrorMessage(); }

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
		insertResultCode = SQLExecDirect(hStmt, query, SQL_NTS);

		// INSERT 결과에 따른 메세지 출력
		if (insertResultCode == 0) { successMessage(); }
		else if (insertResultCode == -1) { errorMessage(); }
		else { damageErrorMessage(); }

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
		insertResultCode = SQLExecDirect(hStmt, query, SQL_NTS);

		// INSERT 결과에 따른 메세지 출력
		if (insertResultCode == 0) { successMessage(); }
		else if (insertResultCode == -1) { errorMessage(); }
		else { damageErrorMessage(); }

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
		insertResultCode = SQLExecDirect(hStmt, query, SQL_NTS);

		// INSERT 결과에 따른 메세지 출력
		if (insertResultCode == 0) { successMessage(); }
		else if (insertResultCode == -1) { errorMessage(); }
		else { damageErrorMessage(); }

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
		insertResultCode = SQLExecDirect(hStmt, query, SQL_NTS);

		// INSERT 결과에 따른 메세지 출력
		if (insertResultCode == 0) { successMessage(); }
		else if (insertResultCode == -1) { errorMessage(); }
		else { damageErrorMessage(); }

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

		// 0 생략되는것 체크하기
		sprintf((char*)query, "INSERT INTO DEPENDENT_ VALUES('%s', %s, %s);", cName, cWedding, cFno);
		insertResultCode = SQLExecDirect(hStmt, query, SQL_NTS);

		// INSERT 결과에 따른 메세지 출력
		if (insertResultCode == 0) { successMessage(); }
		else if (insertResultCode == -1) { errorMessage(); }
		else { damageErrorMessage(); }

		system("pause");
		break;
	}
}

void DELETE_TABLE()
{
	int deleteResultCode = 0;

	printDeleteMenu();
	cin >> selectTableNum;

	switch (selectTableNum)
	{
	case 1: // 1. 방송국 삭제하기
		getchar();
		enterStationNameForDelete();
		getline(cin, sNo);
		cNo = (char*)sNo.c_str();

		sprintf((char*)query, "DELETE FROM BROADCASTING_STATION WHERE BNO = '%s';", cNo);
		deleteResultCode = SQLExecDirect(hStmt, query, SQL_NTS);

		if (deleteResultCode == 0) { successMessage(); }
		else					   { errorMessage(); }

		system("pause");
		break;
	case 2: // 2. 직원 해고하기
		getchar();
		enterEmployeeNumForDelete();
		getline(cin, sNo);
		cNo = (char*)sNo.c_str();

		sprintf((char*)query, "DELETE FROM EMPLOYEE WHERE EMPNO = '%s';", cNo);
		deleteResultCode = SQLExecDirect(hStmt, query, SQL_NTS);

		if (deleteResultCode == 0) { successMessage(); }
		else					   { errorMessage(); }

		system("pause");
		break;
	case 3: // 3. TV프로그램 폐지하기
		getchar();
		enterTvProgramNumForDelete();
		getline(cin, sNo);
		cNo = (char*)sNo.c_str();

		sprintf((char*)query, "DELETE FROM TVPROGRAM WHERE TVPNO = '%s';", cNo);
		deleteResultCode = SQLExecDirect(hStmt, query, SQL_NTS);

		if (deleteResultCode == 0) { successMessage(); }
		else					   { errorMessage(); }

		system("pause");
		break;
	}
}

void UPDATE()
{
	// 전체 수정하는 기능을 만들고 ( 1~6 )
	// NULL 이 아닌 값 위주로 수정하는 기능을 만들자
	// 1. 방송국 이름 수정하기
	// 2. TV프로그램 시청률 수정하기
	// 3. 출연진 나이 수정하기

	int updateResultCode = 0;

	printUpdateMenu();
	cin >> selectTableNum;

	switch (selectTableNum)
	{
	case 1:
		updateTable();
		cin >> selectTableNum;
		switch (selectNumber)
		{

		}
		break;
	case 2: // 방송국 이름 수정하기

		// 원래정보를 입력받고
		getchar();
		enterStationName();
		getline(cin, sName);
		cName = (char*)sName.c_str();

		// 바꿀내용을 입력받는다
		getchar();
		whatReplacement();
		getline(cin, str);

		


			



		break;
	case 3: // TV프로그램 시청률 수정하기
		break;
	case 4: // 출연진 나이 수정하기
		break;
	}
}

// 결과 값이 존재하지 않을경우 Error Message
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
