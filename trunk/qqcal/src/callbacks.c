#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "main_window.h"
#include "calendar.h"
#include "event.h"
#include "setup.h"
#include "func.h"
#include "support.h"

struct eventtips{
	char tips[512];
	struct eventtips *next;
};

static struct eventtips *tipshead = NULL;

void show_message(GtkWidget *window,gchar *message)
{
	GtkWidget *dialog;
	dialog = gtk_message_dialog_new(GTK_WINDOW(window), 0,
				GTK_MESSAGE_INFO, GTK_BUTTONS_OK, message);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}

gboolean update_clock(gpointer data)
{
	time_t now;
	struct tm *timenow;
	char strtmp[64];
	char *markup, *event;
	struct xevent *tevent = NULL;
	static int countevent = 0;
	int i = 0;
	
	struct top_show_event *ts_event = (struct top_show_event *)data;	
	
	time(&now);
	timenow = localtime(&now);
	sprintf(strtmp, "%s", asctime(timenow)); 
	//printf("recent time is : %s ", asctime(timenow)); 
	strtmp[strlen(strtmp) - 9]= '\0'; 
	markup = g_markup_printf_escaped ("<span foreground='#14A1F5' >%s </span>", strtmp + 11);
	gtk_label_set_markup (GTK_LABEL (ts_event->xtime), markup);
	g_free (markup);
	tevent = ts_event->hevent;

	for(i = 0; i < countevent; i++){
		if (!tevent->next)
			break;
		tevent = tevent->next;
	}
	//printf("xx-tevent->event:%s len:%d\n",tevent->event, strlen(tevent->event));
	if (strlen(tevent->event) > 22){
		snprintf(strtmp, 22, " %s", tevent->event); 
		strcat(strtmp, "...");
	}else
		sprintf(strtmp, " %s", tevent->event); 
	printf("xx-strtemp:%s len:%d\n",strtmp, strlen(tevent->event));
	countevent += 1;
	if (countevent > ts_event->hevent->time)
		countevent = 0;
	
	markup = g_markup_printf_escaped ("%s", strtmp);
	gtk_label_set_markup (GTK_LABEL (ts_event->xtitle), markup);
	g_free (markup);
	return TRUE;
}

gboolean xcalendar_event(GtkWidget *widget, struct add_event_obj *obj)
{
	int len= 0, i = 0;
	struct tm tm;
//	char xdate[16];
	GList* clilds;
	GtkWidget *xcal_check;

	gtk_calendar_get_date(GTK_CALENDAR(obj->xcalendar), &tm.tm_year, &tm.tm_mon, &tm.tm_mday);/*取得选择的年月日*/
	tm.tm_year -= 1900;
	strftime(obj->xdate, 16,"%Y%m%d", &tm);
	g_print("date:%s\n", obj->xdate);

	get_event_date(obj->event_box, obj->xdate);
	return FALSE;
}

