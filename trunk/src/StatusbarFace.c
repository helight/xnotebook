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
	GtkWidget *status_xnote;

        hbox_status = gtk_hbox_new (TRUE,0);
        gtk_widget_show (hbox_status);
        gtk_box_pack_start (GTK_BOX (vbox), hbox_status, FALSE, TRUE, 0);
        GTK_WIDGET_SET_FLAGS (hbox_status, GTK_CAN_DEFAULT);


        status_xnote = gtk_statusbar_new ();
        gtk_widget_show (status_xnote);
        gtk_box_pack_start (GTK_BOX (hbox_status), status_xnote, FALSE, TRUE, 0);
        
	clist->statusbar.status_xnote = status_xnote;
	
  return hbox_status;
}
  
