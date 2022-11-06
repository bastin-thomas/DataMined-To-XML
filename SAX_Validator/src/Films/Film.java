/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Films;

import java.util.Collection;
import java.util.Iterator;
import java.util.Vector;

/**
 *
 * @author student
 */
public class Film implements Comparable<Film>, Cloneable {

    /**
     * @return the OriginalTitle
     */
    public String getOriginalTitle() {
        return OriginalTitle;
    }

    /**
     * @param OriginalTitle the OriginalTitle to set
     */
    public void setOriginalTitle(String OriginalTitle) {
        this.OriginalTitle = OriginalTitle;
    }

    /**
     * @return the Id
     */
    public int getId() {
        return Id;
    }

    /**
     * @param Id the Id to set
     */
    public void setId(int Id) {
        this.Id = Id;
    }

    /**
     * @return the Title
     */
    public String getTitle() {
        return Title;
    }

    /**
     * @param Title the Title to set
     */
    public void setTitle(String Title) {
        this.Title = Title;
    }

    /**
     * @return the Path
     */
    public String getPath() {
        return Path;
    }

    /**
     * @param Path the Path to set
     */
    public void setPath(String Path) {
        this.Path = Path;
    }

    /**
     * @return the Date
     */
    public String getDate() {
        return Date;
    }

    /**
     * @param Date the Date to set
     */
    public void setDate(String Date) {
        this.Date = Date;
    }

    /**
     * @return the Status
     */
    public String getStatus() {
        return Status;
    }

    /**
     * @param Status the Status to set
     */
    public void setStatus(String Status) {
        this.Status = Status;
    }

    /**
     * @return the VoteCount
     */
    public int getVoteCount() {
        return VoteCount;
    }

    /**
     * @param VoteCount the VoteCount to set
     */
    public void setVoteCount(int VoteCount) {
        this.VoteCount = VoteCount;
    }

    /**
     * @return the VoteAverage
     */
    public float getVoteAverage() {
        return VoteAverage;
    }

    /**
     * @param VoteAverage the VoteAverage to set
     */
    public void setVoteAverage(float VoteAverage) {
        this.VoteAverage = VoteAverage;
    }

    /**
     * @return the RunTime
     */
    public int getRunTime() {
        return RunTime;
    }

    /**
     * @param RunTime the RunTime to set
     */
    public void setRunTime(int RunTime) {
        this.RunTime = RunTime;
    }

    /**
     * @return the Certif
     */
    public String getCertif() {
        return Certif;
    }

    /**
     * @param Certif the Certif to set
     */
    public void setCertif(String Certif) {
        this.Certif = Certif;
    }

    /**
     * @return the Budget
     */
    public int getBudget() {
        return Budget;
    }

    /**
     * @param Budget the Budget to set
     */
    public void setBudget(int Budget) {
        this.Budget = Budget;
    }

    /**
     * @return the Summary
     */
    public String getSummary() {
        return Summary;
    }

    /**
     * @param Summary the Summary to set
     */
    public void setSummary(String Summary) {
        this.Summary = Summary;
    }

    /**
     * @return the Genres
     */
    public Vector<Genre> getGenres() {
        return Genres;
    }

    /**
     * @param Genres the Genres to set
     */
    public void setGenres(Vector<Genre> Genres) {
        this.Genres = Genres;
    }

    /**
     * @return the Directors
     */
    public Vector<Director> getDirectors() {
        return Directors;
    }

    /**
     * @param Directors the Directors to set
     */
    public void setDirectors(Vector<Director> Directors) {
        this.Directors = Directors;
    }

    /**
     * @return the Actors
     */
    public Vector<Actor> getActors() {
        return Actors;
    }

    /**
     * @param Actors the Actors to set
     */
    public void setActors(Vector<Actor> Actors) {
        this.Actors = Actors;
    }

    public Film(int Id, String path) {
        this.Id = Id;
        this.setPath(path);
    }

    public Film() {
        Id = -1;
    }
    
     @Override
    public Object clone() throws CloneNotSupportedException {
        Film copy = new Film();
        
        copy.setActors(Actors);
        copy.setBudget(Budget);
        copy.setCertif(Certif);
        copy.setDate(Date);
        copy.setDirectors(Directors);
        copy.setGenres(Genres);
        copy.setId(Id);
        copy.setOriginalTitle(OriginalTitle);
        copy.setPath(Path);
        copy.setRunTime(RunTime);
        copy.setStatus(Status);
        copy.setSummary(Summary);
        copy.setTitle(Title);
        copy.setVoteAverage(VoteAverage);
        copy.setVoteCount(VoteCount);
        
        return copy;
    }
   
    
    private int Id;
    private String Title;
    private String OriginalTitle;
    private String Path;
    private String Date;
    private String Status;
    private int VoteCount;
    private float VoteAverage;
    private int RunTime;
    private String Certif;
    private int Budget;
    private String Summary;
    private Vector<Genre> Genres;
    private Vector<Director> Directors;
    private Vector<Actor> Actors;

    @Override
    public String toString() {
        Iterator i = Genres.iterator();
        String msg;
        
        msg = "Film{" + "Id=" + Id + ", Title=" + Title + ", Path=" + Path + ", Date=" + Date + ", Status=" + Status + ", VoteCount=" + VoteCount + ", VoteAverage=" + VoteAverage + ", RunTime=" + RunTime + ", Certif=" + Certif + ", Budget=" + Budget + ", Summary=" + Summary + 
                ", Genres=(";
        while(i.hasNext()){
            Genre g = (Genre) i.next();
            msg+= " " + g.toString() + ", ";
        }
        
        msg +=") , Directors=(";
        
        i = Directors.iterator();
        while(i.hasNext()){
            Director g = (Director) i.next();
            msg+= " " + g.toString() + ", ";
        }
                
        msg +="), Actors=(";
        
        i = Actors.iterator();
        while(i.hasNext()){
            Actor g = (Actor) i.next();
            msg+= " " + g.toString() + ", ";
        }
        
        msg += ")}";
                
        return msg;        
    }

    @Override
    public int compareTo(Film o) {
        if(o == null) return +1;
        
        if(this.getVoteAverage() < o.getVoteAverage()){
            return +1;
        }
        if(this.getVoteAverage() > o.getVoteAverage()){
            return -1;
        }
        return 0;
    }
}







