/****************
*PID:uva10340
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
char s[maxn],t[maxn];

int main()
{
    int i,n,m;
    while(scanf("%s%s",s,t)!=EOF){
        int cur=0;
        n=strlen(s);
        m=strlen(t);
        for(i=0;i<m;i++){
            if(t[i]==s[cur])
                cur++;
            if(cur==n) break;
        }
        if(cur<n)
            printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}
