#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct elemento{
    char pdd;
    struct elemento *prox;
    struct elemento *ant;
}elemento;

typedef struct pilha{
    int qnt;
    struct elemento *inicio;
    struct elemento *fim;
}pilha;

void pop(pilha*p);

int main(){
    pilha *pilha1 = (pilha*) malloc(sizeof(pilha));
    char a[1010];
    int i=0,v,diamante;
    elemento *aux;
    scanf("%d",&v);
    for(int j=0;j<v;j++){
        pilha1->inicio=NULL;
        pilha1->qnt=0;
        scanf("%s",a);
        i=0;
        diamante=0;
        while(a[i]!='\0'){
            
            if(a[i]=='>'||a[i]=='<'){
                aux = (elemento*) malloc(sizeof(elemento));
                if(pilha1->inicio==NULL){
                    pilha1->inicio = aux;
                    pilha1->fim = aux;
                    aux->ant = NULL;
                    aux->prox = NULL;
                    aux->pdd = a[i];
                    pilha1->qnt++;
                }
                else if(a[i]=='>'&&pilha1->fim->pdd=='<'){
                
                    pop(pilha1);
                    diamante++;
                }
                else{
                    pilha1->fim->prox = aux;
                    aux->ant = pilha1->fim;
                    pilha1->fim = aux;
                    aux->prox= NULL;
                    aux->pdd = a[i];
                    pilha1->qnt++;
                }
            }
            i++;
        }
            printf("%d\n",diamante);

    }


}
void pop(pilha*p){
    if(p->qnt ==0){
        return;
    }
    if(p->qnt==1){
        free(p->inicio);
        p->inicio =NULL;
        p->fim= NULL;
        p->qnt = 0;
        return;
    }
    elemento *aux =p->fim;
    aux->ant->prox=NULL;
    p->fim = aux->ant;
    free(aux);
    p->qnt--;
    return;
}