gboolean
on_main_delete_event(GtkWidget * widget, GdkEvent * event, gpointer user_data)
{
	struct xevent *tevent = NULL, *p = NULL;;
	struct top_show_event *ts_event = (struct top_show_event *)user_data;
	
	tevent = ts_event->hevent;
	//p = tevent;
	/*while(p->next){
			tevent = p->next;
	//		free(p);
			p = tevent;
	};*/
	//free(p);
	//ts_event->hevent->next = NULL;
	printf("bey world;\n");

	
	gtk_main_quit();

	return FALSE;
}
gint mouse_event_handle(GtkWidget *widget, GdkEventButton *event, gpointer data)
{
	GtkWidget *oldImage;
	GtkWidget *newImage;
	
	char png[2];
	snprintf(png, 2, "%s", data);
	printf("png:%s\n", png);
	
	switch(event->type){
	case GDK_BUTTON_PRESS:
		printf("click button\n");
		//gtk_main_quit();
		break;
	case GDK_ENTER_NOTIFY:
		printf("enter button\n");
		oldImage = GTK_WIDGET(gtk_container_children(GTK_CONTAINER(widget))->data);
		gtk_object_ref(GTK_OBJECT(oldImage));
		gtk_container_remove(GTK_CONTAINER(widget), oldImage);
		switch(png[0]){
		case 'c':
			newImage = create_pixmap("xcal.png");
			break;
		case 'e':
			newImage = create_pixmap("event.png");
			break;
		case 'n':
			newImage = create_pixmap("new.png");
			break;
		case 's':
			newImage = create_pixmap("setup.png");
			break;
		case 'x':
			newImage = create_pixmap("exit.png");
			break;
		}		
		gtk_container_add(GTK_CONTAINER(widget), newImage);
		gtk_widget_show(newImage);
		break;
	case GDK_LEAVE_NOTIFY:
		printf("enter button\n");
		oldImage = GTK_WIDGET(gtk_container_children(GTK_CONTAINER(widget))->data);
		gtk_object_ref(GTK_OBJECT(oldImage));
		gtk_container_remove(GTK_CONTAINER(widget), oldImage);
		switch(png[0]){
		case 'c':
			newImage = create_pixmap("xcal1.png");
			break;
		case 'e':
			newImage = create_pixmap("event1.png");
			break;
		case 'n':
			newImage = create_pixmap("new1.png");
			break;
		case 's':
			newImage = create_pixmap("setup1.png");
			break;
		case 'x':
			newImage = create_pixmap("exit1.png");
			break;
		}	
		gtk_container_add(GTK_CONTAINER(widget), newImage);
		gtk_widget_show(newImage);
		printf("out button\n");
		break;
	}
	return FALSE;
}

void add_event_ok_clicked (GtkButton *button, gpointer user_data)
{
	time_t timep;
	struct tm *tmp;
	char xdate[16];
	GtkWidget *xcal_check;
	GtkTooltips *tooltip;
	const gchar *title = NULL;
	gchar *comment = NULL;
	GtkTextIter start,end;
	struct xevent *tevent = NULL, *p = NULL;
	gchar *msg = "words not long \nenough or too \nmany words \n"; 
	struct add_event_obj *obj = (struct add_event_obj *)user_data;
	
	title = gtk_entry_get_text(GTK_ENTRY(obj->event_title));
	printf("title: %s\n", title);
	if(strlen(title) < 3 || strlen(title) > 500) {
		show_message(obj->main_window, msg);
		goto out;
	}
	gtk_text_buffer_get_bounds (GTK_TEXT_BUFFER(obj->event_comment), 
							&start, &end);
	comment = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(obj->event_comment), 
							&start,&end,FALSE);
	if (strlen(comment) > 500){
		show_message(obj->main_window, msg);
		goto out;
	}

	time(&timep);
	printf("time:%d \n", timep);
	tmp = localtime(&timep);
	strftime(xdate, 16,"%Y%m%d", tmp);
	printf("date: %s\n", xdate);
	
	if(open_db("xcal.db"))
		printf("Open database failed.\n");
	else {
		char vsql[1024];
		sprintf(vsql, "insert into xcal (fin, event, moreinfo, rtime, xdate, xtime) values(1, '%s', '%s', %d, '%s', %d);", title, comment, timep, obj->xdate, timep);
		//char *sql = "insert into xcal (fin, event, moreinfo, rtime, xdate, xtime) values(1, 'xcalendar v0.01', 'v0.01', '12:50', '20100817', '12:30');";
		//char *sql = "delete from xcal where fin = 1;";
		printf("vsql:%s\n", vsql);
		if(exec_sql(vsql)){
			printf("Insert records failed.\n");
			goto dbout;
		}
		tevent = obj->hevent;
		tevent->time += 1;
		snprintf(tevent->event, 24, "Today %d tasks to do!", tevent->time);
		
		p = malloc(sizeof(struct xevent));
		snprintf(p->event, 24, "%s", title);
		p->next = NULL;
		while(tevent->next)
			tevent = tevent->next;
		tevent->next = p;
/*		char *gsql = "select fin, event from xcal;";
		sqlite3_stmt *stmt = get_records(gsql);
		if (stmt){
			int nret, fin;
			char *event;
			while(1) {
				nret = sqlite3_step(stmt);
				if(nret != SQLITE_ROW)
					break;
				fin = sqlite3_column_int(stmt,0);
				event = (char *)sqlite3_column_text(stmt,1);
				printf("\txxx%d\t\t%s\n", fin, event);
			}	
			sqlite3_finalize(stmt);
		}
*/
		if (obj->event_box)
			get_event_date(obj->event_box, obj->xdate);
dbout:	if(close_db())
			printf("Close database failed.\n");
	}

