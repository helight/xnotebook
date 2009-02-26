/*
 * funs.c
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "Debug.h"
#include "Funs.h"


void show_folders(struct clist_struct *cclist)
{
	gchar *fname[1][1] = {NULL};
	gchar msg[64];
	gint num = 0;
	char *ch=NULL;
	DIR *dir;
	struct dirent *ptr;
	debug_p("root_path:%s\n",cclist->root_path);
opendir:if((dir = opendir(cclist->root_path)) == NULL){
		perror("cann't open it\n");
		switch(errno){
		case EACCES:
			perror("Permission denied.\n");
			exit(1);
		default:
			printf("Directory does not exist, or name is an empty string.\n");
			if(mkdir(cclist->root_path, 0755) < 0){
				perror("mkdir:\n");
				exit(1);
				}
			goto opendir;
		}
	}
	
	while((ptr = readdir(dir)) != NULL){
		ch = ptr->d_name;
		if(*ch != '.'){
			fname[0][0] = ptr->d_name;
			gtk_clist_append((GtkCList*)cclist->clist_folder,fname[0]);
			num++;
		}
		debug_p("file name:%s fname[]:%s\n",ch, fname[0][0]);
	}	
	gtk_clist_select_row((GtkCList*)cclist->clist_folder,0,0);
	cclist->folder_row = 0;
	closedir(dir);
	
	memset(msg, '\0', sizeof(msg));
	g_snprintf(msg, 80, "Folder : %d", num);
	show_status(cclist->statusbar.status_folder, msg);
	
	return;
}

void show_notes(struct clist_struct *cclist)
{
	gint i = 0, n = 0, row = -1;
	gchar *fname[1][2] = {NULL,NULL};
	gchar buf_time[32];
	gchar file_path[512];
	gchar msg[64];
	gint num = 0;
	char *ch=NULL;
	DIR *dir;
	struct dirent *ptr;
	struct stat stat;
	
	if((dir = opendir(cclist->root_path)) == NULL){
		printf("cann't open it\n");
		return;
	}	
	row = cclist->folder_row;	
	while((ptr = readdir(dir)) != NULL){
		ch = ptr->d_name;
		if(*ch != '.'){
			if(i++ == row){
				memset(cclist->sub_path, '\0', sizeof(cclist->sub_path));
				snprintf(cclist->sub_path, sizeof(cclist->sub_path), "%s/%s",
				 cclist->root_path, ptr->d_name);
			}			
		}		
	}
	debug_p("path: %s\n", cclist->sub_path);
	closedir(dir);
		
	if((dir = opendir(cclist->sub_path)) == NULL){
		printf("cann't open it\n");
		return;
	}	
	gtk_clist_clear(GTK_CLIST(cclist->clist_note));	
	while((ptr = readdir(dir)) != NULL){
		ch = ptr->d_name;
		if(*ch != '.'){
			memset(file_path, '\0', sizeof(file_path));
			snprintf(file_path, sizeof(file_path), "%s/%s",
				 cclist->sub_path, ptr->d_name);
			
			if(strstr(file_path, ".txt")){
				if(lstat(file_path, &stat) == -1){
					perror("stat:");
					return;
				}
				memset(msg, '\0', sizeof(msg));	
				snprintf(msg, sizeof(msg), "%s %s",
				 ptr->d_name, "     ");
				fname[0][0] = msg;
				memset(buf_time, '\0', sizeof(buf_time));
				strcpy(buf_time, ctime(&stat.st_mtime));
				buf_time[strlen(buf_time) -1] = '\0';
				fname[0][1] = buf_time;
				debug_p("file name:%s fname[]:%s : %s\n",ch, fname[0][0], fname[0][1]);
				gtk_clist_append((GtkCList*)cclist->clist_note,fname[0]);
				num++;	
			}
	
		}
	}
	closedir(dir);
		
	if(gtk_text_view_get_editable (GTK_TEXT_VIEW (cclist->note_text)))
		gtk_text_view_set_editable (GTK_TEXT_VIEW (cclist->note_text), FALSE);
	
	memset(msg, '\0', sizeof(msg));
	g_snprintf(msg, sizeof(msg), "Note : %d", num);
	show_status(cclist->statusbar.status_note, msg);
	return;
}

void show_file(struct clist_struct *cclist)
{
	gint i = 0, n = 0, row = -1;
	gchar *fname[1][2] = {"file name","time"};
	gchar file_path[512];
	gchar msg[128];
	char *ch=NULL;
	DIR *dir;
	struct dirent *ptr;
	struct stat stat;
	
	if((dir = opendir(cclist->sub_path)) == NULL){
		perror("cann't opendir\n");
		return;
	}	
	row = cclist->note_row;	
	while((ptr = readdir(dir)) != NULL){
		ch = ptr->d_name;
		if((*ch != '.') && (strstr(ch, ".txt") != NULL)){
			if(i++ == row){
				memset(file_path, '\0', sizeof(file_path));
				snprintf(file_path, sizeof(file_path), "%s/%s",
				 cclist->sub_path, ptr->d_name);
				strcpy(cclist->doc_path,file_path);		
			}
		}		
	}
	closedir(dir);
	debug_p("path: %s: doc_path: %s\n", file_path, cclist->doc_path);
	
	
	if(strstr(file_path, ".txt")){
		gchar buff[64*1024];
		FILE *fd;
		if((fd = fopen(file_path, "r")) == NULL){
			perror("open");
		}
		i = 0;
		while ((buff[i] = fgetc(fd)) != EOF)
			i++;
		buff[i]='\0';
        gtk_text_buffer_set_text (GTK_TEXT_BUFFER(cclist->buffer),
        						 _(buff), -1);
		fclose(fd);
	}
	if(gtk_text_view_get_editable (GTK_TEXT_VIEW (cclist->note_text)))
		gtk_text_view_set_editable (GTK_TEXT_VIEW (cclist->note_text), FALSE);
		
	if(lstat(file_path, &stat) == -1){
		perror("stat:");
		return;
	}
	memset(msg, '\0', sizeof(msg));
	g_snprintf(msg, sizeof(msg), "Name:%s Size:%6d bytes", 
		file_path + strlen(cclist->sub_path) + 1, stat.st_size);
	show_status(cclist->statusbar.status_file, msg);
	
	return;	
}
void show_status(GtkWidget *statusbar, gchar *msg)
{
	gint status_id = 0;
	
	debug_p("status:%s\n",msg);
	status_id = gtk_statusbar_get_context_id(GTK_STATUSBAR(statusbar),"");
	gtk_statusbar_push(GTK_STATUSBAR(statusbar), status_id, msg);
	
}
void add_folder_or_note(struct clist_struct *cclist)
{
	gchar creat_name[512];
	const gchar *fp = NULL;
	gchar msg[64];
	
	memset(creat_name, '\0', sizeof(creat_name));
	fp = gtk_entry_get_text(GTK_ENTRY(cclist->other.entry_name));
	printf("fp: %02x\n", *fp);
	if((strchr(fp, ' ') == NULL) && (*fp != 0)){
			if(cclist->creat == FOLDER){
				snprintf(creat_name, sizeof(creat_name), "%s/%s",
				 cclist->root_path, fp);
			} else if(cclist->creat == NOTEFILE){
				snprintf(creat_name, sizeof(creat_name), "%s/%s",
				 cclist->sub_path, fp);
			} else {
				strcpy(msg, "Cann't creat....");
				goto out;
				return;
			}
				
		if(cclist->creat == FOLDER){
			if(mkdir(creat_name, 0755) < 0){
				perror("mkdir:\n");
				strcpy(msg, "Cann't Creat Folder....");
				goto out;
			}
			gtk_clist_clear(GTK_CLIST(cclist->clist_folder));	
			show_folders(cclist);
		} else if(cclist->creat == NOTEFILE){
			if(strstr(fp, ".txt") == NULL){
				strcpy(msg, "The name should be like xxx.txt");
				message_box_for_add_folder(cclist->other.window,msg);
				return;
			}
			int fd = 0;
			if ((fd = open(creat_name, O_CREAT, 0644)) < 0){
				perror("open:");
				strcpy(msg, "Cann't Creat NoteFile....");
				close(fd);
				goto out;
			}
			close(fd);
			gtk_clist_clear(GTK_CLIST(cclist->clist_note));
			show_notes(cclist);
		}
		strcpy(msg, "Add OK");
out:		message_box_for_add_folder(cclist->other.window,msg);
		debug_p("root_path:%s \n", creat_name);	
		gtk_widget_destroy(GTK_WIDGET(cclist->other.window));
		cclist->other.window = NULL;
		cclist->other.entry_name = NULL;
	} else {
		debug_p("no words or input the wrong name\n");
		strcpy(msg, "No words or input the wrong name");
		message_box_for_add_folder(cclist->other.window,msg);
	}
}


void message_box_for_add_folder(GtkWidget *window,gchar *message)
{
	GtkWidget *dialog;
	dialog = gtk_message_dialog_new(GTK_WINDOW(window), 0,
				GTK_MESSAGE_INFO, GTK_BUTTONS_OK, message);
	gtk_dialog_run(GTK_DIALOG(dialog));
	gtk_widget_destroy(dialog);
}

void del_folder_or_note(struct clist_struct *cclist)
{
	if(cclist->del == FOLDER){
		if(cclist->folder_row < 0)
			return;
		debug_p("the path :%s \n", cclist->sub_path);
		gint fd = 0;
		gchar cmd[256];
		memset(cmd, '\0', sizeof(cmd));
		snprintf(cmd, sizeof(cmd), "rm -rf %s", cclist->sub_path);

		if((fd = system(cmd)) < 0)
			perror("remove folder:\n");
		debug_p("cmd: %s \n", cmd);
		gtk_clist_clear(GTK_CLIST(cclist->clist_folder));
		show_folders(cclist);
	} else if(cclist->del == NOTEFILE){
		if(cclist->note_row < 0)
			return;
		debug_p("the path :%s \n", cclist->doc_path);
		gint fd = 0;
		if((fd = remove(cclist->doc_path)) < 0)
			perror("remove note:\n");
			
		gtk_clist_clear(GTK_CLIST(cclist->clist_note));
		show_notes(cclist);		
	} else {
		debug_p("Nothing will be deleted...\n");
		return;
	}
	cclist->del = NOTHING;
	return;
}

void save_note(struct clist_struct *cclist)
{
	gchar *text = NULL;
	gint len = 0;
	GtkTextIter start,end;
	//int fd = 0;
	FILE *fd = NULL;

	gtk_text_buffer_get_bounds (GTK_TEXT_BUFFER(cclist->buffer), 
        					&start, &end);
	text = gtk_text_buffer_get_text(GTK_TEXT_BUFFER(cclist->buffer), 
    						&start,&end,FALSE);
	if((fd = fopen(cclist->doc_path, "w")) == NULL)
		perror("open\n");
    	
	len = strlen(text);
	debug_p("save:%s len :%d\n", text, len);
	//printf("save:%s len :%d\n", text, len);
	if(fwrite(text, len, 1, fd) != 1)
		perror("fweite:");
 
	fclose(fd);
}
