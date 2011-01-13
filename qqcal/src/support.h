#ifndef SUPPORT
#define SUPPORT
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>

/*
 * Standard gettext macros.
 */
#ifdef ENABLE_NLS
#include <libintl.h>
#undef _
#define _(String) dgettext (PACKAGE, String)
#define Q_(String) g_strip_context ((String), gettext (String))
#ifdef gettext_noop
#define N_(String) gettext_noop (String)
#else
#define N_(String) (String)
#endif
#else
#define textdomain(String) (String)
#define gettext(String) (String)
#define dgettext(Domain,Message) (Message)
#define dcgettext(Domain,Message,Type) (Message)
#define bindtextdomain(Domain,Directory) (Domain)
#define _(String) (String)
#define Q_(String) g_strip_context ((String), (String))
#define N_(String) (String)
#endif

struct xevent{
	int fin;
	int time;
	char event[512];
	struct xevent *next;
};

struct top_show_event{
	GtkWidget *xtime;
	GtkWidget *xtitle;
	struct xevent *hevent;
};

struct add_event_obj{
	GtkWidget *main_window;
	GtkWidget *event_box;
	GtkWidget *event_box1;
	GtkWidget *event_box2;
	GtkWidget *add_window;
	GtkWidget *event_title;
	GtkTextBuffer *event_comment;
	GtkWidget *xcalendar;
	struct xevent *hevent;
	char xdate[16];
};

typedef struct _cursoroffset {gint x,y;} CursorOffset;

void shape_pressed (GtkWidget *widget, GdkEventButton *event);

void shape_motion (GtkWidget *widget, GdkEventMotion *event);

/* Use this function to set the directory containing installed pixmaps. */
void add_pixmap_directory(const gchar * directory);

/* This is used to create the pixmaps used in the interface. */
GtkWidget *create_pixmap(const gchar * filename);

/* This is used to create the pixbufs used in the interface. */
GdkPixbuf *create_pixbuf(const gchar * filename);

#endif
