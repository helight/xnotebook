/*
 * CalendarFace.c
 *
 *	Created on: Feb 19, 2009
 *	    Author: helight
 */
#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include <gtk/gtk.h>
#include "Calendar.h"

GtkWidget*                                                                                                                                                                                                                                                 
create_window_note (void)
{
        GtkWidget *window_note;
        GtkWidget *vbox_calendar;
        GtkWidget *calendar_note;
        GtkWidget *button_close;
        GtkWidget *alignment_colse;
        GtkWidget *hbox_colse;
        GtkWidget *image_colse;
        GtkWidget *label_colse;

        window_note = gtk_window_new (GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position (GTK_WINDOW (window_note), GTK_WIN_POS_CENTER);
        gtk_window_set_destroy_with_parent (GTK_WINDOW (window_note), TRUE);
        gtk_window_set_resizable (GTK_WINDOW (window_note), FALSE);
        gtk_window_set_title (GTK_WINDOW (window_note), _("Xnotebook-Calendar"));

        vbox_calendar = gtk_vbox_new (FALSE, 0);
        gtk_widget_show (vbox_calendar);
        gtk_container_add (GTK_CONTAINER (window_note), vbox_calendar);

        calendar_note = gtk_calendar_new ();
        gtk_widget_show (calendar_note);
        gtk_box_pack_start (GTK_BOX (vbox_calendar), calendar_note, TRUE, TRUE, 0);
        gtk_widget_set_size_request (calendar_note, 227, 186);
        gtk_calendar_display_options (GTK_CALENDAR (calendar_note),
                                      GTK_CALENDAR_SHOW_HEADING
                                      | GTK_CALENDAR_SHOW_DAY_NAMES);

        button_close = gtk_button_new ();
        gtk_widget_show (button_close);
        gtk_box_pack_start (GTK_BOX (vbox_calendar), button_close, FALSE, FALSE, 0);

        alignment_colse = gtk_alignment_new (0.5, 0.5, 0, 0);
        gtk_widget_show (alignment_colse);
        gtk_container_add (GTK_CONTAINER (button_close), alignment_colse);

        hbox_colse = gtk_hbox_new (FALSE, 2);
        gtk_widget_show (hbox_colse);
        gtk_container_add (GTK_CONTAINER (alignment_colse), hbox_colse);

        image_colse = gtk_image_new_from_stock ("gtk-cancel", GTK_ICON_SIZE_BUTTON);
        gtk_widget_show (image_colse);
        gtk_box_pack_start (GTK_BOX (hbox_colse), image_colse, FALSE, FALSE, 0);

        label_colse = gtk_label_new_with_mnemonic (_("Close"));
        gtk_widget_show (label_colse);
        gtk_box_pack_start (GTK_BOX (hbox_colse), label_colse, FALSE, FALSE, 0);

        g_signal_connect ((gpointer) button_close, "clicked",
                          G_CALLBACK (on_button_close_clicked),
                          (gpointer)window_note);

        /* Store pointers to all widgets, for use by lookup_widget(). */
        GLADE_HOOKUP_OBJECT_NO_REF (window_note, window_note, "window_note");
        GLADE_HOOKUP_OBJECT (window_note, vbox_calendar, "vbox_calendar");
        GLADE_HOOKUP_OBJECT (window_note, calendar_note, "calendar_note");
        GLADE_HOOKUP_OBJECT (window_note, button_close, "button_close");
        GLADE_HOOKUP_OBJECT (window_note, alignment_colse, "alignment_colse");
        GLADE_HOOKUP_OBJECT (window_note, hbox_colse, "hbox_colse");
        GLADE_HOOKUP_OBJECT (window_note, image_colse, "image_colse");
        GLADE_HOOKUP_OBJECT (window_note, label_colse, "label_colse");

        return window_note;
}

void
on_button_close_clicked (GtkButton *button, gpointer user_data)
{
        GtkWidget *window_note = ( GtkWidget *)user_data;
        gtk_widget_destroy(GTK_WIDGET(window_note));
        return;
}
