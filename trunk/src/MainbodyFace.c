/*
 * body.c
 *
 *	Created on: Feb 19, 2009
 *	    Author: helight
 */
#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include <gtk/gtk.h>
#include "Support.h"
#include "Mainbody.h"

GtkWidget *
create_mainbody(GtkWidget *main_windown, GtkWidget *vbox, 
		GtkTooltips *tooltips, GtkAccelGroup *accel_group,
		struct clist_struct *clist)
{
	GtkTextBuffer *buffer;
	
	GtkWidget *hpaned;
	GtkWidget *scrolledwindow4;
	GtkWidget *folder_list;
	GtkWidget *folder_list_title;
	GtkWidget *vpaned1;
	GtkWidget *alignment6;
	GtkWidget *scrolledwindow5;
	GtkWidget *note_list;
	GtkWidget *note_title;
	GtkWidget *note_time;
	GtkWidget *scrolledwindow6;
	GtkWidget *note_text;
	
	hpaned = gtk_hpaned_new ();
	gtk_widget_show (hpaned);
	gtk_box_pack_start (GTK_BOX (vbox), hpaned, TRUE, TRUE, 0);

	scrolledwindow4 = gtk_scrolled_window_new (NULL, NULL);
	gtk_widget_show (scrolledwindow4);
	gtk_paned_pack1 (GTK_PANED (hpaned), scrolledwindow4, FALSE, TRUE);
	gtk_widget_set_size_request (scrolledwindow4, 150, -1);
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow4), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
	gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow4), GTK_SHADOW_IN);

	folder_list = gtk_clist_new (1);
	gtk_widget_show (folder_list);
	gtk_container_add (GTK_CONTAINER (scrolledwindow4), folder_list);
	gtk_widget_set_size_request (folder_list, 150, -1);
	gtk_clist_set_column_width (GTK_CLIST (folder_list), 0, 80);
	gtk_clist_column_titles_show (GTK_CLIST (folder_list));

	folder_list_title = gtk_label_new (_("All Folders"));
	gtk_widget_show (folder_list_title);
	gtk_clist_set_column_widget (GTK_CLIST (folder_list), 0, folder_list_title);

	vpaned1 = gtk_vpaned_new ();
	gtk_widget_show (vpaned1);
	gtk_paned_pack2 (GTK_PANED (hpaned), vpaned1, TRUE, TRUE);

	alignment6 = gtk_alignment_new (0.5, 0.5, 1, 1);
	gtk_widget_show (alignment6);
	gtk_paned_pack1 (GTK_PANED (vpaned1), alignment6, FALSE, TRUE);
	gtk_widget_set_size_request (alignment6, -1, 182);

	scrolledwindow5 = gtk_scrolled_window_new (NULL, NULL);
	gtk_widget_show (scrolledwindow5);
	gtk_container_add (GTK_CONTAINER (alignment6), scrolledwindow5);
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow5), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
	gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow5), GTK_SHADOW_IN);

	note_list = gtk_clist_new (2);
	gtk_widget_show (note_list);
	gtk_container_add (GTK_CONTAINER (scrolledwindow5), note_list);
	gtk_widget_set_size_request (note_list, -1, 180);
	//gtk_clist_set_column_width (GTK_CLIST (note_list), 0, 300);
	gtk_clist_set_column_auto_resize(GTK_CLIST(note_list),0,TRUE);
	//gtk_clist_set_column_width (GTK_CLIST (note_list), 1, 200);
	gtk_clist_set_column_auto_resize(GTK_CLIST(note_list),1,TRUE);
	gtk_clist_column_titles_show (GTK_CLIST (note_list));
	gtk_clist_set_selection_mode (GTK_CLIST (note_list), GTK_SELECTION_BROWSE);
	
	note_title = gtk_label_new (_("Title"));
	gtk_widget_show (note_title);
	gtk_clist_set_column_widget (GTK_CLIST (note_list), 0, note_title);

	note_time = gtk_label_new (_("Time"));
	gtk_widget_show (note_time);
	gtk_clist_set_column_widget (GTK_CLIST (note_list), 1, note_time);

	scrolledwindow6 = gtk_scrolled_window_new (NULL, NULL);
	gtk_widget_show (scrolledwindow6);
	gtk_paned_pack2 (GTK_PANED (vpaned1), scrolledwindow6, TRUE, TRUE);
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow6), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
	gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow6), GTK_SHADOW_IN);

	note_text = gtk_text_view_new ();
	gtk_widget_show (note_text);
	gtk_container_add (GTK_CONTAINER (scrolledwindow6), note_text);	
	buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW (note_text));	
	gtk_text_view_set_editable (GTK_TEXT_VIEW (note_text), FALSE);
	gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (note_text), GTK_WRAP_WORD);
	
	g_signal_connect ((gpointer) vpaned1, "key_press_event",
                    G_CALLBACK (on_vpaned1_key_press_event),
                    NULL);
	
	g_signal_connect((gpointer)(folder_list),"select_row",
        					G_CALLBACK(clist_folder_get_selection_row),
        					(gpointer *)clist);
	g_signal_connect((gpointer)(note_list),"select_row",
        					G_CALLBACK(clist_note_get_selection_row),
        					(gpointer *)clist);
        					
	GLADE_HOOKUP_OBJECT (main_windown, scrolledwindow4, "scrolledwindow4");
	GLADE_HOOKUP_OBJECT (main_windown, folder_list, "folder_list");
	GLADE_HOOKUP_OBJECT (main_windown, folder_list_title, "folder_list_title");
	GLADE_HOOKUP_OBJECT (main_windown, vpaned1, "vpaned1");
	GLADE_HOOKUP_OBJECT (main_windown, alignment6, "alignment6");
	GLADE_HOOKUP_OBJECT (main_windown, scrolledwindow5, "scrolledwindow5");
	GLADE_HOOKUP_OBJECT (main_windown, note_list, "note_list");
	GLADE_HOOKUP_OBJECT (main_windown, note_title, "note_title");
	GLADE_HOOKUP_OBJECT (main_windown, note_time, "note_time");
	GLADE_HOOKUP_OBJECT (main_windown, scrolledwindow6, "scrolledwindow6");
	GLADE_HOOKUP_OBJECT (main_windown, note_text, "note_text");
	
	clist->buffer = buffer;
	clist->clist_folder = folder_list;
	clist->clist_note = note_list;
	clist->note_text = note_text;
	return hpaned;
 }
