/*
* Initial main.c file generated by Glade. Edit as required.
* Glade will not overwrite this file.
*/

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>

#include "main_window.h"
#include "support.h"
static int sta = 0;

void callback_icon(GtkStatusIcon * status_icon, gpointer data)
{
	GtkWidget *main = (GtkWidget *) data;
	if (sta == 0) {
		gtk_widget_hide(main);
		sta = 1;
	} else {
		gtk_widget_show(main);
		sta = 0;
	}
}
void window_event(gpointer data)
{
	GtkWidget *window=GTK_WIDGET(data);
	
		gtk_widget_hide(window);
		sta = 1;
}
int main(int argc, char *argv[])
{
	GtkWidget *main_xcalendar;
	GtkStatusIcon *icon;
	GdkPixbuf *panel_icon_pixbuf;

#ifdef ENABLE_NLS
	bindtextdomain(GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
	bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
	textdomain(GETTEXT_PACKAGE);
#endif

	gtk_set_locale();
	gtk_init(&argc, &argv);
	
	add_pixmap_directory(PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");
	add_pixmap_directory("../pixmaps");
	add_pixmap_directory("./pixmaps");
	main_xcalendar = create_main_window();

	panel_icon_pixbuf = create_pixbuf("logo.png");
	icon = gtk_status_icon_new_from_pixbuf(panel_icon_pixbuf);
	gtk_status_icon_set_tooltip(icon, "Xcalendar");

	g_signal_connect((gpointer) icon, "activate", G_CALLBACK(callback_icon),
			 main_xcalendar);
	g_signal_connect((gpointer) main_xcalendar, "delete_event",
			 G_CALLBACK(window_event), NULL);

	gtk_widget_show_all (main_xcalendar);
	gtk_main();

	return 0;
}
