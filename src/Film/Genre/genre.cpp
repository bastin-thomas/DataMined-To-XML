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
    tmp = Film::getTokens(s, L"․");

    try{ setId(stoi(tmp[0])); }
    catch(exception &err){ throw "Error: id is not an int"; }

    setLabel(tmp[1]);    
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
    s << "Genre( id=" << t1.getId() << ", label=" << t1.getLabel() << " )";
    return s;
}