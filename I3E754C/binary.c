#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int *decToBin(Stack *p, int bin, int *tam);
int *fracToBin(Stack *p, double bin, int *tam);
int expoent(double *num);

int main() {
    Stack *p = create();

    double num;
    int pti = 0, i, j, tam, tam2, prec = 23;
    int sinal;
    int expo;
    int *expoente;
    int *mantissa;
    printf("informe o numero a ser convertido\n");
    scanf("%lf", &num);
    /*Verifica Sinal do Numero*/
    if (num < 0) {
        sinal = 1;
        num = num * (-1);
    } else {
        sinal = 0;
    }


    expo = expoent(&num);
    expoente = decToBin(p,expo,&tam);

    mantissa = fracToBin(p,num,&tam2);

    printf("%d | ",sinal);
    for(i=0;i < tam;i++){
    	printf("%d", expoente[i]);
    }
    printf(" | ");
    for(i=0;i < tam2;i++){
    	printf("%d", mantissa[i]);
    }	
    printf("\n");



    return 0;
}

int *decToBin(Stack *p, int bin, int *tam) {
    int rest, i, z;
    int *e;
    if (bin == 0) {
       push(p,0);
    }
    else if(bin !=0){
	    while (bin > 0) {
	        rest = bin % 2;
	        push(p, rest);
	        bin = bin / 2;
	    }
	}    
    if(sizeStack(p) != 8){
    	if(sizeStack(p) > 8){
    		while(sizeStack(p) != 8){
    			pop(p);
    		}
    	}
    	else{
    		while(sizeStack(p) != 8){
    			push(p, 0);
    		}
    	}
    }
    e = (int*) malloc(sizeStack(p) * sizeof (int));
    *tam = sizeStack(p);
    z = sizeStack(p);
    for (i = 0; i < z; i++) {
        e[i] = pop(p);
    }
    return e;
}

int *fracToBin(Stack *p, double bin, int *tam) {
    double result;
    result = bin;
    int z = 23;
    int i = 0;
    int j = 22;
    int aux;
    while (z > 0) {
        result = result*2;
        if (result >= 1) {
            push(p, 1);
            result = result - 1;
        }else{
            push(p, 0);
        }
        z--;
    }
    aux = (sizeStack(p));
    int *temp = (int*) malloc(aux*sizeof(int));
    *tam = sizeStack(p);
    for(i=0;i<aux;i++){
        temp[j] = pop(p);
        j--;
    }
    return temp;
}




int expoent(double *num) {
    int checkNum = *num;
    int check;
    int z;
    int expoente;
    int excesso = 127;
    double temp;
    temp = *num;
    int i = 0;

    if (temp > 2) {
        while (i != 1) {
            temp = temp / 2;
            check = temp;
            if (check == 1) {
                i = 1;
            }
            expoente++;
        }
    } 
    
    else if ((checkNum == 1)) {
        *num = (temp - 1);
        return excesso;
    } 
    
    else if ((checkNum == 0)) {
        return 0;
    } 
    
    else if ((temp < -2)) {
        while (i != 1) {
            temp = temp * 2;
            check = temp;
            if (check == 1) {
                i = 1;
            }
            expoente--;
        }
    }
    *num = (temp-1);
    return expoente + excesso;
}