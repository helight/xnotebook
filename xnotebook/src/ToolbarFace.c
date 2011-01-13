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
/*-----------------button_nf-----------------------*/
        GtkWidget *toolitem1; 
        GtkWidget *button_nf;
        GtkWidget *alignment6;
        GtkWidget *hbox7;
        GtkWidget *image_nf;
        GtkWidget *label_nf;
/*-----------------button_nn-----------------------*/
        GtkWidget *toolitem2;
        GtkWidget *button_nn;
        GtkWidget *alignment7;
        GtkWidget *hbox8;
        GtkWidget *image_nn;
        GtkWidget *label_nn;
/*-----------------button_edit-----------------------*/
        GtkWidget *toolitem3;
        GtkWidget *button_edit;
        GtkWidget *alignment8;
        GtkWidget *hbox9;
        GtkWidget *image_edit;
        GtkWidget *label_edit;
/*-----------------button_save-----------------------*/
        GtkWidget *toolitem4;
        GtkWidget *button_save;
        GtkWidget *alignment9;
        GtkWidget *hbox10;
        GtkWidget *image_save;
        GtkWidget *label_save;
/*-----------------button_df-----------------------*/
        GtkWidget *toolitem5;
        GtkWidget *button_df;
        GtkWidget *alignment10;
        GtkWidget *hbox11;
        GtkWidget *image_df;
        GtkWidget *label1_df;
/*-----------------button_dn-----------------------*/
        GtkWidget *toolitem6;
        GtkWidget *button_dn;
        GtkWidget *alignment11;
        GtkWidget *hbox12;
        GtkWidget *image_dn;
        GtkWidget *label_dn;
/*-----------------button_bk-----------------------*/
        GtkWidget *toolitem7;
        GtkWidget *button_bk;
        GtkWidget *alignment12;
        GtkWidget *hbox13;
        GtkWidget *image_bk;
        GtkWidget *label_bk;
