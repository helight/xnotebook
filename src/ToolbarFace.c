/*
 * itoolbar.c
 *
 *	Created on: Feb 19, 2009
 *	    Author: helight
 */
#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include <gtk/gtk.h>
#include "Toolbar.h"


GtkWidget *
create_toolbar(GtkWidget *main_windown, GtkWidget *vbox, 
				GtkTooltips *tooltips, GtkAccelGroup *accel_group, 
				struct clist_struct *clist)
{
	GtkWidget *toolbar;
	GtkIconSize tmp_toolbar_icon_size;
	GtkWidget *toolitem4;
	GtkWidget *new_note;
	GtkWidget *alignment7;
	GtkWidget *hbox7;
	GtkWidget *image_new;
	GtkWidget *label_new;
	GtkWidget *toolitem_folder;
	GtkWidget *new_folder;
	GtkWidget *alignment_folder;
	GtkWidget *hbox_folder;
	GtkWidget *image_fnew;
	GtkWidget *label_fnew;
	GtkWidget *toolitem5;
	GtkWidget *edit;
	GtkWidget *alignment8;
	GtkWidget *hbox8;
	GtkWidget *image_edit;
	GtkWidget *toolitem6;
	GtkWidget *save_note;
	GtkWidget *toolitem7;
	GtkWidget *del_folder;
	GtkWidget *alignment9;
	GtkWidget *hbox9;
	GtkWidget *image_cut;
	GtkWidget *label_cut;
	GtkWidget *toolitem8;
	GtkWidget *del_note;
	GtkWidget *alignment10;
	GtkWidget *hbox10;
	GtkWidget *image_copy;
	GtkWidget *label_copy;
	GtkWidget *toolitem9;
	GtkWidget *about_note;
	GtkWidget *alignment11;
	GtkWidget *hbox11;
	GtkWidget *image_paste;
	GtkWidget *label_paste;
	
	toolbar = gtk_toolbar_new ();
	gtk_widget_show (toolbar);
	gtk_box_pack_start (GTK_BOX (vbox), toolbar, FALSE, FALSE, 0);
	gtk_toolbar_set_style (GTK_TOOLBAR (toolbar), GTK_TOOLBAR_TEXT);
	tmp_toolbar_icon_size = gtk_toolbar_get_icon_size (GTK_TOOLBAR (toolbar));

	toolitem_folder = (GtkWidget*) gtk_tool_item_new ();
	gtk_widget_show (toolitem_folder);
	gtk_container_add (GTK_CONTAINER (toolbar), toolitem_folder);

	new_folder = gtk_button_new ();
	gtk_widget_show (new_folder);
	gtk_container_add (GTK_CONTAINER (toolitem_folder), new_folder);

	alignment_folder = gtk_alignment_new (0.5, 0.5, 0, 0);
	gtk_widget_show (alignment_folder);
	gtk_container_add (GTK_CONTAINER (new_folder), alignment_folder);

	hbox_folder = gtk_hbox_new (FALSE, 2);
	gtk_widget_show (hbox_folder);
	gtk_container_add (GTK_CONTAINER (alignment_folder), hbox_folder);

	image_fnew = gtk_image_new_from_stock ("gtk-new", GTK_ICON_SIZE_BUTTON);
	gtk_widget_show (image_fnew);
	gtk_box_pack_start (GTK_BOX (hbox_folder), image_fnew, FALSE, FALSE, 0);

	label_fnew = gtk_label_new_with_mnemonic (_("New Folder"));
	gtk_widget_show (label_fnew);
	gtk_box_pack_start (GTK_BOX (hbox_folder), label_fnew, FALSE, FALSE, 0);

	toolitem4 = (GtkWidget*) gtk_tool_item_new ();
	gtk_widget_show (toolitem4);
	gtk_container_add (GTK_CONTAINER (toolbar), toolitem4);
	
	new_note = gtk_button_new ();
	gtk_widget_show (new_note);
	gtk_container_add (GTK_CONTAINER (toolitem4), new_note);

	alignment7 = gtk_alignment_new (0.5, 0.5, 0, 0);
	gtk_widget_show (alignment7);
	gtk_container_add (GTK_CONTAINER (new_note), alignment7);

	hbox7 = gtk_hbox_new (FALSE, 2);
	gtk_widget_show (hbox7);
	gtk_container_add (GTK_CONTAINER (alignment7), hbox7);

	image_new = gtk_image_new_from_stock ("gtk-new", GTK_ICON_SIZE_BUTTON);
	gtk_widget_show (image_new);
	gtk_box_pack_start (GTK_BOX (hbox7), image_new, FALSE, FALSE, 0);

	label_new = gtk_label_new_with_mnemonic (_("New Note"));
	gtk_widget_show (label_new);
	gtk_box_pack_start (GTK_BOX (hbox7), label_new, FALSE, FALSE, 0);

