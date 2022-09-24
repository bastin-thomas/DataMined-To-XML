#include "Director.hpp"

Director::Director(){
    setId(-1);
    setLabel("null");
}

Director::Director(int ident, string lab){
    setId(ident);
    setLabel(lab);
}

Director::Director(string s){
    vector<string> tmp;
    tmp = Film::getTokens(s, L"․");

    try{ setId(stoi(tmp[0])); }
    catch(exception &err){ throw "Error: id is not an int"; }

    setLabel(tmp[1]);    
}

Director::Director(const Director& e){
    setId(e.getId());
    setLabel(e.getLabel());
}

int Director::getId() const{
    return id;
}

void Director::setId(int indent){
    id = indent;
}

string Director::getLabel() const{
    return label;
}

void Director::setLabel(const string& s){
    label = s;
}

//=
Director& Director::operator=(const Director& e){
    *this = Director(e);
    return *this;
}

//<<
std::ostream& operator<<(std::ostream& s, const Director& t1){
    s << "Director( id=" << t1.getId() << ", Name=" << t1.getLabel() << " )";
    return s;
}