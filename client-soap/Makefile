## Makefile ##

GSOAP_DIR = /projects/gsoap-2.8.54

all:	rest

rest:			stubs client

copyfiles:
		cp $(GSOAP_DIR)/gsoap/stdsoap2.h .
		cp $(GSOAP_DIR)/gsoap/stdsoap2.cpp .

stubs:
		$(GSOAP_DIR)/gsoap/wsdl/wsdl2h -o service.h service.wsdl
		$(GSOAP_DIR)/gsoap/src/soapcpp2 -j -CL -I$(GSOAP_DIR)/gsoap/import service.h

client: client-soap.cpp
		c++ -o ../bin/client-soap client-soap.cpp soapC.cpp soapserviceProxy.cpp stdsoap2.cpp

clean:
		-rm -rf *.o soapC.cpp soapH.h soapStub.h service.h service.nsmap soapservice* service.toUpper*.xml ../bin/client-soap

.c.o:
			$(CC) $(CFLAG) -c $*.c

.cpp.o:
			$(CC) $(CFLAG) $(CPPFLAGS) -c $*.cpp
