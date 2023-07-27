#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(){
    int k,t,p=0,flag=0;
    char str[3001],num[5];
    int length =0;
    while(length<3000){
            str[length]=' ';
            length++;
    }
        str[3000]='\0';
    while(scanf("%s",str)!=EOF){
        for(int i=2999;i>=0;i--){
            if(str[i]=='\0'){
                k=i;
                break;
            }

        }
        if(flag>0){
            printf("\n");
        }
        flag++;
        str[k]=' ';
        num[3]=str[k-1];
        num[2]=str[k-2];
        num[1]=str[k-3];
        num[0]=str[k-4];
        int x = atoi(num);
    
        int sum,sp,si;
        sum=0,sp=0,si=0;
        for (int i= k; i>=0; i--)
        {
            if ((str[i] >= '0') && (str[i] <= '9'))
            {
                if((i+1)%2==0){
                    sp+=(str[i]-'0');
                }
                if((i+1)%2!=0){
                    si+=(str[i]-'0');
                }
                sum += (str[i] - '0');

            }
        }
        p=0;
        if(x%4==0 && x%100!=0){
            printf("This is leap year.\n");
            p=1;
        }
        if(x%16==0 && x%25==0){
            printf("This is leap year.\n");
            p=1;
        }
        if(sum%3==0 && x%5==0){
            printf("This is huluculu festival year.\n");
            if(p!=1){
                p=2;
            }
        }
        if((sp-si)%11==0 && x%5==0 && p==1){
            printf("This is bulukulu festival year.\n");
            p=1;
        }
        if(p==0){
            printf("This is an ordinary year.\n");
        }
        sum=0,sp=0,si=0;    
    }
}
