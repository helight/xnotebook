/*
 * AboutCall.c
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "About.h"

void
on_okbutton_clicked (GtkButton *button, gpointer user_data)
{
	GtkWidget *dialog_about = (GtkWidget *)user_data;
	gtk_widget_destroy(GTK_WIDGET(dialog_about));
}
