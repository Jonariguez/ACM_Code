#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=512*64+10;
const int maxm=128;

int Get(char c){
    if(c>='A' && c<='Z') return c-'A';
    if(c>='a' && c<='z') return c-'a'+26;
    if(c>='0' && c<='9') return c-'0'+52;
    if(c=='+') return 62;
    return 63;
}

void cal(int v,int *c){
    int i,l=6;
    while(v){
        c[--l]=v%2;
        v/=2;
    }
    while(l>0)
        c[--l]=0;
    for(i=0;i<6;i++)
        printf("%d",c[i]);
    printf("\n");
}

int b[500];

void exchange(char *s,int *a){
    int i,j,k,t,d,n;
    int Equal=0;
    n=strlen(s);
    while(s[--n]=='=') Equal++;
    j=0;
    for(i=0;i<=n;i++){
        cal(Get(s[i]),b+j);
        j+=6;
    }
    int mark=3-Equal,l;
    if(mark==3)
        l=j;
    else if(mark==1){
        if(j/8%3==2) l=j/8*8;
        else if(j/8%3==1) l=j/8*8+8;
    }else if(mark==2){
        if(j/8%3==1) l=j/8*8;
        else if(j/8%3==2)
}

int main()
{
    int i,j,n;
    char str[40000];
    int v[5000];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s",str);
        exchange(str,v);
    }
    return 0;
}
