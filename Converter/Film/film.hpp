#ifndef FILM_H
#define FILM_H

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>

#include <sstream>
#include <wchar.h>
#include <codecvt>
#include <locale>
#include <vector>
#include <ctime>

#include "../UtilityLib/utilitylib.hpp"
#include "./Genre/genre.hpp"
#include "./Director/director.hpp"
#include "./Actor/actor.hpp"

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

        vector<Genre> genres;
        vector<Director> directors;
        vector<Actor> actors; //Actor: id, name, character

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

    //Affiche un tuple de Film:
    void Affiche();

    //OPPERATOR SURCHARGE
    //=
    Film& operator=(const Film& t2);

    //<<
    friend std::ostream& operator<<(std::ostream& s, const Film& t1);

    /*
    //Flux Gestion Fichier:
    void Save(ofstream& fichier) const;    //Save Objet in Fichier
    void Load(ifstream& fichier);          //Load Objet from Fichier 
    */


    //Getters/Setters:
    int getId() const;
    void setId(const int idP);

    string getTitle() const;
    void setTitle(const string s);

    string getOriginalTitle() const;
    void setOriginalTitle(const string s);

    tm getRealeseDate() const;
    void setRealeseDate(const tm d);
    
    string getStatus() const;
    void setStatus(const string s);

    double getVoteAverage() const;
    void setVoteAverage(const double d);
    
    int getVoteCount() const;
    void setVoteCount(const int v);

    int getRunTime() const;
    void setRunTime(const int run);
    
    string getCertification() const;
    void setCertification(const string c);
    
    string getPosterPath() const;
    void setPosterPath(const string ppath);
    
    double getBudget() const;
    void setBudget(const double b);

    string getTag() const;
    void setTag(const string s);
        
    vector<Genre> getGenres() const;
    void setGenres(const vector<Genre> v);

    vector<Director> getDirectors() const;
    void setDirectors(const vector<Director> d);

    vector<Actor> getActors() const;
    void setActors(const vector<Actor> a);
};
#endif