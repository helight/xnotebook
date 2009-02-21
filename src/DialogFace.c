/*
 * itoolbar.c
 *
 *	Created on: Feb 19, 2009
 *	    Author: helight
 */
#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include "Dialog.h"

GtkWidget*
create_dialog_del (struct clist_struct *cclist)
{
        GtkWidget *dialog_del;                                                                                                                                                                                                                             
        GtkWidget *dialog_vbox1;
        GtkWidget *label_note;
        GtkWidget *dialog_action_area1;
        GtkWidget *button_cancel;
        GtkWidget *button_ok;
	
	gchar *msg = NULL;
	
        dialog_del = gtk_dialog_new ();
        gtk_window_set_title (GTK_WINDOW (dialog_del), _("Are You Suer?"));
        gtk_window_set_position (GTK_WINDOW (dialog_del), GTK_WIN_POS_CENTER);
        gtk_window_set_default_size (GTK_WINDOW (dialog_del), 100, 70);
        gtk_window_set_destroy_with_parent (GTK_WINDOW (dialog_del), TRUE);
        gtk_window_set_icon_name (GTK_WINDOW (dialog_del), "gtk-dialog-warning");
        gtk_window_set_type_hint (GTK_WINDOW (dialog_del), GDK_WINDOW_TYPE_HINT_DIALOG);

        dialog_vbox1 = GTK_DIALOG (dialog_del)->vbox;
        gtk_widget_show (dialog_vbox1);
	
	if(cclist->del == FOLDER){
		msg = cclist->sub_path + strlen(cclist->root_path) +1;
	} else if(cclist->del == NOTEFILE){
		msg = cclist->doc_path + strlen(cclist->root_path) +1;
	} else {
		gchar mmsg[]="<b>You Select Nothing TO Del...</b>";
		msg = mmsg;
	}
	debug_p("label note: %s \n", msg);
        label_note = gtk_label_new (_(msg));
        gtk_widget_show (label_note);
        gtk_box_pack_start (GTK_BOX (dialog_vbox1), label_note, FALSE, FALSE, 0);
        gtk_label_set_use_markup (GTK_LABEL (label_note), TRUE);

        dialog_action_area1 = GTK_DIALOG (dialog_del)->action_area;
        gtk_widget_show (dialog_action_area1);
        gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area1), GTK_BUTTONBOX_SPREAD);

        button_cancel = gtk_button_new_from_stock ("gtk-cancel");
        gtk_widget_show (button_cancel);
        gtk_dialog_add_action_widget (GTK_DIALOG (dialog_del), button_cancel, GTK_RESPONSE_CANCEL);
        GTK_WIDGET_SET_FLAGS (button_cancel, GTK_CAN_DEFAULT);

        button_ok = gtk_button_new_from_stock ("gtk-ok");
        gtk_widget_show (button_ok);
        gtk_dialog_add_action_widget (GTK_DIALOG (dialog_del), button_ok, GTK_RESPONSE_OK);
        GTK_WIDGET_SET_FLAGS (button_ok, GTK_CAN_DEFAULT);

        g_signal_connect ((gpointer) button_cancel, "clicked",
                          G_CALLBACK (on_button_cancel_clicked),
                          (gpointer)cclist);
        g_signal_connect ((gpointer) button_ok, "clicked",
                          G_CALLBACK (on_button_ok_clicked),
                          (gpointer)cclist);
        g_signal_connect ((gpointer) dialog_del, "delete_event",
                          G_CALLBACK (on_dialog_delete_event),
                          (gpointer)cclist);
        /* Store pointers to all widgets, for use by lookup_widget(). */
        GLADE_HOOKUP_OBJECT_NO_REF (dialog_del, dialog_del, "dialog_del");
        GLADE_HOOKUP_OBJECT_NO_REF (dialog_del, dialog_vbox1, "dialog_vbox1");
        GLADE_HOOKUP_OBJECT (dialog_del, label_note, "label_note");
        GLADE_HOOKUP_OBJECT_NO_REF (dialog_del, dialog_action_area1, "dialog_action_area1");
        GLADE_HOOKUP_OBJECT (dialog_del, button_cancel, "button_cancel");
        GLADE_HOOKUP_OBJECT (dialog_del, button_ok, "button_ok");
        cclist->dialog.dialog = dialog_del;
        return dialog_del;

}
