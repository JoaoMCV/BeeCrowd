#include<stdio.h>
#include<stdlib.h>

typedef struct item{
    long int valor;
    struct item *prox;
}item;

typedef struct pilha{
    long int qnt,menor;
    struct item *inicio,*fim;
}pilha;

void push(pilha *p,int v);
int ver_menor(pilha *p);
void pop(pilha *p);


int main(){
    pilha *pilha1 = (pilha*) malloc(sizeof(pilha));
    pilha1->menor = -1;
    pilha1->fim =NULL;
    pilha1->inicio = NULL;
    pilha1->qnt = 0;
    long int k,n;
    char a[5];
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        scanf("%s",a);
        if(a[1]=='U'){
            scanf("%ld",&n);
            push(pilha1,n);
        }
        else if(a[1]=='O'){
            pop(pilha1);
        }
        else{
            if(pilha1->menor==-1){
                printf("EMPTY\n");
            }
            else{
                printf("%ld\n",pilha1->menor);
            }
            
        }


    }

}

void push(pilha *p,int v){
    if(p->inicio== NULL){
        item *novo = (item*) malloc(sizeof(item));
        novo->prox = NULL;
        novo->valor = v;
        p->inicio = novo;
        p->fim = novo;
        p->menor = novo->valor;
        p->qnt++;
    }
    else{
        item *novo = (item*) malloc(sizeof(item));
        novo->valor = v;
        novo->prox = p->inicio;
        p->inicio = novo;
        if(novo->valor<p->menor){
            p->menor = novo->valor;
        }
        p->qnt++;
    }
}

int ver_menor(pilha *p){
    item *aux = p->inicio;
    int menor = aux->valor;
    while(aux!=NULL){
        if(aux->valor<menor){
            menor = aux->valor;
        }
        aux = aux->prox;
    }
    return menor;
}

void pop(pilha *p){
    if(p->qnt==0){
        printf("EMPTY\n");
        return;
    }
    if(p->qnt==1){
        p->inicio = NULL;
        p->fim = NULL;
        p->menor = -1;
        p->qnt = 0;
        return;
    }
    item *aux = p->inicio;
    if(aux->valor == p->menor){
        p->inicio = aux->prox;
        p->menor = aux->prox->valor;
        p->menor = ver_menor(p);
        p->qnt--;
        free(aux);
        return;
    }
    else{
        p->inicio = aux->prox;
        p->qnt--;
        free(aux);
        return;
    }
    return;
}
