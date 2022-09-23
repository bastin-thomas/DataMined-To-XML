#ifndef FILM_H
#define FILM_H

#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <wchar.h>
#include <codecvt>
#include <locale>
#include <vector>
#include <ctime>

using namespace std;

class Film {
    private:
        int id;
        string title;
        string originalTitle;
        tm releaseDate;
        
        string status;
        double voteAverage;
        int voteCount;
        int runTime;
        string certification;
        
        string posterPath;
        double budget;
        
        string tag;
        
        // vector<Genre> genres; // Genre: id, name
        // vector<Director> directors; // Director: id, name
        // vector<Actor> actors; //Actor: id, name, character

    public:
    //Constructeur par Default
    Film();

    //Constructeur d'init
    Film(int id);
    
    Film(string line);

    //Constructeur de copievoid setIdGroupes(const Liste<int> &idG);
    Film(const Film &e);

    //Deconstructeur
    ~Film();

    //Getters Setters
    int getId() const;

    void setId(const int idP);

    //Affiche un tuple de Film:
    void Affiche();

    //OPPERATOR SURCHARGE
    //=
    Film& operator=(const Film& t2);

    //== 
    friend bool operator==(const Film& t1, const Film& t2);

    //< 
    friend bool operator<(const Film& t1, const Film& t2);

    //>
    friend bool operator>(const Film& t1, const Film& t2);

    //<<
    friend std::ostream& operator<<(std::ostream& s, const Film& t1);

    /*
    //Flux Gestion Fichier:
    void Save(ofstream& fichier) const;    //Save Objet in Fichier
    void Load(ifstream& fichier);          //Load Objet from Fichier 
    */

    static vector<string> getTokens(string line, const wchar_t * sep);

    static tm stodate(string sdate);

    static vector<string> stoTags(string stags);

};


#endif