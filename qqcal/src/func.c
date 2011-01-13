#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "support.h"
#include "func.h"

sqlite3* xcal_db = NULL;

int open_db(char* dbpath)
{
	int nret = sqlite3_open(dbpath,&xcal_db);
	if(nret != SQLITE_OK){
		printf("%s\n",sqlite3_errmsg(xcal_db));
		return -1;
	}else
		return 0;
}

int exec_sql(char * sql)
{
	char* szMsg = NULL;
	int nret = sqlite3_exec(xcal_db, sql, NULL, NULL, &szMsg);
	if(nret != SQLITE_OK){
		printf("%s\n",sqlite3_errmsg(xcal_db));
		return -1;
	}else
		return 0;
}

sqlite3_stmt *get_records(char *sql)
{
	sqlite3_stmt *stmt = NULL;
	char *szMsg = NULL;
	int nret = 0;

	nret = sqlite3_prepare(xcal_db, sql, strlen(sql), &stmt, (const char**)(&szMsg));
	if(nret != SQLITE_OK)
		return NULL;

	return stmt;
}

int close_db()
{
	sqlite3_close(xcal_db);
	xcal_db = NULL;
	return 0;
}

struct xevent *get_date_event(char *xdate, int *count)
{
	struct xevent *xtevent = NULL, *p = NULL, *tmp = NULL;
	int cout = 0;
	if(open_db("xcal.db"))
		printf("Open database failed.\n");
	else {	
		char gsql[1024];
		snprintf(gsql, 1024, "%s'%s';", "select fin, event from xcal where xdate=", xdate);
		sqlite3_stmt *stmt = get_records(gsql);
		if (stmt){
			int nret, fin;
			char *event;
			while(1) {
				nret = sqlite3_step(stmt);
				if(nret != SQLITE_ROW)
					break;
				fin = sqlite3_column_int(stmt,0);
				event = (char *)sqlite3_column_text(stmt,1);
				p = (struct xevent *)malloc(sizeof(struct xevent));
				p->next = NULL;
				p->fin = fin;
				snprintf(p->event, 24, "%s", event);
				if (cout == 0){
					xtevent = p;
					tmp = p;					
				}else{
					tmp->next = p;
					tmp = p;
				}
				cout += 1; 
				printf("\txxx%d\t\t%s\n", fin, event);
			}	
			sqlite3_finalize(stmt);
		}
		
		if(close_db())
			printf("Close database failed.\n");
	}	
	
	*count = cout;
/*	tmp = xtevent;
	if(tmp){
		do{
		printf("tmp->event:%s\n",tmp->event);
		}while(tmp = tmp->next);
	}
*/
	return xtevent;
}

void get_date_today (char *xdate)
{
	time_t now;
	struct tm *timenow;
	
	time(&now);
	timenow = localtime(&now);
	strftime(xdate, 16, "%Y%m%d", timenow);
}
void get_date_tom (char *xdate)
{
	time_t now;
	struct tm *tm;
	
	time(&now);
	tm = localtime(&now);
//	gtk_calendar_get_date(GTK_CALENDAR(obj->xcalendar), &tm.tm_year, &tm.tm_mon, &tm.tm_mday);/*取得选择的年月日*/
	if (tm->tm_mon == 1 || tm->tm_mon == 3 || tm->tm_mon == 5 || tm->tm_mon == 7 || tm->tm_mon == 8 || tm->tm_mon == 10 || tm->tm_mon == 12) {
		if (tm->tm_mday != 31)
			tm->tm_mday += 1;
		else {
			tm->tm_mday = 1;
			if (tm->tm_mon != 12)
				tm->tm_mon += 1;
			else
				tm->tm_mon = 1;
		}	
	} else if (tm->tm_mon == 4 || tm->tm_mon == 6 || tm->tm_mon == 9 || tm->tm_mon == 11) {
		if (tm->tm_mday != 30)
			tm->tm_mday += 1;
		else {
			tm->tm_mday = 1;
			tm->tm_mon += 1;
		}		
	} else if (tm->tm_mon == 2) {
		if (tm->tm_year%4) {
			if (tm->tm_mday != 28)
				tm->tm_mday += 1;
			else {
				tm->tm_mday = 1;
				tm->tm_mon += 1;
			}
		} else {
			if (tm->tm_mday != 29)
				tm->tm_mday += 1;
			else {
				tm->tm_mday = 1;
				tm->tm_mon += 1;
			}
		}
	}
	strftime(xdate, 16,"%Y%m%d", tm);
}
/*
	while(1) {
		nret = sqlite3_step(stmt);
		if(nret != SQLITE_ROW)
			break;
		one = sqlite3_column_int(stmt,0);
		two = sqlite3_column_int(stmt,1);
		printf("\txxx%d\t\t%d\n",one,two);
	}
	sqlite3_finalize(stmt);
	printf("\n");
 */
