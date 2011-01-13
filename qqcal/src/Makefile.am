## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@ \
	-I../include/ 
SQLite_lib = -L../lib -lsqlite3 

bin_PROGRAMS = xqqcal

xqqcal_SOURCES = \
	main.c \
	support.c support.h \
	main_window.c main_window.h \
	calendar.c calendar.h \
	event.c event.h \
	setup.c setup.h \
	callbacks.c callbacks.h \
	func.c func.h
PACKAGE_LIBS += $(SQLite_lib)
xqqcal_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)  $(SQLite_lib)


