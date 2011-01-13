/*
 * Statusbar.h
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */

#ifndef STATUSBAR_H_
#define STATUSBAR_H_

#include <gtk/gtk.h>
#include "Support.h"
#include "Debug.h"

GtkWidget *
create_status(GtkWidget *main_windown, GtkWidget *vbox, 
				GtkTooltips *tooltips, GtkAccelGroup *accel_group, 
				struct clist_struct *clist);


#endif /* TOOLBAR_H_ */