/*-----------------button_quit-----------------------*/
        GtkWidget *toolitem8;
        GtkWidget *button_quit;
        GtkWidget *alignment13;
        GtkWidget *hbox14;
        GtkWidget *image_quit;
        GtkWidget *label_quit;

        toolbar = gtk_toolbar_new ();
        gtk_widget_show (toolbar);
        gtk_box_pack_start (GTK_BOX (vbox), toolbar, FALSE, FALSE, 0);
        gtk_toolbar_set_style (GTK_TOOLBAR (toolbar), GTK_TOOLBAR_TEXT);
        tmp_toolbar_icon_size = gtk_toolbar_get_icon_size (GTK_TOOLBAR (toolbar));

        toolitem1 = (GtkWidget*) gtk_tool_item_new ();
        gtk_widget_show (toolitem1);
        gtk_container_add (GTK_CONTAINER (toolbar), toolitem1);

        button_nf = gtk_button_new ();
        gtk_widget_show (button_nf);
        gtk_container_add (GTK_CONTAINER (toolitem1), button_nf);
	gtk_button_set_relief (GTK_BUTTON (button_nf), GTK_RELIEF_NONE);
	
        alignment6 = gtk_alignment_new (0.5, 0.5, 0, 0);
        gtk_widget_show (alignment6);
        gtk_container_add (GTK_CONTAINER (button_nf), alignment6);

        hbox7 = gtk_hbox_new (FALSE, 2);
        gtk_widget_show (hbox7);
        gtk_container_add (GTK_CONTAINER (alignment6), hbox7);

        image_nf = gtk_image_new_from_stock ("gtk-new", GTK_ICON_SIZE_BUTTON);
        gtk_widget_show (image_nf);
        gtk_box_pack_start (GTK_BOX (hbox7), image_nf, FALSE, FALSE, 0);

        label_nf = gtk_label_new_with_mnemonic (_("Folder"));
        gtk_widget_show (label_nf);
        gtk_box_pack_start (GTK_BOX (hbox7), label_nf, FALSE, FALSE, 0);

        toolitem2 = (GtkWidget*) gtk_tool_item_new ();
        gtk_widget_show (toolitem2);
        gtk_container_add (GTK_CONTAINER (toolbar), toolitem2);

        button_nn = gtk_button_new ();
        gtk_widget_show (button_nn);
        gtk_container_add (GTK_CONTAINER (toolitem2), button_nn);
	gtk_button_set_relief (GTK_BUTTON (button_nn), GTK_RELIEF_NONE);

        alignment7 = gtk_alignment_new (0.5, 0.5, 0, 0);
        gtk_widget_show (alignment7);
        gtk_container_add (GTK_CONTAINER (button_nn), alignment7);

        hbox8 = gtk_hbox_new (FALSE, 2);
        gtk_widget_show (hbox8);
        gtk_container_add (GTK_CONTAINER (alignment7), hbox8);

        image_nn = gtk_image_new_from_stock ("gtk-new", GTK_ICON_SIZE_BUTTON);
        gtk_widget_show (image_nn);
        gtk_box_pack_start (GTK_BOX (hbox8), image_nn, FALSE, FALSE, 0);

        label_nn = gtk_label_new_with_mnemonic (_("Note"));
        gtk_widget_show (label_nn);
        gtk_box_pack_start (GTK_BOX (hbox8), label_nn, FALSE, FALSE, 0);

        toolitem3 = (GtkWidget*) gtk_tool_item_new ();
        gtk_widget_show (toolitem3);
        gtk_container_add (GTK_CONTAINER (toolbar), toolitem3);

        button_edit = gtk_button_new ();
        gtk_widget_show (button_edit);
        gtk_container_add (GTK_CONTAINER (toolitem3), button_edit);
	gtk_button_set_relief (GTK_BUTTON (button_edit), GTK_RELIEF_NONE);

        alignment8 = gtk_alignment_new (0.5, 0.5, 0, 0);
        gtk_widget_show (alignment8);
        gtk_container_add (GTK_CONTAINER (button_edit), alignment8);

        hbox9 = gtk_hbox_new (FALSE, 2);
        gtk_widget_show (hbox9);
        gtk_container_add (GTK_CONTAINER (alignment8), hbox9);

        image_edit = gtk_image_new_from_stock ("gtk-edit", GTK_ICON_SIZE_BUTTON);
        gtk_widget_show (image_edit);
        gtk_box_pack_start (GTK_BOX (hbox9), image_edit, FALSE, FALSE, 0);

        label_edit = gtk_label_new_with_mnemonic (_("Edit"));
        gtk_widget_show (label_edit);
        gtk_box_pack_start (GTK_BOX (hbox9), label_edit, FALSE, FALSE, 0);

        toolitem4 = (GtkWidget*) gtk_tool_item_new ();
        gtk_widget_show (toolitem4);
        gtk_container_add (GTK_CONTAINER (toolbar), toolitem4);

        button_save = gtk_button_new ();
        gtk_widget_show (button_save);
        gtk_container_add (GTK_CONTAINER (toolitem4), button_save);
	gtk_button_set_relief (GTK_BUTTON (button_save), GTK_RELIEF_NONE);

        alignment9 = gtk_alignment_new (0.5, 0.5, 0, 0);
        gtk_widget_show (alignment9);
        gtk_container_add (GTK_CONTAINER (button_save), alignment9);

        hbox10 = gtk_hbox_new (FALSE, 2);
        gtk_widget_show (hbox10);
        gtk_container_add (GTK_CONTAINER (alignment9), hbox10);

        image_save = gtk_image_new_from_stock ("gtk-save", GTK_ICON_SIZE_BUTTON);
        gtk_widget_show (image_save);
        gtk_box_pack_start (GTK_BOX (hbox10), image_save, FALSE, FALSE, 0);

        label_save = gtk_label_new_with_mnemonic (_("Save"));
        gtk_widget_show (label_save);
        gtk_box_pack_start (GTK_BOX (hbox10), label_save, FALSE, FALSE, 0);
/*-----------------------------------------------------------*/
        toolitem5 = (GtkWidget*) gtk_tool_item_new ();
        gtk_widget_show (toolitem5);
        gtk_container_add (GTK_CONTAINER (toolbar), toolitem5);

        button_df = gtk_button_new ();
        gtk_widget_show (button_df);
        gtk_container_add (GTK_CONTAINER (toolitem5), button_df);
	gtk_button_set_relief (GTK_BUTTON (button_df), GTK_RELIEF_NONE);

        alignment10 = gtk_alignment_new (0.5, 0.5, 0, 0);
        gtk_widget_show (alignment10);
        gtk_container_add (GTK_CONTAINER (button_df), alignment10);

        hbox11 = gtk_hbox_new (FALSE, 2);
        gtk_widget_show (hbox11);
        gtk_container_add (GTK_CONTAINER (alignment10), hbox11);

        image_df = gtk_image_new_from_stock ("gtk-delete", GTK_ICON_SIZE_BUTTON);
        gtk_widget_show (image_df);
        gtk_box_pack_start (GTK_BOX (hbox11), image_df, FALSE, FALSE, 0);

        label1_df = gtk_label_new_with_mnemonic (_("Folder"));
        gtk_widget_show (label1_df);
        gtk_box_pack_start (GTK_BOX (hbox11), label1_df, FALSE, FALSE, 0);

        toolitem6 = (GtkWidget*) gtk_tool_item_new ();
        gtk_widget_show (toolitem6);
        gtk_container_add (GTK_CONTAINER (toolbar), toolitem6);

        button_dn = gtk_button_new ();
        gtk_widget_show (button_dn);
        gtk_container_add (GTK_CONTAINER (toolitem6), button_dn);
	gtk_button_set_relief (GTK_BUTTON (button_dn), GTK_RELIEF_NONE);

        alignment11 = gtk_alignment_new (0.5, 0.5, 0, 0);
        gtk_widget_show (alignment11);
        gtk_container_add (GTK_CONTAINER (button_dn), alignment11);

        hbox12 = gtk_hbox_new (FALSE, 2);
        gtk_widget_show (hbox12);
        gtk_container_add (GTK_CONTAINER (alignment11), hbox12);

        image_dn = gtk_image_new_from_stock ("gtk-delete", GTK_ICON_SIZE_BUTTON);
        gtk_widget_show (image_dn);
        gtk_box_pack_start (GTK_BOX (hbox12), image_dn, FALSE, FALSE, 0);

        label_dn = gtk_label_new_with_mnemonic (_("Note"));
        gtk_widget_show (label_dn);
        gtk_box_pack_start (GTK_BOX (hbox12), label_dn, FALSE, FALSE, 0);
