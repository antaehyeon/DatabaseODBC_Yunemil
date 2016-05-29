#pragma once

#include <Windows.h>
#include <sql.h>
#include <sqlext.h>
#include <string>

using namespace std;

/*						DATA							*/

// BROADCASTING_STATION
SQLINTEGER BNO;
SQLCHAR BROADNAME[20], BROADLOCATION[100];

// TVPROGRAM
SQLINTEGER TVPNO, F_BNO_TV;
SQLCHAR TVPNAME[50], TVPTIME[100];
SQLDOUBLE RATING;

// ENTERTAINMENT
SQLINTEGER ENTNO;
SQLCHAR ENTNAME[20], ENTLOCATION[100];

// CAST_
SQLINTEGER CASTNO, CASTAGE, F_ENTNO, F_TVPNO;
SQLCHAR CASTJOB[20], CASTNAME[20];

// EMPLOYEE
SQLINTEGER EMPNO, SALARY, F_BNO_EMP;
SQLCHAR EMPNAME[20];

// DEPENDENT_
SQLCHAR DEPNAME[12], WEDDINGANNVIERSARY[10];
SQLINTEGER F_EMPNO;

SQLHENV hEnv = NULL;
SQLHDBC hDbc = NULL;
static SQLCHAR query[256];	// Query statement
SQLHSTMT hStmt;				// Statement Handle#pragma once

int mode = 0;
int selectTableNum = 0;
int selectFunctionNumber = 0;
int selectNumber = 0;

string querySentence;
SQLINTEGER COUNTROW;

/*						FUNCTION							*/

void mainMenuPrint();
void printInputQueryMenu();
void printSelectNumber();
void centerString(char * s);
void printTitle(char * string);
void printSelectTable();
void printJoinList();
void enterTvProgramName();
void enterCastName();
void noExistData();
bool printNoExistMessage(int param);
void divisionLine();
void pirntSalarySelectTable();
void enterSalary();
void enterEmployeeName();

bool DBConnect(SQLHENV * hEnv, SQLHDBC * hDbc);		// Connect to the SQL Server
void DBDisconnect(SQLHENV * hEnv, SQLHDBC * hDbc);	// Disconnect from the SQL Server

void SELECT();
void INSERT();
void JOIN();