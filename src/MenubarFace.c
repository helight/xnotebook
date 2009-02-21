/*
 * imenuba.c
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "Support.h"
#include "Menubar.h"


GtkWidget *
create_menubar(GtkWidget *main_windown,GtkWidget *vbox,
				GtkTooltips *tooltips,GtkAccelGroup *accel_group)
{
	  GtkWidget *menubar; /*menu bar pointer*/
	  /*-----------file ---------*/
	  GtkWidget *menuitem1;
	  GtkWidget *menu1;
	  GtkWidget *new1;
	  GtkWidget *save1;
	  GtkWidget *separatormenuitem1;
	  GtkWidget *quit1;
	  /*---------edit-----------*/
	  GtkWidget *menuitem2;
	  GtkWidget *menu2;
	  GtkWidget *cut1;
	  GtkWidget *copy1;
	  GtkWidget *paste1;
	  GtkWidget *delete1;
	  /*---------view-----------*/
	  GtkWidget *menuitem3;
	  GtkWidget *menu3;
	  /*---------help-----------*/
	  GtkWidget *menuitem4;
	  GtkWidget *menu4;
	  GtkWidget *about1;
	  
	  /*create menu bar*/
	  menubar = gtk_menu_bar_new ();
	  gtk_widget_show (menubar);
	  gtk_box_pack_start (GTK_BOX (vbox), menubar, FALSE, FALSE, 0);
	  gtk_widget_set_size_request (menubar, -1, 30);
	  
	  menuitem1 = gtk_menu_item_new_with_mnemonic (_("_File"));
	  gtk_widget_show (menuitem1);
	  gtk_container_add (GTK_CONTAINER (menubar), menuitem1);
	
	  menu1 = gtk_menu_new ();
	  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem1), menu1);
	
	  new1 = gtk_image_menu_item_new_from_stock ("gtk-new", accel_group);
	  gtk_widget_show (new1);
	  gtk_container_add (GTK_CONTAINER (menu1), new1);
	
	  save1 = gtk_image_menu_item_new_from_stock ("gtk-save", accel_group);
	  gtk_widget_show (save1);
	  gtk_container_add (GTK_CONTAINER (menu1), save1);
	
	  separatormenuitem1 = gtk_separator_menu_item_new ();
	  gtk_widget_show (separatormenuitem1);
	  gtk_container_add (GTK_CONTAINER (menu1), separatormenuitem1);
	  gtk_widget_set_sensitive (separatormenuitem1, FALSE);
	
	  quit1 = gtk_image_menu_item_new_from_stock ("gtk-quit", accel_group);
	  gtk_widget_show (quit1);
	  gtk_container_add (GTK_CONTAINER (menu1), quit1);
	
	  menuitem2 = gtk_menu_item_new_with_mnemonic (_("_Edit"));
	  gtk_widget_show (menuitem2);
	  gtk_container_add (GTK_CONTAINER (menubar), menuitem2);
	
	  menu2 = gtk_menu_new ();
	  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem2), menu2);
	
	  cut1 = gtk_image_menu_item_new_from_stock ("gtk-cut", accel_group);
	  gtk_widget_show (cut1);
	  gtk_container_add (GTK_CONTAINER (menu2), cut1);
	
	  copy1 = gtk_image_menu_item_new_from_stock ("gtk-copy", accel_group);
	  gtk_widget_show (copy1);
	  gtk_container_add (GTK_CONTAINER (menu2), copy1);
	
	  paste1 = gtk_image_menu_item_new_from_stock ("gtk-paste", accel_group);
	  gtk_widget_show (paste1);
	  gtk_container_add (GTK_CONTAINER (menu2), paste1);
	
	  delete1 = gtk_image_menu_item_new_from_stock ("gtk-delete", accel_group);
	  gtk_widget_show (delete1);
	  gtk_container_add (GTK_CONTAINER (menu2), delete1);
	
	  menuitem3 = gtk_menu_item_new_with_mnemonic (_("_View"));
	  gtk_widget_show (menuitem3);
	  gtk_container_add (GTK_CONTAINER (menubar), menuitem3);
	
	  menu3 = gtk_menu_new ();
	  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem3), menu3);
	
	  menuitem4 = gtk_menu_item_new_with_mnemonic (_("_Help"));
	  gtk_widget_show (menuitem4);
	  gtk_container_add (GTK_CONTAINER (menubar), menuitem4);
	
	  menu4 = gtk_menu_new ();
	  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem4), menu4);
	
	  about1 = gtk_menu_item_new_with_mnemonic (_("_About"));
	  gtk_widget_show (about1);
	  gtk_container_add (GTK_CONTAINER (menu4), about1);
	  
	  g_signal_connect ((gpointer) new1, "activate",
	  G_CALLBACK (on_new1_activate),
	  NULL);
	  g_signal_connect ((gpointer) save1, "activate",
	              G_CALLBACK (on_save1_activate),
	              NULL);
	  g_signal_connect ((gpointer) quit1, "activate",
	              G_CALLBACK (on_quit1_activate),
	              NULL);
	  g_signal_connect ((gpointer) cut1, "activate",
	              G_CALLBACK (on_cut1_activate),
	              NULL);
	  g_signal_connect ((gpointer) copy1, "activate",
	              G_CALLBACK (on_copy1_activate),
	              NULL);
	  g_signal_connect ((gpointer) paste1, "activate",
	              G_CALLBACK (on_paste1_activate),
	              NULL);
	  g_signal_connect ((gpointer) delete1, "activate",
	              G_CALLBACK (on_delete1_activate),
	              NULL);
	  g_signal_connect ((gpointer) about1, "activate",
	              G_CALLBACK (on_about1_activate),
	              NULL);
	  GLADE_HOOKUP_OBJECT (main_windown, menuitem1, "menuitem1");
	  GLADE_HOOKUP_OBJECT (main_windown, menu1, "menu1");
	  GLADE_HOOKUP_OBJECT (main_windown, new1, "new1");
	  GLADE_HOOKUP_OBJECT (main_windown, save1, "save1");
	  GLADE_HOOKUP_OBJECT (main_windown, separatormenuitem1, "separatormenuitem1");
	  GLADE_HOOKUP_OBJECT (main_windown, quit1, "quit1");
	  GLADE_HOOKUP_OBJECT (main_windown, menuitem2, "menuitem2");
	  GLADE_HOOKUP_OBJECT (main_windown, menu2, "menu2");
	  GLADE_HOOKUP_OBJECT (main_windown, cut1, "cut1");
	  GLADE_HOOKUP_OBJECT (main_windown, copy1, "copy1");
	  GLADE_HOOKUP_OBJECT (main_windown, paste1, "paste1");
	  GLADE_HOOKUP_OBJECT (main_windown, delete1, "delete1");
	  GLADE_HOOKUP_OBJECT (main_windown, menuitem3, "menuitem3");
	  GLADE_HOOKUP_OBJECT (main_windown, menu3, "menu3");
	  GLADE_HOOKUP_OBJECT (main_windown, menuitem4, "menuitem4");
	  GLADE_HOOKUP_OBJECT (main_windown, menu4, "menu4");
	  GLADE_HOOKUP_OBJECT (main_windown, about1, "about1");
	  
	  return menubar;
}

