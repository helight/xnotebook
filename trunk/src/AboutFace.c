/*
 * AboutFace.c
 *
 *	Created on: Feb 19, 2009
 *			Author: helight
 */
#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include <gtk/gtk.h>
#include "About.h"

GtkWidget*
create_about_xnote (GtkWidget *main_window)
{
	GtkWidget *about_xnote;
	GdkPixbuf *about_xnote_icon_pixbuf;
	GtkWidget *dialog_vbox3;
	GtkWidget *vbox5;
	GtkWidget *image6;
	GtkWidget *label15;
	GtkWidget *label16;
	GtkWidget *button3;
	GtkWidget *dialog_action_area3;
	GtkWidget *close_about;

	about_xnote = gtk_dialog_new_with_buttons("About Xnotebook", 
		GTK_WINDOW(main_window), GTK_DIALOG_DESTROY_WITH_PARENT,NULL);
	gtk_window_set_type_hint (GTK_WINDOW (about_xnote), GDK_WINDOW_TYPE_HINT_DIALOG);
	
	about_xnote_icon_pixbuf = create_pixbuf ("zhwen.png");
	if (about_xnote_icon_pixbuf)
	{
		gtk_window_set_icon (GTK_WINDOW (about_xnote), about_xnote_icon_pixbuf);
		gdk_pixbuf_unref (about_xnote_icon_pixbuf);
	}

	dialog_vbox3 = GTK_DIALOG (about_xnote)->vbox;
	gtk_widget_show (dialog_vbox3);

	vbox5 = gtk_vbox_new (FALSE, 0);
	gtk_widget_show (vbox5);
	gtk_box_pack_start (GTK_BOX (dialog_vbox3), vbox5, TRUE, TRUE, 0);

	image6 = create_pixmap (about_xnote, "zhwen.png");
	gtk_widget_show (image6);
	gtk_box_pack_start (GTK_BOX (vbox5), image6, TRUE, TRUE, 0);

	label15 = gtk_label_new (_("<b>Xnotebook (0.08)</b>"));
	gtk_widget_show (label15);
	gtk_box_pack_start (GTK_BOX (vbox5), label15, FALSE, FALSE, 0);
	gtk_label_set_use_markup (GTK_LABEL (label15), TRUE);

	label16 = gtk_label_new (_("Xnotebook is a open source software.\nCopyright \302\251 Helight.xu@gmail.com"));
	gtk_widget_show (label16);
	gtk_box_pack_start (GTK_BOX (vbox5), label16, FALSE, FALSE, 0);

	button3 = gtk_button_new_with_mnemonic (_("http://zhwen.org"));
	gtk_widget_show (button3);
	gtk_box_pack_start (GTK_BOX (vbox5), button3, FALSE, FALSE, 0);
	gtk_button_set_relief (GTK_BUTTON (button3), GTK_RELIEF_NONE);

	dialog_action_area3 = GTK_DIALOG (about_xnote)->action_area;
		gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area3), GTK_BUTTONBOX_SPREAD);
	gtk_widget_show (dialog_action_area3);

	close_about = gtk_button_new_from_stock ("gtk-close");
	gtk_widget_show (close_about);
	gtk_dialog_add_action_widget (GTK_DIALOG (about_xnote), close_about, GTK_RESPONSE_CLOSE);
	GTK_WIDGET_SET_FLAGS (close_about, GTK_CAN_DEFAULT);

	g_signal_connect ((gpointer) button3, "clicked", 
		G_CALLBACK (on_button_link_clicked), NULL);
	g_signal_connect ((gpointer) close_about, "clicked", 
		G_CALLBACK (on_close_about_clicked), about_xnote);

	gtk_widget_grab_focus (button3);
	return about_xnote;
}

	
