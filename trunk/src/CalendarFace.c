/*
 * CalendarFace.c
 *
 *	Created on: Feb 19, 2009
 *			Author: helight
 */
#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include <gtk/gtk.h>
#include "Calendar.h"

GtkWidget*
create_calendar_note (GtkWidget *main_window)
{
	GtkWidget *calendar_xnote;
	GtkWidget *dialog_vbox2;
	GtkWidget *xcalendar;
	GtkWidget *dialog_action_area2;
	GtkWidget *close_calendar;

	calendar_xnote = gtk_dialog_new_with_buttons("Xnote-Calendar", 
		GTK_WINDOW(main_window), GTK_DIALOG_DESTROY_WITH_PARENT,NULL);
	gtk_window_set_position (GTK_WINDOW (calendar_xnote), GTK_WIN_POS_CENTER);
	gtk_window_set_type_hint (GTK_WINDOW (calendar_xnote), GDK_WINDOW_TYPE_HINT_DIALOG);

	dialog_vbox2 = GTK_DIALOG (calendar_xnote)->vbox;
	gtk_widget_show (dialog_vbox2);

	xcalendar = gtk_calendar_new ();
	gtk_widget_show (xcalendar);
	gtk_box_pack_start (GTK_BOX (dialog_vbox2), xcalendar, TRUE, TRUE, 0);
	gtk_calendar_display_options (GTK_CALENDAR (xcalendar),
				GTK_CALENDAR_SHOW_HEADING
				| GTK_CALENDAR_SHOW_DAY_NAMES
				| GTK_CALENDAR_SHOW_WEEK_NUMBERS);

	dialog_action_area2 = GTK_DIALOG (calendar_xnote)->action_area;
	gtk_widget_show (dialog_action_area2);
	gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area2), GTK_BUTTONBOX_SPREAD);

	close_calendar = gtk_button_new_from_stock ("gtk-close");
	gtk_widget_show (close_calendar);
	gtk_dialog_add_action_widget (GTK_DIALOG (calendar_xnote), close_calendar, GTK_RESPONSE_CLOSE);
	GTK_WIDGET_SET_FLAGS (close_calendar, GTK_CAN_DEFAULT);

	g_signal_connect ((gpointer) close_calendar, "clicked",
										G_CALLBACK (on_close_calendar_clicked),
										calendar_xnote);

	/* Store pointers to all widgets, for use by lookup_widget(). */
	GLADE_HOOKUP_OBJECT_NO_REF (calendar_xnote, calendar_xnote, "calendar_xnote");
	GLADE_HOOKUP_OBJECT_NO_REF (calendar_xnote, dialog_vbox2, "dialog_vbox2");
	GLADE_HOOKUP_OBJECT (calendar_xnote, xcalendar, "xcalendar");
	GLADE_HOOKUP_OBJECT_NO_REF (calendar_xnote, dialog_action_area2, "dialog_action_area2");
	GLADE_HOOKUP_OBJECT (calendar_xnote, close_calendar, "close_calendar");

	gtk_widget_grab_focus (close_calendar);
	return calendar_xnote;
}


void
on_close_calendar_clicked (GtkButton *button, gpointer user_data)
{
				GtkWidget *window_note = ( GtkWidget *)user_data;
				gtk_widget_destroy(GTK_WIDGET(window_note));
				return;
}
