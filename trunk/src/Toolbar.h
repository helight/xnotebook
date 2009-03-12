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

GtkWidget *
create_toolbar(GtkWidget *main_window, GtkWidget *vbox, 
		GtkTooltips *tooltips, GtkAccelGroup *accel_group, 
		struct clist_struct *clist);

void
on_button_nf_clicked (GtkButton *button, gpointer user_data);

void
on_button_nn_clicked (GtkButton *button, gpointer user_data);

void
on_button_edit_clicked (GtkButton *button, gpointer user_data);

void
on_button_save_clicked (GtkButton *button, gpointer user_data);

void
on_button_df_clicked (GtkButton  *button, gpointer user_data);

void
on_button_df_clicked (GtkButton *button, gpointer user_data);

void
on_button_dn_clicked (GtkButton *button, gpointer user_data);

void
on_button_about_clicked (GtkButton *button, gpointer user_data);

void
on_button_quit_clicked (GtkButton *button, gpointer user_data);

#endif /* TOOLBAR_H_ */
