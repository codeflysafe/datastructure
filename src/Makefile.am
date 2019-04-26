check_LIBRARIES=libcalgtest.a
lib_LTLIBRARIES=libcalg.la

MAIN_HEADERFILES = include/common.h

CALG_HEADERFILES=\
include/array_list.h  include/avl_tree.h      include/b_tree.h      include/binary_search_tree.h  include/binary_tree.h         \
include/dequeue.h  include/double_linked_list.h  include/linked_list.h        include/queue.h       \
include/skip_list.h      include/stack.h   include/string.h   include/tree.h       

SRC=\
array_list.c  avl_tree.c      b_tree.c      binary_search_tree.c  binary_tree.c         \
common.c   dequeue.c  double_linked_list.c  linked_list.c        queue.c       \
skip_list.c      stack.c   string.c   tree.c  

libcalgtest_a_CFLAGS=$(TEST_CFLAGS) -DALLOC_TESTING -I../test -g
libcalgtest_a_SOURCES=$(SRC) $(MAIN_HEADERFILES)

libcalg_la_CFLAGS=$(MAIN_CFLAGS)
libcalg_la_SOURCES=$(SRC) $(MAIN_HEADERFILES) $(CALG_HEADERFILES)

headerfilesdir=$(includedir)/libcalg-1.0
headerfiles_HEADERS=$(MAIN_HEADERFILES)

calgheaderfilesdir=$(headerfilesdir)/libcalg
calgheaderfiles_HEADERS=$(CALG_HEADERFILES)

EXTRA_DIST=gencov
