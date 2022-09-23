#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <list>
#include <vector>
#include <bits/stdc++.h>
#include <wchar.h>
#include <codecvt>
#include <locale>
#include "./Film/film.h"

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