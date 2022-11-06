#include "utilitylib.hpp"

    //Utility Functions
    vector<string> UtilityLib::getTokens(string line, const wchar_t * sep){
        vector<string> tokens;
        wstring temp;

        //Convert string to wstring
        wstringstream wss(wstring_convert<codecvt_utf8<wchar_t>>().from_bytes(line));

        while(getline(wss, temp, *sep)){
            //1rst convert wstring to string
            //2nd add to the tokens list
            tokens.push_back(wstring_convert<codecvt_utf8<wchar_t>>().to_bytes(temp));
        }

        return tokens;
    }

    

//Take a String and construct a time_t Date
    tm UtilityLib::stodate(string sdate)
    {
        tm Date;
        vector<string> tokens;
        tokens = UtilityLib::getTokens(sdate, L"-");
        
        if(tokens.size() != 0){
            try{
                Date.tm_mday = stoi(tokens[2]);
                Date.tm_mon = stoi(tokens[1]);
                Date.tm_year = stoi(tokens[0]);
            }
            catch(exception &err){
                throw "Error: DateFormatInvalid";
            }
        }
        else{
            Date.tm_year = -1;
        }
        
        return Date;
    }



void UtilityLib::replace_all( string& s, string const& toReplace, string const& replaceWith) 
{
    bool hasmodified = false;

    if (toReplace.empty()) {
        return;
    }

    for (size_t pos = 0; (pos = s.find(toReplace, pos)) != string::npos;) {
        s.replace(pos, toReplace.length(), replaceWith);
        pos += replaceWith.length();
        hasmodified = true;
    }
}