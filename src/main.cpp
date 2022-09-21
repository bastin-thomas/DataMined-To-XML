#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <list>

using namespace std;

int main(){
    string fileName;
    string line;
    
    ifstream csv;

    fileName = "../File/";
    fileName += "test.csv";

    csv.open(fileName);

    while(csv >> line){
        cout << line << endl;
    }

    return 0;
}