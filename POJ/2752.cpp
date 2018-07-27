#include <stdio.h>
#include <string.h>

const int maxn=400000+10;
int next[maxn],n;
char str[maxn];

void build_next(){
    int i,j;
    n=strlen(str);
    next[0]=next[1]=j=0;
    for(i=1;i<n;i++){
        while(j && str[j]!=str[i])
            j=next[j];
        if(str[j]==str[i]) j++;
        next[i+1]=j;
    }
}

void print(int x){
    if(next[x]){
        print(next[x]);
        printf(" ");
    }
    printf("%d",x);
}

int main()
{
    int i,j;
    while(scanf("%s",str)!=EOF){
        build_next();
        print(n);
        printf("\n");
    }
    return 0;
}
