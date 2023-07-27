#include <stdio.h>
long long int teste(int n);
int main(){
    int m;
    while(scanf("%d",&m) != EOF){
        printf("%lld\n",teste(m));
    }
      /*
    scanf("%d",&m);
    prinf("%lld",teste(m));
    */
    return 0;
}
long long int teste(int n){
long long int phill[17];
for(int i=0;i<17;i++){
    if(i<2){
        phill[i]=i;
    }
    else if(i%2==0){
        phill[i]= phill[i-2]+phill[i-1];
    }
    else if(i%2!=0){
        phill[i]=phill[i-2]*phill[i-1];
    }
}
return phill[n-1];
}