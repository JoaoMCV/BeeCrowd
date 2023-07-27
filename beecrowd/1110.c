#include <stdio.h>
#include <stdlib.h>

typedef struct carta{
    int valor;
    struct carta *prox;
}carta;

typedef struct pilha{
    int qnt;
    struct carta *fim;
    struct carta *inicio;
}pilha;

int main(){

    pilha *pilha1 = (pilha*) calloc(1,sizeof(pilha));
    carta *aux;
    int desc[55],n,k;
    while(scanf("%d",&n)!=0){
        pilha1->fim=NULL;
        pilha1->inicio=NULL;
        pilha1->qnt=0;
        k=0;
        if(n==0){
            return 0;
        }
        for(int i=0;i<55;i++){
            desc[i]=0;
        }
        for(int i=0;i<n;i++){
            aux = (carta*) calloc(1,sizeof(carta));
            aux->valor = i+1;
            carta *aux2 = pilha1->inicio;
            if(pilha1->inicio==NULL){
                pilha1->inicio = aux;
                pilha1->fim = aux;
                aux->prox = NULL;
                pilha1->qnt++;
            }
            else{
                while(aux2->prox!=NULL){
                    aux2 = aux2->prox;
                }
                aux2->prox = aux;
                pilha1->fim = aux;
                pilha1->qnt++;
            }
        }
        printf("Discarded cards: ");
        while(pilha1->qnt>1){
            aux = pilha1->inicio;
            desc[k] = aux->valor;

            pilha1->fim->prox = aux->prox;
            pilha1->fim = aux->prox;
            pilha1->inicio = aux->prox->prox;
            pilha1->qnt--;
          
            free(aux);
            printf("%d",desc[k]);
            if(pilha1->qnt!=1){
                printf(", ");
            }
            k++;
        }
        
        //printf("Discarded cards:");
        //for(int i=0;i<k;i++){
        //    
        //    printf("%d",desc[k]);
        //    if(i!=k-1){
        //        printf(",");
        //    }
        //}
        printf("\nRemaining card: %d\n",pilha1->fim->valor);

    }



}