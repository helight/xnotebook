/*
 * menuba.h
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */

#ifndef MENUBA_H_
#define MENUBA_H_

#include <gtk/gtk.h>

GtkWidget *
create_menubar(GtkWidget *main_windown,GtkWidget *vbox_main,
				GtkTooltips *tooltips,GtkAccelGroup *accel_group);
void
on_new1_activate                       (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_save1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_quit1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_cut1_activate                       (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_copy1_activate                      (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_paste1_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_delete1_activate                    (GtkMenuItem     *menuitem,
                                        gpointer         user_data);

void
on_about1_activate                     (GtkMenuItem     *menuitem,
                                        gpointer         user_data);
#endif /* MENUBA_H_ */
