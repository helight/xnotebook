/*
 * imenuba.c
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "Support.h"
#include "Menubar.h"


GtkWidget *
create_menubar(GtkWidget *main_windown,GtkWidget *vbox,
		GtkTooltips *tooltips,GtkAccelGroup *accel_group,
		struct clist_struct *clist)
{
	  GtkWidget *menubar; /*menu bar pointer*/
	  /*-----------file ---------*/
	  GtkWidget *menuitem_file;
	  GtkWidget *menu_file;
	  
	  GtkWidget *new_folder;
	  GtkWidget *image_new_folder;
	  
	  GtkWidget *new_note;
	  GtkWidget *image_new_note;
	  
	  GtkWidget *save_note;
	  GtkWidget *image_save;
	  GtkWidget *separatormenuitem_file;
	  GtkWidget *quit;
	  /*---------edit-----------*/
	  GtkWidget *menuitem_edit;
	  GtkWidget *menu_edit;
	  GtkWidget *edit_note;
	  GtkWidget *image_edit;
	  
	  GtkWidget *rename_folder;
	  GtkWidget *image_ref;
	  
	  GtkWidget *rename_note;
	  GtkWidget *image_ren;
	  
	  GtkWidget *separatormenuitem_edit;
	  GtkWidget *del_folder;
	  GtkWidget *image_del_folder;
	  GtkWidget *del_note;
	  GtkWidget *image_del_note;
	  /*---------tool-----------*/
	  GtkWidget *menuitem_tools;
	  GtkWidget *menu_tools;
	  GtkWidget *calendar_note;
	  GtkWidget *image_calendar;

	  GtkWidget *backup_note;
	  GtkWidget *image_backup;
	  /*---------help-----------*/
	  GtkWidget *menuitem_about;
	  GtkWidget *menu_about;
	  GtkWidget *about_me;
	  GtkWidget *image_about;
	  
	  /*create menu bar*/
	  menubar = gtk_menu_bar_new ();
	  gtk_widget_show (menubar);
	  gtk_box_pack_start (GTK_BOX (vbox), menubar, FALSE, FALSE, 0);
	  gtk_widget_set_size_request (menubar, -1, 30);
	  
	  menuitem_file = gtk_menu_item_new_with_mnemonic (_("_File"));
	  gtk_widget_show (menuitem_file);
	  gtk_container_add (GTK_CONTAINER (menubar), menuitem_file);
	
	  menu_file = gtk_menu_new ();
	  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem_file), menu_file);
 /*------------------------------------------------------------------------------------*/
	  new_folder = gtk_image_menu_item_new_with_mnemonic (_("New Folder"));
	  gtk_widget_show (new_folder);
          gtk_container_add (GTK_CONTAINER (menu_file), new_folder);
          gtk_tooltips_set_tip (tooltips, new_folder, _("Add A New Folder"), NULL);
          gtk_widget_add_accelerator (new_folder, "activate", accel_group,
                                                    GDK_F, (GdkModifierType) GDK_CONTROL_MASK,
                                                     GTK_ACCEL_VISIBLE);
                                                     
          image_new_folder = gtk_image_new_from_stock ("gtk-new", GTK_ICON_SIZE_MENU);
	  gtk_widget_show (image_new_folder);
          gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (new_folder), image_new_folder);
 /*------------------------------------------------------------------------------------*/	
	  new_note = gtk_image_menu_item_new_with_mnemonic (_("New Note"));
	  gtk_widget_show (new_note);
          gtk_container_add (GTK_CONTAINER (menu_file), new_note);
          gtk_tooltips_set_tip (tooltips, new_note, _("Add A New Note"), NULL);
          gtk_widget_add_accelerator (new_note, "activate", accel_group,
                                                    GDK_N, (GdkModifierType) GDK_CONTROL_MASK,
                                                     GTK_ACCEL_VISIBLE);
                                                     
          image_new_note = gtk_image_new_from_stock ("gtk-new", GTK_ICON_SIZE_MENU);
	  gtk_widget_show (image_new_note);
          gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (new_note), image_new_note);
 /*------------------------------------------------------------------------------------*/          
	  save_note = gtk_image_menu_item_new_with_mnemonic (_("Save"));
	  gtk_widget_show (save_note);
          gtk_container_add (GTK_CONTAINER (menu_file), save_note);
          gtk_tooltips_set_tip (tooltips, save_note, _("Save Note"), NULL);
          gtk_widget_add_accelerator (save_note, "activate", accel_group,
                                                    GDK_S, (GdkModifierType) GDK_CONTROL_MASK,
                                                     GTK_ACCEL_VISIBLE);
                                                     
          image_save = gtk_image_new_from_stock ("gtk-save", GTK_ICON_SIZE_MENU);
	  gtk_widget_show (image_save);
          gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (save_note), image_save);
 /*------------------------------------------------------------------------------------*/	
	  separatormenuitem_file = gtk_separator_menu_item_new ();
	  gtk_widget_show (separatormenuitem_file);
	  gtk_container_add (GTK_CONTAINER (menu_file), separatormenuitem_file);
	  gtk_widget_set_sensitive (separatormenuitem_file, FALSE);
 /*------------------------------------------------------------------------------------*/	
	  quit = gtk_image_menu_item_new_from_stock ("gtk-quit", accel_group);
	  gtk_widget_show (quit);
	  gtk_container_add (GTK_CONTAINER (menu_file), quit);
 /*------------------------------------------------------------------------------------*/	
	  menuitem_edit = gtk_menu_item_new_with_mnemonic (_("_Edit"));
	  gtk_widget_show (menuitem_edit);
	  gtk_container_add (GTK_CONTAINER (menubar), menuitem_edit);
 /*------------------------------------------------------------------------------------*/	
	  menu_edit = gtk_menu_new ();
	  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem_edit), menu_edit);
 /*------------------------------------------------------------------------------------*/	
	  edit_note = gtk_image_menu_item_new_with_mnemonic (_("Edit Note"));
	  gtk_widget_show (edit_note);
          gtk_container_add (GTK_CONTAINER (menu_edit), edit_note);
          gtk_tooltips_set_tip (tooltips, edit_note, _("Add A New Note"), NULL);
          gtk_widget_add_accelerator (edit_note, "activate", accel_group,
                                                    GDK_E, (GdkModifierType) GDK_CONTROL_MASK,
                                                     GTK_ACCEL_VISIBLE);
                                                     
          image_edit = gtk_image_new_from_stock ("gtk-edit", GTK_ICON_SIZE_MENU);
	  gtk_widget_show (image_edit);
          gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (edit_note), image_edit);
 /*------------------------------------------------------------------------------------*/
	  rename_folder = gtk_image_menu_item_new_with_mnemonic (_("Rename Folder"));
	  gtk_widget_show (rename_folder);
          gtk_container_add (GTK_CONTAINER (menu_edit), rename_folder);
          gtk_tooltips_set_tip (tooltips, rename_folder, _("Rename The Folder"), NULL);
          gtk_widget_add_accelerator (rename_folder, "activate", accel_group,
                                                    GDK_Y, (GdkModifierType) GDK_CONTROL_MASK,
                                                     GTK_ACCEL_VISIBLE);
                                                     
          image_ref = gtk_image_new_from_stock ("gtk-edit", GTK_ICON_SIZE_MENU);
	  gtk_widget_show (image_ref);
          gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (rename_folder), image_ref); 
