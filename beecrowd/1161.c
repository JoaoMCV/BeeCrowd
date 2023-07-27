#include <stdio.h>
long long int fatorial(int x);
int main(){
    int m,n;
    long long int aux;
    while(scanf("%d %d",&m,&n) !=EOF){
    aux= fatorial(m) + fatorial(n);
    printf("%lld\n",aux);
    }


}
long long int fatorial(int x){
    long long int fact=x;
    if(x==0){
        return 1;
    }
    else{
        for(int i=1;i<x;i++){
        fact= fact*(x-i);
        }
        return fact;
    }

}