#include <stdio.h>
#include <math.h>
int main(){
    long long int graos,casos;
    double quadrados;
    scanf("%lld",&casos);
    for(casos;casos>0;casos--){
        scanf("%lf",&quadrados);
        graos=(pow(2.00,quadrados)/12000.00);
        printf("%lld kg\n",graos);
    }
}