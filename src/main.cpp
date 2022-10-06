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
    xml << "<!DOCTYPE Films [" <<endl;
    xml << "<!ELEMENT Films (Film*)>"<<endl;
    xml << "\t<!ELEMENT Film (Title, Time?, Status, Vote, RunTime, Certification, Budget, Tag, Genres, Directors, Actors)>"<<endl;
    xml << "\t\t<!ATTLIST Film Id CDATA #REQUIRED>"<<endl;
    xml << "\t\t<!ATTLIST Film PosterPath CDATA #REQUIRED>"<<endl;
    xml << "\t<!ELEMENT Title (#PCDATA)>"<<endl;
    xml << "\t\t<!ATTLIST Title OriginalTitle CDATA #REQUIRED>"<<endl;
    xml << "\t<!ELEMENT Time EMPTY>"<<endl;
    xml << "\t\t<!ATTLIST Time Day CDATA #REQUIRED>"<<endl;
	xml << "\t\t<!ATTLIST Time Month CDATA #REQUIRED>"<<endl;
    xml << "\t\t<!ATTLIST Time Year CDATA #REQUIRED>"<<endl;
    xml << "\t<!ELEMENT Status (#PCDATA)>"<<endl;
    xml << "\t<!ELEMENT Vote (#PCDATA)>"<<endl;
    xml << "\t\t<!ATTLIST Vote Count CDATA #REQUIRED>"<<endl;
    xml << "\t<!ELEMENT RunTime (#PCDATA)>"<<endl;
    xml << "\t<!ELEMENT Certification (#PCDATA)>"<<endl;
    xml << "\t<!ELEMENT Budget (#PCDATA)>"<<endl;
    xml << "\t<!ELEMENT Tag (#PCDATA)>"<<endl;
    xml << "\t<!ELEMENT Genres (Genre*)>"<<endl;
    xml << "\t\t<!ELEMENT Genre EMPTY>"<<endl;
    xml << "\t\t\t<!ATTLIST Genre Id CDATA #REQUIRED>" << endl;
    xml << "\t\t\t<!ATTLIST Genre Label CDATA #REQUIRED>" << endl;
    xml << "\t<!ELEMENT Directors (Director*)>\n\t\t<!ELEMENT Director EMPTY>" << endl;
    xml << "\t\t\t<!ATTLIST Director Id CDATA #REQUIRED>\n\t\t\t<!ATTLIST Director Name CDATA #REQUIRED>" << endl;
    xml << "\t<!ELEMENT Actors (Actor*)>\n\t\t<!ELEMENT Actor EMPTY>" << endl;
    xml << "\t\t\t<!ATTLIST Actor Id CDATA #REQUIRED>\n\t\t\t<!ATTLIST Actor ActName CDATA #REQUIRED>\n\t\t\t<!ATTLIST Actor CharName CDATA #REQUIRED>" << endl;
    xml << "]>" << endl;


	
		
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