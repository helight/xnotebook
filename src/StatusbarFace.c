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
	GtkWidget *status_sys;
	GtkWidget *status_note;

        hbox_status = gtk_hbox_new (TRUE, 0);                                                                                              
        gtk_widget_show (hbox_status);
        gtk_box_pack_start (GTK_BOX (vbox), hbox_status, FALSE, TRUE, 0);
        GTK_WIDGET_SET_FLAGS (hbox_status, GTK_CAN_DEFAULT);

        status_folder = gtk_statusbar_new ();
        gtk_widget_show (status_folder);
        gtk_box_pack_start (GTK_BOX (hbox_status), status_folder, FALSE, FALSE, 0);
        gtk_widget_set_size_request (status_folder, 200, 21);

        status_sys = gtk_statusbar_new ();
        gtk_widget_show (status_sys);
        gtk_box_pack_start (GTK_BOX (hbox_status), status_sys, FALSE, FALSE, 0);
        gtk_widget_set_size_request (status_sys, 200, 21);

        status_note = gtk_statusbar_new ();
        gtk_widget_show (status_note);
        gtk_box_pack_start (GTK_BOX (hbox_status), status_note, FALSE, FALSE, 0);
        gtk_widget_set_size_request (status_note, 200, 21);
        
	GLADE_HOOKUP_OBJECT (main_windown, hbox_status, "hbox_status");
	GLADE_HOOKUP_OBJECT (main_windown, status_folder, "status_folder");
	GLADE_HOOKUP_OBJECT (main_windown, status_sys, "status_sys");
	GLADE_HOOKUP_OBJECT (main_windown, status_note, "status_note");
	
	clist->statusbar.status_folder = status_folder;
	clist->statusbar.status_sys = status_sys;
	clist->statusbar.status_note = status_note;
	
  return hbox_status;
}
  
