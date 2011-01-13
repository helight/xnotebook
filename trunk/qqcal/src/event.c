/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "event.h"
#include "support.h"
#include "func.h"

gboolean
on_event_windown_delete_event (GtkWidget *widget, GdkEvent *event, 
								gpointer user_data)
{
	struct add_event_obj *obj = (struct add_event_obj *)user_data;
	
	obj->event_box = NULL;
	printf("bey world;\n");

	return FALSE;
}
void create_event (GtkButton *button, struct add_event_obj *obj)
{
	GtkWidget *xcal_window;
	GtkWidget *dialog_vbox; 
	GtkWidget *xcal_vbox;
	
	GtkWidget *xtod_hbox;
	GtkWidget *xtod_img;
	GtkWidget *xtod_label;
	GtkWidget *xtod_vbox;
	GtkWidget *xtod_add_but;
	GtkWidget *xtod_add_img;
		
	GtkWidget *xtom_hbox;
	GtkWidget *xtom_img;
	GtkWidget *xtom_label;
	GtkWidget *xtom_vbox;
	GtkWidget *xtom_add_but;
	GtkWidget *xtom_add_img;
		
	GtkWidget *xcal_foot_area;
	GtkWidget *foot_label;

	CursorOffset* icon_pos;
	char xdate[16];
	
	xcal_window = gtk_dialog_new_with_buttons("Xcalendar", 
		GTK_WINDOW(obj->main_window), GTK_DIALOG_DESTROY_WITH_PARENT,NULL);
	gtk_window_set_type_hint (GTK_WINDOW (xcal_window), GDK_WINDOW_TYPE_HINT_DIALOG);
	gtk_window_set_position (GTK_WINDOW (xcal_window), GTK_WIN_POS_MOUSE);
	gtk_widget_set_size_request (xcal_window, 220, -1);
	gtk_window_set_resizable (GTK_WINDOW (xcal_window), FALSE);
	gtk_window_set_destroy_with_parent (GTK_WINDOW (xcal_window), TRUE);
	gtk_window_set_modal (GTK_WINDOW (xcal_window), TRUE);
	//gtk_window_set_decorated(xcal_window, FALSE);
	gtk_widget_show(xcal_window);
	
	dialog_vbox = GTK_DIALOG (xcal_window)->vbox;
	gtk_widget_show (dialog_vbox);
	
	xcal_vbox = gtk_vbox_new(FALSE,0);
	gtk_widget_show(xcal_vbox);
	gtk_container_add(GTK_CONTAINER(dialog_vbox), xcal_vbox);
/****************************************************************************************************/	
	xtod_hbox = gtk_hbox_new(FALSE,0);
	gtk_widget_show(xtod_hbox);
	gtk_box_pack_start (GTK_BOX (xcal_vbox), xtod_hbox, FALSE, FALSE, 0);
	gtk_container_set_border_width (GTK_CONTAINER (xtod_hbox), 5);
	
	xtod_img = create_pixmap("cal.png");
	gtk_widget_show (xtod_img);
	gtk_box_pack_start (GTK_BOX (xtod_hbox), xtod_img, FALSE, FALSE, 0);
		
	xtod_label = gtk_label_new (_("<span foreground='#14A1F5' ><b>   Today ......</b></span>"));
	gtk_widget_show (xtod_label);
	gtk_box_pack_start (GTK_BOX (xtod_hbox), xtod_label, FALSE, FALSE, 0);
	gtk_misc_set_alignment (GTK_MISC (xtod_label), 0.02, 0.5);
	gtk_label_set_use_markup (GTK_LABEL (xtod_label), TRUE);
	gtk_widget_set_size_request (xtod_label, 160, -1);
	
	xtod_add_but = gtk_button_new ();
	gtk_widget_show (xtod_add_but);
	gtk_box_pack_start (GTK_BOX (xtod_hbox), xtod_add_but, FALSE, FALSE, 0);
	gtk_button_set_relief (GTK_BUTTON (xtod_add_but), GTK_RELIEF_NONE);
	xtod_add_img = create_pixmap("add.png");
	gtk_widget_show (xtod_add_img);
	gtk_container_add (GTK_CONTAINER (xtod_add_but), xtod_add_img);
		
	xtod_vbox = gtk_vbox_new(FALSE,0);
	gtk_widget_show (xtod_vbox);
	gtk_box_pack_start (GTK_BOX (xcal_vbox), xtod_vbox, TRUE, TRUE, 0);
	
/****************************************************************************************************/	
	xtom_hbox = gtk_hbox_new(FALSE,0);
	gtk_widget_show(xtom_hbox);
	gtk_box_pack_start (GTK_BOX (xcal_vbox), xtom_hbox, FALSE, FALSE, 0);
	gtk_container_set_border_width (GTK_CONTAINER (xtom_hbox), 5);
	
	xtom_img = create_pixmap("cal.png");
	gtk_widget_show (xtom_img);
	gtk_box_pack_start (GTK_BOX (xtom_hbox), xtom_img, FALSE, FALSE, 0);
	
	xtom_label = gtk_label_new (_("<span foreground='#14A1F5' ><b>   Tomorrow ......</b></span>"));
	gtk_widget_show (xtom_label);
	gtk_box_pack_start (GTK_BOX (xtom_hbox), xtom_label, FALSE, FALSE, 0);
	gtk_misc_set_alignment (GTK_MISC (xtom_label), 0.02, 0.5);
	gtk_label_set_use_markup (GTK_LABEL (xtom_label), TRUE);
	gtk_widget_set_size_request (xtom_label, 160, -1);
	
	xtom_add_but = gtk_button_new ();
	gtk_widget_show (xtom_add_but);
	gtk_box_pack_start (GTK_BOX (xtom_hbox), xtom_add_but, FALSE, FALSE, 0);
	gtk_button_set_relief (GTK_BUTTON (xtom_add_but), GTK_RELIEF_NONE);
	xtom_add_img = create_pixmap("add.png");
	gtk_widget_show (xtom_add_img);
	gtk_container_add (GTK_CONTAINER (xtom_add_but), xtom_add_img);
	
	xtom_vbox = gtk_vbox_new(FALSE,0);
	gtk_widget_show (xtom_vbox);
	gtk_box_pack_start (GTK_BOX (xcal_vbox), xtom_vbox, TRUE, TRUE, 0);
	
/****************************************************************************************************/
	xcal_foot_area = GTK_DIALOG (xcal_window)->action_area;
	gtk_widget_show (xcal_foot_area);
	gtk_button_box_set_layout (GTK_BUTTON_BOX (xcal_foot_area), GTK_BUTTONBOX_START);
  
	foot_label = gtk_label_new (_("state......"));
	gtk_widget_show (foot_label);
	gtk_dialog_add_action_widget (GTK_DIALOG (xcal_window), foot_label, GTK_RESPONSE_OK);
	GTK_WIDGET_SET_FLAGS (foot_label, GTK_CAN_DEFAULT);
/****************************************************************************************************/
	obj->event_box1 = xtod_vbox;
	obj->event_box2 = xtom_vbox;
	
	g_signal_connect(GTK_OBJECT(xtod_add_but), "clicked",
				G_CALLBACK(add_event_today), (struct add_event_obj *)obj);				
	g_signal_connect(GTK_OBJECT(xtom_add_but), "clicked",
				G_CALLBACK(add_event_tomorrow), (struct add_event_obj *)obj);
	g_signal_connect ((gpointer) xcal_window, "delete_event",
				  G_CALLBACK (on_event_windown_delete_event),
				  (struct add_event_obj *)obj);		
	get_date_today(obj->xdate);	
	get_event_date(xtod_vbox, obj->xdate);
	
	get_date_tom(obj->xdate);	
	get_event_date(xtom_vbox, obj->xdate);
}
