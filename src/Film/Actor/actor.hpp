#ifndef ACTOR_H
#define ACTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>

#include <vector>
#include <sstream>
#include "../../UtilityLib/utilitylib.hpp"


using namespace std;

class Actor{
    protected:
        int id;
        string actname;
        string charname;

    public:
        Actor();

        Actor(int ident, string lab);

        Actor(string s);

        Actor(const Actor& e);

        int getId() const;
        void setId(int indent);

        string getActName() const;
        void setActName(const string& s);

        string getCharName() const;
        void setCharName(const string& s);

        //=
        Actor& operator=(const Actor& e);

        //<<
        friend std::ostream& operator<<(std::ostream& s, const Actor& t1);

        static vector<Actor> stoAs(string sActor);
};
#endif