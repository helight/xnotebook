/*
 * AboutFace.c
 *
 *	Created on: Feb 19, 2009
 *			Author: helight
 */
#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include "Popmenu.h"

GtkWidget*
create_folder_list_popmenu (struct clist_struct *clist)
{
	GtkWidget *folder_popmenu;
	GtkWidget *Add_Folder;
	GtkWidget *image_add;
	GtkWidget *Rename;
	GtkWidget *image_rename;
	GtkWidget *Delete;
	GtkWidget *image6;

	folder_popmenu = gtk_menu_new ();

	Add_Folder = gtk_image_menu_item_new_with_mnemonic (_("Add New"));
	gtk_widget_show (Add_Folder);
	gtk_container_add (GTK_CONTAINER (folder_popmenu), Add_Folder);
	gtk_widget_set_size_request (folder_popmenu, 100, -1);

	image_add = gtk_image_new_from_stock ("gtk-new", GTK_ICON_SIZE_MENU);
	gtk_widget_show (image_add);
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (Add_Folder), image_add);

	Rename = gtk_image_menu_item_new_with_mnemonic (_("Rename"));
	gtk_widget_show (Rename);
	gtk_container_add (GTK_CONTAINER (folder_popmenu), Rename);

	image_rename = gtk_image_new_from_stock ("gtk-refresh", GTK_ICON_SIZE_MENU);
	gtk_widget_show (image_rename);
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (Rename), image_rename);

	Delete = gtk_image_menu_item_new_with_mnemonic (_("Delete"));
	gtk_widget_show (Delete);
	gtk_container_add (GTK_CONTAINER (folder_popmenu), Delete);

	image6 = gtk_image_new_from_stock ("gtk-delete", GTK_ICON_SIZE_MENU);
	gtk_widget_show (image6);
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (Delete), image6);

	g_signal_connect ((gpointer) Add_Folder, "activate",
			G_CALLBACK (on_add_folder_pop_activate),
			clist);
	g_signal_connect ((gpointer) Rename, "activate",
			G_CALLBACK (on_rename_folder_pop_activate),
			clist);
	g_signal_connect ((gpointer) Delete, "activate",
			G_CALLBACK (on_delete_folder_pop_activate),
			clist);

	/* Store pointers to all widgets, for use by lookup_widget(). */
	GLADE_HOOKUP_OBJECT_NO_REF (folder_popmenu, folder_popmenu, "folder_popmenu");
	GLADE_HOOKUP_OBJECT (folder_popmenu, Add_Folder, "Add_Folder");
	GLADE_HOOKUP_OBJECT (folder_popmenu, image_add, "image_add");
	GLADE_HOOKUP_OBJECT (folder_popmenu, Rename, "Rename");
	GLADE_HOOKUP_OBJECT (folder_popmenu, image_rename, "image_rename");
	GLADE_HOOKUP_OBJECT (folder_popmenu, Delete, "Delete");
	GLADE_HOOKUP_OBJECT (folder_popmenu, image6, "image6");

	return folder_popmenu;
}

GtkWidget*
create_note_list_popmenu (struct clist_struct *clist)
{
	GtkWidget *note_list_popmenu;
	GtkWidget *add_note_pop;
	GtkWidget *image_add_note_pop;
	GtkWidget *rename_note_pop;
	GtkWidget *image_rename_note_pop;
	GtkWidget *delete_note_pop;
	GtkWidget *image_delete_note_pop;

	note_list_popmenu = gtk_menu_new ();

	add_note_pop = gtk_image_menu_item_new_with_mnemonic (_("Add Note"));
	gtk_widget_show (add_note_pop);
	gtk_container_add (GTK_CONTAINER (note_list_popmenu), add_note_pop);

	image_add_note_pop = gtk_image_new_from_stock ("gtk-new", GTK_ICON_SIZE_MENU);
	gtk_widget_show (image_add_note_pop);
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (add_note_pop), image_add_note_pop);

	rename_note_pop = gtk_image_menu_item_new_with_mnemonic (_("Rename"));
	gtk_widget_show (rename_note_pop);
	gtk_container_add (GTK_CONTAINER (note_list_popmenu), rename_note_pop);

	image_rename_note_pop = gtk_image_new_from_stock ("gtk-refresh", GTK_ICON_SIZE_MENU);
	gtk_widget_show (image_rename_note_pop);
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (rename_note_pop), image_rename_note_pop);

	delete_note_pop = gtk_image_menu_item_new_with_mnemonic (_("Delete"));
	gtk_widget_show (delete_note_pop);
	gtk_container_add (GTK_CONTAINER (note_list_popmenu), delete_note_pop);

	image_delete_note_pop = gtk_image_new_from_stock ("gtk-delete", GTK_ICON_SIZE_MENU);
	gtk_widget_show (image_delete_note_pop);
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (delete_note_pop), image_delete_note_pop);

	g_signal_connect ((gpointer) add_note_pop, "activate",
			G_CALLBACK (on_add_note_pop_activate),
			clist);
	g_signal_connect ((gpointer) rename_note_pop, "activate",
			G_CALLBACK (on_rename_note_pop_activate),
			clist);
	g_signal_connect ((gpointer) delete_note_pop, "activate",
			G_CALLBACK (on_delete_note_pop_activate),
			clist);

	/* Store pointers to all widgets, for use by lookup_widget(). */
	GLADE_HOOKUP_OBJECT_NO_REF (note_list_popmenu, note_list_popmenu, "note_list_popmenu");
	GLADE_HOOKUP_OBJECT (note_list_popmenu, add_note_pop, "add_note_pop");
	GLADE_HOOKUP_OBJECT (note_list_popmenu, image_add_note_pop, "image_add_note_pop");
	GLADE_HOOKUP_OBJECT (note_list_popmenu, rename_note_pop, "rename_note_pop");
	GLADE_HOOKUP_OBJECT (note_list_popmenu, image_rename_note_pop, "image_rename_note_pop");
	GLADE_HOOKUP_OBJECT (note_list_popmenu, delete_note_pop, "delete_note_pop");
	GLADE_HOOKUP_OBJECT (note_list_popmenu, image_delete_note_pop, "image_delete_note_pop");

	return note_list_popmenu;
}

