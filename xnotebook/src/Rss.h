/*
 * Rss.h
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */

#ifndef RSS_H_
#define RSS_H_

#include "Support.h"

#define sport 80

#define rss_file_q  "GET %s HTTP/1.1\nHost: %s:%s\n%s%s"
#define rss_accept "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8\n"
#define rss_connet "Accept-Charset: ISO-8859-1,utf-8;q=0.7,*;q=0.7\nKeep-Alive: 300\nConnection: keep-alive\n\n"

void get_rss(char *rss_url, char *rss_file);

void del_rss(struct clist_struct *cclist);
#endif /* RSS_H_ */
