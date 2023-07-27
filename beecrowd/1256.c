#include<stdio.h>
#include<stdlib.h>

typedef struct item{
    int valor;
    struct item *prox;
}item;

int hashindex(int val,int tam);
void inserthash(int val,int tam,item *hash[]);
void freehash(item *h[],int tam);
int main(){
    item *hashtable[200];
    item *aux;
    int k,n,m,l;
    for(int i=0;i<200;i++){
        hashtable[i]= NULL;
    }
    scanf("%d",&k);
    for(int i=0 ;i<k;i++){
        scanf("%d %d",&n,&m);
        for(int j=0;j<m;j++){
            scanf("%d",&l);
            inserthash(l,n,hashtable);
        }
        for(int i=0;i<n;i++){
            aux = hashtable[i];
            if(hashtable[i] == NULL){
                printf("%d -> \\\n",i);
            }
            else{
                printf("%d",i);
                    while(aux!=NULL){
                        printf(" -> %d",aux->valor);
                        aux = aux->prox;
                    }
                printf(" -> \\\n");
            }
        }
        if(i!= k-1) {
            printf("\n");
        }

        
        freehash(hashtable,n);

        
    }

}

void inserthash(int val,int tam,item *hash[]){
    int index = hashindex(val,tam);
    item *novo = (item*) malloc(sizeof(item));
    item *aux = hash[index];
    if(hash[index] == NULL){
        novo->prox = NULL;
        novo->valor = val;
        hash[index] = novo;
        return;
    }
    else{
        while(aux->prox !=NULL){
            aux = aux->prox;
        
        }
        aux->prox = novo;
        novo->valor = val;
        novo->prox = NULL;
        return;
    }
    return;

}


void freehash(item *h[],int tam){
        item *aux,*aux2;
        for(int i=0;i<tam;i++){
            aux = h[i];
            if(h[i]!=NULL){
                h[i]=NULL;
                while(aux->prox!=NULL){
                    aux2 = aux->prox;
                    free(aux);
                    aux = aux2;
                }
                free(aux);
            }

        }
    return;
}

int hashindex(int val,int tam){
    return val % tam;
}