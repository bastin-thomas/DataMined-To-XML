    #include "film.hpp"
   
    //Constructeur par Default
    Film::Film(){
        id = -30;
    }

    //Constructeur d'init    
    Film::Film(string line){
        vector<string> tokenizedString = getTokens(line, L"+");

        try{ id = stoi(tokenizedString[0]); }
        catch(exception &err){ throw "Error: id not an Int"; }

        title = tokenizedString[1];
        originalTitle = tokenizedString[2];
        releaseDate = stodate(tokenizedString[3]);
        status = tokenizedString[4];

        try{ voteAverage = stod(tokenizedString[5]); } 
        catch(exception &err){ throw "Error: voteAverage not a Double."; }
        
        try{ voteCount = stoi(tokenizedString[6]); }
        catch(exception &err){ throw "Error: voteCount not an Int.";}

        try{ runTime = stoi(tokenizedString[7]); }
        catch(exception &err){ throw "Error: runTime not an Int.";}

        certification = tokenizedString[8];
        posterPath = tokenizedString[9];

        try{ budget = stod(tokenizedString[10]); } 
        catch(exception &err){ throw "Error: budget not a Double."; }

        tag = tokenizedString[11];

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



    //Utility Functions
    vector<string> Film::getTokens(string line, const wchar_t * sep){
        vector<string> tokens;
        wstring temp;

        //Convert string to wstring
        wstringstream wss(wstring_convert<codecvt_utf8<wchar_t>>().from_bytes(line));

        while(getline(wss, temp, *sep)){
            //1rst convert wstring to string
            //2nd add to the tokens list
            tokens.push_back(wstring_convert<codecvt_utf8<wchar_t>>().to_bytes(temp));
        }

        return tokens;
    }

    //Take a String and construct a time_t Date
    tm Film::stodate(string sdate)
    {
        tm Date;
        vector<string> tokens;
        tokens = getTokens(sdate, L"-");
        
        try{
            Date.tm_mday = stoi(tokens[2]);
            Date.tm_mon = stoi(tokens[1]);
            Date.tm_year = stoi(tokens[0]);
        }
        catch(exception &err){
            throw "Error: DateFormatInvalid";
        }
        
        return Date;
    }





    /*
    //Flux Gestion Fichier:
    void Save(ofstream& fichier) const;    //Save Objet in Fichier
    void Load(ifstream& fichier);          //Load Objet from Fichier 
    */