#include<stdio.h>
int mdc(int x,int y);
int main(){
    int N,F1,F2;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d %d",&F1,&F2);
        if(F1==F2){
            printf("%d\n",F1);
        }
        else if(F1>F2){
            if(F1>500){
                printf("%d\n",mdc(F1%F2,F2%(F1%F2)));
            }
            else printf("%d\n",mdc(F1,F2));
        }
        else if(F2>F1){
            if(F2>500){
                printf("%d\n",mdc(F2%F1,F1%(F2%F1)));
            }
            else printf("%d\n",mdc(F2,F1));
        }
        else if(F1==0) {printf("%d\n",F2);}
        else if(F2==0) {printf("%d\n",F1);;}

    }
}
int mdc(int x,int y){
    for(int i=y;i>=1;i--){
        if(x%i==0&&y%i==0){
            return i;
        }

    }

}