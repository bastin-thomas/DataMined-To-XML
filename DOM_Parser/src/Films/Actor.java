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
public class Actor{
    public Actor(int id, String ActName, String CharName) {
        this.id = id;
        this.ActName = ActName;
        this.CharName = CharName;
    }

    @Override
    public String toString() {
        return "Actor{" + "id=" + id + ", ActName=" + ActName + ", CharName=" + CharName + '}';
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
     * @return the ActName
     */
    public String getActName() {
        return ActName;
    }

    /**
     * @param ActName the ActName to set
     */
    public void setActName(String ActName) {
        this.ActName = ActName;
    }

    /**
     * @return the CharName
     */
    public String getCharName() {
        return CharName;
    }

    /**
     * @param CharName the CharName to set
     */
    public void setCharName(String CharName) {
        this.CharName = CharName;
    }

    
    private int id;
    private String ActName;
    private String CharName;
    
}