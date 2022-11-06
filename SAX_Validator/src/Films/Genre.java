/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Films;

/**
 *
 * @author student
 */
public class Genre {
    public Genre(int id, String Name) {
        this.id = id;
        this.Name = Name;
    }
    
    
    /**
     * @return the id
     */
    public int getId() {
        return id;
    }

    /**
     * @param id the id to set
     */
    public void setId(int id) {
        this.id = id;
    }

    /**
     * @return the Name
     */
    public String getName() {
        return Name;
    }

    /**
     * @param Name the Name to set
     */
    public void setName(String Name) {
        this.Name = Name;
    }

    @Override
    public String toString() {
        return "Genre{" + "id=" + id + ", Name=" + Name + '}';
    }
    
    
    private int id;
    private String Name;
}
