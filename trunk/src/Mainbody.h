/*
 * Mainbody.h
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */

#ifndef BODY_H_
#define BODY_H_

#include <gtk/gtk.h>

enum WHICH_BUTTON{
	BUTTON_LEFT=1,
	BUTTON_MODD,
	BUTTON_RIGHT
}; 

GtkWidget *
create_mainbody(GtkWidget *main_windown, GtkWidget *vbox, 
				GtkTooltips *tooltips, GtkAccelGroup *accel_group,
				struct clist_struct *clist);
				
void on_vpaned1_key_press_event(GtkWidget *widget,  GdkEventKey *event, 
				gpointer user_data);
				
gboolean folder_list_button_press_event(GtkWidget *widget, GdkEventButton  *event,
				gpointer user_data);
				
void clist_folder_get_selection_row(GtkCList *gtkclist,gint row,
			gint column, GdkEventButton *event, gpointer user_data);	
			
gboolean note_list_button_press_event(GtkWidget *widget, GdkEventButton  *event,
				gpointer user_data);
										
void clist_note_get_selection_row(GtkCList *gtkclist,gint row,
			gint column, GdkEventButton *event, gpointer user_data);

gboolean clist_rss_button_press_event(GtkWidget *widget, GdkEventButton  *event,
				gpointer user_data);
										
void clist_rss_get_selection_row(GtkCList *gtkclist,gint row,
			gint column, GdkEventButton *event, gpointer user_data);	
#endif /* BODY_H_ */
