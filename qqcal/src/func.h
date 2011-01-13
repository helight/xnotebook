/*
 * func.h
 *
 *  Created on: Aug 29, 2010
 *      Author: helight
 */

#ifndef FUNC_H_
#define FUNC_H_

#include "sqlite3.h"
int open_db(char* dbpath);
int exec_sql(char * sql);
sqlite3_stmt *get_records(char *sql);
struct xevent *get_date_event(char *xdate, int *count);
int close_db();

void get_date_today(char *xdate);
#endif 
