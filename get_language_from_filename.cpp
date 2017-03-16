/*
  @file get_language_from_filename.cpp

  Implementation of get_language_from_filename()
*/

#include "get_language_from_filename.hpp"
#include <map>
#include <string>

namespace {

    // from extension extract language
    const std::map<std::string, std::string> ext2lang = {

        { ".c", "C" },
        { ".h", "C" },
        { ".i", "C" },
        { ".cpp", "C++" },
        { ".CPP", "C++" },
        { ".cp", "C++" },
        { ".hpp", "C++" },
        { ".cxx", "C++" },
        { ".hxx", "C++" },
        { ".cc", "C++" },
        { ".hh", "C++" },
        { ".c++", "C++" },
        { ".h++", "C++" },
        { ".C", "C++" },
        { ".H", "C++" },
        { ".tcc", "C++" },
        { ".ii", "C++" },
        { ".java", "Java" },
        { ".aj", "AspectJ" },
        { ".cs", "C#" },
    };
}

// The language from the extension of the given file
// returns an empty string if no associated language
std::string get_language_from_filename(const std::string& filename) {

    // find the last extension (including the '.')
    int pos = filename.rfind('.');
    if (pos == std::string::npos)
        return "";
    std::string extension = filename.substr(pos);

    // the language for that extension, or empty string if no associated language
    return ext2lang.find(extension) != ext2lang.end() ? ext2lang.find(extension)->second : "";
}
