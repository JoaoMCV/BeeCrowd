#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct elemento{
    char coisa;
    struct elemento *prox;
}elemento;

typedef struct pilha{
    int qnt;
    struct elemento *topo;
}pilha;

void push(pilha *p,char v);
void pop(pilha *p);
int preferencia(char v);

int main(){
    int k,len;
    char expressao[1000];
    pilha *pilha1 = (pilha*) malloc(sizeof(pilha));
    scanf("%d",&k);
    for(int i = 0;i<k;i++){
        pilha1->topo = NULL;
        pilha1->qnt = 0;
        scanf("%s",expressao);
        len = strlen(expressao);
        for(int j=0;j<len;j++){
            if(isalpha(expressao[j])||isdigit(expressao[j])){
                printf("%c",expressao[j]);
            }
            else if(expressao[j]=='(' || expressao[j] == '^'){
                push(pilha1,expressao[j]);
            }
            else if(expressao[j]==')'){
                while(pilha1->topo!=NULL && pilha1->topo->coisa!='('){
                        printf("%c",pilha1->topo->coisa);
                        pop(pilha1);
                }
                pop(pilha1);
            }
            else{
                    while(pilha1->topo != NULL && pilha1->topo->coisa!='(' && preferencia(expressao[j])<=preferencia(pilha1->topo->coisa)){
                        printf("%c",pilha1->topo->coisa);
                        pop(pilha1);
                    }
                    push(pilha1,expressao[j]);
            }


        }
        while(pilha1->topo!=NULL){
            printf("%c",pilha1->topo->coisa);
            pop(pilha1);
        }
        printf("\n");
    }


}

void push(pilha *p,char v){
    elemento *novo = (elemento*) malloc(sizeof(elemento));
    if(p->topo == NULL){
        novo->coisa = v;
        novo->prox = NULL;
        p->topo = novo; 
        p->qnt++;
    }
    else{
        novo->coisa = v;
        novo->prox = p->topo;
        p->topo = novo;
        p->qnt++;
    }
}

void pop(pilha *p){
    if(p->topo==NULL){
        return;
    }
    if(p->qnt==1){
        p->topo = NULL;
        p->qnt=0;
        return;
    }
    else{
        elemento *aux;
        aux = p->topo;
        p->topo = p->topo->prox;
        p->qnt--;
        free(aux);
    }
}
int preferencia(char v){
    switch(v){
        case'+':

        case'-': return 1;

        case'*':

        case'/': return 2;
    }

}