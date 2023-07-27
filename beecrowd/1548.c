#include<stdio.h>
#include<stdlib.h>

void quick(int *arr,int in, int tam);

int main(){
    int k,n,contador =0, arr[1000], arr2[1000];
    scanf("%d",&k);
    for(int i=0;i<k;i++){
        contador=0;
        scanf("%d",&n);
        for(int j=0;j<n;j++){
            scanf("%d",&arr[j]);
            arr2[j] = arr[j];
        }
        quick(arr2,0,n);
        for(int i=0;i<n;i++){
            if(arr[i]== arr2[n-i-1]){
                contador++;
            }
        }
        printf("%d\n",contador);
    }




}



void quick(int *arr,int in, int tam){
    if(in>tam){
        return;
    }
    
    int pivo,aux,temp;
    pivo = tam;
    aux = in;
    while(aux!=pivo){
        if(aux>pivo && arr[aux]<arr[pivo]){
            temp = arr[pivo];
            arr[pivo] = arr[aux];
            arr[aux] = temp;
            temp = pivo;
            pivo = aux;
            aux = temp;
        }
        else if(aux<pivo && arr[aux]>arr[pivo]){
            temp = arr[pivo];
            arr[pivo] = arr[aux];
            arr[aux] = temp;
            temp = pivo;
            pivo = aux;
            aux = temp;
        }
        if(aux>pivo){
            aux--;
        }
        else{
            aux++;
        }

    }

    quick(arr,in,pivo-1);
    quick(arr,pivo+1,tam);

}
