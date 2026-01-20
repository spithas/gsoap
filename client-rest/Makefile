## Makefile ##

GSOAP_DIR = /projects/gsoap-2.8.54

all:	rest

rest:			stubs client

copyfiles:
		cp $(GSOAP_DIR)/gsoap/samples/xml-rpc-json/json.h .
		cp $(GSOAP_DIR)/gsoap/samples/xml-rpc-json/json.cpp .
		cp $(GSOAP_DIR)/gsoap/samples/xml-rpc-json/xml-rpc.h .
		cp $(GSOAP_DIR)/gsoap/samples/xml-rpc-json/xml-rpc-iters.h .
		cp $(GSOAP_DIR)/gsoap/samples/xml-rpc-json/xml-rpc.cpp .
		cp $(GSOAP_DIR)/gsoap/stdsoap2.h .
		cp $(GSOAP_DIR)/gsoap/stdsoap2.cpp .
stubs:
		$(GSOAP_DIR)/gsoap/src/soapcpp2 -CSL xml-rpc.h

client:	client-json-post.cpp
		c++ -DWITH_OPENSSL -DWITH_GZIP -o ../bin/client-json-post client-json-post.cpp xml-rpc.cpp json.cpp stdsoap2.cpp soapC.cpp -lcrypto -lssl -lz

clean:
		-rm -rf *.o soapC.cpp soapH.h soapStub.h soap.nsmap ../bin/client-json-post

.c.o:
			$(CC) $(CFLAG) -c $*.c

.cpp.o:
			$(CC) $(CFLAG) $(CPPFLAGS) -c $*.cpp
