#############################################################################
# Makefile for building: aracne
# Generated by qmake (2.01a) (Qt 4.8.7) on: dom nov 10 19:08:56 2019
# Project:  ProxyUI.pro
# Template: app
# Command: /usr/lib/x86_64-linux-gnu/qt4/bin/qmake -o Makefile ProxyUI.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -std=c++11 -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/x86_64-linux-gnu/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		proxyui.cpp \
		Parser.cpp \
		Request.cpp \
		Response.cpp \
		Servidor_proxy.cpp \
		Spider.cpp \
		Functions_aux.cpp moc_proxyui.cpp
OBJECTS       = main.o \
		proxyui.o \
		Parser.o \
		Request.o \
		Response.o \
		Servidor_proxy.o \
		Spider.o \
		Functions_aux.o \
		moc_proxyui.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		ProxyUI.pro
QMAKE_TARGET  = aracne
DESTDIR       = 
TARGET        = aracne

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_proxyui.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: ProxyUI.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/shared.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile ProxyUI.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/shared.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile ProxyUI.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/aracne1.0.0 || $(MKDIR) .tmp/aracne1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/aracne1.0.0/ && $(COPY_FILE) --parents proxyui.h Request.hpp Response.hpp Servidor_proxy.hpp Functions_aux.hpp Spider.hpp Parser.hpp .tmp/aracne1.0.0/ && $(COPY_FILE) --parents main.cpp proxyui.cpp Parser.cpp Request.cpp Response.cpp Servidor_proxy.cpp Spider.cpp Functions_aux.cpp .tmp/aracne1.0.0/ && $(COPY_FILE) --parents proxyui.ui .tmp/aracne1.0.0/ && (cd `dirname .tmp/aracne1.0.0` && $(TAR) aracne1.0.0.tar aracne1.0.0 && $(COMPRESS) aracne1.0.0.tar) && $(MOVE) `dirname .tmp/aracne1.0.0`/aracne1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/aracne1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_proxyui.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_proxyui.cpp
moc_proxyui.cpp: Servidor_proxy.hpp \
		proxyui.h
	/usr/lib/x86_64-linux-gnu/qt4/bin/moc $(DEFINES) $(INCPATH) proxyui.h -o moc_proxyui.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_proxyui.h
compiler_uic_clean:
	-$(DEL_FILE) ui_proxyui.h
ui_proxyui.h: proxyui.ui
	/usr/lib/x86_64-linux-gnu/qt4/bin/uic proxyui.ui -o ui_proxyui.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp Parser.hpp \
		Spider.hpp \
		Servidor_proxy.hpp \
		Request.hpp \
		Response.hpp \
		Functions_aux.hpp \
		proxyui.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

proxyui.o: proxyui.cpp proxyui.h \
		Servidor_proxy.hpp \
		ui_proxyui.h \
		Request.hpp \
		Response.hpp \
		Functions_aux.hpp \
		Spider.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o proxyui.o proxyui.cpp

Parser.o: Parser.cpp Parser.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Parser.o Parser.cpp

Request.o: Request.cpp Request.hpp \
		Functions_aux.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Request.o Request.cpp

Response.o: Response.cpp Response.hpp \
		Functions_aux.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Response.o Response.cpp

Servidor_proxy.o: Servidor_proxy.cpp Servidor_proxy.hpp \
		Request.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Servidor_proxy.o Servidor_proxy.cpp

Spider.o: Spider.cpp Parser.hpp \
		Spider.hpp \
		Servidor_proxy.hpp \
		Request.hpp \
		Response.hpp \
		Functions_aux.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Spider.o Spider.cpp

Functions_aux.o: Functions_aux.cpp Functions_aux.hpp
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Functions_aux.o Functions_aux.cpp

moc_proxyui.o: moc_proxyui.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_proxyui.o moc_proxyui.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
