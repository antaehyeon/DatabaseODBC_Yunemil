
/*						DATA							*/

SQLHENV hEnv = NULL;
SQLHDBC hDbc = NULL;
static SQLCHAR query[100];	// Query statement
SQLHSTMT hStmt;				// Statement Handle#pragma once

/*						FUNCTION							*/

bool DBConnect(SQLHENV * hEnv, SQLHDBC * hDbc);		// Connect to the SQL Server
void DBDisconnect(SQLHENV * hEnv, SQLHDBC * hDbc);	// Disconnect from the SQL Server