out:
	gtk_widget_destroy(GTK_WIDGET(obj->add_window));
	obj->add_window = NULL;
	obj->event_title = NULL;
	obj->event_box = NULL;
	obj->event_comment = NULL;
	return;	
}

GtkWidget* create_new_add_window (struct add_event_obj *obj)
{
	GtkWidget *add_window; 
	GtkWidget *dialog_vbox; 
	GtkWidget *vbox_top;
	GtkWidget *label_title;
	GtkWidget *event_title;
	GtkWidget *note_scrool;
	GtkWidget *note_text;
	GtkTextBuffer *event_comment;
	GtkWidget *hbox_bottom;
	GtkWidget *button_ok;
	GtkWidget *image_apply;

	add_window = gtk_dialog_new_with_buttons("Xcalendar", 
		GTK_WINDOW(obj->main_window), GTK_DIALOG_DESTROY_WITH_PARENT,NULL);
	gtk_window_set_position (GTK_WINDOW (add_window), GTK_WIN_POS_MOUSE);
	gtk_widget_set_size_request (add_window, 250, -1);
	gtk_window_set_resizable (GTK_WINDOW (add_window), FALSE);
	gtk_window_set_destroy_with_parent (GTK_WINDOW (add_window), TRUE);
	gtk_window_set_icon_name (GTK_WINDOW (add_window), "gtk-add");
	gtk_window_set_modal (GTK_WINDOW (add_window), TRUE);
	
	dialog_vbox = GTK_DIALOG (add_window)->vbox;
	gtk_widget_show (dialog_vbox);
  
	vbox_top = gtk_vbox_new (FALSE, 0);
	gtk_widget_show (vbox_top);
	gtk_container_add (GTK_CONTAINER (dialog_vbox), vbox_top);
	
	label_title = gtk_label_new (_("<b>No more 50 or less 3</b>"));
	gtk_widget_show (label_title);
	gtk_box_pack_start (GTK_BOX (vbox_top), label_title, FALSE, FALSE, 0);
	  gtk_misc_set_alignment (GTK_MISC (label_title), 0.02, 0.5);
	gtk_label_set_use_markup (GTK_LABEL (label_title), TRUE);
	gtk_label_set_line_wrap (GTK_LABEL (label_title), TRUE);

	event_title = gtk_entry_new ();
	gtk_widget_show (event_title);
	gtk_box_pack_start (GTK_BOX (vbox_top), event_title, FALSE, FALSE, 0);
	gtk_entry_set_invisible_char (GTK_ENTRY (event_title), 1024);
	gtk_entry_set_text(GTK_ENTRY (event_title), "Input the Subject");

	label_title = gtk_label_new (_("<b>No more 500</b>"));
	gtk_widget_show (label_title);
	gtk_box_pack_start (GTK_BOX (vbox_top), label_title, FALSE, FALSE, 0);
	  gtk_misc_set_alignment (GTK_MISC (label_title), 0.02, 0.5);
	gtk_label_set_use_markup (GTK_LABEL (label_title), TRUE);
	gtk_label_set_line_wrap (GTK_LABEL (label_title), TRUE);
	
	note_scrool = gtk_scrolled_window_new (NULL, NULL);
	gtk_widget_show (note_scrool);
	gtk_box_pack_start (GTK_BOX (vbox_top), note_scrool, FALSE, FALSE, 0);
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (note_scrool), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
	gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (note_scrool), GTK_SHADOW_IN);
  
	note_text = gtk_text_view_new ();
	gtk_widget_show (note_text);
	gtk_container_add (GTK_CONTAINER (note_scrool), note_text);
	event_comment = gtk_text_view_get_buffer(GTK_TEXT_VIEW (note_text));
	gtk_widget_set_size_request (note_text, -1, 100);
	gtk_text_view_set_editable (GTK_TEXT_VIEW (note_text), TRUE);
	gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (note_text), GTK_WRAP_WORD);
	gtk_text_buffer_set_text (GTK_TEXT_BUFFER(event_comment), _("Input comment!"), -1);
		
	hbox_bottom = gtk_hbox_new (TRUE, 0);
	gtk_widget_show (hbox_bottom);
	gtk_box_pack_start (GTK_BOX (vbox_top), hbox_bottom, FALSE, FALSE, 0);

	button_ok = gtk_button_new ();
	gtk_widget_show (button_ok);
	gtk_box_pack_start (GTK_BOX (hbox_bottom), button_ok, FALSE, FALSE, 0);
	gtk_button_set_relief (GTK_BUTTON (button_ok), GTK_RELIEF_NONE);

	image_apply = create_pixmap("accept.png");
	gtk_widget_show (image_apply);
	gtk_container_add (GTK_CONTAINER (button_ok), image_apply);
	
	g_signal_connect ((gpointer) button_ok, "clicked",
			  G_CALLBACK (add_event_ok_clicked),
			  (gpointer)obj);
	gtk_widget_grab_focus (event_title);
	
	obj->add_window = add_window;
	obj->event_title = event_title;
	obj->event_comment = event_comment;

	return add_window; 
}

