#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int primo(int num);

int main(){
    int qnt,m,l;
    while(scanf("%d",&qnt)!=EOF){
        int moedas[qnt],soma;
        for(int i=0;i<qnt;i++){
            printf("a\n");
            scanf("%d",&moedas[i]);
        }
        scanf("%d",&m);
        for(int i=0;i<qnt;i+m){
            soma = soma + moedas[i];
        }
        printf("%d",soma);
        if(primo(soma)==1){
            printf("Bad boy! Ill hit you.\n");
        }
        else{
            printf("You’re a coastal aircraft, Robbie, a large silver aircraft\n");
        }

    }


}

int primo(int num){
    printf("b\n");
    int div=2;
    while(div<(num/2)){
        printf("c\n");
        if(num%div==0){
            return 1;
        }
    }
    return 0;

}