    #include "film.hpp"
   
    //Constructeur par Default
    Film::Film(){
        id = -30;
    }

    //Constructeur d'init    
    Film::Film(string line){
        vector<string> tokenizedString = getTokens(line, L"‣");

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

        genres = stoGs(tokenizedString[12]);
    }

    //Constructeur de copievoid setIdGroupes(const Liste<int> &idG);
    Film::Film(const Film &e){
        *this = e;
    }

    //Deconstructeur
    Film::~Film(){

    }

    //Affiche un tuple de Film:
    void Film::Affiche(){
        cout << "ID = " << getId() << endl;
        cout << "Title = " << getTitle() << endl;
        cout << "OriginalTitle = " << getOriginalTitle() << endl;
        
        if(getRealeseDate().tm_year != -1){
            cout << "Time = " << getRealeseDate().tm_mday << "/" << getRealeseDate().tm_mon << "/" << getRealeseDate().tm_year <<endl;
        }
        
        cout << "Status = " << getStatus() << endl;
        cout << "VoteAverage = " << getVoteAverage() << endl;
        cout << "VoteCount = " << getVoteCount() << endl;
        cout << "RunTime = " << getRunTime() << endl;
        cout << "Certification = " << getCertification() << endl;
        cout << "PosterPath = " << getPosterPath() << endl;
        cout << "Budget = " << getBudget() << endl;
        cout << "Tag = " << getTag() << endl;

        for(int i = 0 ; i<getGenres().size() ; i++){
            cout << "Genre = " << getGenres()[i] << endl;
        }

        cout << endl << endl;
    }

    //OPPERATOR SURCHARGE
    //=
    Film& Film::operator=(const Film& t2){
        setId(t2.getId());
        setTitle(t2.getTitle());
        setOriginalTitle(t2.getOriginalTitle());
        setRealeseDate(t2.getRealeseDate());
        setStatus(t2.getStatus());
        setVoteAverage(t2.getVoteAverage());
        setVoteCount(t2.getVoteCount());
        setRunTime(t2.getRunTime());
        setCertification(t2.getCertification());
        setPosterPath(t2.getPosterPath());
        setBudget(t2.getBudget());
        setTag(t2.getTag());
        setGenres(t2.getGenres());

        return *this;
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
        
        if(tokens.size() != 0){
            try{
                Date.tm_mday = stoi(tokens[2]);
                Date.tm_mon = stoi(tokens[1]);
                Date.tm_year = stoi(tokens[0]);
            }
            catch(exception &err){
                throw "Error: DateFormatInvalid";
            }
        }
        else{
            Date.tm_year = -1;
        }
        
        return Date;
    }


    vector<Genre> Film::stoGs(string sgenre){
        bool test = false;
        vector<Genre> genres;

        vector<string> tmp;
        tmp = getTokens(sgenre, L"‖");

        for(int i = 0 ; i < tmp.size() ; i++){
            vector<string> tmp2;
            tmp2 = getTokens(tmp[i], L"․");

            try{ genres.push_back( Genre(stoi(tmp2[0]), tmp2[1])); test = true;} 
            catch(exception &err){ throw "Genre: Id is not an Int."; test = false;}
        }

        if(test == false) return genres;
        else return genres;
    }
    
    int Film::getId() const
    {
        return id;
    }
    
    void Film::setId(const int idP)
    {
        id = idP;   
    }
    
    string Film::getTitle() const
    {
        return title;
    }
    
    void Film::setTitle(const string s)
    {
        title = s;
    }
    
    string Film::getOriginalTitle() const
    {
        return originalTitle;
    }
    
    void Film::setOriginalTitle(const string s)
    {
        originalTitle = s;
    }
    
    tm Film::getRealeseDate() const
    {
        return releaseDate;
    }
    
    void Film::setRealeseDate(const tm d)
    {
        releaseDate = d;
    }
    
    string Film::getStatus() const
    {
        return status;
    }
    
    void Film::setStatus(const string s)
    {
        status = s;
    }
    
    double Film::getVoteAverage() const
    {
        return voteAverage;
    }
    
    void Film::setVoteAverage(const double d)
    {
        voteAverage = d;
    }
    
    int Film::getVoteCount() const
    {
        return voteCount;
    }
    
    void Film::setVoteCount(const int v)
    {
        voteCount = v;
    }
    
    int Film::getRunTime() const
    {
        return runTime;
    }
    
    void Film::setRunTime(const int run)
    {
        runTime = run;
    }
    
    string Film::getCertification() const
    {
        return certification;
    }
    
    void Film::setCertification(const string c)
    {
        certification = c;
    }
    
    string Film::getPosterPath() const
    {
        return posterPath;
    }
    
    void Film::setPosterPath(const string ppath)
    {
        posterPath = ppath;
    }
    
    double Film::getBudget() const
    {
        return budget;
    }
    
    void Film::setBudget(const double b)
    {
        budget = b;
    }
    
    string Film::getTag() const
    {
        return tag;
    }
    
    void Film::setTag(const string s)
    {
        tag = s;
    }
    
    vector<Genre> Film::getGenres() const
    {
        return genres;
    }
    
    void Film::setGenres(const vector<Genre> v)
    {
        genres = v;
    }