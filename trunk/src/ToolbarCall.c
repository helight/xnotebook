/*
 * ctoolbar.c
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include "AddFolder.h"
#include "Toolbar.h"
#include "Dialog.h"
#include "About.h"
#include "Funs.h"

void
on_button_nf_clicked (GtkButton *button, gpointer user_data)
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
on_button_nn_clicked (GtkButton *button, gpointer user_data)
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
on_button_edit_clicked (GtkButton *button, gpointer user_data)
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
on_button_save_clicked (GtkButton *button, gpointer  user_data)
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
on_button_ref_clicked (GtkButton  *button, gpointer user_data)
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
on_button_ren_clicked (GtkButton  *button, gpointer user_data)
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
on_button_df_clicked (GtkButton  *button, gpointer user_data)
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
on_button_dn_clicked (GtkButton *button, gpointer user_data)
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

void
on_button_quit_clicked (GtkButton *button, gpointer user_data)
{
	GtkWidget *main_windown = (GtkWidget *)user_data;
	gtk_widget_destroy(GTK_WIDGET(main_windown));
	gtk_main_quit();
}
