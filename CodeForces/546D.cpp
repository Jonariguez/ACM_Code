#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef __int64 ll;

const int maxn=5000000+10;
ll s[maxn];
bool vis[maxn];

void pre_solve(){
    int i,j;
    memset(vis,0,sizeof(vis));
    memset(s,0,sizeof(s));
    for(i=2;i<=5000000;i++){
        if(!s[i]){
            for(j=i;j<=5000000;j+=i){
                int t=j/i;
                while(true){    //计算j能被i除几次，那么j里就有几个i，自然s[j]就加几次喽
                    s[j]++;
                    if(t%i) break;
                    t/=i;
                }
            }
        }
    }
    s[1]=0;
    for(i=2;i<=5000000;i++)
        s[i]+=s[i-1];
}

int main()
{
    int i,j,a,b,T;
    pre_solve();
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&a,&b);
        printf("%I64d\n",s[a]-s[b]);
    }
    return 0;
}
