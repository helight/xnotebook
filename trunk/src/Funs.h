/*
 * toolbar.h
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */

#ifndef FUNS_H_
#define FUNS_H_

#include "Support.h"

void show_folders(struct clist_struct *clist);

void show_notes(struct clist_struct *clist);

void show_file(struct clist_struct *cclist);

gboolean enable_edit(struct clist_struct *cclist);

void show_status(GtkWidget *statusbar, gchar *msg);

void add_folder_or_note(struct clist_struct *clist);

void message_box_for_add_folder(GtkWidget *window,gchar *message);

void del_folder_or_note(struct clist_struct *cclist);

void save_note(struct clist_struct *cclist);

#endif /* TOOLBAR_H_ */
