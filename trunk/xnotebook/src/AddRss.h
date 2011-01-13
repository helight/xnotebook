/*
 * AboutCall.c
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */

#ifndef ADDRSS_H_
#define ADDRSS_H_

#include <gtk/gtk.h>

GtkWidget*
create_add_rss_window (struct clist_struct *clist);

void handle_for_create_rss_window(gpointer user_data);

void
on_button_add_rss_ok_clicked (GtkButton *button, gpointer user_data);

void
on_button_add_rss_cancel_clicked (GtkButton *button, gpointer user_data);

void
on_window_add_rss_destroy (GtkObject *object, gpointer user_data);

struct rss_add{
	GtkWidget *window;
	GtkWidget *title;
	GtkWidget *url;
};
#endif /* ADDRSS_H_ */
