#include<stdio.h>
#include<math.h>
int fib(int x);
int main(){
    double dao;
    while(scanf("%lf",&dao)!=EOF){
        printf("%lf",fib(1));


    }
}
double fib(double x){
 double phill=  (pow(1.618,x)-pow(1-1.618,x))/2.236; 
 return phill;
}