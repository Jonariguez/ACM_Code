/****************
*PID:hdu5585
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=40;
char s[maxn];

int main()
{
    int i,j,now,n;
    while(scanf("%s",s+1)!=EOF){
        n=strlen(s+1);
        if(s[n]=='5' || (s[n]-'0')%2==0){
            printf("YES\n");continue;
        }
        now=0;
        for(i=1;i<=n;i++)
            now=(now+s[i]-'0')%3;
        if(now==0)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
