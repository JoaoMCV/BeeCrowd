#include <stdio.h>
#include<math.h>
int main(){
int i;
double p,a,ap, pi=3.14159265358979323846;
scanf("%d",&i);
for(i;i>0;i--){
    scanf("%lf",&p);
   ap= p/(2.00f*tan((36*pi)/180.00f));
   a = ((p*5.00f)*ap)/2.00f;
    //a=(5.00*(p*p))/(4.00*tan(0.628319));
    printf("%.3lf\n",a);
}

}
//(5.00*(p*p)/(4.00*tan(0.628319))
//\n