gboolean add_event(GtkButton * button, struct add_event_obj *obj)
{
	GtkWidget *window;

	window=(GtkWidget *)create_new_add_window (obj);
	gtk_window_set_transient_for (GTK_WINDOW (window), GTK_WINDOW (obj->main_window));
	gtk_widget_show(window);
	
	return FALSE;
}

gboolean add_event_today(GtkButton * button, struct add_event_obj *obj)
{
	GtkWidget *window;
	
	obj->event_box = obj->event_box1;
	get_date_today(obj->xdate);
	window=(GtkWidget *)create_new_add_window (obj);
	gtk_window_set_transient_for (GTK_WINDOW (window), GTK_WINDOW (obj->main_window));
	gtk_widget_show(window);
	
	return FALSE;
}

gboolean add_event_tomorrow(GtkButton * button, struct add_event_obj *obj)
{
	GtkWidget *window;
	
	obj->event_box = obj->event_box2;
	get_date_tom (obj->xdate);
	g_print("date:%s\n", obj->xdate);
	
	window=(GtkWidget *)create_new_add_window (obj);
	gtk_window_set_transient_for (GTK_WINDOW (window), GTK_WINDOW (obj->main_window));
	gtk_widget_show(window);
	
	return FALSE;
}

GtkWidget* create_show_evnet_window (int id)
{
	GtkWidget *add_window; 
	GtkWidget *dialog_vbox; 
	GtkWidget *vbox_top;
	GtkWidget *label_title;
	GtkWidget *event_title;
	GtkWidget *note_scrool;
	GtkWidget *note_text;
	GtkTextBuffer *event_comment;

	add_window = gtk_dialog_new_with_buttons("Xcalendar", 
		NULL, GTK_DIALOG_DESTROY_WITH_PARENT,NULL);
	gtk_window_set_position (GTK_WINDOW (add_window), GTK_WIN_POS_MOUSE);
	gtk_widget_set_size_request (add_window, 250, -1);
	gtk_window_set_resizable (GTK_WINDOW (add_window), FALSE);
	gtk_window_set_destroy_with_parent (GTK_WINDOW (add_window), TRUE);
	gtk_window_set_icon_name (GTK_WINDOW (add_window), "gtk-add");
	gtk_window_set_modal (GTK_WINDOW (add_window), TRUE);
	
	dialog_vbox = GTK_DIALOG (add_window)->vbox;
	gtk_widget_show (dialog_vbox);
  
	vbox_top = gtk_vbox_new (FALSE, 0);
	gtk_widget_show (vbox_top);
	gtk_container_add (GTK_CONTAINER (dialog_vbox), vbox_top);
	


	if(open_db("xcal.db"))
		printf("Open database failed.\n");
	else {	
		char strtmp[1024]; 
		
		sprintf(strtmp,"%s'%d';", "select event, moreinfo from xcal where id=", id);
		sqlite3_stmt *stmt = get_records(strtmp);
		if (stmt){
			int nret;
			char *title_text, *comment_text;

			nret = sqlite3_step(stmt);
			if(nret != SQLITE_ROW){
				label_title = gtk_label_new (_("<b>Wrong Subject!</b>"));
				gtk_widget_show (label_title);
				gtk_box_pack_start (GTK_BOX (vbox_top), label_title, FALSE, FALSE, 0);
				gtk_misc_set_alignment (GTK_MISC (label_title), 0.02, 0.5);
				gtk_label_set_use_markup (GTK_LABEL (label_title), TRUE);
				gtk_label_set_line_wrap (GTK_LABEL (label_title), TRUE);
				return add_window; 
			}
			label_title = gtk_label_new (_("<b>Subject</b>"));
			gtk_widget_show (label_title);
			gtk_box_pack_start (GTK_BOX (vbox_top), label_title, FALSE, FALSE, 0);
			gtk_misc_set_alignment (GTK_MISC (label_title), 0.02, 0.5);
			gtk_label_set_use_markup (GTK_LABEL (label_title), TRUE);
			gtk_label_set_line_wrap (GTK_LABEL (label_title), TRUE);
	
			title_text = (char *)sqlite3_column_text(stmt, 0);
			comment_text = (char *)sqlite3_column_text(stmt, 1);
			printf("\t\t%s\t%s\n", title_text, event_comment);
			
			event_title = gtk_entry_new ();
			gtk_widget_show (event_title);
			gtk_box_pack_start (GTK_BOX (vbox_top), event_title, FALSE, FALSE, 0);
			gtk_entry_set_invisible_char (GTK_ENTRY (event_title), 1024);
			gtk_entry_set_text(GTK_ENTRY (event_title), title_text);

			label_title = gtk_label_new (_("<b>Comment</b>"));
			gtk_widget_show (label_title);
			gtk_box_pack_start (GTK_BOX (vbox_top), label_title, FALSE, FALSE, 0);
			  gtk_misc_set_alignment (GTK_MISC (label_title), 0.02, 0.5);
			gtk_label_set_use_markup (GTK_LABEL (label_title), TRUE);
			gtk_label_set_line_wrap (GTK_LABEL (label_title), TRUE);

			note_scrool = gtk_scrolled_window_new (NULL, NULL);
			gtk_widget_show (note_scrool);
			gtk_box_pack_start (GTK_BOX (vbox_top), note_scrool, FALSE, FALSE, 0);
			gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (note_scrool), GTK_POLICY_NEVER, GTK_POLICY_AUTOMATIC);
			gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (note_scrool), GTK_SHADOW_IN);

			note_text = gtk_text_view_new ();
			gtk_widget_show (note_text);
			gtk_container_add (GTK_CONTAINER (note_scrool), note_text);
			event_comment = gtk_text_view_get_buffer(GTK_TEXT_VIEW (note_text));
			gtk_widget_set_size_request (note_text, -1, 100);
			gtk_text_view_set_editable (GTK_TEXT_VIEW (note_text), TRUE);
			gtk_text_view_set_wrap_mode (GTK_TEXT_VIEW (note_text), GTK_WRAP_WORD);
			gtk_text_buffer_set_text (GTK_TEXT_BUFFER(event_comment), _(comment_text), -1);

			sqlite3_finalize(stmt);

		}else{
			printf("yyyyyy%d\t\t%s\n", 1, "xxxx");
		}
		
		if(close_db())
			printf("Close database failed.\n");
	}		
	gtk_widget_grab_focus (event_title);

	return add_window; 
}

