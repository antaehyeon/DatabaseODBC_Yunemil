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
			cin >> selectMenu;

			if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS)
			{
				switch (selectMenu)
				{
				case '1': // SELECT
					SELECT();
					break;
				case '2': // INSERT
					INSERT();
					break;
				case '3': // DELETE
					DELETE_TABLE();
					break;
				case '4': // UPDATE
					UPDATE();
					break;
				case '5': // SHOW
					SHOW();
					break;
				case '6':
					return;
				default:
					cin.clear();
					fflush(stdin);
					continue;
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


//if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS)
//{
//
//	SQLCloseCursor(hStmt);
//	SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
//}


/*						SELECT						*/

void SELECT()
{
	bool dataExistCheck = false;
	printSelectTable();
	cin >> selectMenu;
	switch (selectMenu)
	{
	case '1': // TV 프로그램의 시청률 조회
		printTitle("RESULT");

		selectTvProgram();
		
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

		cout << endl;
		divisionLine();

		while (SQLFetch(hStmt) != SQL_NO_DATA)
		{
			dataExistCheck = true; // 결과를 체크하기 위한 BOOL
			cout << endl << "TV Program Name : " << TVPNAME << endl;
			cout << "Rating : " << RATING << endl;
			divisionLine();
		}
		cout << endl;

		// 결과가 없을 시 
		if (!dataExistCheck) { noExistData(); }

		system("pause");
		break;
	case '2': // 배우의 직업과 나이 조회
		printTitle("RESULT");
		selectCast();
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
			cout << endl << "Cast Name : " << CASTNAME << endl;
			cout << "Cast Job : " << CASTJOB << endl;
			cout << "Cast Age : " << CASTAGE << endl;
			divisionLine();
		}
		cout << endl;

		// 결과가 없을 시 
		if (!dataExistCheck) { noExistData(); }
		
		system("pause");

		break;
	case '3': // 방송국 직원의 월급 조회
		printTitle("RESULT");
		
		pirntSalarySelectTable();
		cin >> selectMenu;
		switch (selectMenu)
		{
		case '1': // 급여 검색
			selectEmployee();
			enterEmployeeName();

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
				cout << endl << "Employee Name : " << EMPNAME << endl;
				cout << "Employee Salary : " << SALARY << endl;
				divisionLine();
			}
			cout << endl;

			// 결과가 없을 시 
			if (!dataExistCheck) { noExistData(); }
			
			system("pause");
			break;
		case '2': // 입력된 값 이상 급여 검색
			selectEmployee();
			enterSalary();

			getchar();
			getline(cin, str);
			ch = (char*)str.c_str();
			cin.clear();

			if (str == "")
			{
				errorMessage();
				system("pause");
				break;
			}

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
				cout << endl << "Employee Name : " << EMPNAME << endl;
				cout << "Employee Salary : " << SALARY << endl;
				divisionLine();
			}
			cout << endl;

			// 결과가 없을 시 
			if (!dataExistCheck) { noExistData(); }
			
			system("pause");
			break;
		case '3': // 입력된 값 이하 급여 검색
			selectEmployee();
			enterSalary();

			getchar();
			getline(cin, str);
			ch = (char*)str.c_str();
			cin.clear();

			if (str == "")
			{
				errorMessage();
				system("pause");
				break;
			}

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
				cout << endl << "Employee Name : " << EMPNAME << endl;
				cout << "Employee Salary : " << SALARY << endl;
				divisionLine();
			}
			cout << endl;

			// 결과가 없을 시 
			if (!dataExistCheck) { noExistData(); }
			
			system("pause");
			break;
		default:
			break;
		}
		break;
	case '4': // 중첩질의
		/*
			SELECT	 BROADNAME
			FROM	 BROADCASTING_STATION
			WHERE	 BNO = ( SELECT F_BNO_TV
							 FROM TVPROGRAM
							 WHERE TVPNAME = 'TV프로그램 이름');
		*/
		
		selectTvProgram();
		enterTvProgramName();
	
		getchar();
		getline(cin, str);
		ch = (char*)str.c_str();
		cin.clear();

		sprintf((char*)query, "SELECT BROADNAME FROM BROADCASTING_STATION WHERE BNO = (SELECT F_BNO_TV FROM TVPROGRAM WHERE TVPNAME = '%s')", ch);
		SQLExecDirect(hStmt, query, SQL_NTS);
		SQLBindCol(hStmt, 1, SQL_C_CHAR, BROADNAME, 20, NULL);

		printTitle("RESULT");
		cout << endl;
		divisionLine();
		while (SQLFetch(hStmt) != SQL_NO_DATA)
		{
			dataExistCheck = true; // 결과를 체크하기 위한 BOOL
			cout << endl << "Broadcasting station corresponding to the " << ch << endl;
			cout << "Broadcasting station Name : " << BROADNAME << endl;
			divisionLine();
		}
		cout << endl;

		// 결과가 없을 시 
		if (!dataExistCheck) { noExistData(); }

		system("pause");
		break;
	case '5': // 해당 직원의 배우자와 결혼기념일 출력
		/*
			SELECT EMPNAME, DEPNAME, WEDDINGANNVIERSARY
			FROM EMPLOYEE AS E, DEPENDENT_ AS D
			WHERE E.EMPNO = D.F_EMPNO AND (E.EMPNAME = '직원이름');
		*/
		selectEmployee();
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
			cout << endl << EMPNAME << " husband is " << DEPNAME << endl;
			cout << "The wedding anniversary of the couple :  " << WEDDINGANNVIERSARY << endl;
			divisionLine();
		}

		// 결과가 없을 시 
		if (!dataExistCheck) { noExistData(); }
		
		system("pause");
		break;
	case '6': // '어떤' 방송국의 직원의 배우자와 결혼기념일 조회
		/*
			SELECT BROADNAME, EMPNAME, DEPNAME, WEDDINGANNVIERSARY
			FROM BROADCASTING_STATION AS B, EMPLOYEE AS E, DEPENDENT_ AS D
			WHERE B.BNO = E.F_BNO_EMP AND E.EMPNO = D.F_EMPNO AND B.BROADNAME = '방송국 이름'
		*/
		selectBroadcastingStation();
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

		cout << endl << " List spouse and wedding annviersary of all employee worked in " << str << endl;
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

	cin >> selectMenu;

	switch (selectMenu)
	{
	case '1': // BROADCASTING_STATION
		printBCSExample();
		selectBroadcastingStation();

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
	case '2': // TV PROGRAM
		printTvProgramExample();
		selectTvProgram();

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
	case '3': // ENTERTAINMENT
		printEntExample();
		selectEnt();

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
	case '4': // CAST
		printCastExample();
		selectCast();

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
	case '5': // EMPLOYEE
		printEmployeeExample();
		selectEmployee();

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
	case '6': // DEPENDENT
		printDependentExample();
		selectDependent();

		getchar();
		enterName();
		getline(cin, sName);
		cName = (char*)sName.c_str();

		enterWeddingDate();
		getline(cin, sWedding);
		cWedding = (char*)sWedding.c_str();

		enterForeignKeyOfEMPNO();
		getline(cin, sFno);
		cFno = (char*)sFno.c_str();

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
	cin >> selectMenu;

	switch (selectMenu)
	{
	case '1': // 1. 방송국 삭제하기
		getchar();
		selectBroadcastingStation();
		enterStationNameForDelete();
		getline(cin, sNo);
		cNo = (char*)sNo.c_str();

		sprintf((char*)query, "DELETE FROM BROADCASTING_STATION WHERE BNO = '%s';", cNo);
		deleteResultCode = SQLExecDirect(hStmt, query, SQL_NTS);

		if (deleteResultCode == 0) { successMessage(); }
		else					   { errorMessage(); }

		system("pause");
		break;
	case '2': // 2. 직원 해고하기
		getchar();
		selectEmployee();
		enterEmployeeNumForDelete();
		getline(cin, sNo);
		cNo = (char*)sNo.c_str();

		sprintf((char*)query, "DELETE FROM EMPLOYEE WHERE EMPNO = '%s';", cNo);
		deleteResultCode = SQLExecDirect(hStmt, query, SQL_NTS);

		if (deleteResultCode == 0) { successMessage(); }
		else					   { errorMessage(); }

		system("pause");
		break;
	case '3': // 3. TV프로그램 폐지하기
		getchar();
		selectTvProgram();
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
	cin >> selectMenu;

	switch (selectMenu)
	{
	case '1':
		updateTable();
		cin >> selectMenu;
		switch (selectMenu)
		{
		case '1': // BROADCASTING
			updateAllOfStation();

			selectBroadcastingStation();

			getchar();
			setUpdateInfoOfStation();
			getline(cin, sSD);
			cSD = (char*)sSD.c_str();

			printNewInputData();
				
			enterBNO();
			getline(cin, sNo);
			cNo = (char*)sNo.c_str();

			enterBROADNAME();
			getline(cin, sName);
			cName = (char*)sName.c_str();

			enterLocation();
			getline(cin, sLocation);
			cLocation = (char*)sLocation.c_str();

			sprintf((char*)query, "UPDATE BROADCASTING_STATION SET BNO = %s, BROADNAME = '%s', LOCATION = '%s' WHERE BNO = %s;", cNo, cName, cLocation, cSD);
			updateResultCode = SQLExecDirect(hStmt, query, SQL_NTS);

			if (updateResultCode == 0) { successMessage(); }
			else { errorMessage(); }

			system("pause");
			break;
		case '2': // CAST
			updateAllOfCast();

			selectCast();

			getchar();
			setUpdateInfoOfCast();
			getline(cin, sSD);
			cSD = (char*)sSD.c_str();

			printNewInputData();

			enterCASTNO();
			getline(cin, sNo);
			cNo = (char*)sNo.c_str();

			enterCASTJOB();
			getline(cin, sJob);
			cJob = (char*)sJob.c_str();

			enterCASTNAME();
			getline(cin, sName);
			cName = (char*)sName.c_str();

			enterCASTAGE();
			getline(cin, sAge);
			cAge = (char*)sAge.c_str();

			enterForeignKeyOfENTNO();
			getline(cin, sFno);
			cFno = (char*)sFno.c_str();

			enterForeignKeyOfTVPNO();
			getline(cin, sFno2);
			cFno2 = (char*)sFno2.c_str();

			sprintf((char*)query, "UPDATE CAST_ SET CASTNO = %s, CASTJOB = '%s', CASTNAME = '%s', CASTAGE = %s, F_ENTNO = %s, F_TVPNO = %s WHERE CASTNO = %s;", cNo, cJob, cName, cAge, cFno, cFno2, cSD);
			updateResultCode = SQLExecDirect(hStmt, query, SQL_NTS);

			if (updateResultCode == 0) { successMessage(); }
			else { errorMessage(); }

			system("pause");
			break;
		case '3': // DEPENDENT
			updateAllOfDependent();

			selectDependent();

			getchar();
			setUpdateInfoOfDependent();
			getline(cin, sSD);
			cSD = (char*)sSD.c_str();

			printNewInputData();

			enterDEPNAME();
			getline(cin, sName);
			cName = (char*)sName.c_str();

			enterWEDDINGANNIVERSARY();
			getline(cin, sWedding);
			cWedding = (char*)sWedding.c_str();

			enterForeignKeyOfEMPNO();
			getline(cin, sFno);
			cFno = (char*)sFno.c_str();

			sprintf((char*)query, "UPDATE DEPENDENT_ SET DEPNAME = '%s', WEDDINGANNVIERSARY = %s, F_EMPNO = %s WHERE DEPNAME = '%s';", cName, cWedding, cFno, cSD);
			updateResultCode = SQLExecDirect(hStmt, query, SQL_NTS);

			if (updateResultCode == 0) { successMessage(); }
			else { errorMessage(); }

			system("pause");
			break;
		case '4': // EMPLOYEE
			updateAllOfEmployee();

			selectEmployee();

			getchar();
			setUpdateInfoOfEmployee();
			getline(cin, sSD);
			cSD = (char*)sSD.c_str();

			printNewInputData();

			enterEMPNO();
			getline(cin, sNo);
			cNo = (char*)sNo.c_str();

			enterEMPNAME();
			getline(cin, sName);
			cName = (char*)sName.c_str();

			enterSALARY();
			getline(cin, sSalary);
			cSalary = (char*)sSalary.c_str();

			enterForeignKeyOfBNOEMP();
			getline(cin, sFno);
			cFno = (char*)sFno.c_str();

			sprintf((char*)query, "UPDATE EMPLOYEE SET EMPNO = %s, EMPNAME = '%s', SALARY = %s, F_BNO_EMP = %s WHERE EMPNO = %s;", cNo, cName, cSalary, cFno, cSD);
			updateResultCode = SQLExecDirect(hStmt, query, SQL_NTS);

			if (updateResultCode == 0) { successMessage(); }
			else { errorMessage(); }

			system("pause");
			break;
		case '5': // ENTERTAINMENT
			updateAllOfEnt();

			selectEnt();

			getchar();
			setUpdateInfoOfEntertainment();
			getline(cin, sSD);
			cSD = (char*)sSD.c_str();

			printNewInputData();

			enterENTNO();
			getline(cin, sNo);
			cNo = (char*)sNo.c_str();

			enterENTNAME();
			getline(cin, sName);
			cName = (char*)sName.c_str();

			enterLOCATIONForEnt();
			getline(cin, sLocation);
			cLocation = (char*)sLocation.c_str();

			sprintf((char*)query, "UPDATE ENTERTAINMENT SET ENTNO = %s, ENTNAME = '%s', ENTLOCATION = '%s' WHERE ENTNO = %s;", cNo, cName, cLocation, cSD);
			updateResultCode = SQLExecDirect(hStmt, query, SQL_NTS);

			if (updateResultCode == 0) { successMessage(); }
			else { errorMessage(); }

			system("pause");
			break; 
		case '6': // TVPROGRAM
			updateAllOfTvProgram();

			selectTvProgram();

			getchar();
			setUpdateInfoOfTvProgram();
			getline(cin, sSD);
			cSD = (char*)sSD.c_str();

			printNewInputData();

			enterTVPNO();
			getline(cin, sNo);
			cNo = (char*)sNo.c_str();

			enterTVPNAME();
			getline(cin, sName);
			cName = (char*)sName.c_str();

			enterRATING();
			getline(cin, sRating);
			cRating = (char*)sRating.c_str();

			enterTVPTIME();
			getline(cin, sTime);
			cTime = (char*)sTime.c_str();

			enterForeignKeyOfBNO();
			getline(cin, sFno);
			cFno = (char*)sFno.c_str();

			sprintf((char*)query, "UPDATE TVPROGRAM SET TVPNO = %s, TVPNAME = '%s', RATING = %s, TVPTIME = '%s', F_BNO_TV = '%s' WHERE TVPNO = %s;", cNo, cName, cRating, cTime, cFno, cSD);
			updateResultCode = SQLExecDirect(hStmt, query, SQL_NTS);

			if (updateResultCode == 0) { successMessage(); }
			else { errorMessage(); }

			system("pause");
			break;
		}
		break;
	case '2': // 방송국 이름 수정하기

		// 원래정보를 입력받고
		getchar();
		selectBroadcastingStation();
		enterStationName();
		getline(cin, sName);
		cName = (char*)sName.c_str();

		printNewInputData();

		// 바꿀내용을 입력받는다
		whatReplacement();
		getline(cin, sRep);
		cRep = (char*)sRep.c_str();

		sprintf((char*)query, "UPDATE BROADCASTING_STATION SET BROADNAME = '%s' WHERE BROADNAME = '%s';", cRep, cName);
		updateResultCode = SQLExecDirect(hStmt, query, SQL_NTS);
		
		if (updateResultCode == 0) { successMessage(); }
		else { errorMessage(); }

		system("pause");
		break;
	case '3': // TV프로그램 시청률 수정하기
		getchar();
		selectTvProgram();
		enterTvProgramNum();
		getline(cin, sNo);
		cNo = (char*)sNo.c_str();

		printNewInputData();

		whatReplacement();
		getline(cin, sRep);
		cRep = (char*)sRep.c_str();

		sprintf((char*)query, "UPDATE TVPROGRAM SET RATING = '%s' WHERE TVPNO = '%s';", cRep, cNo);
		updateResultCode = SQLExecDirect(hStmt, query, SQL_NTS);

		if (updateResultCode == 0) { successMessage(); }
		else { errorMessage(); }

		system("pause");
		break;
	case '4': // 출연진 나이 수정하기
		getchar();
		selectCast();
		enterCastNameForUpdate();
		getline(cin, sName);
		cName = (char*)sName.c_str();

		printNewInputData();

		whatReplacement();
		getline(cin, sRep);
		cRep = (char*)sRep.c_str();

		sprintf((char*)query, "UPDATE CAST_ SET CASTAGE = '%s' WHERE CASTNAME = '%s';", cRep, cName);
		updateResultCode = SQLExecDirect(hStmt, query, SQL_NTS);

		if (updateResultCode == 0) { successMessage(); }
		else { errorMessage(); }

		system("pause");
		break;
	}
}

void SHOW()
{
	selectBroadcastingStation();
	selectTvProgram();
	selectEnt();
	selectCast();
	selectEmployee();
	selectDependent();
	system("pause");
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

void selectBroadcastingStation()
{
	if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS)
	{
		centerString("BROADCASTING RESULT");

		sprintf((char*)query, "SELECT * FROM BROADCASTING_STATION");
		SQLExecDirect(hStmt, query, SQL_NTS);

		SQLBindCol(hStmt, 1, SQL_INTEGER, &BNO, 4, NULL);
		SQLBindCol(hStmt, 2, SQL_C_CHAR, BROADNAME, 20, NULL);
		SQLBindCol(hStmt, 3, SQL_C_CHAR, BROADLOCATION, 70, NULL);

		cout << endl << "BNO	BROADNAME		BROADLOCATION" << endl;

		while (SQLFetch(hStmt) != SQL_NO_DATA)
		{
			cout << BNO << "\t" << BROADNAME << "\t" << BROADLOCATION << endl;
		}
		cout << endl << endl;
	
		SQLCloseCursor(hStmt);
	}
}

void selectTvProgram()
{
	if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS)
	{
		centerString("TV PROGRAM RESULT");
		sprintf((char*)query, "SELECT * FROM TVPROGRAM");
		SQLExecDirect(hStmt, query, SQL_NTS);

		SQLBindCol(hStmt, 1, SQL_INTEGER, &TVPNO, 8, NULL);
		SQLBindCol(hStmt, 2, SQL_C_CHAR, TVPNAME, 20, NULL);
		SQLBindCol(hStmt, 3, SQL_DOUBLE, &RATING, 3, NULL);
		SQLBindCol(hStmt, 4, SQL_C_CHAR, TVPTIME, 24, NULL);
		SQLBindCol(hStmt, 5, SQL_INTEGER, &F_BNO_TV, 8, NULL);

		cout << endl << "TVPNO	TVPNAME				RATING		TVPTIME				F_BNO_TV" << endl;

		while (SQLFetch(hStmt) != SQL_NO_DATA)
		{
			cout << TVPNO << "\t" << TVPNAME << "\t\t" << RATING << "\t\t" << TVPTIME << "\t\t" << F_BNO_TV << endl;
		}
		cout << endl << endl;
		SQLCloseCursor(hStmt);
	}
}

