#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
  char bra;
  struct elemento *prox;
  struct elemento *ant;
} elemento;

typedef struct pilha {
  int qnt;
  elemento *inicio;
  elemento *fim;
} pilha;

void pop(pilha *p);

int main() {
  pilha *pilha1 = (pilha *)malloc( sizeof(pilha));
  elemento *aux;
  char exp[1010];
  int i=0;
  while (scanf("%s", exp) != EOF) {
    i=0;
    pilha1->inicio = NULL;
    pilha1->fim = NULL;
    pilha1->qnt = 0;
    while (exp[i] != '\0') {
        
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{' ) {
            if (pilha1->inicio == NULL) {
                elemento *novo = (elemento *)malloc( sizeof(elemento));
                novo->bra = exp[i];
                pilha1->inicio = novo;
                pilha1->fim = novo;
                novo->ant = NULL;
                pilha1->qnt++;
            }
            else {
                elemento *novo = (elemento *)malloc( sizeof(elemento));
                novo->bra = exp[i];
                novo->prox = NULL;
                novo->ant = pilha1->fim;
                pilha1->fim->prox = novo;
                pilha1->fim = novo;
                pilha1->qnt++;
            }
        }
        else if( exp[i] == ')'  || exp[i] == ']'  || exp[i] == '}'){
            
            if(pilha1->qnt>0 && exp[i]==')' && pilha1->fim->bra=='('){
                
                pop(pilha1);
            }
            else if(pilha1->qnt>0 && exp[i]==']' && pilha1->fim->bra=='['){
                
                pop(pilha1);
            }
            else if(pilha1->qnt>0 && exp[i]=='}' && pilha1->fim->bra=='{'){
                
                pop(pilha1);
            }
            else{
                pilha1->qnt++;
                break;
            }

        } 

      i++;
      
    }

    if(pilha1->qnt>0){
        printf("incorrect\n");
    }
    else{
        printf("correct\n");
    }


  }
}
void pop(pilha *p){
    if(p->qnt==0){
        return;
    }
    if(p->qnt==1){
        free(p->inicio);
        p->inicio = NULL;
        p->fim = NULL;
        p->qnt =0;
        return;
    }
    
    elemento *aux =p->fim;
    aux->ant->prox=NULL;
    p->fim = aux->ant;
    free(aux);
    p->qnt--;
    return;
}
