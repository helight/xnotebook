/*
 * itoolbar.c
 *
 *	Created on: Feb 19, 2009
 *	    Author: helight
 */
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "Debug.h"
#include "Funs.h"
#include "AddFolder.h"

void handle_for_create_window_add(gpointer user_data)
{
	GtkWidget *window;
	struct clist_struct *clist = (struct clist_struct *)user_data;

  	window=(GtkWidget *)create_new_add_window (user_data);

	if(clist->creat == FOLDER)
		gtk_window_set_title (GTK_WINDOW (window), _(
					"Add A Folder"));
	else if(clist->creat == NOTE_FILE)
		gtk_window_set_title (GTK_WINDOW (window), _(
					"Add A NoteFile"));
	else if(clist->xname == FOLDER)
		gtk_window_set_title (GTK_WINDOW (window), _(
					"Rename The Folder"));
	else if(clist->xname == NOTE_FILE)
		gtk_window_set_title (GTK_WINDOW (window), _(
					"Rename The NoteFile"));
	else{ 
		gtk_window_set_title (GTK_WINDOW (window), _(
					"You Haven't selected Folder or File"));
	}
	gtk_widget_show(window);
}

GtkWidget*
create_new_add_window (struct clist_struct *clist)
{
        GtkWidget *window; 
        GtkWidget *vbox_top;
        GtkWidget *label_title;
        GtkWidget *entry_text;
        GtkWidget *hbox_bottom;
        GtkWidget *button_help;
        GtkWidget *alignment2;
        GtkWidget *hbox3;
        GtkWidget *image_help;
        GtkWidget *label_help;
        GtkWidget *button_cancel;
        GtkWidget *alignment1;
        GtkWidget *hbox2;
        GtkWidget *image_cancel;
        GtkWidget *label_cancel;
        GtkWidget *button_ok;
        GtkWidget *alignment3;
        GtkWidget *hbox4;
        GtkWidget *image_apply;
        GtkWidget *label_apply;

        window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
        gtk_window_set_position (GTK_WINDOW (window), GTK_WIN_POS_CENTER);
        gtk_window_set_default_size (GTK_WINDOW (window), 100, 50);
        gtk_window_set_resizable (GTK_WINDOW (window), FALSE);
        gtk_window_set_destroy_with_parent (GTK_WINDOW (window), TRUE);
        gtk_window_set_icon_name (GTK_WINDOW (window), "gtk-add");

        vbox_top = gtk_vbox_new (TRUE, 0);
        gtk_widget_show (vbox_top);
        gtk_container_add (GTK_CONTAINER (window), vbox_top);
        
	if(clist->creat == FOLDER){
		label_title = gtk_label_new (_("<b>Creat Folder On Root Folder:</b>"));
	} else if(clist->creat == NOTE_FILE){
		gchar title[128];
		gchar *name = clist->sub_path;
		name = name + strlen(clist->root_path)+1;
		g_snprintf(title, sizeof(title), "<b>Creat Folder On \n %s </b>", name);
		debug_p("the foldername:%s\n",name);
		label_title = gtk_label_new (_(title));
	} else if(clist->xname == FOLDER){
		gchar title[128];
		gchar *name = clist->sub_path;
		name = name + strlen(clist->root_path)+1;
		g_snprintf(title, sizeof(title), "<b>Rename This NoteFile \n %s </b>", name);
		debug_p("the foldername:%s\n",name);
		label_title = gtk_label_new (_(title));
		
	} else if(clist->xname == NOTE_FILE){
		gchar title[128];
		gchar *name = clist->doc_path;
		name = name + strlen(clist->sub_path)+1;
		g_snprintf(title, sizeof(title), "<b>Rename This NoteFile \n %s </b>", name);
		debug_p("the foldername:%s\n",name);
		label_title = gtk_label_new (_(title));
	} else {
		label_title = gtk_label_new (_("<b>Nothing Can be Done....!!!</b>"));
	}
        gtk_widget_show (label_title);
        gtk_box_pack_start (GTK_BOX (vbox_top), label_title, FALSE, FALSE, 0);
        gtk_label_set_justify (GTK_LABEL (label_title), GTK_JUSTIFY_CENTER);
        gtk_label_set_use_markup (GTK_LABEL (label_title), TRUE);
        gtk_label_set_line_wrap (GTK_LABEL (label_title), TRUE);

        entry_text = gtk_entry_new ();
        gtk_widget_show (entry_text);
        gtk_box_pack_start (GTK_BOX (vbox_top), entry_text, FALSE, FALSE, 0);
        gtk_entry_set_invisible_char (GTK_ENTRY (entry_text), 9679);

        hbox_bottom = gtk_hbox_new (TRUE, 0);
        gtk_widget_show (hbox_bottom);
        gtk_box_pack_start (GTK_BOX (vbox_top), hbox_bottom, FALSE, FALSE, 0);

        button_help = gtk_button_new ();
        gtk_widget_show (button_help);
        gtk_box_pack_start (GTK_BOX (hbox_bottom), button_help, FALSE, FALSE, 0);

        alignment2 = gtk_alignment_new (0.5, 0.5, 0, 0);
        gtk_widget_show (alignment2);
        gtk_container_add (GTK_CONTAINER (button_help), alignment2);

        hbox3 = gtk_hbox_new (FALSE, 2);
        gtk_widget_show (hbox3);
        gtk_container_add (GTK_CONTAINER (alignment2), hbox3);

        image_help = gtk_image_new_from_stock ("gtk-help", GTK_ICON_SIZE_BUTTON);
        gtk_widget_show (image_help);
        gtk_box_pack_start (GTK_BOX (hbox3), image_help, FALSE, FALSE, 0);

        label_help = gtk_label_new_with_mnemonic (_("Help"));
        gtk_widget_show (label_help);
        gtk_box_pack_start (GTK_BOX (hbox3), label_help, FALSE, FALSE, 0);

        button_cancel = gtk_button_new ();
        gtk_widget_show (button_cancel);
        gtk_box_pack_start (GTK_BOX (hbox_bottom), button_cancel, FALSE, FALSE, 0);

        alignment1 = gtk_alignment_new (0.5, 0.5, 0, 0);
        gtk_widget_show (alignment1);
        gtk_container_add (GTK_CONTAINER (button_cancel), alignment1);

        hbox2 = gtk_hbox_new (FALSE, 2);
        gtk_widget_show (hbox2);
        gtk_container_add (GTK_CONTAINER (alignment1), hbox2);

        image_cancel = gtk_image_new_from_stock ("gtk-cancel", GTK_ICON_SIZE_BUTTON);
        gtk_widget_show (image_cancel);
        gtk_box_pack_start (GTK_BOX (hbox2), image_cancel, FALSE, FALSE, 0);

        label_cancel = gtk_label_new_with_mnemonic (_("Cancel"));
        gtk_widget_show (label_cancel);
        gtk_box_pack_start (GTK_BOX (hbox2), label_cancel, FALSE, FALSE, 0);

        button_ok = gtk_button_new ();
        gtk_widget_show (button_ok);
        gtk_box_pack_start (GTK_BOX (hbox_bottom), button_ok, FALSE, FALSE, 0);

        alignment3 = gtk_alignment_new (0.5, 0.5, 0, 0);
        gtk_widget_show (alignment3);
        gtk_container_add (GTK_CONTAINER (button_ok), alignment3);

        hbox4 = gtk_hbox_new (FALSE, 2);
        gtk_widget_show (hbox4);
        gtk_container_add (GTK_CONTAINER (alignment3), hbox4);

        image_apply = gtk_image_new_from_stock ("gtk-apply", GTK_ICON_SIZE_BUTTON);
        gtk_widget_show (image_apply);
        gtk_box_pack_start (GTK_BOX (hbox4), image_apply, FALSE, FALSE, 0);

        label_apply = gtk_label_new_with_mnemonic (_("Apply"));
        gtk_widget_show (label_apply);
        gtk_box_pack_start (GTK_BOX (hbox4), label_apply, FALSE, FALSE, 0);
        
        
        g_signal_connect ((gpointer) window, "destroy",
                          G_CALLBACK (on_window_add_folder_destroy),
                          (gpointer)clist);
        g_signal_connect ((gpointer) button_cancel, "clicked",
                          G_CALLBACK (on_button_add_folder_cancel_clicked),
                          (gpointer)clist);
        g_signal_connect ((gpointer) button_ok, "clicked",
                          G_CALLBACK (on_button_add_folder_ok_clicked),
                          (gpointer)clist);
        g_signal_connect ((gpointer) button_help, "clicked",
                          G_CALLBACK (on_button_add_folder_help_clicked),
                          NULL);

        /* Store pointers to all widgets, for use by lookup_widget(). */
        GLADE_HOOKUP_OBJECT_NO_REF (window, window, "window");
        GLADE_HOOKUP_OBJECT (window, vbox_top, "vbox_top");
        GLADE_HOOKUP_OBJECT (window, label_title, "label_title");
        GLADE_HOOKUP_OBJECT (window, entry_text, "entry_text");
        GLADE_HOOKUP_OBJECT (window, hbox_bottom, "hbox_bottom");
        GLADE_HOOKUP_OBJECT (window, button_help, "button_help");
        GLADE_HOOKUP_OBJECT (window, alignment2, "alignment2");
        GLADE_HOOKUP_OBJECT (window, hbox3, "hbox3");
        GLADE_HOOKUP_OBJECT (window, image_help, "image_help");
        GLADE_HOOKUP_OBJECT (window, label_help, "label_help");
        GLADE_HOOKUP_OBJECT (window, button_cancel, "button_cancel");
        GLADE_HOOKUP_OBJECT (window, alignment1, "alignment1");
        GLADE_HOOKUP_OBJECT (window, hbox2, "hbox2");
        GLADE_HOOKUP_OBJECT (window, image_cancel, "image_cancel");
        GLADE_HOOKUP_OBJECT (window, label_cancel, "label_cancel");
        GLADE_HOOKUP_OBJECT (window, button_ok, "button_ok");
        GLADE_HOOKUP_OBJECT (window, alignment3, "alignment3");
        GLADE_HOOKUP_OBJECT (window, hbox4, "hbox4");
        GLADE_HOOKUP_OBJECT (window, image_apply, "image_apply");
        GLADE_HOOKUP_OBJECT (window, label_apply, "label_apply");
        
        gtk_widget_grab_focus (entry_text);
        clist->other.window = window;
        clist->other.entry_name = entry_text;
        return window;                                                                                                        
}

