/*
KMP
思路和2406一样
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=1000000+10;
char str[maxn];
int next[maxn],n;

void get_next(){
    int i,j;
    next[0]=next[1]=j=0;
    for(i=1;i<n;i++){
        while(j && str[j]!=str[i])
            j=next[j];
        if(str[j]==str[i]) j++;
        next[i+1]=j;
    }
}

int main()
{
    int i,t,kcase=1;
    while(scanf("%d",&n),n){
        scanf("%s",str);
        get_next();
        printf("Test case #%d\n",kcase++);
        for(i=2;i<=n;i++){
            if(next[i]!=0 && i%(i-next[i])==0)
                printf("%d %d\n",i,i/(i-next[i]));
        }
        printf("\n");
    }
    return 0;
}
