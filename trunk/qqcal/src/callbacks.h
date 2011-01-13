/*
 * callbacks.h
 *
 *  Created on: Aug 29, 2010
 *      Author: helight
 */

#ifndef CALLBACKS_H_
#define CALLBACKS_H_

#include <gtk/gtk.h>
struct add_event_obj;

gboolean on_main_destroy_event(GtkWidget * widget, GdkEvent * event,
			       gpointer user_data);

gboolean on_main_delete_event(GtkWidget * widget, GdkEvent * event,
			      gpointer user_data);
gint mouse_event_handle(GtkWidget *widget, GdkEventButton *event, gpointer data);

gboolean update_clock(gpointer data);

gboolean xcalendar_event(GtkWidget * widget, struct add_event_obj *obj);

gboolean add_event(GtkButton * button, struct add_event_obj *obj);
gboolean add_event_today(GtkButton * button, struct add_event_obj *obj);
gboolean add_event_tomorrow(GtkButton * button, struct add_event_obj *obj);

gboolean big_add_event(GtkButton * button, struct add_event_obj *obj);

char* get_event_date (GtkWidget *event_box, char *xdate);
#endif 