void
on_button_add_folder_ok_clicked (GtkButton *button, gpointer user_data)
{
	struct clist_struct *cclist=(struct clist_struct *)user_data;
	if((cclist->creat == NOTHING) && (cclist->xname == NOTHING)){
		gchar msg[] = "You Select Nothing";
		message_box_for_add_folder(cclist->other.window,msg);		
		return;	
	} else if(cclist->creat != NOTHING){
		add_folder_or_note(cclist);
	}else if(cclist->xname != NOTHING){
		rename_folder_or_note(cclist);
	}
	return;	
}
void
on_button_add_folder_cancel_clicked (GtkButton *button, gpointer user_data)
{
	struct clist_struct *cclist=(struct clist_struct *)user_data;
	gtk_widget_destroy(GTK_WIDGET(cclist->other.window));
	cclist->other.window = NULL;
	cclist->other.entry_name = NULL;
	
	return;	
	
}

void
on_window_add_folder_destroy (GtkObject *object, gpointer user_data)
{
	struct clist_struct *cclist=(struct clist_struct *)user_data;
	cclist->other.window = NULL;
	cclist->other.entry_name = NULL;
	
	gtk_widget_destroy(GTK_WIDGET(object));
	return;	
}

void
on_button_add_folder_help_clicked (GtkButton *button, gpointer user_data)
{
	gchar msg[]="Please Input The Name:\n You can input input the\
	name of the folder of note that you want to creat.";
	message_box_for_add_folder(user_data,msg);
	
	return;	
}
