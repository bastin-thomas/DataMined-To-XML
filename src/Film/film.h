#ifndef FILM_H
#define FILM_H

#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;

class Film {
    private:
        int id;

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

};


#endif