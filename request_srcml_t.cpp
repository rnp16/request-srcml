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
        /*For a plain old file the entry_filename is the literal string "data" and you should use the local_filename*/
    {
        srcml_request request = { "", "test.cpp", "data", ""};
        assert(request_filename(request) == "test.cpp");
        assert(request_language(request, "") == "");
    }
    /*The filename can be explicitly given as an option and this supersedes all other filenames*/
    {
        srcml_request request = { "test.cpp", "test2.zip", "main.cpp", ""};
        assert(request_filename(request) == "test.cpp");
        assert(request_language(request, "") == "");
    }
    /*The language is based on the file extension. The function get_language_from_filename() is used for this.*/
    {
        srcml_request request = { "", "test.cpp", "data", ""};
        assert(request_filename(request) == "test.cpp");
        assert(request_language(request, "test.cpp") == "C++");
    }
    /*The language can be explicitly given as an option and this supersedes all other language settings*/
    {
        srcml_request request = {"", "test.cpp", "data", "C++"};
        assert(request_filename(request) == "test.cpp");
        assert(request_language(request, "test.cpp") == "C++");
    }

    return 0;
}
