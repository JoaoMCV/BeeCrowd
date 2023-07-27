#include <stdio.h>
#include<math.h>
int primo(long long int x);
int main(){
int n;
long long int p;
scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&p);
        if(primo(p)==1){
            printf("Prime\n");
        }
        else{
            printf("Not Prime\n");
        }
    }

}
int primo(long long int x){
    if(x==2){
        return 1;
    }
    for(int i=2;i<sqrt(x);i++){
        if(x%i==0){
            return 0;
        }
    }
    return 1;
}
//2147483646