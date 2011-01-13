/*
 * menuba.h
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */

#ifndef MENUBA_H_
#define MENUBA_H_

#include <gtk/gtk.h>

#include "Support.h"
#include "Debug.h"

GtkWidget *
create_menubar(GtkWidget *main_windown,GtkWidget *vbox_main,
		GtkTooltips *tooltips,GtkAccelGroup *accel_group,
		struct clist_struct *clist);
				
void on_new_folder_activate (GtkMenuItem *menuitem, gpointer user_data);
void on_new_note_activate (GtkMenuItem  *menuitem, gpointer user_data);
void on_quit_activate (GtkMenuItem *menuitem, gpointer user_data);
void on_save_note_activate (GtkMenuItem *menuitem, gpointer user_data);
void on_edit_note_activate (GtkMenuItem *menuitem, gpointer user_data);
void on_rename_folder_activate (GtkMenuItem *menuitem, gpointer user_data);
void on_rename_note_activate (GtkMenuItem *menuitem, gpointer user_data);
void on_del_folder_activate (GtkMenuItem *menuitem, gpointer user_data);
void on_del_note_activate (GtkMenuItem *menuitem, gpointer user_data);
void on_backup_note_activate (GtkMenuItem *menuitem, gpointer user_data);
void on_calendar_note_activate (GtkMenuItem *menuitem, gpointer user_data);
void on_about_me_activate (GtkMenuItem *menuitem, gpointer user_data);
#endif /* MENUBA_H_ */
