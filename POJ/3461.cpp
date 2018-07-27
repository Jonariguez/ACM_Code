#include <stdio.h>
#include <string.h>

const int maxw=10000+10;
const int maxt=1000000+10;
char W[maxw],T[maxt];
int next[maxw];

void get_next(){
    int i,j,n;
    n=strlen(W);
    next[0]=next[1]=j=0;
    for(i=1;i<n;i++){
        while(j && W[j]!=W[i])
            j=next[j];
        if(W[j]==W[i]) j++;
        next[i+1]=j;
    }
}

int kmp(){
    int i,j,n,m,res=0;
    n=strlen(T);
    m=strlen(W);
    get_next();
    j=0;
    for(i=0;i<n;i++){
        while(j && W[j]!=T[i])
            j=next[j];
        if(W[j]==T[i])
            j++;
        if(j==m){
            res++;j=next[j];
        }
    }
    return res;
}

int main()
{
    int i,n;
    scanf("%d",&n);
    while(n--){
        scanf("%s%s",W,T);
        printf("%d\n",kmp());
    }
    return 0;
}
