## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = xnotebook

xnotebook_SOURCES = \
	main.c \
	Support.c Support.h \
	Mainwindow.c Mainwindow.h \
	AddFolderFace.c AddFolder.h\
	Callbacks.c Callbacks.h	\
	MenubarFace.c MenubarCall.c Menubar.h \
	MainbodyFace.c MainbodyCall.c Mainbody.h \
	ToolbarFace.c ToolbarCall.c Toolbar.h \
	StatusbarFace.c Statusbar.h \
	CalendarFace.c Calendar.h \
	DialogFace.c DialogCall.c Dialog.h \
	AboutFace.c AboutCall.c About.h \
	Funs.c Funs.h \
	Init.c Init.h

xnotebook_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

