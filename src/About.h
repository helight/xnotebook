/*
 * About.h
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */

#ifndef ABOUT_H_
#define ABOUT_H_

#include <gtk/gtk.h>
#include "Support.h"
#include "Debug.h"

GtkWidget *create_about_xnote (GtkWidget *mainwindow);


void
on_close_about_clicked (GtkButton *button, gpointer user_data);

void
on_button_link_clicked (GtkButton *button, gpointer user_data);

#endif /* TOOLBAR_H_ */
