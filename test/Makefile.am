AM_CFLAGS = $(TEST_CFLAGS) -I../src -g
AM_CXXFLAGS = $(AM_CFLAGS)
LDADD = $(top_builddir)/src/libcalgtest.a libtestframework.a

if USE_VALGRIND
TESTS_ENVIRONMENT=./valgrind-wrapper
endif

TESTS =                          \
        test-avl-tree            

check_PROGRAMS = $(TESTS)
check_LIBRARIES = libtestframework.a

libtestframework_a_SOURCES=\


# test_cpp_SOURCES = test-cpp.cpp

EXTRA_DIST=valgrind-wrapper
