#include<stdio.h>
int main(){
    float primeiro,b,c;
    int contador=0;
    while(scanf("%f %f",&primeiro,&b)!=EOF){
        contador++;
        c = (b/primeiro)-1;
        printf("Projeto %d:\nPercentual dos juros da aplicacao: %.2f %%\n\n",contador,c*100);
    }



}