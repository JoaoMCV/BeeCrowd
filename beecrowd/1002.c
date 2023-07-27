#include<stdio.h>
int main(){
    double raio,pi=3.14159,A;
    while(scanf("%lf",&raio)!=EOF){
        
        A=(raio*raio)*pi;
        printf("A=%.4lf\n",A);
    }
    
}