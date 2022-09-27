#include "actor.hpp"

Actor::Actor(){
    setId(-1);
    setActName("null");
}

Actor::Actor(int ident, string lab){
    setId(ident);
    setActName(lab);
}

Actor::Actor(string s){
    vector<string> tmp;
    tmp = UtilityLib::getTokens(s, L"․");

    try{ setId(stoi(tmp[0])); }
    catch(exception &err){ throw "Error: id is not an int"; }
    setActName(tmp[1]);    
    setCharName(tmp[2]);
}

Actor::Actor(const Actor& e){
    setId(e.getId());
    setActName(e.getActName());
    setCharName(e.getCharName());
}

int Actor::getId() const{
    return id;
}

void Actor::setId(int indent){
    id = indent;
}

string Actor::getActName() const{
    return actname;
}

void Actor::setActName(const string& s){
    actname = s;
}

string Actor::getCharName() const{
    return charname;
}

void Actor::setCharName(const string& s){
    charname = s;
}

//=
Actor& Actor::operator=(const Actor& e){
    *this = Actor(e);
    return *this;
}

//<<
std::ostream& operator<<(std::ostream& s, const Actor& t1){
    s << "Actor( id=" << t1.getId() << ", Name=" << t1.getActName() <<", CharName=" << t1.getCharName() << " )";
    return s;
}


vector<Actor> Actor::stoAs(string sActor){
    vector<Actor> Actors;
    vector<string> tmp;

    tmp = UtilityLib::getTokens(sActor, L"‖");

    for(int i=0 ; i<tmp.size() ; i++){
        try{
            Actors.push_back(Actor(tmp[i]));
        }
        catch(const char * t){
            throw t;
        }
        catch(...){
            throw "Error: Not Implemented Exception.";
        }
    }

    if(tmp.size() == 0 && sActor.compare("") != 0){
        try{ Actors.push_back(Actor(sActor)); }
        catch(const char * t){ throw t; }
        catch(...){ throw "Error: Not Implemented Exception."; }
    }

    return Actors;
}