/*
 * funs.c
 *
 *  Created on: Feb 19, 2009
 *      Author: helight
 */
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <sys/types.h>
#include <sys/ioctl.h>
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
	gint num = 0;
	char *ch=NULL;
	DIR *dir;
	struct dirent *ptr;
	debug_p("root_path:%s\n",cclist->root_path);
opendir:if((dir = opendir(cclist->root_path)) == NULL){
		perror("can't open it\n");
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
	
	cclist->folder_num = num;
	
	return;
}

void show_rss(struct clist_struct *cclist)
{
	gchar *fname[1][1] = {NULL};
	gint num = 0;
	char *ch=NULL;
	DIR *dir;
	struct dirent *ptr;
	debug_p("root_path:%s\n",cclist->rss_path);
opendir:if((dir = opendir(cclist->rss_path)) == NULL){
		perror("can't open it\n");
		switch(errno){
		case EACCES:
			perror("Permission denied.\n");
			exit(1);
		default:
			printf("Directory does not exist, or name is an empty string.\n");
			if(mkdir(cclist->rss_path, 0755) < 0){
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
			gtk_clist_append((GtkCList*)cclist->clist_rss,fname[0]);
			num++;
		}
		debug_p("file name:%s fname[]:%s\n",ch, fname[0][0]);
	}	
	//gtk_clist_select_row((GtkCList*)cclist->clist_rss,0,0);
	cclist->rss_row = 0;
	closedir(dir);
	
	return;
}

void show_rss_item(struct clist_struct *cclist)
{
	gint i = 0, n = 0, row = -1, len = 0;
	char *ret = NULL;
	FILE *fd = NULL;
	gchar *fname[1][2] = {NULL,NULL};	
	gchar buf[1024];
	char *ch=NULL;
	DIR *dir;
	struct dirent *ptr;
	struct stat stat;
	
	if((dir = opendir(cclist->rss_path)) == NULL){
		printf("can't open it\n");
		return;
	}	
	row = cclist->rss_row;	
	while((ptr = readdir(dir)) != NULL){
		ch = ptr->d_name;
		if(*ch != '.'){
			if(i++ == row){
				memset(cclist->rss_file_path, '\0', sizeof(cclist->rss_path));
				snprintf(cclist->rss_file_path, sizeof(cclist->rss_file_path), "%s/%s",
				 cclist->rss_path, ptr->d_name);
			}			
		}		
	}
	debug_p("path: %s\n", cclist->rss_file_path);
	closedir(dir);
	gtk_clist_clear(GTK_CLIST(cclist->clist_note));	
	
	fd = fopen(cclist->rss_file_path, "r");
	ret = fgets(buf, sizeof(buf), fd);
	debug_p("%s\n", buf);
	while(ret) {
		ret = fgets(buf, sizeof(buf), fd);
		if(ret == NULL)
			break;
		ch = strstr(buf, "http://");
		*(ch -1) = '\0';
		fname[0][0] = buf;
		len = strlen(ch);
		*(ch + len -1) = '\0';
		fname[0][1] = ch;
		debug_p("%s\n", buf);
		debug_p("%s\n", ch);
		if(ret)
			gtk_clist_append((GtkCList*)cclist->clist_note,fname[0]);
	};
	
	debug_p("ok\n");
	fclose(fd);
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
		printf("can't open it\n");
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
		printf("can't open it\n");
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
				*(ptr->d_name + strlen(ptr->d_name) - 4) = '\0';
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
	cclist->note_num = num;

	return;
}

void show_file(struct clist_struct *cclist)
{
	gint i = 0, n = 0, row = -1;
	gchar *fname[1][2] = {"file name","time"};
	gchar file_path[512];
	gchar msg[512];
	char *ch=NULL;
	DIR *dir;
	struct dirent *ptr;
	struct stat stat;
	GtkSourceLanguage *lang;
	gchar *content_type;
	gboolean result_uncertain;
	
	if((dir = opendir(cclist->sub_path)) == NULL){
		perror("can't opendir\n");
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

		content_type = g_content_type_guess(file_path, NULL, 0, &result_uncertain);
		lang = gtk_source_language_manager_guess_language(cclist->lang_manager, file_path, content_type);
		g_free(content_type);
		if (lang == NULL) {
			lang = gtk_source_language_manager_get_language(cclist->lang_manager, "c");
			debug_p("use default language: C\n");
		}
		debug_p("lang: %s (%s)\n", gtk_source_language_get_name(lang), gtk_source_language_get_id(lang));
		gtk_source_buffer_set_language(cclist->buffer, lang);
		gtk_text_buffer_set_text (GTK_TEXT_BUFFER(cclist->buffer), _(buff), -1);
		fclose(fd);
	}
	if(gtk_text_view_get_editable (GTK_TEXT_VIEW (cclist->note_text)))
		gtk_text_view_set_editable (GTK_TEXT_VIEW (cclist->note_text), FALSE);
		
	if(lstat(file_path, &stat) == -1){
		perror("stat:");
		return;
	}
	memset(msg, '\0', sizeof(msg));
	g_snprintf(msg, sizeof(msg), "Folder: %d --- Total Note: %d --- Note: %s --- Size: %6d bytes --- Can't Edit: Locked", 
		cclist->folder_num, cclist->note_num, file_path + strlen(cclist->sub_path) + 1, stat.st_size);
	show_status(cclist->statusbar.status_xnote, msg);
	
	return;	
}

gboolean set_edit_enable(struct clist_struct *cclist, gboolean value)
{
	gchar msg[512];
	struct stat stat;
	
	if (value == get_edit_enabled(cclist)) {
		return TRUE;
	}

	if(cclist->note_row >= 0){
		if(lstat(cclist->doc_path, &stat) == -1){
			perror("stat:");
			return;
		}
		gtk_text_view_set_editable (GTK_TEXT_VIEW (cclist->note_text), value);
		
		memset(msg, '\0', sizeof(msg));
		g_snprintf(msg, sizeof(msg), "Folder: %d --- Total Note: %d --- Note: %s --- Size: %6d bytes --- %s", 
		cclist->folder_num, cclist->note_num, cclist->doc_path + strlen(cclist->sub_path) + 1, stat.st_size, value ? "Editable" : "Can't Edit: Locked");
		show_status(cclist->statusbar.status_xnote, msg);

		debug_p("enable edit\n");		
		return TRUE;
	}
	
	return FALSE;
}

gboolean get_edit_enabled(struct clist_struct *cclist)
{
	return gtk_text_view_get_editable(GTK_TEXT_VIEW (cclist->note_text));
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
			} else if(cclist->creat == NOTE_FILE){
				snprintf(creat_name, sizeof(creat_name), "%s/%s",
				 cclist->sub_path, fp);
			} else {
				strcpy(msg, "Can't creat....");
				goto out;
				return;
			}
				
		if(cclist->creat == FOLDER){
			if(mkdir(creat_name, 0755) < 0){
				perror("mkdir:\n");
				strcpy(msg, "Can't Creat Folder....");
				goto out;
			}
			gtk_clist_clear(GTK_CLIST(cclist->clist_folder));	
			show_folders(cclist);
		} else if(cclist->creat == NOTE_FILE){
			if(strstr(fp, ".txt") == NULL){
				strcat(creat_name, ".txt");
			}
			int fd = 0;
			if ((fd = open(creat_name, O_CREAT, 0644)) < 0){
				perror("open:");
				strcpy(msg, "Can't Creat NoteFile....");
				close(fd);
				goto out;
			}
			close(fd);
			gtk_clist_clear(GTK_CLIST(cclist->clist_note));
			show_notes(cclist);
		}
		strcpy(msg, "Add OK");
out:
		message_box_for_add_folder(cclist->other.window,msg);
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

void rename_folder_or_note(struct clist_struct *cclist)
{
	gchar creat_name[512];
	gchar cmd[1024];
	const gchar *fp = NULL;
	gchar msg[64];
	
	memset(creat_name, '\0', sizeof(creat_name));
	fp = gtk_entry_get_text(GTK_ENTRY(cclist->other.entry_name));
	printf("fp: %02x\n", *fp);
	if((strchr(fp, ' ') == NULL) && (*fp != 0)){
			if(cclist->xname == FOLDER){
				g_snprintf(cmd, sizeof(cmd), "mv %s %s/%s", 
				 	cclist->sub_path, cclist->root_path, fp);
				 system(cmd);	
				gtk_clist_clear(GTK_CLIST(cclist->clist_folder));	
				show_folders(cclist);
				
				strcpy(msg, "Reame OK");
			} else if(cclist->xname == NOTE_FILE){
				if(strstr(fp, ".txt") == NULL){
					g_snprintf(cmd, sizeof(cmd), "mv %s %s/%s%s", 
				 	cclist->doc_path, cclist->sub_path, fp, ".txt");
				}else{
					g_snprintf(cmd, sizeof(cmd), "mv %s %s/%s", 
				 	cclist->doc_path, cclist->sub_path, fp);
				}
				system(cmd);
				gtk_clist_clear(GTK_CLIST(cclist->clist_note));
				show_notes(cclist);
				strcpy(msg, "Reame OK");
			} else {
				strcpy(msg, "Can't Rename....");
			}
		message_box_for_add_folder(cclist->other.window,msg);
		debug_p("root_path:%s \n", creat_name);	
		gtk_widget_destroy(GTK_WIDGET(cclist->other.window));
		cclist->other.window = NULL;
		cclist->other.entry_name = NULL;
	} else {
		debug_p("no words or input the wrong name\n");
		strcpy(msg, "No words or input the wrong name");
		message_box_for_add_folder(cclist->other.window,msg);
	}
	
	return;
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
	} else if(cclist->del == NOTE_FILE){
		if(cclist->note_row < 0)
			return;
		debug_p("the path :%s \n", cclist->doc_path);
		gint fd = 0;
		if((fd = remove(cclist->doc_path)) < 0)
			perror("remove note:\n");
			
		gtk_clist_clear(GTK_CLIST(cclist->clist_note));
		show_notes(cclist);		
	} else if(cclist->del == RSS_ITEM){
		if(cclist->rss_row < 0)
			return;
		debug_p("the path :%s \n", cclist->rss_file_path);
		gint fd = 0;
		if((fd = remove(cclist->rss_file_path)) < 0)
			perror("remove rss:\n");
			
		gtk_clist_clear(GTK_CLIST(cclist->clist_rss));
		show_rss(cclist);
		return;
	} else if(cclist->del == BACKUP){
		gchar backup_cmd[512];

		memset(backup_cmd, '\0', sizeof(backup_cmd));
		sprintf(backup_cmd, "tar czf %s/xnotebook.tar.gz %s",
			       	getenv("HOME"), cclist->root_path);
		printf("backup_cmd: %s\n", backup_cmd);
		system(backup_cmd);
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

	if (cclist == NULL || cclist->doc_path == NULL || cclist->doc_path[0] == '\0') {
		g_print("some thing is wrong in %s()?\n", __func__);
		return;
	}

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

	set_edit_enable(cclist, FALSE);
}
