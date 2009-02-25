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

void on_vpaned1_key_press_event(GtkWidget *widget,  GdkEventKey *event, 
				gpointer user_data)
{
	return FALSE;
}
void 
clist_folder_get_selection_row(GtkCList *gtkclist,gint row,gint column,
							 GdkEventButton *event,gpointer user_data)
{
	struct clist_struct *clist = (struct clist_struct *)user_data;
	clist->folder_row = row;
	show_notes(clist);
	//memset(clist->doc_path, '\0', sizeof(clist->doc_path));
	clist->note_row = -1;	
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
