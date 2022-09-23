#ifndef GENRE_H
#define GENRE_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Genre{
    protected:
        int id;
        string label;

    public:
        Genre(int ident, string lab){
            id = ident;
            label = lab;
        }

        int getId() const;
        void setId(int indent);

        string getLabel() const;
        void setLabel(const string& s);


        //=
        Genre& operator=(const Genre& t2);

        //<<
        friend std::ostream& operator<<(std::ostream& s, const Genre& t1);
};
#endif