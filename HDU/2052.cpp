#include <stdio.h>

void print(char c,int len,char a){
    printf("%c",c);
    for(int i=0;i<len;i++)
        printf("%c",a);
    printf("%c",c);
}

int main()
{
    int h,i,l;
    while(scanf("%d%d",&l,&h)!=EOF){
        for(i=0;i<=h+1;i++){
            if(i==0 || i==h+1)
                print('+',l,'-');
            else
                print('|',l,' ');
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
