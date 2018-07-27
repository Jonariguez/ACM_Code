/****************
*PID:bc54
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;

struct pp{
    int v;
    char name[1004];
    int st,en;
}s[maxn];

int cmp(const pp &x,const pp &y){
    return x.v>y.v;
}

char str[1100];

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        getchar();
        for(i=0;i<n;i++){
            gets(str);
            strcpy(s[i].name,str);
            int len=strlen(str);
            j=len-1;
            int v=0;
            while(j>=0 && str[j]!=' '){
                j--;
            }
            for(int k=j+1;k<len;k++)
                v=v*10+str[k]-'0';
            s[i].v=v;s[i].st=0;s[i].en=j-1;
        }
        sort(s,s+n,cmp);
        for(i=0;i<n;i++){
            for(j=s[i].st;j<=s[i].en;j++)
                printf("%c",s[i].name[j]);
            printf("\n");
        }
    }
    return 0;
}

/*
2
2
abc ab 200
abc bc d 100
*/
