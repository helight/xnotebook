/*
 * StatusbarFace.c
 *
 *	Created on: Feb 19, 2009
 *	    Author: helight
 */
#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include <gtk/gtk.h>
#include "About.h"

GtkWidget *
create_status(GtkWidget *main_windown, GtkWidget *vbox, 
				GtkTooltips *tooltips, GtkAccelGroup *accel_group, 
				struct clist_struct *clist)
{
	GtkWidget *hbox_status;
	GtkWidget *status_folder;
	GtkWidget *status_file;
	GtkWidget *status_note;

        hbox_status = gtk_hbox_new (TRUE, 0);                                                                                              
        gtk_widget_show (hbox_status);
        gtk_box_pack_start (GTK_BOX (vbox), hbox_status, FALSE, TRUE, 0);
        GTK_WIDGET_SET_FLAGS (hbox_status, GTK_CAN_DEFAULT);

        status_folder = gtk_statusbar_new ();
        gtk_widget_show (status_folder);
        gtk_box_pack_start (GTK_BOX (hbox_status), status_folder, FALSE, FALSE, 0);
        gtk_widget_set_size_request (status_folder, 120, 21);

        status_file = gtk_statusbar_new ();
        gtk_widget_show (status_file);
        gtk_box_pack_start (GTK_BOX (hbox_status), status_file, FALSE, FALSE, 0);
        gtk_widget_set_size_request (status_file, 500, 21);

        status_note = gtk_statusbar_new ();
        gtk_widget_show (status_note);
        gtk_box_pack_start (GTK_BOX (hbox_status), status_note, FALSE, FALSE, 0);
        gtk_widget_set_size_request (status_note, 120, 21);
        
	GLADE_HOOKUP_OBJECT (main_windown, hbox_status, "hbox_status");
	GLADE_HOOKUP_OBJECT (main_windown, status_folder, "status_folder");
	GLADE_HOOKUP_OBJECT (main_windown, status_file, "status_file");
	GLADE_HOOKUP_OBJECT (main_windown, status_note, "status_note");
	
	clist->statusbar.status_folder = status_folder;
	clist->statusbar.status_file = status_file;
	clist->statusbar.status_note = status_note;
	
  return hbox_status;
}
  
