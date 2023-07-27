#include<stdio.h>
int main(){
    int fib[40],fibrc[40],n,x;
    for(int i=0;i<40;i++){
        if(i<2){
            fib[i]=i;
        }
        else{
            fib[i]=fib[i-1]+fib[i-2];
        }

    }
    fibrc[0]=0;fibrc[1]=0;fibrc[2]=2;fibrc[3]=4;
    for(int i=4;i<40;i++){
        fibrc[i]=fibrc[i-1]+fibrc[i-2]+2;
    }
    scanf("%d",&n);
     for(int i=0;i<n;i++){
        scanf("%d",&x);
        printf("fib(%d) = %d calls = %d\n",x,fibrc[x],fib[x]);
     }

}