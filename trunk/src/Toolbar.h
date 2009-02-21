/*
 * toolbar.h
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */

#ifndef TOOLBAR_H_
#define TOOLBAR_H_

#include <gtk/gtk.h>
#include "Support.h"
#include "Debug.h"
#include "string.h"

GtkWidget *
create_toolbar(GtkWidget *main_window, GtkWidget *vbox, 
				GtkTooltips *tooltips, GtkAccelGroup *accel_group, 
				struct clist_struct *clist);

void
on_new_folder_clicked (GtkButton *button, gpointer user_data);
void
on_new_note_clicked (GtkButton *button, gpointer user_data);
void
on_edit_clicked (GtkButton *button, gpointer user_data);

void
on_save_note_clicked (GtkButton *button, gpointer user_data);

void
on_del_folder_clicked (GtkButton *button, gpointer user_data);

void
on_del_note_clicked (GtkButton *button, gpointer user_data);

void
on_about_note_clicked (GtkButton *button, gpointer user_data);

#endif /* TOOLBAR_H_ */
