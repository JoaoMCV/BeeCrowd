#include<stdio.h>
#include<stdlib.h>

void quick(int *p,int in,int fim);
void inverse_quick(int *p,int in,int fim);

int main(){
    
    int n,k=0,aux;
    scanf("%d",&n);
    int arr[n+1],impar[n+1],par[n+1];
    
    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);
        arr[i+1]=-1;
    }
    int i=0,j=0,m=0;
    while(arr[i]!=-1){
        if(arr[i]%2==0){
            par[j]=arr[i];
            j++;
        }
        else{
            impar[m]=arr[i];
            m++;
        }
        i++;
    }
    quick(par,0,j-1);
    inverse_quick(impar,0,m-1);
   
    for(int i=0;i<j;i++){
        printf("%d\n",par[i]);
    }
   
    for(int i=0;i<m;i++){
        printf("%d\n",impar[i]);
    }

}

void quick(int *p,int in,int fim){
        if(in > fim){
            return;
        }
        int pivo=in,aux=fim,troca;
        while (pivo!=aux)
        {
            if(pivo>aux){
                if(p[pivo]<p[aux]){
                    troca = p[pivo];
                    p[pivo]=p[aux];
                    p[aux]=troca;
                    troca=pivo;
                    pivo=aux;
                    aux=troca;
                }
            }
            else{
                if(p[pivo]>p[aux]){
                    troca = p[pivo];
                    p[pivo] = p[aux];
                    p[aux] = troca;
                    troca = pivo;
                    pivo = aux;
                    aux = troca;
                }
            }
            if(pivo>aux){
                aux++;
            }
            else{
                aux--;
            }
        }
        quick(p,in,pivo-1);
        quick(p,pivo+1,fim);
        

}
void inverse_quick(int *p,int in,int fim){
        if(in > fim){
            return;
        }

        int pivo=in,aux=fim,troca;
        while (pivo!=aux)
        {
            if(pivo>aux){
                if(p[pivo]>p[aux]){
                    troca = p[pivo];
                    p[pivo]=p[aux];
                    p[aux]=troca;
                    troca=pivo;
                    pivo=aux;
                    aux=troca;
                }
            }
            else{
                if(p[pivo]<p[aux]){
                    troca = p[pivo];
                    p[pivo] = p[aux];
                    p[aux] = troca;
                    troca = pivo;
                    pivo = aux;
                    aux = troca;
                }
            }
            if(pivo>aux){
                aux++;
            }
            else{
                aux--;
            }
        }
        inverse_quick(p,in,pivo-1);
        inverse_quick(p,pivo+1,fim);


}