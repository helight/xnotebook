/*
 * cmenubar.c
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "Menubar.h"
#include "AddFolder.h"
#include "Toolbar.h"
#include "Dialog.h"
#include "About.h"
#include "Calendar.h"
#include "Funs.h"


void
on_new_folder_activate (GtkMenuItem *menuitem, gpointer user_data)
{
	struct clist_struct *cclist=(struct clist_struct *)user_data;	
	debug_p("root_path:%s \n", cclist->root_path);
	cclist->creat = FOLDER;
	
	handle_for_create_window_add(cclist);
	debug_p("new!!!\n");
	return;
}


void
on_new_note_activate (GtkMenuItem  *menuitem, gpointer user_data)
{
	struct clist_struct *cclist=(struct clist_struct *)user_data;	
	debug_p("root_path:%s \n", cclist->root_path);
	cclist->creat = NOTEFILE;
	handle_for_create_window_add(cclist);
	debug_p("new!!!\n");
	return;
}

void
on_quit_activate (GtkMenuItem *menuitem, gpointer user_data)
{
        printf("bey world;\n");
        gtk_main_quit();
        return;
}

void
on_save_note_activate (GtkMenuItem *menuitem, gpointer user_data)
{
	struct clist_struct *cclist = (struct clist_struct *)user_data;
	
	if(cclist->note_row < 0) return;
	
	save_note(cclist);

	if(gtk_text_view_get_editable (GTK_TEXT_VIEW (cclist->note_text)))
		gtk_text_view_set_editable (GTK_TEXT_VIEW (
					cclist->note_text), FALSE);
	return;
}


void
on_edit_note_activate (GtkMenuItem *menuitem, gpointer user_data)
{
	struct clist_struct *cclist = (struct clist_struct *)user_data;
	if(cclist->note_row >= 0){
		gtk_text_view_set_editable (GTK_TEXT_VIEW (
					cclist->note_text), TRUE);
		debug_p("enable edit\n");
	}
	return;
}

void
on_del_folder_activate (GtkMenuItem *menuitem, gpointer user_data)
{
	GtkWidget *dialog_del;
	struct clist_struct *cclist = (struct clist_struct *)user_data;
	if(cclist->folder_row < 0)
		cclist->del = NOTHING;
	else
		cclist->del = FOLDER;
	debug_p("folder_row:%d \n", cclist->folder_row);
	dialog_del = create_dialog_del(cclist);
	gtk_widget_show (dialog_del);
}


void
on_del_note_activate (GtkMenuItem *menuitem, gpointer user_data)
{
	GtkWidget *dialog_del;
	struct clist_struct *cclist = (struct clist_struct *)user_data;
	if(cclist->note_row < 0)
		cclist->del = NOTHING;
	else
		cclist->del = NOTEFILE;
	
	dialog_del = create_dialog_del(cclist);
	gtk_widget_show (dialog_del);
	debug_p("del note\n");
}

void
on_calendar_note_activate (GtkMenuItem *menuitem, gpointer user_data)
{
	GtkWidget *window;
	window = create_window_note ();
	gtk_widget_show (window);
}
void
on_about_me_activate (GtkMenuItem *menuitem, gpointer user_data)
{
	GtkWidget *window_about;
	window_about = create_window_about ();
	gtk_widget_show (window_about);

}