#include <stdio.h>
 
int main() {
 char nome[100];
 float sal,prod,aux,aux2;
 
    scanf("%s %f %f",nome,&sal,&prod);
    aux2 =(sal+(0.15*prod))*100;
    aux =aux2/100;
    printf("TOTAL = R$ %.2f\n",aux);
 
    return 0;
}