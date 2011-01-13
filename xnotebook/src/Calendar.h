/*
 * Calendar.h
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */

#ifndef CALENDAR_H_
#define CALENDAR_H_

#include <gtk/gtk.h>
#include "Support.h"
#include "Debug.h"

GtkWidget*
create_calendar_note(GtkWidget* main_window);

void
on_close_calendar_clicked (GtkButton *button, gpointer user_data);

#endif /* CALENDAR_H_ */
