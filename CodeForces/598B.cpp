/****************
*PID:
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=10000+10;
char s[maxn],t[maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%s",s+1)!=EOF){
        scanf("%d",&m);
        n=strlen(s+1);
        while(m--){
            int l,r,k,cnt;
            scanf("%d%d%d",&l,&r,&k);
            cnt=k%(r-l+1);
            if(cnt==0) continue;
            for(i=r-cnt+1,j=l;j<=r;j++){
                t[j]=s[i];
                if(i==r) i=l;
                else i++;
            }
            for(i=l;i<=r;i++)
                s[i]=t[i];
        }
        printf("%s\n",s+1);
    }
    return 0;
}
