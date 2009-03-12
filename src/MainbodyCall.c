/*
 * cbody.c
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */

#include <gdk/gdkkeysyms.h>

#include "Popmenu.h"
#include "Support.h"
#include "Debug.h"
#include "Mainbody.h"
#include "Funs.h"

void on_vpaned1_key_press_event(GtkWidget *widget,  GdkEventKey *event, 
				gpointer user_data)
{
	return;
}


gboolean
folder_list_button_press_event(GtkWidget *widget, GdkEventButton  *event,
				gpointer user_data)
{
	struct clist_struct *clist = (struct clist_struct *)user_data;
	GtkWidget *popup_menu_folder_list;
  
	if(event->button == BUTTON_RIGHT){
		popup_menu_folder_list= (GtkWidget *)create_folder_list_popmenu(clist);
		gtk_menu_popup (GTK_MENU(popup_menu_folder_list), 
						NULL, NULL, NULL, NULL,event->button, event->time);	
        return TRUE;
    }
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
	clist->note_row = 0;	
	return;
}

gboolean 
note_list_button_press_event(GtkWidget *widget, GdkEventButton  *event,
				gpointer user_data)
{
	struct clist_struct *clist = (struct clist_struct *)user_data;
	GtkWidget *popup_menu_folder_list;
  
	if(event->button == BUTTON_RIGHT){
		popup_menu_folder_list= (GtkWidget *)create_note_list_popmenu(clist);
		gtk_menu_popup (GTK_MENU(popup_menu_folder_list), 
						NULL, NULL, NULL, NULL,event->button, event->time);	
        return TRUE;
    }
    return FALSE;
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
