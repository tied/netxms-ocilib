DRIVER = baystack

pkglib_LTLIBRARIES = baystack.la
baystack_la_SOURCES = baystack.cpp
baystack_la_CPPFLAGS=-I@top_srcdir@/include -I@top_srcdir@/src/server/include
baystack_la_LDFLAGS = -module -avoid-version
baystack_la_LIBADD = ../lib/avaya-ers/libavaya-ers.la ../../libnxsrv/libnxsrv.la \
                     ../../../snmp/libnxsnmp/libnxsnmp.la ../../../libnetxms/libnetxms.la

EXTRA_DIST = \
	baystack.vcproj \
	baystack.h \
	Makefile.w32

install-exec-hook:
	if test "x`uname -s`" = "xAIX" ; then OBJECT_MODE=@OBJECT_MODE@ $(AR) x $(DESTDIR)$(pkglibdir)/$(DRIVER).a $(DESTDIR)$(pkglibdir)/$(DRIVER)@SHLIB_SUFFIX@ ; rm -f $(DESTDIR)$(pkglibdir)/$(DRIVER).a ; fi
	mkdir -p $(DESTDIR)$(pkglibdir)/ndd
	mv -f $(DESTDIR)$(pkglibdir)/$(DRIVER)@SHLIB_SUFFIX@ $(DESTDIR)$(pkglibdir)/ndd/$(DRIVER).ndd
	rm -f $(DESTDIR)$(pkglibdir)/$(DRIVER).la
