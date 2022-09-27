#include "genre.hpp"

Genre::Genre(){
    setId(-1);
    setLabel("null");
}

Genre::Genre(int ident, string lab){
    setId(ident);
    setLabel(lab);
}

Genre::Genre(string s){
    vector<string> tmp;
    tmp = UtilityLib::getTokens(s, L"․");
    int count = tmp.size();

    if(count == 1){
        if(tmp[0].size() == 0){
            setId(-1);
            setLabel("");
        }
        else{
            try{ setId(stoi(tmp[0])); }
            catch(exception &err){ throw "Error: id is not an int"; }
            setLabel("");
        }
    }
    if(count == 2){
        try{ setId(stoi(tmp[0])); }
        catch(exception &err){ throw "Error: id is not an int"; }

        setLabel(tmp[1]);
    } 
}

Genre::Genre(const Genre& e){
    setId(e.getId());
    setLabel(e.getLabel());
}

int Genre::getId() const{
    return id;
}

void Genre::setId(int indent){
    id = indent;
}

string Genre::getLabel() const{
    return label;
}

void Genre::setLabel(const string& s){
    label = s;
}

//=
Genre& Genre::operator=(const Genre& e){
    *this = Genre(e);
    return *this;
}

//<<
std::ostream& operator<<(std::ostream& s, const Genre& t1){
    s << "<Genre Id=\""<<t1.getId()<<"\" Label=\""<<t1.getLabel()<<"\"/>";
    return s;
}




vector<Genre> Genre::stoGs(string sgenre){
    vector<Genre> genres;
    vector<string> tmp;

    tmp = UtilityLib::getTokens(sgenre, L"‖");

    if(tmp.size() != 0){
        for(int i = 0 ; i < tmp.size() ; i++){
            try{ genres.push_back( Genre(tmp[i])); }
            catch(const char * t){ throw t; }
            catch(...){ throw "Error: Not Implemented Exception."; }       
        }
    }
    else{
        if(sgenre.compare("") != 0){ 
            try{ genres.push_back( Genre(sgenre) ); }
            catch(const char * t){ throw t; }
            catch(...){ throw "Error: Not Implemented Exception."; }    
        }
    }

    return genres;
}