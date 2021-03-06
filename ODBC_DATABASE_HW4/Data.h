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
char selectMenu;

string str;
char * ch;

string sNo;
string sName;
string sLocation;
string sRating;
string sTime;
string sFno;
string sFno2;
string sAge;
string sJob;
string sSalary;
string sWedding;
string sRep;
string sSD;

char * cNo;
char * cName;
char * cLocation;
char * cRating;
char * cTime;
char * cFno;
char * cFno2;
char * cAge;
char * cJob;
char * cSalary;
char * cWedding;
char * cRep;
char * cSD;

/*						FUNCTION							*/
void mainMenuPrint();
void printSelectNumber();
void centerString(char * s);
void printTitle(char * string);
void printSelectTable();
void enterTvProgramName();
void enterCastName();
void noExistData();
bool printNoExistMessage(int param);
void selectBroadcastingStation();
void selectCast();
void selectDependent();
void selectEmployee();
void selectEnt();
void selectTvProgram();
void divisionLine();
void pirntSalarySelectTable();
void enterSalary();
void enterEmployeeName();
void insertTable();
void printBCSExample();
void enterNo();
void enterName();
void enterLocation();
void successMessage();
void errorMessage();
void printTvProgramExample();
void enterTime();
void enterRating();
void printEntExample();
void printCastExample();
void enterAge();
void enterJob();
void printEmployeeExample();
void enterSalaryData();
void printDependentExample();
void enterWeddingDate();
void damageErrorMessage();
void enterBroadcastingStationName();
void printDeleteMenu();
void enterStationNameForDelete();
void enterEmployeeNumForDelete();
void enterTvProgramNumForDelete();
void printUpdateMenu();
void updateTable();
void enterStationNameForUpdate();
void enterStationName();
void whatReplacement();
void enterTvProgramNum();
void enterCastNameForUpdate();

void setUpdateInfoOfStation();
void setUpdateInfoOfCast();
void setUpdateInfoOfDependent();
void setUpdateInfoOfEmployee();
void setUpdateInfoOfEntertainment();
void setUpdateInfoOfTvProgram();

void enterBNO();
void enterBROADNAME();
void enterLOCATIONForEnt();
void enterTVPNO();
void enterTVPNAME();
void enterRATING();
void enterTVPTIME();
void enterForeignKeyOfBNO();
void updateAllOfStation();
void updateAllOfCast();
void updateAllOfDependent();
void updateAllOfEmployee();
void updateAllOfEnt();
void updateAllOfTvProgram();
void enterCASTNO();
void enterCASTJOB();
void enterCASTNAME();
void enterCASTAGE();
void enterForeignKeyOfENTNO();
void enterForeignKeyOfTVPNO();
void enterDEPNAME();
void enterWEDDINGANNIVERSARY();
void enterForeignKeyOfEMPNO();
void enterEMPNO();
void enterEMPNAME();
void enterSALARY();
void enterForeignKeyOfBNOEMP();
void enterENTNO();
void enterENTNAME();
void printNewInputData();


bool DBConnect(SQLHENV * hEnv, SQLHDBC * hDbc);		// Connect to the SQL Server
void DBDisconnect(SQLHENV * hEnv, SQLHDBC * hDbc);	// Disconnect from the SQL Server

void SELECT();
void INSERT();
void DELETE_TABLE();
void UPDATE();
void SHOW();
void JOIN();