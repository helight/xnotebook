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
create_dialog_about (void)
{
  GtkWidget *dialog_about;
  GtkWidget *dialog_vbox2;
  GtkWidget *label_about;
  GtkWidget *dialog_action_area2;
  GtkWidget *okbutton;

  dialog_about = gtk_dialog_new ();
  gtk_window_set_title (GTK_WINDOW (dialog_about), _("About Zhwen-Note"));
  gtk_window_set_default_size (GTK_WINDOW (dialog_about), 200, 210);
  gtk_window_set_position (GTK_WINDOW (dialog_about), GTK_WIN_POS_CENTER);
  gtk_window_set_destroy_with_parent (GTK_WINDOW (dialog_about), TRUE);
  gtk_window_set_type_hint (GTK_WINDOW (dialog_about), GDK_WINDOW_TYPE_HINT_DIALOG);

  dialog_vbox2 = GTK_DIALOG (dialog_about)->vbox;
  gtk_widget_show (dialog_vbox2);

  label_about = gtk_label_new (_("<b>\n  Zhwen-Note is a open source software.\n\
  This is wrote by Zhwen Xu. \n\n  You can get all the code at\n  http://zhwen.org.\n\n \
  And my email address is \n  Heligh.xu@gmail.com.</b>"));
  gtk_widget_show (label_about);
  gtk_box_pack_start (GTK_BOX (dialog_vbox2), label_about, FALSE, FALSE, 0);
  gtk_label_set_use_markup (GTK_LABEL (label_about), TRUE);

  dialog_action_area2 = GTK_DIALOG (dialog_about)->action_area;
  gtk_widget_show (dialog_action_area2);
  gtk_button_box_set_layout (GTK_BUTTON_BOX (dialog_action_area2), GTK_BUTTONBOX_SPREAD);

  okbutton = gtk_button_new_from_stock ("gtk-ok");
  gtk_widget_show (okbutton);
  gtk_dialog_add_action_widget (GTK_DIALOG (dialog_about), okbutton, GTK_RESPONSE_OK);
  GTK_WIDGET_SET_FLAGS (okbutton, GTK_CAN_DEFAULT);

  g_signal_connect ((gpointer) okbutton, "clicked",
                    G_CALLBACK (on_okbutton_clicked),
                    (gpointer *) dialog_about);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (dialog_about, dialog_about, "dialog_about");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog_about, dialog_vbox2, "dialog_vbox2");
  GLADE_HOOKUP_OBJECT (dialog_about, label_about, "label_about");
  GLADE_HOOKUP_OBJECT_NO_REF (dialog_about, dialog_action_area2, "dialog_action_area2");
  GLADE_HOOKUP_OBJECT (dialog_about, okbutton, "okbutton");

  return dialog_about;
}
  
