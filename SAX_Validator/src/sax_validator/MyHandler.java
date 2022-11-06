/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sax_validator;

import java.io.BufferedWriter;
import java.io.ByteArrayOutputStream;
import java.io.FileWriter;
import java.io.OutputStream;
import java.util.ArrayList;
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
    
    public MyHandler(){
        super();
    }
    
    private int cptTags = 0;
    
    @Override
    public void characters(char[] ch, int start, int length) throws SAXException{
        String chain = new String(ch, start ,length).trim();
        if(chain.length()>0){
            System.out.println(chain);
        }
    }
    
    @Override
    public void startDocument() throws SAXException{
        System.out.println("** Début Document **");
    }
    
    @Override
    public void endDocument() throws SAXException{
        System.out.println("** Fin Document **");
        throw new SAXException("FIN");
    }
    
    @Override
    public void startElement(String uri, String localName, String qName, Attributes attr) throws SAXException{
        System.out.println("* Début d'un élément");
        cptTags++;
        System.out.println("++ compteur de tags : " + cptTags);
        if (uri != null && uri.length() > 0) {
            System.out.println(" uri : "+ uri);
        }
        System.out.println(" nom complet : "+ qName);
        if (uri != null && uri.length() > 0) {
            System.out.println(" nom complet : "+ qName);
        }
        int nAttr = attr.getLength();
            System.out.println(" nombre d'attributs :" + nAttr);
        if (nAttr == 0) {
            return;
        }
        for (int i = 0; i < nAttr; i++) {
            System.out.println(" attribut n°" + i + " = " + attr.getLocalName(i) + " avec valeur : " + attr.getValue(i));
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
        System.out.println("* Fin de l'élément " + localName);
        cptTags++;
        System.out.println("++ compteur de tags : " + cptTags);
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
}
