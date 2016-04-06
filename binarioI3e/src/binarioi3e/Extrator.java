/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package binarioi3e;

import java.util.regex.Pattern;

/**
 *
 * @author Marcos Vinicius Golom RA: 1602608
 * @author Thiago Alexsander RA: 1602624
 * 
 */
public class Extrator{
    private Double numero;
    String temp;
    int decimal;
    private int cosnt;
    Double fracionar;
    String dec[];
    String dec2[];
    
    public int toInt(){
        temp = numero.toString();
        dec = temp.split(Pattern.quote("."));
        decimal = Integer.parseInt(dec[0]);
        setCosnt(decimal);
        return decimal;
    }
    
    public Double toFrac(){
        toInt();
        int numfr = getCosnt();
        fracionar = numero-numfr;
        return fracionar;
    }

    public Double getNumero() {
        return numero;
    }

    public void setNumero(Double numero) {
        this.numero = numero;
    }

    private int getCosnt() {
        return cosnt;
    }

    private void setCosnt(int cosnt) {
        this.cosnt = cosnt;
    }



}
