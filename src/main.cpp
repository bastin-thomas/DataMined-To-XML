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

    csv.open(fileName);

    while(getline(csv, line)){
        Film tmp;
        tmp = Film(line);
    }
    return 0;
}