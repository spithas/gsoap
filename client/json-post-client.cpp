#include "json.h"
#include <sstream>

struct Namespace namespaces[] = { {NULL, NULL} }; // no XML namespaces needed

int main(int argc, char **argv)
{
    //std::stringstream soap_error;

  if (argc >= 2) {
    // new context with JSON indentation formatting (same as XML indent)
    soap *ctx = soap_new1(SOAP_C_UTFSTRING | SOAP_XML_INDENT);

    // create a value for the GitHub API response
    value request(ctx), response(ctx);

    request = "[fdsfds]";

    // private repos require authentication (should check that we use HTTPS!)
    if (argc > 3)
    {
      ctx->userid = argv[2];
      ctx->passwd = argv[3];
    }

    // JSON REST call and show response if OK (returns SOAP_OK (0) or error code)
    if (json_call(ctx, argv[1], &request, &response)) {
      //soap_stream_fault(ctx, soap_error);
      printf("\nERROR(%ld):%s...",ctx->error, ctx->fault->faultstring);
      printf("\nERROR2(%s):%s...",soap_faultcode(ctx), soap_faultstring(ctx));
    } else {
      std::cout << "." << response << "." << response.size() << "." << std::endl;
      std::stringstream str_json;
      str_json << response;
      printf("\n1:%s.",str_json.str().c_str());
    }

    
    std::cout << "\n\nDone...\n";


    soap_destroy(ctx); // delete managed objects
    soap_end(ctx);     // delete managed data
    soap_free(ctx);    // delete context
  }
  return 0;
}