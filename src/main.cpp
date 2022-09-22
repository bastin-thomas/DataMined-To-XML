#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

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
        Film tmp = Film(line);

        //Creation des premiers Tokens, récupérer en vecteur
        tokens = tmp.getTokens(line, L'‣');

        //Lecture des premiers Tokens, pour les distribués en Type Film
        for(int i = 0; i < tokens.size() ; i++){
            cout << tokens[i] << ",  ";
        }       

        cout << endl;
    }

    return 0;
}