void selectEnt()
{
	if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS)
	{
		centerString("ENTERTAINMENT RESULT");
		sprintf((char*)query, "SELECT * FROM ENTERTAINMENT");
		SQLExecDirect(hStmt, query, SQL_NTS);

		SQLBindCol(hStmt, 1, SQL_INTEGER, &ENTNO, 4, NULL);
		SQLBindCol(hStmt, 2, SQL_C_CHAR, ENTNAME, 20, NULL);
		SQLBindCol(hStmt, 3, SQL_C_CHAR, ENTLOCATION, 70, NULL);

		cout << endl << "ENTNO	ENTNAME			ENTLOCATION" << endl;

		while (SQLFetch(hStmt) != SQL_NO_DATA)
		{
			cout << ENTNO << "\t" << ENTNAME << "\t" << ENTLOCATION << endl;
		}
		cout << endl << endl;
		SQLCloseCursor(hStmt);
	}
}

void selectCast()
{
	if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS)
	{
		centerString("CAST RESULT");
		sprintf((char*)query, "SELECT * FROM CAST_");
		SQLExecDirect(hStmt, query, SQL_NTS);

		SQLBindCol(hStmt, 1, SQL_INTEGER, &CASTNO, 8, NULL);
		SQLBindCol(hStmt, 2, SQL_C_CHAR, CASTJOB, 10, NULL);
		SQLBindCol(hStmt, 3, SQL_C_CHAR, CASTNAME, 8, NULL);
		SQLBindCol(hStmt, 4, SQL_INTEGER, &CASTAGE, 4, NULL);
		SQLBindCol(hStmt, 5, SQL_INTEGER, &F_ENTNO, 4, NULL);
		SQLBindCol(hStmt, 6, SQL_INTEGER, &F_TVPNO, 4, NULL);

		cout << endl << "CASTNO		CASTJOB			CASTNAME	CASTANGE	F_ENTNO		F_TVPNO" << endl;

		while (SQLFetch(hStmt) != SQL_NO_DATA)
		{
			cout << CASTNO << "\t\t" << CASTJOB << "\t\t" << CASTNAME << "\t\t" << CASTAGE << "\t\t" << F_ENTNO << "\t\t" << F_TVPNO << endl;
		}
		cout << endl << endl;
		SQLCloseCursor(hStmt);
	}
}

