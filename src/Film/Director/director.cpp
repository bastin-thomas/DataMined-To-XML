#include "director.hpp"

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
    s << "<Director Id=\""<<t1.getId()<<"\" Name=\""<<t1.getLabel()<<"\"/>";
    return s;
}


vector<Director> Director::stoDs(string sdirector){
    vector<Director> directors;
    vector<string> tmp;

    tmp = UtilityLib::getTokens(sdirector, L"‖");

    for(int i=0 ; i<tmp.size() ; i++){
        try{
            directors.push_back(Director(tmp[i]));
        }
        catch(const char * t){
            throw t;
        }
        catch(...){
            throw "Error: Not Implemented Exception.";
        }
    }

    if(tmp.size() == 0 && sdirector.compare("") != 0){
        try{ directors.push_back(Director(sdirector)); }
        catch(const char * t){ throw t; }
        catch(...){ throw "Error: Not Implemented Exception."; }
    }

    return directors;
}