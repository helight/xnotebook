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


void show_folders(struct clist_struct *clist)
{
	gchar *fname[1][1];
	char *ch=NULL;
	DIR *dir;
	struct dirent *ptr;
	printf("root_path:%s\n",clist->root_path);
opendir:if((dir = opendir(clist->root_path)) == NULL){
		perror("cann't open it\n");
		switch(errno){
		case EACCES:
			perror("Permission denied.\n");
			exit(1);
		default:
			printf("Directory does not exist, or name is an empty string.\n");
			if(mkdir(clist->root_path, 0755) < 0){
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
			gtk_clist_append((GtkCList*)clist->clist_folder,(gchar*)fname[0]);
		}
		debug_p("file name:%s fname[]:%s\n",ch, fname[0][0]);
	}	
	gtk_clist_select_row((GtkCList*)clist->clist_folder,0,0);
	clist->folder_row = 0;
	closedir(dir);
	
	return;
}

void show_notes(struct clist_struct *cclist)
{
	gint i = 0, n = 0, row = -1;	
	gchar *fname[1][2] = {"file name","time"};
	gchar buf_time[32];
	gchar file_path[512];
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
					strcpy(cclist->sub_path, cclist->root_path);
					strcat(cclist->sub_path, "/");
					strcat(cclist->sub_path, ch);		
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
			strcpy(file_path, cclist->sub_path);
			strcat(file_path, "/");
			strcat(file_path, ptr->d_name);
			
			if(strstr(file_path, ".txt")){
				if(lstat(file_path, &stat) == -1){
					perror("stat:");
					return;
				}
				
				fname[0][0] = ptr->d_name;
				memset(buf_time, '\0', sizeof(buf_time));
				strcpy(buf_time, ctime(&stat.st_mtime));
				buf_time[strlen(buf_time) -1] = '\0';
				fname[0][1] = buf_time;
				//*(fname[0][1] + strlen(fname[0][1] -1)) = '\0';
				debug_p("file name:%s fname[]:%s : %s\n",ch, fname[0][0], fname[0][1]);
				gtk_clist_append((GtkCList*)cclist->clist_note,(gchar*)fname[0]);
				
			}
	
		}
	}
	closedir(dir);
	cclist->folder_row = -1;
	
	if(gtk_text_view_get_editable (GTK_TEXT_VIEW (cclist->note_text)))
		gtk_text_view_set_editable (GTK_TEXT_VIEW (cclist->note_text), FALSE);
	return;
}

void show_file(struct clist_struct *cclist)
{
	gint i = 0, n = 0, row = -1;
	gchar *fname[1][2] = {"file name","time"};
	gchar file_path[512];
	char *ch=NULL;
	DIR *dir;
	struct dirent *ptr;
	
	if((dir = opendir(cclist->sub_path)) == NULL){
		printf("cann't open it\n");
		return;
	}	
	row = cclist->note_row;	
	while((ptr = readdir(dir)) != NULL){
		ch = ptr->d_name;
		if(*ch != '.'){
			if(strstr(ch, ".txt")){
				if(i++ == row){
						memset(file_path, '\0', sizeof(file_path));
						strcpy(file_path, cclist->sub_path);
						strcat(file_path, "/");
						strcat(file_path, ch);
						strcpy(cclist->doc_path,file_path);		
				}			
			}
		}		
	}
	debug_p("path: %s: doc_path: %s\n", file_path, cclist->doc_path);
	closedir(dir);
	
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
	return;	
}

void add_folder_or_note(struct clist_struct *cclist)
{
	gchar creat_name[512];
	const gchar *fp = NULL;
	gchar msg[64];
	
	memset(creat_name, '\0', sizeof(creat_name));
	if(cclist->creat == FOLDER){
		strcpy(creat_name, cclist->root_path);
	} else if(cclist->creat == NOTEFILE){
		strcpy(creat_name, cclist->sub_path);
	} else {
		strcpy(msg, "Cann't creat....");
		goto out;
		return;
	}
	fp = gtk_entry_get_text(GTK_ENTRY(cclist->other.entry_name));
	printf("fp: %02x\n", *fp);
	if((strchr(fp, ' ') == NULL) && (*fp != 0)){		
		strcat(creat_name, "/");
		strcat(creat_name, fp);
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