	toolitem5 = (GtkWidget*) gtk_tool_item_new ();
	gtk_widget_show (toolitem5);
	gtk_container_add (GTK_CONTAINER (toolbar), toolitem5);
	
	edit = gtk_button_new ();
	gtk_widget_show (edit);
	gtk_container_add (GTK_CONTAINER (toolitem5), edit);

	alignment8 = gtk_alignment_new (0.5, 0.5, 0, 0);
	gtk_widget_show (alignment8);
	gtk_container_add (GTK_CONTAINER (edit), alignment8);

	hbox8 = gtk_hbox_new (FALSE, 2);
	gtk_widget_show (hbox8);
	gtk_container_add (GTK_CONTAINER (alignment8), hbox8);

	image_edit = gtk_image_new_from_stock ("gtk-edit", GTK_ICON_SIZE_BUTTON);
	gtk_widget_show (image_edit);
	gtk_box_pack_start (GTK_BOX (hbox8), image_edit, FALSE, FALSE, 0);

	label_new = gtk_label_new_with_mnemonic (_("Edit"));
	gtk_widget_show (label_new);
	gtk_box_pack_start (GTK_BOX (hbox8), label_new, FALSE, FALSE, 0);

	toolitem6 = (GtkWidget*) gtk_tool_item_new ();
	gtk_widget_show (toolitem6);
	gtk_container_add (GTK_CONTAINER (toolbar), toolitem6);

	save_note = gtk_button_new_from_stock ("gtk-save");
	gtk_widget_show (save_note);
	gtk_container_add (GTK_CONTAINER (toolitem6), save_note);

	toolitem7 = (GtkWidget*) gtk_tool_item_new ();
	gtk_widget_show (toolitem7);
	gtk_container_add (GTK_CONTAINER (toolbar), toolitem7);

	del_folder = gtk_button_new ();
	gtk_widget_show (del_folder);
	gtk_container_add (GTK_CONTAINER (toolitem7), del_folder);

	alignment9 = gtk_alignment_new (0.5, 0.5, 0, 0);
	gtk_widget_show (alignment9);
	gtk_container_add (GTK_CONTAINER (del_folder), alignment9);

	hbox9 = gtk_hbox_new (FALSE, 2);
	gtk_widget_show (hbox9);
	gtk_container_add (GTK_CONTAINER (alignment9), hbox9);

	image_cut = gtk_image_new_from_stock ("gtk-delete", GTK_ICON_SIZE_BUTTON);
	gtk_widget_show (image_cut);
	gtk_box_pack_start (GTK_BOX (hbox9), image_cut, FALSE, FALSE, 0);

	label_cut = gtk_label_new_with_mnemonic (_("Del Folder"));
	gtk_widget_show (label_cut);
	gtk_box_pack_start (GTK_BOX (hbox9), label_cut, FALSE, FALSE, 0);

	toolitem8 = (GtkWidget*) gtk_tool_item_new ();
	gtk_widget_show (toolitem8);
	gtk_container_add (GTK_CONTAINER (toolbar), toolitem8);

	del_note = gtk_button_new ();
	gtk_widget_show (del_note);
	gtk_container_add (GTK_CONTAINER (toolitem8), del_note);

	alignment10 = gtk_alignment_new (0.5, 0.5, 0, 0);
	gtk_widget_show (alignment10);
	gtk_container_add (GTK_CONTAINER (del_note), alignment10);

	hbox10 = gtk_hbox_new (FALSE, 2);
	gtk_widget_show (hbox10);
	gtk_container_add (GTK_CONTAINER (alignment10), hbox10);

	image_copy = gtk_image_new_from_stock ("gtk-delete", GTK_ICON_SIZE_BUTTON);
	gtk_widget_show (image_copy);
	gtk_box_pack_start (GTK_BOX (hbox10), image_copy, FALSE, FALSE, 0);

	label_copy = gtk_label_new_with_mnemonic (_("Del Note"));
	gtk_widget_show (label_copy);
	gtk_box_pack_start (GTK_BOX (hbox10), label_copy, FALSE, FALSE, 0);

	toolitem9 = (GtkWidget*) gtk_tool_item_new ();
	gtk_widget_show (toolitem9);
	gtk_container_add (GTK_CONTAINER (toolbar), toolitem9);

	about_note = gtk_button_new ();
	gtk_widget_show (about_note);
	gtk_container_add (GTK_CONTAINER (toolitem9), about_note);

	alignment11 = gtk_alignment_new (0.5, 0.5, 0, 0);
	gtk_widget_show (alignment11);
	gtk_container_add (GTK_CONTAINER (about_note), alignment11);

	hbox11 = gtk_hbox_new (FALSE, 2);
	gtk_widget_show (hbox11);
	gtk_container_add (GTK_CONTAINER (alignment11), hbox11);

