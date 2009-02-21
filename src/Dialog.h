/*
 * Dialog.h
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */

#ifndef DIALOG_H_
#define DIALOG_H_

#include <gtk/gtk.h>
#include "Support.h"
#include "Debug.h"

GtkWidget* create_dialog_del (struct clist_struct *clist);

gboolean
on_dialog_delete_event(GtkWidget *widget, GdkEvent *event, gpointer user_data);

void on_button_cancel_clicked (GtkButton *button, gpointer user_data);

void on_button_ok_clicked (GtkButton *button, gpointer user_data);

#endif /* TOOLBAR_H_ */
