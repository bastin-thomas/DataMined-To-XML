    #include "film.hpp"
   
    //Constructeur par Default
    Film::Film(){
        id = -30;
    }

    //Constructeur d'init    
    Film::Film(string line){
        vector<string> tokenizedString = UtilityLib::getTokens(line, L"‣");

        try{ id = stoi(tokenizedString[0]); }
        catch(exception &err){ throw "Error: id not an Int"; }

        title = tokenizedString[1];
        originalTitle = tokenizedString[2];
        releaseDate = UtilityLib::stodate(tokenizedString[3]);
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

        genres = Genre::stoGs(tokenizedString[12]);

        directors = Director::stoDs(tokenizedString[13]);

        actors = Actor::stoAs(tokenizedString[14]);
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
        cout << *this << endl;
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
        setDirectors(t2.getDirectors());
        setActors(t2.getActors());
        return *this;
    }


    //<<
    std::ostream& operator<<(std::ostream& s, const Film& e){
        if(e.getId() == -1){
            return s;
        }
        s << "<Film Id=\"" << e.getId() << "\" PosterPath=\"" << e.getPosterPath() << "\" >" << endl;
        
        s << "\t<Title OriginalTitle=\""<<e.getOriginalTitle()<<"\" >" << e.getTitle() << "</Title>"<< endl;

        if(e.getRealeseDate().tm_year != -1){
            s << "\t<Time Day=\"" << e.getRealeseDate().tm_mday <<"\" Month=\""<< e.getRealeseDate().tm_mon<<"\" Year=\""<< e.getRealeseDate().tm_year <<"\"/>"<<endl;
        }
        
        s << "\t<Status>" << e.getStatus() << "</Status>" << endl;
        
        if(e.getVoteCount() != 0 ){
            s << "\t<Vote Count=\"" << e.getVoteCount() << "\">" << e.getVoteAverage() << "</Vote>" << endl;
        }
        else{
            s << "\t<Vote Count=\"\"></Vote>" << endl;
        }
        
        s << "\t<RunTime>" << e.getRunTime() << "</RunTime>" << endl;
        
        s << "\t<Certification>" << e.getCertification() << "</Certification>" << endl;
        
        if(e.getBudget()>0.1){
            s << "\t<Budget>" << e.getBudget() << "</Budget>" << endl;
        }
        else{
            s << "\t<Budget></Budget>" << endl;
        }

        s << "\t<Tag>" << e.getTag() << "</Tag>" << endl;

        s << "\t<Genres>"<<endl;
        for(int i = 0 ; i<e.getGenres().size() ; i++){
            s <<"\t\t"<< e.getGenres()[i] << endl;
        }
        s << "\t</Genres>"<<endl;

        s << "\t<Directors>"<<endl;
        for(int i = 0 ; i<e.getDirectors().size() ; i++){
            s <<"\t\t"<< e.getDirectors()[i] << endl;
        }
        s << "\t</Directors>"<<endl;

        s << "\t<Actors>"<<endl;
        for(int i = 0 ; i<e.getActors().size() ; i++){
            s <<"\t\t"<< e.getActors()[i] << endl;
        }
        s << "\t</Actors>"<<endl;

        s << "</Film>" << endl;
        return s;
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
    
    vector<Director> Film::getDirectors() const
    {
        return directors;
    }
    
    void Film::setDirectors(const vector<Director> d)
    {
        directors = d;
    }
    
    vector<Actor> Film::getActors() const
    {
        return actors;
    }
    
    void Film::setActors(const vector<Actor> a)
    {
        actors = a;
    }


