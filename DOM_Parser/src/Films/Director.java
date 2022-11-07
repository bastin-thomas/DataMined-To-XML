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
public class Director{
    public Director(int id, String Name) {
        this.id = id;
        this.Name = Name;
    }

    @Override
    public String toString() {
        return "Director{" + "id=" + id + ", Name=" + Name + '}';
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

    
    private int id;
    private String Name;
}