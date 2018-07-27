/****************
*PID:520c div2
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
const LL MOD=1e9+7;
char str[maxn];

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        scanf("%s",str);
        int s[4];
        memset(s,0,sizeof(s));
        for(i=0;i<n;i++){
            if(str[i]=='A') s[0]++;
            if(str[i]=='C') s[1]++;
            if(str[i]=='G') s[2]++;
            if(str[i]=='T') s[3]++;
        }
        sort(s,s+4);
        LL cnt=1;
        for(i=3;i>0;i--){
            if(s[i]==s[i-1])
                cnt++;
            else break;
        }
        LL res=1;
        for(i=0;i<n;i++)
            res=(res*cnt)%MOD;
        printf("%I64d\n",res%MOD);
    }
    return 0;
}
