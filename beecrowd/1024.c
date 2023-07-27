#include<stdio.h>
char* index_counter(char a[2000],char b[2000]);
int main(){
    char mensagem[2000];
    int numero_de_palavras,index;
    scanf("%d",&numero_de_palavras);
    for(int i=0;i<numero_de_palavras;i++){
        fflush(stdin);
        fgets(mensagem,2000,stdin);
        printf("%s",index_counter(mensagem,mensagem));
    }
}
char* index_counter(char a[2000],char b[2000]){
    int i =0,j=0;
    while(a[i]!='\0'){
        if((a[i]>=65 && a[i]<=90)||(a[i]>=97 && a[i]<=122)){
            a[i]=a[i]+3;
        }
        i++;
    }
    printf("%s\n",a);
    i--;
    while(j<=i){
        //if(j<(i/2)){
        //    b[j]=a[i-j];
        //}
        //else{
        //    b[j]=a[i-j];
        //}
        //
        b[j]=a[i-j];
        j++;
        printf("%s\n",a);
    }
    b[j+1]='\0';
    char* mensagemcriptografada = b;
    return mensagemcriptografada;
}