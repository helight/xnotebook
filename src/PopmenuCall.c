/*
 * AboutCall.c
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include "Popmenu.h"
#include "AddFolder.h"
#include "Dialog.h"
#include "About.h"
#include "Funs.h"
void
on_add_folder_pop_activate (GtkMenuItem *menuitem, gpointer user_data)
{
	struct clist_struct *cclist=(struct clist_struct *)user_data;	
	debug_p("root_path:%s \n", cclist->root_path);
	cclist->creat = FOLDER;
	
	cclist->del = NOTHING;
	cclist->xname = NOTHING;	
	handle_for_create_window_add(cclist);
	debug_p("new!!!\n");
	return;
}


void
on_rename_folder_pop_activate (GtkMenuItem *menuitem, gpointer user_data)
{
	struct clist_struct *cclist = (struct clist_struct *)user_data;
	if(cclist->folder_row < 0)
		cclist->xname = NOTHING;
	else
		cclist->xname = FOLDER;
	cclist->creat = NOTHING;
	cclist->del = NOTHING;
	debug_p("folder_row:%d \n", cclist->folder_row);
	handle_for_create_window_add(cclist);
}


void
on_delete_folder_pop_activate (GtkMenuItem *menuitem, gpointer user_data)
{
	GtkWidget *dialog_del;
	gchar msg[] = "Del This Folder?";
	struct clist_struct *cclist = (struct clist_struct *)user_data;
	if(cclist->folder_row < 0)
		cclist->del = NOTHING;
	else
		cclist->del = FOLDER;
	cclist->creat = NOTHING;
	cclist->xname = NOTHING;
	debug_p("folder_row:%d \n", cclist->folder_row);
	dialog_del = create_dialog(cclist, msg);
	gtk_widget_show (dialog_del);
}


void
on_add_note_pop_activate (GtkMenuItem *menuitem, gpointer user_data)
{
	struct clist_struct *cclist=(struct clist_struct *)user_data;	
	debug_p("root_path:%s \n", cclist->root_path);
	cclist->creat = NOTE_FILE;
	
	cclist->del = NOTHING;
	cclist->xname = NOTHING;
	handle_for_create_window_add(cclist);
	debug_p("new!!!\n");
	return;
}


void
on_rename_note_pop_activate (GtkMenuItem *menuitem, gpointer user_data)
{
	gchar msg[] = "";
	struct clist_struct *cclist = (struct clist_struct *)user_data;
	if(cclist->note_row < 0)
		cclist->xname = NOTHING;
	else
		cclist->xname = NOTE_FILE;
	
	cclist->creat = NOTHING;
	cclist->del = NOTHING;	
	debug_p("Rename note: %d\n", cclist->note_row);
	handle_for_create_window_add(cclist);
}


void
on_delete_note_pop_activate (GtkMenuItem *menuitem, gpointer user_data)
{
	GtkWidget *dialog_del;
	gchar msg[] = "Del This Note?";
	struct clist_struct *cclist = (struct clist_struct *)user_data;
	if(cclist->note_row < 0)
		cclist->del = NOTHING;
	else
		cclist->del = NOTE_FILE;
		
	cclist->creat = NOTHING;
	cclist->xname = NOTHING;	
	dialog_del = create_dialog(cclist, msg);
	gtk_widget_show (dialog_del);
	debug_p("del note\n");
}
