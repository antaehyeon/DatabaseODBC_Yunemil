// Note: Project > Project's property > General > Character Set > Use Multi-Byte Character Set
// Header files for the use of SQL
#include <Windows.h>
#include <sql.h>
#include <sqlext.h>

bool DBConnect(SQLHENV * hEnv, SQLHDBC * hDbc)
{
	SQLRETURN Ret;

	// Allocate the Environment Handle (hEnv)
	if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, hEnv) != SQL_SUCCESS)
	{
		return false;
	}

	// Set attributes of the Environment Handle (hEnv)
	if (SQLSetEnvAttr(*hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER) != SQL_SUCCESS)
	{
		return false;
	}

	// Allocate the Connection Handle (hDbc)
	if (SQLAllocHandle(SQL_HANDLE_DBC, *hEnv, hDbc) != SQL_SUCCESS)
	{
		return false;
	}

	// Connect to the SQL Sever with ODBC name, ID, and PW
	Ret = SQLConnect(*hDbc, (SQLCHAR *)"mydb", SQL_NTS, (SQLCHAR *)"antaehyeon", SQL_NTS, (SQLCHAR *)"xogus1696", SQL_NTS);
	if ((Ret != SQL_SUCCESS) && (Ret != SQL_SUCCESS_WITH_INFO))
	{
		return false;
	}

	return true;
}

void DBDisconnect(SQLHENV * hEnv, SQLHDBC * hDbc)
{
	SQLDisconnect(*hDbc);					// Disconnect from the SQL Server
	SQLFreeHandle(SQL_HANDLE_DBC, *hDbc);	// Free the Connection Handle
	SQLFreeHandle(SQL_HANDLE_ENV, *hEnv);	// Free the Environment Handle
}