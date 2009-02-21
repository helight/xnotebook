#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include "Callbacks.h"

gboolean
on_main_windown_delete_event (GtkWidget *widget,
                              GdkEvent *event,
                              gpointer user_data)
{
        printf("bey world;\n");
        gtk_main_quit();

	return FALSE;
}