/***********************************backup**************************************/
        toolitem7 = (GtkWidget*) gtk_tool_item_new ();
        gtk_widget_show (toolitem7);
        gtk_container_add (GTK_CONTAINER (toolbar), toolitem7);

        button_bk = gtk_button_new ();
        gtk_widget_show (button_bk);
        gtk_container_add (GTK_CONTAINER (toolitem7), button_bk);
	gtk_button_set_relief (GTK_BUTTON (button_bk), GTK_RELIEF_NONE);

        alignment12 = gtk_alignment_new (0.5, 0.5, 0, 0);
        gtk_widget_show (alignment12);
        gtk_container_add (GTK_CONTAINER (button_bk), alignment12);

        hbox13 = gtk_hbox_new (FALSE, 2);
        gtk_widget_show (hbox13);
        gtk_container_add (GTK_CONTAINER (alignment12), hbox13);

        image_bk = gtk_image_new_from_stock ("gtk-harddisk", GTK_ICON_SIZE_BUTTON);
        gtk_widget_show (image_bk);
        gtk_box_pack_start (GTK_BOX (hbox13), image_bk, FALSE, FALSE, 0);

        label_bk = gtk_label_new_with_mnemonic (_("Backup"));
        gtk_widget_show (label_bk);
        gtk_box_pack_start (GTK_BOX (hbox13), label_bk, FALSE, FALSE, 0);
/***********************************quit************************************/
        
        toolitem8 = (GtkWidget*) gtk_tool_item_new ();
        gtk_widget_show (toolitem8);
        gtk_container_add (GTK_CONTAINER (toolbar), toolitem8);

        button_quit = gtk_button_new ();
        gtk_widget_show (button_quit);
        gtk_container_add (GTK_CONTAINER (toolitem8), button_quit);
	gtk_button_set_relief (GTK_BUTTON (button_quit), GTK_RELIEF_NONE);

        alignment13 = gtk_alignment_new (0.5, 0.5, 0, 0);
        gtk_widget_show (alignment13);
        gtk_container_add (GTK_CONTAINER (button_quit), alignment13);

        hbox14 = gtk_hbox_new (FALSE, 2);
        gtk_widget_show (hbox14);
        gtk_container_add (GTK_CONTAINER (alignment13), hbox14);

        image_quit = gtk_image_new_from_stock ("gtk-quit", GTK_ICON_SIZE_BUTTON);
        gtk_widget_show (image_quit);
        gtk_box_pack_start (GTK_BOX (hbox14), image_quit, FALSE, FALSE, 0);

        label_quit = gtk_label_new_with_mnemonic (_("Quit"));
        gtk_widget_show (label_quit);
        gtk_box_pack_start (GTK_BOX (hbox14), label_quit, FALSE, FALSE, 0);
	
	g_signal_connect ((gpointer) button_nf, "clicked",
	                  G_CALLBACK (on_button_nf_clicked),
	                  (gpointer *)clist); 
	g_signal_connect ((gpointer) button_nn, "clicked",
	                  G_CALLBACK (on_button_nn_clicked),
	                  (gpointer *)clist);
	g_signal_connect ((gpointer) button_edit, "clicked",
	                  G_CALLBACK (on_button_edit_clicked),
	                  (gpointer *)clist);
	g_signal_connect ((gpointer) button_save, "clicked",
	                  G_CALLBACK (on_button_save_clicked),
	                  (gpointer *)clist);
	g_signal_connect ((gpointer) button_df, "clicked",
	                  G_CALLBACK (on_button_df_clicked),
	                  (gpointer *)clist);
	g_signal_connect ((gpointer) button_dn, "clicked",
	                  G_CALLBACK (on_button_dn_clicked),
	                  (gpointer *)clist);
	g_signal_connect ((gpointer) button_bk, "clicked",
	                  G_CALLBACK (on_button_bk_clicked),
	                  (gpointer *)clist);
	g_signal_connect ((gpointer) button_quit, "clicked",
	                  G_CALLBACK (on_button_quit_clicked),
	                  (gpointer *)main_windown);	
	                  
	return toolbar;
}
