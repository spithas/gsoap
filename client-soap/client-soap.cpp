#include "service.nsmap"
#include "soapserviceProxy.h"
#include <string.h>

int main()
{
    serviceProxy serv;
    std::string result;

    if (serv.toUpper("test string", result) == SOAP_OK)
    {
        printf("\nresult:(%s)\n", result.c_str());
    }
    else
    {
        serv.soap_stream_fault(std::cerr);
    }

    serv.destroy();

    return 0;
}
