/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package binarioi3e;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;
import java.lang.String;
import java.util.Arrays;
import java.util.List;
import java.util.regex.Pattern;


/**
 *
 * @author Marcos Vinicius Golom RA: 1602608
 * @author Thiago Alexsander RA: 1602624
 * 
 */
public class IEEE {
    /**
     * @param args the command line arguments
     */
    
    public static void main(String[] args) {
        Double numero;
        int partdec;
        Double partfrac;
        String[] temp2;
        Integer sinal;
        Integer tmpexpoente;
        Deque<Integer> expoente = new LinkedList(); 
        Double tmpMantissa;
        List<Integer> mantissa = new LinkedList();
        
        Dectobin dec = new Dectobin();
        Extrator converTo = new Extrator();
        Expoente expo = new Expoente();
        Scanner entrada = new Scanner(System.in);
        
        System.out.println("Informe o numero no seguinte formato  0,0000");
        numero = entrada.nextDouble();
        if(numero < 0){
            sinal = 1;
            numero = numero*-1;
        }
        else{
            sinal = 0;
        }
        expo.setNumero(numero);
        
        tmpexpoente = expo.getExpoent();
        numero = expo.getNfrac();
        converTo.setNumero(numero);
        dec.setDecimal(tmpexpoente);
        expoente = dec.binario();
        while(expoente.size() < 8){
            expoente.addFirst(0);  
        }
        
        
        tmpMantissa = converTo.toFrac();
        dec.setFracionario(tmpMantissa);
        mantissa = dec.binarioF();
        
        
        System.out.print(sinal+" | ");
        for(Object object : expoente) {
            int element = (int) object;
            System.out.print(element);
        }
        System.out.print(" | ");
        for(Object object : mantissa) {
            int element = (int) object;
            System.out.print(element);
        }
        System.out.println("");
        
        
        
        
        
    }
    
    
    
}
