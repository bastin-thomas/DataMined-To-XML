#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>

#include <vector>
#include <sstream>
#include "../../UtilityLib/utilitylib.hpp"


using namespace std;

class Director{
    protected:
        int id;
        string label;

    public:
        Director();

        Director(int ident, string lab);

        Director(string s);

        Director(const Director& e);

        int getId() const;
        void setId(int indent);

        string getLabel() const;
        void setLabel(const string& s);

        //=
        Director& operator=(const Director& e);

        //<<
        friend std::ostream& operator<<(std::ostream& s, const Director& t1);

        static vector<Director> stoDs(string sdirector);
};
#endif