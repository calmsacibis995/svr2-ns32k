################################################################################
#                         Copyright (c) 1985 AT&T                              #
#                           All Rights Reserved                                #
#                                                                              #
#                                                                              #
#          THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T                 #
#        The copyright notice above does not evidence any actual               #
#        or intended publication of such source code.                          #
################################################################################
#	@(#)dirname.sh	1.2
expr \
  ${1-.}'/' : '\(/\)[^/]*/$' \
  \| ${1-.}'/' : '\(.*[^/]\)//*[^/][^/]*//*$' \
  \| .
