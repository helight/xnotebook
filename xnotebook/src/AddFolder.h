#ifndef _ADD_GROUP_H
#define _ADD_GROUP_H

#include <gtk/gtk.h>
#include "Support.h"

void handle_for_create_window_add(gpointer user_data);

GtkWidget*
create_new_add_window (struct clist_struct *clist);

void on_button_add_folder_cancel_clicked(
		GtkButton *button,gpointer   user_data);

void on_button_add_folder_ok_clicked(
		GtkButton *button,gpointer   user_data);

void on_window_add_folder_destroy(
		GtkObject *object,gpointer   user_data);

void on_button_add_folder_help_clicked(
		GtkButton *button,gpointer   user_data);

#endif //_ADD_GROUP_H
