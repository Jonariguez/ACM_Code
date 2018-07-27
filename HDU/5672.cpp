/****************
*PID:hdu5672
*Auth:Jonariguez
*****************
³ßÈ¡
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=1000000+10;
char a[maxn];
int vis[33];

int main()
{
    int i,j,n,m,T;
    sc(T);
    while(T--){
        scanf("%s",a+1);
        n=strlen(a+1);
        LL res=0;
        int k;
        scanf("%d",&k);
        int s=1,t=1;
        memset(vis,0,sizeof(vis));
        int cnt=0;
        for(;t<=n;t++){
            while(t<=n && cnt<k){
                if(vis[a[t]-'a']==0){
                    cnt++;
                }
                vis[a[t]-'a']++;
                if(cnt<k)
                    t++;
                else break;
            }
            if(t>n) break;
            res+=n-t+1;
            vis[a[s]-'a']--;
            if(vis[a[s]-'a']==0){
                cnt--;
            }
            s++;
            if(cnt>=k){
                t--;
            }

        }
        printf("%I64d\n",res);
    }
    return 0;
}



