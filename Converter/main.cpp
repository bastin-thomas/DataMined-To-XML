#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <chrono>

#include "./Film/film.hpp"

using namespace std;

int main(){
    int lineCount = 1;
    string fileName;
    string XmlName;
    string line;
    ifstream csv;
    ofstream xml;
    vector<string> tokens;

    auto begin = std::chrono::high_resolution_clock::now();

    fileName = "../Input/";
    fileName += "1000movies.txt";

    XmlName = "../Output/";
    XmlName += "1000movies.xml";

    try{
        csv.open(fileName);
    }
    catch(const ifstream::failure& e){
        cerr << "Error, not be able to open/read the file";
    }

    try{
        xml.open(XmlName);
    }
    catch(const ofstream::failure& e){
        cerr << "Error, not be able to open/read the file";
    }

    xml << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\" ?>" << endl;
    xml << "<!DOCTYPE Films SYSTEM \"../Validation File/1000movies.dtd\">" <<endl;
	
		
    xml << "<Films>"<<endl;
    while(getline(csv, line)){
        Film tmp;
        try{
            tmp = Film(line);
            
            xml << tmp; //Insérer le film dans le fichier XML
        }
        catch(char const* e)
        {
            cerr << e << ", Line (" << lineCount << ")" << endl;
        }
        catch(...)
        {
            cerr << "Main.Error.Not Implemented Exception, Line(" << lineCount << ")" << endl;
        }

        lineCount++;
    }
    xml << "</Films>" << endl;
    
    
    xml.close();
    csv.close();

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);

    return 0;
}