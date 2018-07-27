/****************
*PID:447b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;
char str[maxn];
int vis[30];

int main()
{
    int i,j,n,m,k;
    while(scanf("%s",str+1)!=EOF){
        n=strlen(str+1);
        scanf("%d",&k);
        int a=0;
        for(i=0;i<26;i++){
            scanf("%d",&vis[i]);
            a=max(a,vis[i]);
        }
        LL res=0;
        for(i=1;i<=n;i++){
            res+=(LL)vis[str[i]-'a']*i;
        }
        while(k--){
            res+=(LL)a*i;
            i++;
        }
        printf("%I64d\n",res);
    }
    return 0;
}
