#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node{
    int data;
    struct node *anterior;
}Node;

typedef struct stack{
    int tam;
    Node *top;
}Stack;


void inicialize(Stack *s);

Stack *create(){
    Stack* s = (Stack*) malloc(sizeof(Stack));
    if (s != NULL) {
      inicialize(s);
      return s;
    }
    else{
       printf("Error stack not allocated"); 
    }
}

/* comentarios para alteracoes se futuramente necessarias  */

void inicialize(Stack *s){
        s->tam=0;
}

void push(Stack *s, int e){

    if(s->tam==0){ // Se for o primeiro elemento
     s->top = (Node*) malloc(sizeof(Node));
     s->top->anterior = NULL; // O anterior dele será NULL <--
    }
    
    else{
        Node *novo = (Node*) malloc(sizeof(Node)); // Crio um novo espaço
        novo->anterior = s->top; // Armazeno o endereço atual do p->top no anterior deste novo espaço
        s->top = novo; // Defino o endereço atual do p->top como o nosso novo espaço
    }
        s->top->data = e; // Insere o valor
        s->tam++;
}

int pop(Stack *s){
int nume; 
    if(sizeStack(s) > 0){
        Node *atual = s->top;
        nume = s->top->data;
        s->top = s->top->anterior;
        s->tam--;
        free(atual);
        return nume;
    }
    else{
        printf("pilha vazia\n");
    }
        
}

int isEmptyStack(Stack *s){
 if(s->top == NULL){
            return 1; // Se estiver vazia, retorna 0
 }
 return 0; // Senão retorna 1
}

int sizeStack(Stack *s){
 return s->tam;
}

void printStack(Stack *s){
    if(sizeStack(s) > 0){
    printf("Elementos da pilha:\n");
    Node *aux; // Variavel auxiliar p/ armazenar endereço
    aux = s->top; // define como o endereço do atual p->top
        while(aux != NULL){
            printf("%d\n" ,aux->data);
            aux = aux->anterior; // define ele mesmo como o anterior
        }// loop para quando ele mesmo for NULL
    }
    else{
    printf("\nSem elementos na pilha!\n");
    }
}

int containsStack(Stack* s, int e){ // Retorna 1 se tiver, 0 se não tiver
    if(sizeStack(s) > 0){
    Node *aux;
    aux = s->top;
        while(aux != NULL){
            if(aux->data == e) return 1;
            aux = aux->anterior;
        }
    }
    return 0;
}