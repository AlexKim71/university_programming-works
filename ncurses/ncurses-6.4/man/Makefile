# $Id: Makefile.in,v 1.54 2022/10/22 16:36:40 tom Exp $
##############################################################################
# Copyright 2019-2021,2022 Thomas E. Dickey                                  #
# Copyright 1998-2013,2015 Free Software Foundation, Inc.                    #
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
# Author: Thomas E. Dickey 1996,1997
#
# Makefile for ncurses manual pages.
#
# NOTE: When you add or rename a man page, make sure you update both
# the top-level MANIFEST and any man/*.renames files!

SHELL		= /bin/sh


DESTDIR		= 
srcdir		= .
prefix		= /home/kim/Desktop/Code/ncurses-install
exec_prefix	= ${prefix}
datarootdir	= ${prefix}/share
datadir		= ${datarootdir}
mandir		= ${datarootdir}/man
includesubdir	= /ncurses

INCLUDEDIR	= $(DESTDIR)$(includedir)$(includesubdir)

INSTALL		= /usr/bin/install -c
INSTALL_DATA	= ${INSTALL} -m 644

################################################################################

.PHONY :	all
.PHONY :	clean
.PHONY :	depend
.PHONY :	distclean
.PHONY :	install
.PHONY :	install.man
.PHONY :	libs
.PHONY :	mostlyclean
.PHONY :	realclean
.PHONY :	sources
.PHONY :	uninstall
.PHONY :	uninstall.man

all \
sources :	terminfo.5
depend :
tags :

$(DESTDIR)$(mandir) :
	mkdir -p $@

EDITARGS = $(DESTDIR)$(mandir) $(srcdir) terminfo.5 *-config.1 $(srcdir)/*.[0-9]*

install install.man : terminfo.5 $(DESTDIR)$(mandir)
	$(SHELL) ../edit_man.sh normal installing $(EDITARGS)

uninstall uninstall.man :
	-$(SHELL) ../edit_man.sh normal removing $(EDITARGS)

# We compose terminfo.5 from the real sources...
CAPLIST	= \
	$(srcdir)/../include/Caps \
	$(srcdir)/../include/Caps-ncurses
terminfo.5: $(srcdir)/terminfo.head \
		$(CAPLIST) \
		$(srcdir)/terminfo.tail \
		Makefile $(srcdir)/MKterminfo.sh
	$(SHELL) $(srcdir)/MKterminfo.sh $(srcdir)/terminfo.head $(CAPLIST) $(srcdir)/terminfo.tail >terminfo.5

mostlyclean :
	-rm -f core tags TAGS *~ *.bak *.ln *.atac trace

clean:	mostlyclean
	rm -f terminfo.5

../edit_man.sed : make_sed.sh
	$(SHELL) $(srcdir)/make_sed.sh /home/kim/Desktop/Code/ncurses/ncurses-6.4/man/man_db.renames >../edit_man.sed

distclean realclean: clean
	-rm -f Makefile *-config.1 ../edit_man.* ../man_alias.* man_db.renames
