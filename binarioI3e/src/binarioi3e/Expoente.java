/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package binarioi3e;

/**
 *
 * @author Marcos Vinicius Golom RA: 1602608
 * @author Thiago Alexsander RA: 1602624
 * 
 */
public class Expoente {
   private double numero;
   int expoent;
   private int excesso = 127;
   private double nfrac;
    
   
   public int getExpoent(){
       int num = 0;
       int check;
       double temp = numero;
       Extrator converter = new Extrator();
       if(temp >= 1){
        while(num != 1){
          temp = temp/2;
          converter.setNumero(temp);
          check = converter.toInt();
          if(check == 1){
              num = 1;
          }      
          expoent++;  
        }
       }
       else if(temp < 1){
         while(num != 1){
          temp = temp*2;
          converter.setNumero(temp);
          check = converter.toInt();
          if(check == 1){
              num = 1;
          }      
          expoent--;  
        }  
       }
       setNfrac(temp);
       return expoent+excesso;       
   }   

    public double getNumero() {
        return numero;
    }

    public void setNumero(double numero) {
        this.numero = numero;
    }

    public double getNfrac() {
        return nfrac;
    }

    private void setNfrac(double nfrac) {
        this.nfrac = nfrac;
    }
}
