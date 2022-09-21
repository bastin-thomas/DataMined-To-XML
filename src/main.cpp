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

vector<string> getTokens(string line);


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

        //Creation des premiers Tokens, récupérer en vecteur
        tokens = getTokens(line);

        //Lecture des premiers Tokens, pour les distribués en Type Film
        for(int i = 0; i < tokens.size() ; i++){
            cout << tokens[i] << ",  ";
        }

                

        cout << endl;
    }

    return 0;
}

vector<string> getTokens(string line){
    vector<string> tokens;
    wstring temp;

    //Convert string to wstring
    wstringstream wss(wstring_convert<codecvt_utf8<wchar_t>>().from_bytes(line));

    while(getline(wss, temp, L'‣')){
        //1rst convert wstring to string
        //2nd add to the tokens list
        tokens.push_back(wstring_convert<codecvt_utf8<wchar_t>>().to_bytes(temp));
    }

    return tokens;
}