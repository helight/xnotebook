/*
 * cbody.c
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */
#include "Support.h"
#include "Debug.h"
#include "Mainbody.h"
#include "Funs.h"
void 
clist_folder_get_selection_row(GtkCList *gtkclist,gint row,gint column,
							 GdkEventButton *event,gpointer user_data)
{
	struct clist_struct *clist = (struct clist_struct *)user_data;
	clist->folder_row = row;
	show_notes(clist);	
	return;
}
/*
 * 
 */
void 
clist_note_get_selection_row(GtkCList *gtkclist,gint row,gint column,
							 GdkEventButton *event,gpointer user_data)
{
	struct clist_struct *clist = (struct clist_struct *)user_data;
	clist->note_row = row;
	show_file(clist);	
	return;
}