GtkWidget*
create_clist_rss_popmenu (struct clist_struct *clist)
{
	GtkWidget *clist_rss_popmenu;
	GtkWidget *add_rss_pop;
	GtkWidget *image_add_rss_pop;
	GtkWidget *rename_rss_pop;
	GtkWidget *image_rename_rss_pop;
	GtkWidget *delete_rss_pop;
	GtkWidget *image_delete_rss_pop;

	clist_rss_popmenu = gtk_menu_new ();

	add_rss_pop = gtk_image_menu_item_new_with_mnemonic (_("Add rss"));
	gtk_widget_show (add_rss_pop);
	gtk_container_add (GTK_CONTAINER (clist_rss_popmenu), add_rss_pop);

	image_add_rss_pop = gtk_image_new_from_stock ("gtk-new", GTK_ICON_SIZE_MENU);
	gtk_widget_show (image_add_rss_pop);
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (add_rss_pop), image_add_rss_pop);

	rename_rss_pop = gtk_image_menu_item_new_with_mnemonic (_("Rename"));
	gtk_widget_show (rename_rss_pop);
	gtk_container_add (GTK_CONTAINER (clist_rss_popmenu), rename_rss_pop);

	image_rename_rss_pop = gtk_image_new_from_stock ("gtk-refresh", GTK_ICON_SIZE_MENU);
	gtk_widget_show (image_rename_rss_pop);
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (rename_rss_pop), image_rename_rss_pop);

	delete_rss_pop = gtk_image_menu_item_new_with_mnemonic (_("Delete"));
	gtk_widget_show (delete_rss_pop);
	gtk_container_add (GTK_CONTAINER (clist_rss_popmenu), delete_rss_pop);

	image_delete_rss_pop = gtk_image_new_from_stock ("gtk-delete", GTK_ICON_SIZE_MENU);
	gtk_widget_show (image_delete_rss_pop);
	gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (delete_rss_pop), image_delete_rss_pop);

	g_signal_connect ((gpointer) add_rss_pop, "activate",
			G_CALLBACK (on_add_rss_pop_activate),
			clist);
	g_signal_connect ((gpointer) rename_rss_pop, "activate",
			G_CALLBACK (on_rename_rss_pop_activate),
			clist);
	g_signal_connect ((gpointer) delete_rss_pop, "activate",
			G_CALLBACK (on_delete_rss_pop_activate),
			clist);

	/* Store pointers to all widgets, for use by lookup_widget(). */
	GLADE_HOOKUP_OBJECT_NO_REF (clist_rss_popmenu, clist_rss_popmenu, "clist_rss_popmenu");
	GLADE_HOOKUP_OBJECT (clist_rss_popmenu, add_rss_pop, "add_rss_pop");
	GLADE_HOOKUP_OBJECT (clist_rss_popmenu, image_add_rss_pop, "image_add_rss_pop");
	GLADE_HOOKUP_OBJECT (clist_rss_popmenu, rename_rss_pop, "rename_rss_pop");
	GLADE_HOOKUP_OBJECT (clist_rss_popmenu, image_rename_rss_pop, "image_rename_rss_pop");
	GLADE_HOOKUP_OBJECT (clist_rss_popmenu, delete_rss_pop, "delete_rss_pop");
	GLADE_HOOKUP_OBJECT (clist_rss_popmenu, image_delete_rss_pop, "image_delete_rss_pop");

	return clist_rss_popmenu;
}
