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

GtkWidget* create_dialog_about (void);
void on_okbutton_clicked (GtkButton *button, gpointer user_data);

#endif /* TOOLBAR_H_ */
