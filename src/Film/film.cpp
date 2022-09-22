    #include "film.h"
   
    //Constructeur par Default
    Film::Film(){

    }

    //Constructeur d'init
    Film::Film(int id){

    }
    
    Film::Film(string line){

    }

    //Constructeur de copievoid setIdGroupes(const Liste<int> &idG);
    Film::Film(const Film &e){

    }

    //Deconstructeur
    Film::~Film(){

    }

    //Getters Setters
    int Film::getId() const{
        return id;
    }

    void Film::setId(const int idP){
        id = idP;
    }

    //Affiche un tuple de Film:
    void Film::Affiche(){

    }

    //OPPERATOR SURCHARGE
    //=
    Film& Film::operator=(const Film& t2){
        Film s = Film(t2);
        return s;
    }

    //== 
    bool operator==(const Film& t1, const Film& t2){
        return false;
    }
    
    //< 
    bool operator<(const Film& t1, const Film& t2){
        return false;
    }

    //>
    bool operator>(const Film& t1, const Film& t2){
        return false;
    }

    //<<
    std::ostream& operator<<(std::ostream& s, const Film& t1){
        s << "";
        return s;
    }


    vector<string> Film::getTokens(string line, const wchar_t sep){
        vector<string> tokens;
        wstring temp;

        //Convert string to wstring
        wstringstream wss(wstring_convert<codecvt_utf8<wchar_t>>().from_bytes(line));

        while(getline(wss, temp, sep)){
            //1rst convert wstring to string
            //2nd add to the tokens list
            tokens.push_back(wstring_convert<codecvt_utf8<wchar_t>>().to_bytes(temp));
        }

        return tokens;
    }

    /*
    //Flux Gestion Fichier:
    void Save(ofstream& fichier) const;    //Save Objet in Fichier
    void Load(ifstream& fichier);          //Load Objet from Fichier 
    */