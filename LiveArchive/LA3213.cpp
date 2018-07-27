/****************
*PID:la3213
*Auth:Jonariguez
*****************
交换位置：无论怎么交换，只要保证个数相等就可以了
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;

char s[maxn],t[maxn];
int a[maxn],b[maxn];

int main()
{
    int i,j,n;
    while(scanf("%s%s",t,s)!=EOF){
        n=strlen(s);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(i=0;i<n;i++){
            a[t[i]-'A']++;
            b[s[i]-'A']++;
        }
        sort(a,a+26);
        sort(b,b+26);
        for(i=0;i<26;i++){
            if(a[i]!=b[i]) break;
        }
        if(i==26)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

