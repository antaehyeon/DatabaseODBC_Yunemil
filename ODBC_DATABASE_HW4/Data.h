#pragma once

#include <Windows.h>
#include <sql.h>
#include <sqlext.h>

/*						DATA							*/

// BROADCASTING_STATION
SQLINTEGER BNO;
SQLCHAR BROADNAME[20], BROADLOCATION[100];

// TVPROGRAM
SQLINTEGER TVPNO, F_BNO_TV;
SQLCHAR TVPNAME[50], TVPTIME[100];
SQLFLOAT RATING;

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
SQLCHAR DEPNAME[12], WEDDINGANNVIERSARY[6];
SQLINTEGER F_EMPNO;

/*						FUNCTION							*/

void mainMenuPrint();