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
on_close_about_clicked (GtkButton *button, gpointer user_data)
{
	GtkWidget *window_about = (GtkWidget *)user_data;
	gtk_widget_destroy(GTK_WIDGET(window_about));
}


void
on_button_link_clicked (GtkButton *button, gpointer user_data)
{
	gchar tmp[80];
	g_snprintf(tmp,80,"firefox http://zhwen.org & >/dev/null");
	system(tmp);
}
