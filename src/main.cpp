#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "./Film/film.hpp"

using namespace std;

int main(){
    string fileName;
    string line;
    ifstream csv;
    vector<string> tokens;

    fileName = "../File/";
    fileName += "1000movies.txt";

    try{
        csv.open(fileName);
    }
    catch(const ifstream::failure& e){
        cout << "Error, not be able to open/read the file";
    }
    

    while(getline(csv, line)){
        Film tmp;
        try{
            tmp = Film(line);
        }
        catch(char const* e)
        {
            cout << e << endl;
        }
        catch(...)
        {
            cout << "Not Implemented Exception"<<endl;
        }
        
        tmp.Affiche();
    }
    return 0;
}