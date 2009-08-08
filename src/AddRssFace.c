/*
 * AboutCall.c
 *
 *	Created on: Feb 19, 2009
 *			Author: helight
 */

#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include <gtk/gtk.h>
#include "Support.h"
#include "Mainbody.h"
#include "AddRss.h"

void handle_for_create_rss_window(gpointer user_data)
{
	GtkWidget *window;
	struct clist_struct *clist = (struct clist_struct *)user_data;

	window=(GtkWidget *)create_add_rss_window (clist);

	gtk_widget_show(window);
}


GtkWidget*
create_add_rss_window (struct clist_struct *clist)
{
	GtkWidget *add_rss_window;
	GtkWidget *vbox4;
	GtkWidget *label_add;
	GtkWidget *hbox4;
	GtkWidget *label_title;
	GtkWidget *entry_title;
	GtkWidget *hbox5;
	GtkWidget *hbox6;
	GtkWidget *label_url;
	GtkWidget *entry_url;
	GtkWidget *hbox7;
	GtkWidget *button_cancel;
	GtkWidget *alignment4;
	GtkWidget *hbox9;
	GtkWidget *image5;
	GtkWidget *label14;
	GtkWidget *button_ok;
	GtkWidget *alignment3;
	GtkWidget *hbox8;
	GtkWidget *image4;
	GtkWidget *label13;

	add_rss_window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_widget_set_size_request (add_rss_window, 300, 100);
	gtk_window_set_title (GTK_WINDOW (add_rss_window), _("Add RSS"));
	gtk_window_set_position (GTK_WINDOW (add_rss_window), GTK_WIN_POS_CENTER);
	gtk_window_set_destroy_with_parent (GTK_WINDOW (add_rss_window), TRUE);

	vbox4 = gtk_vbox_new (TRUE, 0);
	gtk_widget_show (vbox4);
	gtk_container_add (GTK_CONTAINER (add_rss_window), vbox4);
	gtk_widget_set_size_request (vbox4, 206, 100);

	label_add = gtk_label_new (_("<b>Add A RSS Item</b>"));
	gtk_widget_show (label_add);
	gtk_box_pack_start (GTK_BOX (vbox4), label_add, FALSE, TRUE, 0);
	gtk_label_set_use_markup (GTK_LABEL (label_add), TRUE);
/*
	hbox4 = gtk_hbox_new (FALSE, 0);
	gtk_widget_show (hbox4);
	gtk_box_pack_start (GTK_BOX (vbox4), hbox4, FALSE, FALSE, 0);

	label_title = gtk_label_new (_("<b>Title :</b>"));
	gtk_widget_show (label_title);
	gtk_box_pack_start (GTK_BOX (hbox4), label_title, FALSE, FALSE, 0);
	gtk_label_set_use_markup (GTK_LABEL (label_title), TRUE);

	entry_title = gtk_entry_new ();
	gtk_widget_show (entry_title);
	gtk_box_pack_start (GTK_BOX (hbox4), entry_title, TRUE, TRUE, 0);
	gtk_entry_set_invisible_char (GTK_ENTRY (entry_title), 9679);
*/
	hbox5 = gtk_hbox_new (FALSE, 0);
	gtk_widget_show (hbox5);
	gtk_box_pack_start (GTK_BOX (vbox4), hbox5, FALSE, FALSE, 0);

	hbox6 = gtk_hbox_new (FALSE, 0);
	gtk_widget_show (hbox6);
	gtk_box_pack_start (GTK_BOX (hbox5), hbox6, TRUE, TRUE, 0);

	label_url = gtk_label_new (_("<b>URL	:</b>"));
	gtk_widget_show (label_url);
	gtk_box_pack_start (GTK_BOX (hbox6), label_url, FALSE, FALSE, 0);
	gtk_label_set_use_markup (GTK_LABEL (label_url), TRUE);

	entry_url = gtk_entry_new ();
	gtk_widget_show (entry_url);
	gtk_box_pack_start (GTK_BOX (hbox6), entry_url, TRUE, TRUE, 0);
	gtk_entry_set_invisible_char (GTK_ENTRY (entry_url), 9679);

	hbox7 = gtk_hbox_new (TRUE, 0);
	gtk_widget_show (hbox7);
	gtk_box_pack_start (GTK_BOX (vbox4), hbox7, FALSE, FALSE, 0);

	button_cancel = gtk_button_new ();
	gtk_widget_show (button_cancel);
	gtk_box_pack_start (GTK_BOX (hbox7), button_cancel, FALSE, FALSE, 0);

	alignment4 = gtk_alignment_new (0.5, 0.5, 0, 0);
	gtk_widget_show (alignment4);
	gtk_container_add (GTK_CONTAINER (button_cancel), alignment4);

	hbox9 = gtk_hbox_new (FALSE, 2);
	gtk_widget_show (hbox9);
	gtk_container_add (GTK_CONTAINER (alignment4), hbox9);

	image5 = gtk_image_new_from_stock ("gtk-cancel", GTK_ICON_SIZE_BUTTON);
	gtk_widget_show (image5);
	gtk_box_pack_start (GTK_BOX (hbox9), image5, FALSE, FALSE, 0);

	label14 = gtk_label_new_with_mnemonic (_("Cancel"));
	gtk_widget_show (label14);
	gtk_box_pack_start (GTK_BOX (hbox9), label14, FALSE, FALSE, 0);

	button_ok = gtk_button_new ();
	gtk_widget_show (button_ok);
	gtk_box_pack_start (GTK_BOX (hbox7), button_ok, FALSE, FALSE, 0);

	alignment3 = gtk_alignment_new (0.5, 0.5, 0, 0);
	gtk_widget_show (alignment3);
	gtk_container_add (GTK_CONTAINER (button_ok), alignment3);

	hbox8 = gtk_hbox_new (FALSE, 2);
	gtk_widget_show (hbox8);
	gtk_container_add (GTK_CONTAINER (alignment3), hbox8);

	image4 = gtk_image_new_from_stock ("gtk-apply", GTK_ICON_SIZE_BUTTON);
	gtk_widget_show (image4);
	gtk_box_pack_start (GTK_BOX (hbox8), image4, FALSE, FALSE, 0);

	label13 = gtk_label_new_with_mnemonic (_(" Add  "));
	gtk_widget_show (label13);
	gtk_box_pack_start (GTK_BOX (hbox8), label13, FALSE, FALSE, 0);
	

	
	g_signal_connect ((gpointer) add_rss_window, "destroy",
		G_CALLBACK (on_window_add_rss_destroy), (gpointer)add_rss_window);
                          
	g_signal_connect ((gpointer) button_ok, "clicked",
		G_CALLBACK (on_button_add_rss_ok_clicked), (gpointer)clist);
		
	g_signal_connect ((gpointer) button_cancel, "clicked",
		G_CALLBACK (on_button_add_rss_cancel_clicked), (gpointer)add_rss_window);

	clist->other.window = add_rss_window;
	//clist->other.entry_name = entry_title;
	clist->other.entry_url = entry_url;	

	return add_rss_window;
}
