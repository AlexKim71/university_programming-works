#!/bin/sh
# $Id: run_tic.in,v 1.40 2022/07/16 19:37:03 tom Exp $
##############################################################################
# Copyright 2019-2020,2022 Thomas E. Dickey                                  #
# Copyright 2000-2012,2017 Free Software Foundation, Inc.                    #
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
# Author: Thomas E. Dickey 1996-on
#
# This script is used to install terminfo.src using tic.  We use a script
# because the path checking is too awkward to do in a makefile.
#
# Assumes:
#	The leaf directory names (lib, tabset, terminfo)
#
echo "** Building terminfo database, please wait..."
#
# The script is designed to be run from the misc/Makefile as
#	make install.data

: "${suffix:=}"
: "${DESTDIR:=}"
: "${prefix:=/home/kim/Desktop/Code/ncurses-install}"
: "${exec_prefix:=${prefix}}"
: "${bindir:=${exec_prefix}/bin}"
: "${top_srcdir:=..}"
: "${srcdir:=.}"
: "${datarootdir:=${prefix}/share}"
: "${datadir:=${datarootdir}}"
: "${TIC_PATH:=tic}"
: "${ticdir:=/home/kim/Desktop/Code/ncurses-install/share/terminfo}"
: "${source:=${top_srcdir}/misc/terminfo.src}"
: "${cross_compiling:=no}"
: "${ext_funcs:=1}"

test -z "${DESTDIR}" && DESTDIR=

# Allow tic to run either from the install-path, or from the build-directory.
# Do not do this if we appear to be cross-compiling.  In that case, we rely
# on the host's copy of tic to compile the terminfo database.
if test "x$cross_compiling" = "xno"
then
	if test -f ../progs/tic$suffix
	then
		case "$PATH" in
		\:*)
			PATH="../progs:../lib:${DESTDIR}$bindir$PATH"
			;;
		*)
			PATH="../progs:../lib:${DESTDIR}$bindir:$PATH"
			;;
		esac
		export PATH
		if test normal = shared
		then
			SHLIB="sh $srcdir/shlib"
			TIC_PATH="$SHLIB tic"
		else
			TIC_PATH="tic"
		fi
	elif test "$TIC_PATH" = unknown
	then
		echo "? no tic program found"
		exit 1
	fi
else
	# Cross-compiling, so don't set PATH or run shlib.
	SHLIB=
	# reset $suffix, since it applies to the target, not the build platform.
	suffix=
fi


# set another env var that doesn't get reset when `shlib' runs, so `shlib' uses
# the PATH we just set.
SHLIB_PATH=$PATH
export SHLIB_PATH

# set a variable to simplify environment update in shlib
SHLIB_HOST=linux-gnu
export SHLIB_HOST

# don't use user's TERMINFO variable
unset TERMINFO_DIRS
TERMINFO="${DESTDIR}$ticdir" ; export TERMINFO
umask 022

# Construct the name of the old (obsolete) pathname, e.g., /usr/lib/terminfo.
TICDIR=`echo "$TERMINFO" | sed -e 's%/share/\([^/]*\)$%/lib/\1%'`

# Parent directory may not exist, which would confuse the install for hashed
# database.  Fix.
PARENT=`echo "$TERMINFO" | sed -e 's%/[^/]*$%%'`
if test -n "$PARENT"
then
	mkdir -p "$PARENT"
fi

# Remove the old terminfo stuff; we don't care if it existed before, and it
# would generate a lot of confusing error messages if we tried to overwrite it.
# We explicitly remove its contents rather than the directory itself, in case
# the directory is actually a symbolic link.
if test -d "$TERMINFO"
then
	( cd "$TERMINFO" && rm -fr ./? 2>/dev/null )
elif test -f "$TERMINFO.db"
then
	( rm -f "$TERMINFO.db" 2>/dev/null )
fi

if test "$ext_funcs" = 1 ; then
cat <<EOF
Running $TIC_PATH to install $TERMINFO ...

	You may see messages regarding extended capabilities, e.g., AX.
	These are extended terminal capabilities which are compiled
	using
		tic -x
	If you have ncurses 4.2 applications, you should read the INSTALL
	document, and install the terminfo without the -x option.

EOF
$TIC_PATH -V
if ( $TIC_PATH -x -s -o "$TERMINFO" $source )
then
	echo "** built new $TERMINFO"
else
	echo "? tic could not build $TERMINFO"
	exit 1
fi
else
cat <<EOF
Running $TIC_PATH to install $TERMINFO ...

	You may see messages regarding unknown capabilities, e.g., AX.
	These are extended terminal capabilities which may be compiled
	using
		tic -x
	If you have ncurses 4.2 applications, you should read the INSTALL
	document, and install the terminfo without the -x option.

EOF
$TIC_PATH -V
if ( $TIC_PATH -s -o "$TERMINFO" $source )
then
	echo "** built new $TERMINFO"
else
	echo "? tic could not build $TERMINFO"
	exit 1
fi
fi

# Make a symbolic link to provide compatibility with applications that expect
# to find terminfo under /usr/lib.  That is, we'll _try_ to do that.  Not
# all systems support symbolic links, and those that do provide a variety
# of options for 'test'.
if test "$TICDIR" != "$TERMINFO" ; then
	( rm -f "$TICDIR" 2>/dev/null )
	if ( cd "$TICDIR" 2>/dev/null )
	then
		cd "$TICDIR" || exit
		TICDIR=`pwd`
		if test "$TICDIR " != "$TERMINFO "; then
			# Well, we tried.  Some systems lie to us, so the
			# installer will have to double-check.
			echo "Verify if $TICDIR and $TERMINFO are the same."
			echo "The new terminfo is in $TERMINFO; the other should be a link to it."
			echo "Otherwise, remove $TICDIR and link it to $TERMINFO."
		fi
	else
		cd ${DESTDIR}$prefix || exit
		# Construct a symbolic link that only assumes $ticdir has the
		# same $prefix as the other installed directories.
		RELATIVE=`echo $ticdir|sed -e 's%^'$prefix'/%%'`
		if test "$RELATIVE" != "$ticdir" ; then
			RELATIVE=../`echo $ticdir|sed -e 's%^'$prefix'/%%' -e 's%^/%%'`
		fi
		if ( ln -s -f "$RELATIVE" "$TICDIR" )
		then
			echo "** sym-linked $TICDIR for compatibility"
		else
			echo "** could not sym-link $TICDIR for compatibility"
		fi
	fi
fi
# vile:shmode
