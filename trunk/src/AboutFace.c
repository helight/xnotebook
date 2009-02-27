/*
 * AboutFace.c
 *
 *	Created on: Feb 19, 2009
 *	    Author: helight
 */
#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include <gtk/gtk.h>
#include "About.h"


GtkWidget*
create_window_about (void)
{
	GdkPixbuf *window_main_icon_pixbuf;
        GtkWidget *window_about;                                                                                                                                                                                                                                                                                          
        GtkWidget *vbox_about;
        GtkWidget *image_zhwen;
        GtkWidget *label_zhwen;
        GtkWidget *label_xnote;
        GtkWidget *button_link;
        GtkWidget *button_about_close;
        GtkWidget *alignment_close;
        GtkWidget *hbox_close;
        GtkWidget *image_close;
        GtkWidget *label_close;

        window_about = gtk_window_new (GTK_WINDOW_TOPLEVEL);
        gtk_window_set_title (GTK_WINDOW (window_about), _("About Xnotebook"));
	gtk_window_set_default_size (GTK_WINDOW (window_about), 300, 310);
	gtk_window_set_position (GTK_WINDOW (window_about), GTK_WIN_POS_CENTER);
	gtk_window_set_destroy_with_parent (GTK_WINDOW (window_about), TRUE);
	gtk_window_set_type_hint (GTK_WINDOW (window_about), GDK_WINDOW_TYPE_HINT_DIALOG);
	window_main_icon_pixbuf = create_pixbuf ("zhwen.png");
	if (window_main_icon_pixbuf)
	{
		gtk_window_set_icon (GTK_WINDOW (window_about), window_main_icon_pixbuf);
		gdk_pixbuf_unref (window_main_icon_pixbuf);
	}
	
        vbox_about = gtk_vbox_new (FALSE, 0);
        gtk_widget_show (vbox_about);
        gtk_container_add (GTK_CONTAINER (window_about), vbox_about);

        image_zhwen = create_pixmap (window_about, "zhwen.png");
        gtk_widget_show (image_zhwen);
        gtk_box_pack_start (GTK_BOX (vbox_about), image_zhwen, FALSE, TRUE, 0);

        label_zhwen = gtk_label_new (_("<b>Xnotebook (V0.04)</b>"));
        gtk_widget_show (label_zhwen);
        gtk_box_pack_start (GTK_BOX (vbox_about), label_zhwen, FALSE, TRUE, 0);
        gtk_label_set_use_markup (GTK_LABEL (label_zhwen), TRUE);

        label_xnote = gtk_label_new (_("Xnotebook is a open source software.\nCopyright \302\251 Helight.xu@gmail.com"));
        gtk_widget_show (label_xnote);
        gtk_box_pack_start (GTK_BOX (vbox_about), label_xnote, TRUE, TRUE, 0);

        
        button_about_close = gtk_button_new ();
        gtk_widget_show (button_about_close);
        gtk_box_pack_end (GTK_BOX (vbox_about), button_about_close, TRUE, FALSE, 0);

        alignment_close = gtk_alignment_new (0.5, 0.5, 0, 0);
        gtk_widget_show (alignment_close);
        gtk_container_add (GTK_CONTAINER (button_about_close), alignment_close);

        hbox_close = gtk_hbox_new (FALSE, 2);
        gtk_widget_show (hbox_close);
        gtk_container_add (GTK_CONTAINER (alignment_close), hbox_close);

        image_close = gtk_image_new_from_stock ("gtk-close", GTK_ICON_SIZE_BUTTON);
        gtk_widget_show (image_close);
        gtk_box_pack_start (GTK_BOX (hbox_close), image_close, FALSE, FALSE, 0);

        label_close = gtk_label_new_with_mnemonic (_("Close"));
        gtk_widget_show (label_close);
        gtk_box_pack_start (GTK_BOX (hbox_close), label_close, FALSE, FALSE, 0);

        button_link = gtk_button_new_with_mnemonic (_("http://zhwen.org"));
        gtk_widget_show (button_link);
        gtk_box_pack_end (GTK_BOX (vbox_about), button_link, TRUE, FALSE, 0);
	gtk_button_set_relief (GTK_BUTTON (button_link), GTK_RELIEF_NONE);
	
        g_signal_connect ((gpointer) image_zhwen, "button_press_event",
                          G_CALLBACK (on_image_zhwen_button_press_event),
                          NULL);
        g_signal_connect ((gpointer) button_about_close, "clicked",
                          G_CALLBACK (on_button_about_close_clicked),
                          (gpointer)window_about);
        g_signal_connect ((gpointer) button_link, "clicked",
                          G_CALLBACK (on_button_link_clicked),
                          NULL);

        /* Store pointers to all widgets, for use by lookup_widget(). */
        GLADE_HOOKUP_OBJECT_NO_REF (window_about, window_about, "window_about");
        GLADE_HOOKUP_OBJECT (window_about, vbox_about, "vbox_about");
        GLADE_HOOKUP_OBJECT (window_about, image_zhwen, "image_zhwen");
        GLADE_HOOKUP_OBJECT (window_about, label_zhwen, "label_zhwen");
        GLADE_HOOKUP_OBJECT (window_about, label_xnote, "label_xnote");
	GLADE_HOOKUP_OBJECT (window_about, button_link, "button_link");
        GLADE_HOOKUP_OBJECT (window_about, button_about_close, "button_about_close");
        GLADE_HOOKUP_OBJECT (window_about, alignment_close, "alignment_close");
        GLADE_HOOKUP_OBJECT (window_about, hbox_close, "hbox_close");
        GLADE_HOOKUP_OBJECT (window_about, image_close, "image_close");
        GLADE_HOOKUP_OBJECT (window_about, label_close, "label_close");

        gtk_widget_grab_focus (button_link);
        
        return window_about;

}
  
