/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */
#ifndef SUPPORT
#define SUPPORT
#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

/*
 * Standard gettext macros.
 */
#ifdef ENABLE_NLS
#  include <libintl.h>
#  undef _
#  define _(String) dgettext (PACKAGE, String)
#  define Q_(String) g_strip_context ((String), gettext (String))
#  ifdef gettext_noop
#    define N_(String) gettext_noop (String)
#  else
#    define N_(String) (String)
#  endif
#else
#  define textdomain(String) (String)
#  define gettext(String) (String)
#  define dgettext(Domain,Message) (Message)
#  define dcgettext(Domain,Message,Type) (Message)
#  define bindtextdomain(Domain,Directory) (Domain)
#  define _(String) (String)
#  define Q_(String) g_strip_context ((String), (String))
#  define N_(String) (String)
#endif


/*
 * Public Functions.
 */

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
g_object_set_data_full (G_OBJECT (component), name, \
        gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
g_object_set_data (G_OBJECT (component), name, widget)

struct add_entry{
	GtkWidget *window;
	GtkWidget *entry_name;
	GtkWidget *entry_url;
	};
	
struct wdialog{
	GtkWidget *dialog;
	GtkWidget *label_text;
	};
struct statusbar{
	GtkWidget *status_folder;
	GtkWidget *status_file;
	GtkWidget *status_xnote;
	};
	
enum deal{
	NOTHING,
	FOLDER,
	NOTE_FILE,
	RSS_ITEM,
	BACKUP
	};
	
struct clist_struct {
	gchar		root_path[128];
	gchar		rss_path[128];
	gchar		sub_path[128];
	gchar		rss_file_path[256];
	gchar		doc_path[256];
	GtkTextBuffer	*buffer;
	gint		folder_num;
	gint		note_num;
	gint		is_rss;
	enum deal 	creat;
	enum deal 	del;
	enum deal 	xname;
	GtkWidget 	*clist_folder;
	gint 		folder_row;
	GtkWidget 	*clist_note;
	gint 		note_row;
	GtkWidget 	*clist_rss;
	gint 		rss_row;
	GtkWidget 	*note_text;
	struct add_entry other;
	struct wdialog 	dialog;
	struct statusbar statusbar;
};

/*
 * This function returns a widget in a component created by Glade.
 * Call it with the toplevel widget in the component (i.e. a window/dialog),
 * or alternatively any widget in the component, and the name of the widget
 * you want returned.
 */
GtkWidget* lookup_widget (GtkWidget *widget, const gchar *widget_name);


/* Use this function to set the directory containing installed pixmaps. */
void add_pixmap_directory (const gchar *directory);


/*
 * Private Functions.
 */

/* This is used to create the pixmaps used in the interface. */
GtkWidget*  create_pixmap (GtkWidget *widget, const gchar *filename);

/* This is used to create the pixbufs used in the interface. */
GdkPixbuf*  create_pixbuf (const gchar *filename);

/* This is used to set ATK action descriptions. */
void glade_set_atk_action_description (AtkAction *action,
                                      const gchar *action_name,
                                      const gchar *description);

#endif
