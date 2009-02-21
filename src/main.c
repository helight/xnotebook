/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#	include <config.h>
#endif

#include <gtk/gtk.h>

#include "Mainwindow.h"
#include "Support.h"
#include "Init.h"

struct clist_struct clist;

int main (int argc, char *argv[])
{
	GtkWidget *main_windown;

#ifdef ENABLE_NLS
	bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
	bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
	textdomain (GETTEXT_PACKAGE);
#endif

	gtk_set_locale ();
	gtk_init (&argc, &argv);
	
	add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");
	add_pixmap_directory ("../pixmaps");
	add_pixmap_directory("./pixmaps");
	/*
	 * The following code was added by Glade to create one of each component
	 * (except popup menus), just so that you see something after building
	 * the project. Delete any components that you don't want shown initially.
	 */
	
	init_global_clist(&clist);
	
	main_windown = create_main_windown (&clist);
	gtk_widget_show (main_windown);
	
	show_folders(&clist);
	gtk_main ();
	return 0;
}

