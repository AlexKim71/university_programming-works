# $Id: Makefile.in,v 1.46 2022/10/01 22:53:36 tom Exp $
##############################################################################
# Copyright 2018-2021,2022 Thomas E. Dickey                                  #
# Copyright 1998-2014,2015 Free Software Foundation, Inc.                    #
#                                                                            #
# Permission is hereby granted, free of charge, to any person obtaining a    #
# copy of this software and associated documentation files (the "Software"), #
# to deal in the Software without restriction, including without limitation  #
# the rights to use, copy, modify, merge, publish, distribute, distribute    #
# with modifications, sublicense, and/or sell copies of the Software, and to #
# permit persons to whom the Software is furnished to do so, subject to the  #
# following conditions:                                                      #
#                                                                            #
# The above copyright notice and this permission notice shall be included in #
# all copies or substantial portions of the Software.                        #
#                                                                            #
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR #
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,   #
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL    #
# THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER      #
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING    #
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER        #
# DEALINGS IN THE SOFTWARE.                                                  #
#                                                                            #
# Except as contained in this notice, the name(s) of the above copyright     #
# holders shall not be used in advertising or otherwise to promote the sale, #
# use or other dealings in this Software without prior written               #
# authorization.                                                             #
##############################################################################
#
# Author: Thomas E. Dickey		1996-on
#
# Master Makefile for ncurses library.

SHELL 		= /bin/sh


DESTDIR=
RPATH_LIST=${libdir}
TOP_MFLAGS =  DESTDIR="$(DESTDIR)" RPATH_LIST="$(RPATH_LIST)"



NCURSES_MAJOR	= 6
NCURSES_MINOR	= 4
NCURSES_PATCH	= 20221231

top_srcdir	= .
srcdir		= .

prefix		= /home/kim/Desktop/Code/ncurses-install
exec_prefix	= ${prefix}
datarootdir	= ${prefix}/share

bindir		= ${exec_prefix}/bin
ticdir		= /home/kim/Desktop/Code/ncurses-install/share/terminfo
includedir	= ${prefix}/include
includesubdir	= /ncurses
libdir		= ${exec_prefix}/lib
mandir		= ${datarootdir}/man
pkgdir		= ${libdir}/pkgconfig

include_dir	= ${includedir}${includesubdir}

FGREP		= grep -F

INSTALL		= /usr/bin/install -c
INSTALL_DATA	= ${INSTALL} -m 644

DIRS_TO_MAKE	= lib objects obj_g

.PHONY :	all
.PHONY :	check
.PHONY :	clean
.PHONY :	depend
.PHONY :	distclean
.PHONY :	install
.PHONY :	mostlyclean
.PHONY :	preinstall
.PHONY :	realclean
.PHONY :	sources
.PHONY :	tags
.PHONY :	uninstall

all ::	$(DIRS_TO_MAKE)

$(DIRS_TO_MAKE) :
	mkdir $@

preinstall :
	@ echo ''
	@ echo '** Configuration summary for NCURSES $(NCURSES_MAJOR).$(NCURSES_MINOR) $(NCURSES_PATCH):'
	@ echo ''
	@ echo '       extended funcs: '`test 1 != 0 && echo yes || echo no`
	@ echo '       xterm terminfo: 'xterm-new
	@ echo ''
	@ echo '        bin directory: '$(bindir)
	@ echo '        lib directory: '$(libdir)
	@ echo '    include directory: '$(include_dir)
	@ echo '        man directory: '$(mandir)
	@ echo '   terminfo directory: '$(ticdir)
#	@ echo '  using fallback-list: '
#	@ echo ' pkg-config directory: '$(pkgdir)
	@ echo ''
	@ test "$(include_dir)" = "$(prefix)/include" || \
		echo '** Include-directory is not in a standard location'
	@ test ! -f $(include_dir)/termcap.h || \
		$(FGREP) NCURSES_VERSION $(include_dir)/termcap.h >/dev/null || \
		echo '** Will overwrite non-ncurses termcap.h'
	@ test ! -f $(include_dir)/curses.h || \
		$(FGREP) NCURSES_VERSION $(include_dir)/curses.h >/dev/null || \
		echo '** Will overwrite non-ncurses curses.h'