gboolean on_xcal_check_window_leave_notify_event (GtkWidget *widget,
				GdkEventCrossing *event, gpointer user_data)
{
	static time_t open_event = 0, tmp;
		
	printf("event->type: %d\n", event->type);
	switch(event->type){
	case GDK_LEAVE_NOTIFY:
		if(open_event == 0)
			time(&open_event);
		time(&tmp);	
		if ((tmp - open_event) > 1){
			gtk_widget_destroy(GTK_WIDGET(widget));
			open_event = tmp;
		}
		printf("leave_notify_event: \n");
		break;
	}
}
void on_xcal_check_pressed (GtkButton *button, gpointer user_data)
{
	GtkWidget *window;	
	printf("xcal_check_pressed xxxxxx%d\n", (int)user_data);
	
	window=(GtkWidget *)create_show_evnet_window ((int)user_data);
	//gtk_window_set_transient_for (GTK_WINDOW (window), GTK_WINDOW (obj->main_window));
	gtk_window_set_decorated(GTK_WINDOW (window), FALSE);
	gtk_widget_show(window);
	g_signal_connect ((gpointer) window, "leave_notify_event",
			G_CALLBACK (on_xcal_check_window_leave_notify_event), NULL);
	g_signal_connect(G_OBJECT(window), "enter_notify_event", 
			G_CALLBACK (on_xcal_check_window_leave_notify_event), NULL);
	return;
}