/*------------------------------------------------------------------------------------*/
	  rename_note = gtk_image_menu_item_new_with_mnemonic (_("Rename Note"));
	  gtk_widget_show (rename_note);
          gtk_container_add (GTK_CONTAINER (menu_edit), rename_note);
          gtk_tooltips_set_tip (tooltips, rename_note, _("Rename The Note"), NULL);
          gtk_widget_add_accelerator (rename_note, "activate", accel_group,
                                                    GDK_U, (GdkModifierType) GDK_CONTROL_MASK,
                                                     GTK_ACCEL_VISIBLE);
                                                     
          image_ren = gtk_image_new_from_stock ("gtk-edit", GTK_ICON_SIZE_MENU);
	  gtk_widget_show (image_ren);
          gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (rename_note), image_ren);
 /*------------------------------------------------------------------------------------*/
 	  separatormenuitem_edit = gtk_separator_menu_item_new ();
	  gtk_widget_show (separatormenuitem_edit);
	  gtk_container_add (GTK_CONTAINER (menu_edit), separatormenuitem_edit);
	  gtk_widget_set_sensitive (separatormenuitem_edit, FALSE);
 /*------------------------------------------------------------------------------------*/	
	  del_folder = gtk_image_menu_item_new_with_mnemonic (_("Del Folder"));
	  gtk_widget_show (del_folder);
          gtk_container_add (GTK_CONTAINER (menu_edit), del_folder);
          gtk_tooltips_set_tip (tooltips, del_folder, _("Delete A Folder"), NULL);
          gtk_widget_add_accelerator (del_folder, "activate", accel_group,
                                                    GDK_G, (GdkModifierType) GDK_CONTROL_MASK,
                                                     GTK_ACCEL_VISIBLE);
                                                     
          image_del_folder = gtk_image_new_from_stock ("gtk-delete", GTK_ICON_SIZE_MENU);
	  gtk_widget_show (image_del_folder);
          gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (del_folder), image_del_folder);
 /*------------------------------------------------------------------------------------*/	
	  del_note = gtk_image_menu_item_new_with_mnemonic (_("Del Note"));
	  gtk_widget_show (del_note);
          gtk_container_add (GTK_CONTAINER (menu_edit), del_note);
          gtk_tooltips_set_tip (tooltips, del_note, _("Delete A Note"), NULL);
          gtk_widget_add_accelerator (del_note, "activate", accel_group,
                   GDK_D, (GdkModifierType) GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
          image_del_note = gtk_image_new_from_stock ("gtk-delete", GTK_ICON_SIZE_MENU);
	  gtk_widget_show (image_del_note);
          gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (del_note), image_del_note);
 /*------------------------------------------------------------------------------------*/	
	  menuitem_tools = gtk_menu_item_new_with_mnemonic (_("_Tools"));
	  gtk_widget_show (menuitem_tools);
	  gtk_container_add (GTK_CONTAINER (menubar), menuitem_tools);
 /*------------------------------------------------------------------------------------*/	
	  menu_tools = gtk_menu_new ();
	  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem_tools), menu_tools);
 /*------------------------------------------------------------------------------------*/
 	  backup_note = gtk_image_menu_item_new_with_mnemonic (_("Backup"));
	  gtk_widget_show (backup_note);
          gtk_container_add (GTK_CONTAINER (menu_tools), backup_note);
          gtk_tooltips_set_tip (tooltips, backup_note, _("Backup"), NULL);
          gtk_widget_add_accelerator (backup_note, "activate", accel_group,
                   GDK_D, (GdkModifierType) GDK_CONTROL_MASK, GTK_ACCEL_VISIBLE);
          image_backup = gtk_image_new_from_stock ("gtk-dialog-info", GTK_ICON_SIZE_MENU);
	  gtk_widget_show (image_backup);
          gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (backup_note), image_backup);
 /*------------------------------------------------------------------------------------*/
 	  calendar_note = gtk_image_menu_item_new_with_mnemonic (_("Calendar"));
	  gtk_widget_show (calendar_note);
          gtk_container_add (GTK_CONTAINER (menu_tools), calendar_note);
          gtk_tooltips_set_tip (tooltips, calendar_note, _("Calendar"), NULL);
          gtk_widget_add_accelerator (calendar_note, "activate", accel_group,
                                                    GDK_R, (GdkModifierType) GDK_CONTROL_MASK,
                                                     GTK_ACCEL_VISIBLE);
                                                     
          image_calendar = gtk_image_new_from_stock ("gtk-dialog-info", GTK_ICON_SIZE_MENU);
	  gtk_widget_show (image_calendar);
          gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (calendar_note), image_calendar);
  /*------------------------------------------------------------------------------------*/	
	  menuitem_about = gtk_menu_item_new_with_mnemonic (_("_Help"));
	  gtk_widget_show (menuitem_about);
	  gtk_container_add (GTK_CONTAINER (menubar), menuitem_about);
 /*------------------------------------------------------------------------------------*/	
	  menu_about = gtk_menu_new ();
	  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem_about), menu_about);
 /*------------------------------------------------------------------------------------*/	
	  about_me = gtk_image_menu_item_new_with_mnemonic (_("About"));
	  gtk_widget_show (about_me);
          gtk_container_add (GTK_CONTAINER (menu_about), about_me);
          gtk_tooltips_set_tip (tooltips, about_me, _("About Me"), NULL);
          gtk_widget_add_accelerator (about_me, "activate", accel_group,
                                                    GDK_M, (GdkModifierType) GDK_CONTROL_MASK,
                                                     GTK_ACCEL_VISIBLE);
                                                     
          image_about = gtk_image_new_from_stock ("gtk-about", GTK_ICON_SIZE_MENU);
	  gtk_widget_show (image_about);
          gtk_image_menu_item_set_image (GTK_IMAGE_MENU_ITEM (about_me), image_about);
 /*------------------------------------------------------------------------------------*/	  
	  g_signal_connect ((gpointer) new_folder, "activate",
	  		G_CALLBACK (on_new_folder_activate),
	  		(gpointer)clist);
	  g_signal_connect ((gpointer) new_note, "activate",
	              G_CALLBACK (on_new_note_activate),
	              (gpointer)clist);
	  g_signal_connect ((gpointer) save_note, "activate",
	              G_CALLBACK (on_save_note_activate),
	              (gpointer)clist);
	  g_signal_connect ((gpointer) quit, "activate",
	              G_CALLBACK (on_quit_activate),
	              NULL);
	  g_signal_connect ((gpointer) edit_note, "activate",
	              G_CALLBACK (on_edit_note_activate),
	              (gpointer)clist);
	  g_signal_connect ((gpointer) rename_folder, "activate",
	              G_CALLBACK (on_rename_folder_activate),
	              (gpointer)clist);
	  g_signal_connect ((gpointer) rename_note, "activate",
	              G_CALLBACK (on_rename_note_activate),
	              (gpointer)clist);
 	  g_signal_connect ((gpointer) del_folder, "activate",
	              G_CALLBACK (on_del_folder_activate),
	              (gpointer)clist);
	  g_signal_connect ((gpointer) del_note, "activate",
	              G_CALLBACK (on_del_note_activate),
	              (gpointer)clist);
	  g_signal_connect ((gpointer) backup_note, "activate",
	              G_CALLBACK (on_backup_note_activate),
	              (gpointer)clist);
	  g_signal_connect ((gpointer) calendar_note, "activate",
	              G_CALLBACK (on_calendar_note_activate),
	              (gpointer)main_windown);
	  g_signal_connect ((gpointer) about_me, "activate",
	              G_CALLBACK (on_about_me_activate),
	              (gpointer)main_windown);

	  return menubar;
}

