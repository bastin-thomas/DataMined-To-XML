#ifndef UTILITYLIB_HPP
#define UTILITYLIB_HPP


#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>
#include <fstream>

#include <sstream>
#include <wchar.h>
#include <codecvt>
#include <locale>
#include <vector>
#include <ctime>

using namespace std;

class UtilityLib{
        
    public:
        static vector<string> getTokens(string line, const wchar_t * sep);

        static tm stodate(string sdate);

        static vector<string> stoTags(string stags);

        static void replace_all( std::string& s, std::string const& toReplace, std::string const& replaceWith);
};
#endif // !UTILITYLIB_HPP