char* get_event_date (GtkWidget *event_box, char *xdate)
{
	int len= 0, i = 0;
	GList* clilds;
	GtkWidget *xcal_check;
	GtkTooltips *tooltip;
	struct eventtips *comment = NULL;
	
	clilds = gtk_container_get_children(GTK_CONTAINER(event_box));
	len = g_list_length(clilds);
	printf("There are %d child\n", len);
	for(i = 0; i < len; i++){
		printf("xxxThere are %d child\n", len);
		gtk_container_remove((GtkContainer *)event_box, clilds->data);
		clilds = clilds->next;
	}
	
	while(tipshead){	
		comment = tipshead;			
		tipshead = tipshead->next;
		free(comment);
	}
		
	if(open_db("xcal.db"))
		printf("Open database failed.\n");
	else {	
		char strtmp[1024]; 
		
		sprintf(strtmp,"%s'%s';", "select id, fin, event, moreinfo from xcal where xdate=", xdate);
		sqlite3_stmt *stmt = get_records(strtmp);
		if (stmt){
			int nret, fin, id;
			char *event_title, *event_comment;
			len = 0;
			while(1) {
				nret = sqlite3_step(stmt);
				if(nret != SQLITE_ROW)
					break;
				id = sqlite3_column_int(stmt, 0);
				fin = sqlite3_column_int(stmt, 1);
				event_title = (char *)sqlite3_column_text(stmt, 2);
				event_comment = (char *)sqlite3_column_text(stmt, 3);
				printf("\txxx%d\t\t%s\t%s\n", fin, event_title, event_comment);
				if(strlen(event_title) > 25){
					snprintf(strtmp, 25, "%s", event_title);
					strcat(strtmp, "...");	
				}else
					sprintf(strtmp, "%s", event_title);
					
				xcal_check = gtk_check_button_new_with_mnemonic (_(strtmp));
				gtk_widget_show (xcal_check);				
				gtk_box_pack_start (GTK_BOX (event_box), xcal_check, FALSE, FALSE, 0);

				g_signal_connect ((gpointer) xcal_check, "pressed", 
							G_CALLBACK (on_xcal_check_pressed), (gpointer) id);
				len += 1;
			}	
			sqlite3_finalize(stmt);
			if (len == 0){
				xcal_check = gtk_check_button_new_with_mnemonic (_("Today is a Free day!!"));
				gtk_widget_show (xcal_check);
				gtk_box_pack_start (GTK_BOX (event_box), xcal_check, FALSE, FALSE, 0);				
			}
		}else{
			printf("yyyyyy%d\t\t%s\n", 1, "xxxx");
		}
		
		if(close_db())
			printf("Close database failed.\n");
	}
	return NULL;
}
/*				
				tooltip = gtk_tooltips_new();				
				comment = malloc(sizeof(struct eventtips *));			
				snprintf(comment->tips, 512, "%s", event_comment);
				comment->next = NULL;
				gtk_tooltips_set_tip((GtkTooltips *)tooltip, xcal_check, _(comment->tips), NULL);
				if(len == 0)
					tipshead = comment;
				else
					tipshead->next = comment;
*/
