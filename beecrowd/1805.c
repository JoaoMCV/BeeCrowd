#include<stdio.h>
int main(){double a,b;while(scanf("%lf %lf",&a,&b)!=EOF){printf("%.0lf\n",((a+b)*(b-a+1))/2);}}