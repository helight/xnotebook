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

GtkWidget* create_window_about (void);


gboolean
on_image_zhwen_button_press_event      (GtkWidget       *widget,
                                        GdkEventButton  *event,
                                        gpointer         user_data);

void
on_button_about_close_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_link_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

#endif /* TOOLBAR_H_ */
