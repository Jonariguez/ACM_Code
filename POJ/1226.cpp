#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=100+5;
char str[maxn][maxn],sub1[maxn],sub2[maxn];
int next[maxn];

void Strcpy(char *a,int s,int t,char *c){
    int i,k=0;
    for(i=s;i<=t;i++) c[k++]=a[i];
    c[k]='\0';
}

void Reverse(char *a,char *b){
    int i,n;
    n=strlen(a);
    for(i=0;i<n;i++) b[i]=a[n-i-1];
    b[n]='\0';
}

void get_next(char *p){
    int i,j,n;
    n=strlen(p);
    next[0]=next[1]=j=0;
    for(i=1;i<n;i++){
        while(j && p[j]!=p[i]) j=next[j];
        if(p[j]==p[i]) j++;
        next[i+1]=j;
    }
}

bool KMP(const char *a,char *b){
    int i,j,n,m;
    n=strlen(a);
    m=strlen(b);
    if(m>n) return false;
    get_next(b);
    j=0;
    for(i=0;i<n;i++){
        while(j && b[j]!=a[i]) j=next[j];
        if(b[j]==a[i]) j++;
        if(j==m) return true;
    }
    return false;
}


int main()
{
    int i,j,res,n,len,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%s",str[i]);
        res=0;
        len=strlen(str[0]);
        for(i=0;i<len;i++){
            for(j=i;j<len;j++){
                Strcpy(str[0],i,j,sub1);
                Reverse(sub1,sub2);
                int k;
                for(k=1;k<n;k++){
                    if(!KMP(str[k],sub1) && !KMP(str[k],sub2)) break;
                }
                if(k==n)
                    res=max(res,j-i+1);
            }
        }
        printf("%d\n",res);
    }
    return 0;
}

