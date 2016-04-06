/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package binarioi3e;

import java.util.Deque;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author Marcos Vinicius Golom RA: 1602608
 * @author Thiago Alexsander RA: 1602624
 * 
 */
public class Dectobin {
    Integer decimal;
    Integer b;
    Double fracionario;
    Double fb;
    Deque<Integer> binario = new LinkedList<>();
    List<Integer> bFrac = new LinkedList<>();

    public Deque binario(){
        if(decimal == 0){
            binario.addFirst(0);
            return binario;
        }
        while ( decimal > 0){
                b = decimal % 2;
                binario.addFirst(b);
                decimal = decimal / 2 ;
        }
      return binario;  
    }

    public List binarioF(){
        int z = 23;
        Double result = fracionario;
        while(z > 0){    
                result = result*2;
            System.out.println(result);
             if(result >= 1){
                 bFrac.add(1);
                 result = result - 1;
             }
             else{
                 bFrac.add(0);
             }
             z--;
        }
        return bFrac;   
    }
    
    public int getDecimal() {
        return decimal;
    }

    public void setDecimal(int decimal) {
        this.decimal = decimal;
    }
        public Double getFracionario() {
        return fracionario;
    }

    public void setFracionario(Double fracionario) {
        this.fracionario = fracionario;
    }

    public Double getFb() {
        return fb;
    }

    public void setFb(Double fb) {
        this.fb = fb;
    }
    
    
    
}
