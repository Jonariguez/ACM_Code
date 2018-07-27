/****************
*PID:hdu5578
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <set>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=1000+10;
char s[maxn];

int main()
{
    int i,j,n,m,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);
        n=strlen(s+1);
        int res=10000+10;
        for(i=1;i<=n;i++){
            int x=s[i]-'a';
            for(j=1;j<=n;j++){
                if(i!=j && s[j]-'a'==x)
                    res=min(res,abs(j-i));
            }
        }
        if(res==10000+10)
            res=-1;
        printf("Case #%d: %d\n",kcase++,res);
    }
    return 0;
}
