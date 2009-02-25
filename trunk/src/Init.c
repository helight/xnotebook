/*
 * itoolbar.c
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <string.h>
#include <stdlib.h>

#include "Init.h"


void init_global_clist(struct clist_struct *clist)
{
	char *root_path = getenv("HOME");
	strcpy(clist->root_path, root_path);
	strcat(clist->root_path, "/.xnote");
	memset(clist->sub_path, '\0', sizeof(clist->sub_path));
	memset(clist->doc_path, '\0', sizeof(clist->doc_path));
	clist->buffer = NULL;
	clist->creat = NOTHING;
	clist->del = NOTHING;
	clist->clist_folder = NULL;
	clist->folder_row = -1;
	clist->clist_note = NULL;
	clist->note_row = -1;
	clist->note_text = NULL;
	clist->other.window = NULL;
	clist->other.entry_name = NULL;
	clist->dialog.dialog = NULL;
	clist->dialog.label_text = NULL;
	clist->statusbar.status_folder = NULL;
	clist->statusbar.status_file = NULL;
	clist->statusbar.status_note = NULL;
}


