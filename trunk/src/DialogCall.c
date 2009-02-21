/*
 * DialogCall.c
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "Dialog.h"

gboolean
on_dialog_delete_event(GtkWidget *widget, GdkEvent *event, gpointer user_data)
{
	struct clist_struct *cclist = (struct clist_struct *)user_data;
	cclist->del = NOTHING;
	cclist->dialog.dialog = NULL;
	cclist->dialog.label_text = NULL;
		
	return FALSE;	
}
void
on_button_cancel_clicked (GtkButton *button, gpointer user_data)
{
	struct clist_struct *cclist = (struct clist_struct *)user_data;
	cclist->del = NOTHING;
	GtkWidget *dialog_del = cclist->dialog.dialog;
	gtk_widget_destroy(GTK_WIDGET(dialog_del));
}


void
on_button_ok_clicked (GtkButton *button, gpointer user_data)
{
	struct clist_struct *cclist = (struct clist_struct *)user_data;
	del_folder_or_note(cclist);
	cclist->del = NOTHING;
	GtkWidget *dialog_del = cclist->dialog.dialog;
	gtk_widget_destroy(GTK_WIDGET(dialog_del));
}
