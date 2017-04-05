/*
  @file request_srcml_t.cpp

  Test program for request_srcml()
*/

#include "request_srcml.hpp"
#include <cassert>

int main() {

	// all filenames and languages empty
	//Initial Test
    {
    	srcml_request request = { "", "", "", ""};
    	assert(request_filename(request) == "");
    	assert(request_language(request, "") == "");
    }
	/*The local_filename is the name of the file on the disk. For a source-code archive the entry_filename is used instead*/
	{
     	srcml_request request = { "", "code.tar.gz", "test.cpp", ""};
     	assert(request_filename(request) == "test.cpp");
     	assert(request_language(request, "") == "");
     }

    return 0;
}
