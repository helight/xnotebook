/*
 * About.h
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */

#ifndef POPMENU_H_
#define POPMENU_H_

#include <gtk/gtk.h>
#include "Support.h"
#include "Debug.h"


GtkWidget*
create_folder_list_popmenu (struct clist_struct *clist);

GtkWidget*
create_note_list_popmenu (struct clist_struct *clist);

void
on_add_folder_pop_activate (GtkMenuItem *menuitem, gpointer user_data);


void
on_rename_folder_pop_activate (GtkMenuItem *menuitem, gpointer user_data);

void
on_delete_folder_pop_activate (GtkMenuItem *menuitem, gpointer user_data);


void
on_add_note_pop_activate (GtkMenuItem *menuitem, gpointer user_data);

void
on_rename_note_pop_activate (GtkMenuItem *menuitem, gpointer user_data);

void
on_delete_note_pop_activate (GtkMenuItem *menuitem, gpointer user_data);

void
on_add_rss_pop_activate (GtkMenuItem *menuitem, gpointer user_data);

void
on_rename_rss_pop_activate (GtkMenuItem *menuitem, gpointer user_data);

void
on_delete_rss_pop_activate (GtkMenuItem *menuitem, gpointer user_data);
#endif /* POPMENU_H_ */


