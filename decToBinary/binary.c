#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

int *decToBin(Stack *p,int bin,int *tam);
int *fracToBin(Stack *p,double bin,int *tam,int prec);

int main(){
Stack *p= create();

int aux=0;
double ptf = 0;
double num = 0;
int pti = 0,i,j,tam,tam2,prec = 0;
int n = 2;
int* resulti;
int *frac;
printf("informe o numero a ser convertido\n");
scanf("%lf",&num);

printf("informe a precisao fracionaria pra o numero\n");
scanf("%d",&prec);
//parte inteira
pti  = num;

// parte fracionaria
ptf = num - pti;
    int *bin = decToBin(p,pti,&tam);
    for(i=0;i < tam;i++){
       printf("%d",bin[i]);
   	}
    if(prec < 0){
            printf("erro na parte fracionaria\n");    
    }
    else if(ptf > 0){
     frac = fracToBin(p,ptf,&tam2,prec);
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
    rest = bin%2;
    push(p, rest);
    
    if(bin == 0){
      e = (int*)malloc(2*sizeof(int));
      e[0] = 0;
      *tam = 1;
      return e;
    }
    
    while(bin != 1){
        bin = bin/2;
        rest = bin%2;
        push(p, rest);
    }
    e = (int*)malloc(sizeStack(p)*sizeof(int));
    *tam = sizeStack(p);
    z = sizeStack(p);
    printf("%d\n",z);
        for(i = 0;i < z;i++){
            e[i] = pop(p);
        }
    return e;
}

int *fracToBin(Stack *p,double bin,int *tam,int prec){
double result;
result = bin;
int z = prec;
int i = prec-1;


    while(z > 0){    
        result = result*2;
        if(result >= 1){
            push(p,1);
            result = result - 1;
        }
        else if(result < 0){
            push(p,0);
        }
        else{
            push(p,0);
        }
        z--;    
    }
    int *temp = (int*)malloc(sizeStack(p)*sizeof(int));
    *tam = sizeStack(p);
    while(i != 0){
        temp[i] = pop(p);
        i--;
    }
    return temp;
}
