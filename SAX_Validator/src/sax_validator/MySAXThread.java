/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package sax_validator;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Vector;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.DefaultListModel;
import javax.xml.parsers.SAXParser;
import org.xml.sax.SAXException;

/**
 *
 * @author student
 */
public class MySAXThread extends Thread {
    private SAXParser sp;
    private MyHandler dh;
    private String path;
    private DefaultListModel exceptionlist;
    
    public MySAXThread(SAXParser s, MyHandler d, String p, DefaultListModel el){
        sp = s;
        dh = d;
        path = p;
        exceptionlist = el;
    }
    
    @Override
    public void run(){
        try {
            sp.parse(path, dh);            
        } catch (SAXException | IOException ex) {            
            if(ex.getMessage().compareTo("FIN") == 0){
                this.stop();
            }
            exceptionlist.addElement(ex.getMessage());
        }
    }
}