distclean \
realclean ::

check :
	@ echo The test-programs are interactive


# Put the common rules here so that we can easily construct the list of
# directories to visit.
all \
clean \
distclean \
mostlyclean \
realclean \
depend \
sources \
tags \
uninstall \
install ::
	( cd man && ${MAKE} ${TOP_MFLAGS} $@ )
	( cd include && ${MAKE} ${TOP_MFLAGS} $@ )
	( cd ncurses && ${MAKE} ${TOP_MFLAGS} $@ )
	( cd progs && ${MAKE} ${TOP_MFLAGS} $@ )
	( cd panel && ${MAKE} ${TOP_MFLAGS} $@ )
	( cd menu && ${MAKE} ${TOP_MFLAGS} $@ )
	( cd form && ${MAKE} ${TOP_MFLAGS} $@ )
	( cd test && ${MAKE} ${TOP_MFLAGS} $@ )
	( cd misc && ${MAKE} ${TOP_MFLAGS} $@ )
	( cd c++ && ${MAKE} ${TOP_MFLAGS} $@ )

# generated by CF_LIB_RULES

.PHONY :	libs
.PHONY :	lintlib
.PHONY :	install.includes
.PHONY :	uninstall.includes
.PHONY :	install.libs
.PHONY :	uninstall.libs

libs \
install.libs \
uninstall.libs \
install.includes \
uninstall.includes ::
	( cd "include" && ${MAKE} ${TOP_MFLAGS} $@ )

.PHONY :	install.ncurses
.PHONY :	uninstall.ncurses

lint \
libs \
lintlib \
install.libs \
uninstall.libs \
install.ncurses \
uninstall.ncurses ::
	( cd "ncurses" && ${MAKE} ${TOP_MFLAGS} $@ )

.PHONY :	install.progs
.PHONY :	uninstall.progs

lint \
libs \
lintlib \
install.libs \
uninstall.libs \
install.progs \
uninstall.progs ::
	( cd "progs" && ${MAKE} ${TOP_MFLAGS} $@ )

.PHONY :	install.panel
.PHONY :	uninstall.panel

install.includes \
uninstall.includes \
lint \
libs \
lintlib \
install.libs \
uninstall.libs \
install.panel \
uninstall.panel ::
	( cd "panel" && ${MAKE} ${TOP_MFLAGS} $@ )

.PHONY :	install.menu
.PHONY :	uninstall.menu

install.includes \
uninstall.includes \
lint \
libs \
lintlib \
install.libs \
uninstall.libs \
install.menu \
uninstall.menu ::
	( cd "menu" && ${MAKE} ${TOP_MFLAGS} $@ )

.PHONY :	install.form
.PHONY :	uninstall.form

install.includes \
uninstall.includes \
lint \
libs \
lintlib \
install.libs \
uninstall.libs \
install.form \
uninstall.form ::
	( cd "form" && ${MAKE} ${TOP_MFLAGS} $@ )

.PHONY :	install.test
.PHONY :	uninstall.test

lint \
libs \
lintlib \
install.libs \
uninstall.libs \
install.test \
uninstall.test ::
	( cd "test" && ${MAKE} ${TOP_MFLAGS} $@ )

.PHONY :	install.c++
.PHONY :	uninstall.c++

install.includes \
uninstall.includes \
lint \
libs \
lintlib \
install.libs \
uninstall.libs \
install.c++ \
uninstall.c++ ::
	( cd "c++" && ${MAKE} ${TOP_MFLAGS} $@ )

.PHONY :	install.data
.PHONY :	uninstall.data

install.libs uninstall.libs \
install.data uninstall.data ::
	( cd misc && ${MAKE} ${TOP_MFLAGS} $@ )

.PHONY :	install.man
.PHONY :	uninstall.man

install.man \
uninstall.man ::
	( cd man && ${MAKE} ${TOP_MFLAGS} $@ )

distclean ::
	rm -f config.cache config.log config.status Makefile include/ncurses_cfg.h
	rm -f headers.sh headers.sed mk_shared_lib.sh
	rm -f edit_man.* man_alias.*
	rm -rf ${DIRS_TO_MAKE}
