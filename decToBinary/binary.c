#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int *decToBin(Stack *p,int bin,int *tam);
int *fracToBin(Stack *p,double bin,int *tam);

int main(){
Stack *p= create();

int aux=0;
double ptf = 0;
double num = 0;
int pti = 0,i,j,tam,tam2;
int n = 2;
int* resulti;
int *frac;
printf("informe o numero a ser convertido\n");
scanf("%lf",&num);
printf("Precisao 32 bits\n");
if (num < 0) {
   printf("- ");
   num = num * (-1);
}
//parte inteira
pti  = num;

// parte fracionaria
ptf = num - pti;

    int *bin = decToBin(p,pti,&tam);
    for(i=0;i < tam;i++){
       printf("%d",bin[i]);
   	}
    if(ptf > 0){
     frac = fracToBin(p,ptf,&tam2);
     // fracToBin(p,ptf,&tam2,prec);
  	printf(".");
	   	for(i=0;i < tam2;i++){
	       printf("%d",frac[i]);
	   	}
    }
    
   
   
   printf("\n");

return 0;    
}

int *decToBin(Stack *p,int bin,int *tam){
    int rest,i,z;
    int *e;
    
    if(bin == 0){
      e = (int*)malloc(2*sizeof(int));
      e[0] = 0;
      *tam = 1;
      return e;
    }
    
    while(bin > 0){
        rest = bin%2;
        push(p, rest);
        bin = bin/2;
    }
    e = (int*)malloc(sizeStack(p)*sizeof(int));
    *tam = sizeStack(p);
    z = sizeStack(p);
        for(i = 0;i < z;i++){
            e[i] = pop(p);
        }
    return e;
}

int *fracToBin(Stack *p,double bin,int *tam){
double result;
result = bin;
int z = 32;
int i = 0;
int j = 31;
int aux;
    while(z > 0){    
        result = result*2;
        if(result >= 1){
            push(p,1);
            result = result - 1;
        }
        else{
            push(p,0);
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