void selectEmployee()
{
	if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS)
	{
		centerString("EMPLOYEE RESULT");
		sprintf((char*)query, "SELECT * FROM EMPLOYEE");
		SQLExecDirect(hStmt, query, SQL_NTS);

		SQLBindCol(hStmt, 1, SQL_INTEGER, &EMPNO, 8, NULL);
		SQLBindCol(hStmt, 2, SQL_C_CHAR, EMPNAME, 8, NULL);
		SQLBindCol(hStmt, 3, SQL_INTEGER, &SALARY, 10, NULL);
		SQLBindCol(hStmt, 4, SQL_INTEGER, &F_BNO_EMP, 4, NULL);

		cout << endl << "EMPNO		EMPNAME		SALARY		F_BNO_EMP" << endl;

		while (SQLFetch(hStmt) != SQL_NO_DATA)
		{
			cout << EMPNO << "\t\t" << EMPNAME << "\t\t" << SALARY << "\t\t" << F_BNO_EMP << endl;
		}

		cout << endl << endl;
		SQLCloseCursor(hStmt);
	}
}

void selectDependent()
{
	if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS)
	{
		centerString("DEPENDENT RESULT");
		sprintf((char*)query, "SELECT * FROM DEPENDENT_");
		SQLExecDirect(hStmt, query, SQL_NTS);

		SQLBindCol(hStmt, 1, SQL_C_CHAR, DEPNAME, 8, NULL);
		SQLBindCol(hStmt, 2, SQL_C_CHAR, WEDDINGANNVIERSARY, 10, NULL);
		SQLBindCol(hStmt, 3, SQL_INTEGER, &F_EMPNO, 4, NULL);

		cout << endl << "DEPNAME		WEDDINGANNVIERSARY		F_EMPNO" << endl;

		while (SQLFetch(hStmt) != SQL_NO_DATA)
		{
			cout << DEPNAME << "\t\t" << WEDDINGANNVIERSARY << "\t\t\t\t" << F_EMPNO << endl;
		}
		SQLCloseCursor(hStmt);
	}
}