	image_paste = gtk_image_new_from_stock ("gtk-help", GTK_ICON_SIZE_BUTTON);
	gtk_widget_show (image_paste);
	gtk_box_pack_start (GTK_BOX (hbox11), image_paste, FALSE, FALSE, 0);

	label_paste = gtk_label_new_with_mnemonic (_("About"));
	gtk_widget_show (label_paste);
	gtk_box_pack_start (GTK_BOX (hbox11), label_paste, FALSE, FALSE, 0);	
	
	g_signal_connect ((gpointer) new_folder, "clicked",
	                  G_CALLBACK (on_new_folder_clicked),
	                  (gpointer *)clist); 
	g_signal_connect ((gpointer) new_note, "clicked",
	                  G_CALLBACK (on_new_note_clicked),
	                  (gpointer *)clist);
	g_signal_connect ((gpointer) edit, "clicked",
	                  G_CALLBACK (on_edit_clicked),
	                  (gpointer *)clist);
	g_signal_connect ((gpointer) save_note, "clicked",
	                  G_CALLBACK (on_save_note_clicked),
	                  (gpointer *)clist);
	g_signal_connect ((gpointer) del_folder, "clicked",
	                  G_CALLBACK (on_del_folder_clicked),
	                  NULL);
	g_signal_connect ((gpointer) del_note, "clicked",
	                  G_CALLBACK (on_del_note_clicked),
	                  NULL);
	g_signal_connect ((gpointer) about_note, "clicked",
	                  G_CALLBACK (on_about_note_clicked),
	                  (gpointer *)clist);	
	                  
	GLADE_HOOKUP_OBJECT (main_windown, toolitem4, "toolitem4");
	GLADE_HOOKUP_OBJECT (main_windown, new_note, "new_folder");
	GLADE_HOOKUP_OBJECT (main_windown, alignment7, "alignment_folder");
	GLADE_HOOKUP_OBJECT (main_windown, hbox7, "hbox_folder");
	GLADE_HOOKUP_OBJECT (main_windown, image_new, "image_fnew");
	GLADE_HOOKUP_OBJECT (main_windown, label_new, "label_fnew");
	GLADE_HOOKUP_OBJECT (main_windown, new_note, "new_note");
	GLADE_HOOKUP_OBJECT (main_windown, alignment7, "alignment7");
	GLADE_HOOKUP_OBJECT (main_windown, hbox7, "hbox7");
	GLADE_HOOKUP_OBJECT (main_windown, image_new, "image_new");
	GLADE_HOOKUP_OBJECT (main_windown, label_new, "label_new");
	GLADE_HOOKUP_OBJECT (main_windown, toolitem5, "toolitem5");
	GLADE_HOOKUP_OBJECT (main_windown, edit, "edit");
	GLADE_HOOKUP_OBJECT (main_windown, alignment8, "alignment8");
	GLADE_HOOKUP_OBJECT (main_windown, hbox8, "hbox8");
	GLADE_HOOKUP_OBJECT (main_windown, image_edit, "image_edit");
	GLADE_HOOKUP_OBJECT (main_windown, label_new, "label_new");
	GLADE_HOOKUP_OBJECT (main_windown, toolitem6, "toolitem6");
	GLADE_HOOKUP_OBJECT (main_windown, save_note, "save_note");
	GLADE_HOOKUP_OBJECT (main_windown, toolitem7, "toolitem7");
	GLADE_HOOKUP_OBJECT (main_windown, del_folder, "del_folder");
	GLADE_HOOKUP_OBJECT (main_windown, alignment9, "alignment9");
	GLADE_HOOKUP_OBJECT (main_windown, hbox9, "hbox9");
	GLADE_HOOKUP_OBJECT (main_windown, image_cut, "image_cut");
	GLADE_HOOKUP_OBJECT (main_windown, label_cut, "label_cut");
	GLADE_HOOKUP_OBJECT (main_windown, toolitem8, "toolitem8");
	GLADE_HOOKUP_OBJECT (main_windown, del_note, "del_note");
	GLADE_HOOKUP_OBJECT (main_windown, alignment10, "alignment10");
	GLADE_HOOKUP_OBJECT (main_windown, hbox10, "hbox10");
	GLADE_HOOKUP_OBJECT (main_windown, image_copy, "image_copy");
	GLADE_HOOKUP_OBJECT (main_windown, label_copy, "label_copy");
	GLADE_HOOKUP_OBJECT (main_windown, toolitem9, "toolitem9");
	GLADE_HOOKUP_OBJECT (main_windown, about_note, "about_note");
	GLADE_HOOKUP_OBJECT (main_windown, alignment11, "alignment11");
	GLADE_HOOKUP_OBJECT (main_windown, hbox11, "hbox11");
	GLADE_HOOKUP_OBJECT (main_windown, image_paste, "image_paste");
	GLADE_HOOKUP_OBJECT (main_windown, label_paste, "label_paste");
	return toolbar;
}
