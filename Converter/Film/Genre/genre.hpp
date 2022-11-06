#ifndef GENRE_H
#define GENRE_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>

#include <vector>
#include <sstream>

#include "../../UtilityLib/utilitylib.hpp"


using namespace std;

class Genre{
    protected:
        int id;
        string label;

    public:
        Genre();

        Genre(int ident, string lab);

        Genre(string s);

        Genre(const Genre& e);

        int getId() const;
        void setId(int indent);

        string getLabel() const;
        void setLabel(const string& s);

        //=
        Genre& operator=(const Genre& e);

        //<<
        friend std::ostream& operator<<(std::ostream& s, const Genre& t1);

        static vector<Genre> stoGs(string sgenre);
};
#endif