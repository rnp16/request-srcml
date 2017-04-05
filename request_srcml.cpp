/*
  @file request_srcml.cpp

  Implementation of request_srcml()
*/

#include <iostream>
#include "request_srcml.hpp"
#include "get_language_from_filename.hpp"

// extracts the filename to use from the request
std::string request_filename(const srcml_request& request) {

    // TODO: determine the proper filename from the request
    std::string filename;
    if(request.option_filename != "")
    {
        filename = request.option_filename;
        return filename;
    }

    if(request.entry_filename == "data")
    {
        if(request.local_filename == "-")
        {
            filename = "";
            return filename;
        }
        filename = request.local_filename;
        return filename;
    }
    else if(request.local_filename != "" && request.entry_filename != "")
    {
        filename = request.entry_filename;
	return filename;
    }
    else
        filename = "";

    return filename;
}

// extracts the language to use from the request, and the filename
std::string request_language(const srcml_request& request, const std::string& filename) {

    // TODO: determine the proper filename from the request
    std::string language;
    if(request.option_language == "")
    {
        language = get_language_from_filename(filename);
    }
    else
        language = request.option_language;

    return language;
}

// generates srcML based on the request
bool generate_srcml(const srcml_request& request) {

	std::string filename = request_filename(request);
	if (filename == "-") {
		std::err << "Need to declare a language" << "\n";
		return false;
	}
	std::string language = request_language(request, filename);
	
	if (language == "") {
		std::err << "This is not supported" << "\n";
		return false;
	}
	
	return true;

}
