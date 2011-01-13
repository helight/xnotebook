/*
 * AboutCall.c
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <string.h>
#include <stdlib.h>

#include <gtk/gtk.h>

#include "Support.h"
#include "Mainbody.h"
#include "AddRss.h"
#include "Rss.h"

void
on_button_add_rss_ok_clicked (GtkButton *button, gpointer user_data)
{
	gchar *fp = NULL;
	gchar *rss_url = NULL;
	gchar rss_file[256];
	gint len = 0;
	int fd = 0;
	
	struct clist_struct *clist = (struct clist_struct *)user_data;
	rss_url = gtk_entry_get_text(GTK_ENTRY(clist->other.entry_url));
/*	
	fp = gtk_entry_get_text(GTK_ENTRY(clist->other.entry_name));
	len = strlen(fp);
	*(fp + len) = '\0';
	snprintf(rss_file, sizeof(rss_file), "%s/%s", clist->rss_path, fp);
*/
	len = strlen(rss_url);
	*(rss_url + len) = '\0';
	printf("url :%s \n", rss_url);
	
	if ((fd = fork()) < 0) {
		perror("fork:");
		goto out;
	} else if (fd > 0) {
		printf("father:\n");
		goto out;
	} else {
		printf("get rss:\n");
		get_rss(rss_url, clist->rss_path);
		
		exit(0);
	}
out:
	wait(NULL);
	gtk_clist_clear(GTK_CLIST(clist->clist_rss));
		show_rss(clist);
	gtk_widget_destroy(GTK_WIDGET(clist->other.window));	
	return;	
}
void
on_button_add_rss_cancel_clicked (GtkButton *button, gpointer user_data)
{

	gtk_widget_destroy(GTK_WIDGET(user_data));
	return;	
	
}

void
on_window_add_rss_destroy (GtkObject *object, gpointer user_data)
{
	GtkWidget *rss_add_window = (GtkWidget *)user_data;
	gtk_widget_destroy(GTK_WIDGET(rss_add_window));
	
	return;	
}
