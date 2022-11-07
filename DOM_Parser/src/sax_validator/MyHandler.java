/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sax_validator;

import Films.*;
import java.io.BufferedWriter;
import java.io.ByteArrayOutputStream;
import java.io.FileWriter;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Iterator;
import java.util.Vector;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JTextArea;
import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.SAXParseException;
import org.xml.sax.helpers.DefaultHandler;

/**
 *
 * @author student
 */
public class MyHandler extends DefaultHandler {

    /**
     * @return the Films
     */
    public Vector<Film> getFilms() {
        return Films;
    }

    /**
     * @param Films the Films to set
     */
    public void setFilms(Vector<Film> Films) {
        this.Films = Films;
    }
    
    private String LastQname;
    
    public MyHandler(){
        super();
        Films = new Vector<Film>();
        current = null;
    }
    
    private int cptTags = 0;
    private Vector<Film> Films;
    private Film current;
    
    @Override
    public void startDocument() throws SAXException{
        System.out.println("** Début Document **");
    }
    
    @Override
    public void endDocument() throws SAXException{
        System.out.println("** Fin Document **");
    }
    
    @Override
    public void characters(char[] ch, int start, int length) throws SAXException{
        String chain = new String(ch, start ,length).trim();
        
        if(LastQname.equals("Title")){
            current.setTitle(chain);
        }
        
        if(LastQname.equals("Status")){
            current.setStatus(chain);
        }
        
        if(LastQname.equals("Vote")){
            current.setVoteAverage(Float.parseFloat(chain));
        }
        
        if(LastQname.equals("RunTime")){
            current.setRunTime(Integer.parseInt(chain));
        }
        
        if(LastQname.equals("Certification")){
            current.setCertif(chain);
        }
        
        if(LastQname.equals("Budget")){
            current.setBudget(Integer.parseInt(chain));
        }
        
        if(LastQname.equals("Tag")){
            current.setSummary(chain);
        }
    }
    
    @Override
    public void startElement(String uri, String localName, String qName, Attributes attr) throws SAXException{ 
        LastQname = qName;
        
        if("Film".equals(qName)){
            if(attr.getValue("Id").equals("")){
                current.setId(-1);
            }
            else{
                if(attr.getValue("PosterPath") == null){
                    current = new Film(Integer.parseInt(attr.getValue("Id")), "");
                }
                else{
                    current = new Film(Integer.parseInt(attr.getValue("Id")), attr.getValue("PosterPath"));
                }
            }
        }
        
        if("Title".equals(qName)){
            current.setOriginalTitle(attr.getValue("OriginalTitle"));
        }
        
        if("Time".equals(qName)){
            current.setDate(attr.getValue("Day") + "/" + attr.getValue("Month") + "/" + attr.getValue("Year"));
        }
        
        if("Status".equals(qName)){
            //Nothing To do, no Attribute
        }
        
        if("Vote".equals(qName)){
            if(attr.getValue("Count").equals("")){
                current.setVoteCount(0);
            }
            else{
                current.setVoteCount(Integer.parseInt(attr.getValue("Count")));
            }
        }   
        
        if("Genres".equals(qName)){
            current.setGenres(new Vector());
        }
        if("Genre".equals(qName)){
            if(attr.getValue("Id").equals("")){
                current.getGenres().add(new Genre(-1, attr.getValue("Label")));
            }
            else{
                current.getGenres().add(new Genre(Integer.parseInt(attr.getValue("Id")), attr.getValue("Label")));
            }
        }
        
        if("Directors".equals(qName)){
            current.setDirectors(new Vector());
        }
        if("Director".equals(qName)){
            if(attr.getValue("Id").equals("")){
                current.getDirectors().add(new Director(-1, attr.getValue("Name")));
            }
            else{
                current.getDirectors().add(new Director(Integer.parseInt(attr.getValue("Id")), attr.getValue("Name")));
            }
        }
        
        if("Actors".equals(qName)){
            current.setActors(new Vector());
        }
        if("Actor".equals(qName)){
            if(attr.getValue("Id").equals("")){
                current.getActors().add(new Actor(-1, attr.getValue("ActName"), attr.getValue("CharName")));
            }
            else{
                current.getActors().add(new Actor(Integer.parseInt(attr.getValue("Id")), attr.getValue("ActName"), attr.getValue("CharName")));
            }
            
        }
    }
    
    /**
     *
     * @param uri
     * @param localName
     * @param qName
     * @throws SAXException
     */
    @Override
    public void endElement(java.lang.String uri, java.lang.String localName, java.lang.String qName) throws SAXException{
        LastQname = "";
        
        if(localName.equals("Film")){
            getFilms().add(current);
        }
    }
    
    //Et d'autres du error handler
    @Override
    public void warning(SAXParseException e) throws SAXException {
        System.out.println("WARNING : " + e.getMessage());
    }
    
    @Override
    public void error(SAXParseException e) throws SAXException {
        System.out.println("ERROR : " + e.getMessage());
        throw e;
    }
    
    @Override
    public void fatalError(SAXParseException e) throws SAXException {
        System.out.println("FATAL : " + e.getMessage());
        throw e;
    }
    
    
    
    public int CountPg13(){
        int count = 0;
        
        Iterator i = getFilms().iterator();
        while(i.hasNext()){
            Film f = (Film) i.next();
            if(f.getCertif() == null) continue;
            if(f.getCertif().equals("PG-13")){
                count++;
            }
        }
        
        return count;
    }
    
    
    
    public Vector<Film> getBest(){    
        int j = 0;
        Vector<Film> ret = new Vector<Film>();
        Collections.sort(getFilms());
        Iterator i = getFilms().iterator();
        while(i.hasNext() && j<10){
            Film f = (Film) i.next();
            ret.add(f);
            j++;
        }
        return ret;
    }
}
