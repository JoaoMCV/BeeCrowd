#include<stdio.h>
long long int final(long long int x, long long int y);
int main(){
    long long int wariors,opponents;
    while(scanf("%lld %lld",&wariors,&opponents)!= EOF){
        printf("%lld\n",final(wariors,opponents));
    }

}
long long int final(long long int x, long long int y){
    if(y>x){
        return y-x;
    }
    else{
        return x-y;
    }
  }
    /*
    scanf("%lld %lld",&wariors,&opponents);
    final= opponents-wariors;
    printf("%lld",final);
    */