/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define SS(x,y) scanf("d",&x,&y)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#define MP make_pair
#define X first
#define Y second
#define PI acos(-1.0)
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

const int maxn=200000+10;
const int MOD=1e9+7;
int a[maxn],b[maxn],cnt[maxn],per[maxn],vis[maxn],c[maxn];
bool h[maxn];

map<int,int> mp;
vector<int> vec[maxn];

int cmp(int i,int j){
    return vis[i]>vis[j];
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        memset(cnt,0,sizeof(cnt));
        memset(vis,0,sizeof(vis));
        memset(h,0,sizeof(h));
        mp.clear();
        int sum=0;
        for(i=1;i<=n;i++){
            scanf("%d%d",&a[i],&b[i]);
            cnt[a[i]]++;
            vec[a[i]].push_back(b[i]);
            vis[a[i]]=b[i];
            per[i]=i;
            mp[b[i]]=i;
            if(!h[a[i]]) sum++;
            h[a[i]]=1;
        }
        sort(per+1,per+n+1,cmp);
        int q;
        scanf("%d",&q);
        while(q--){
            int k;
            scanf("%d",&k);
            int s=0;
            for(i=1;i<=k;i++){
                scanf("%d",&c[i]);
                if(h[c[i]])
                    s++;
            }
            if(s==sum){
                printf("0 0\n");continue;
            }
            sort(c+1,c+k+1,cmp);
            i=j=1;
            while(i<=k){
                if(per[i]!=c[i]) break;
                i++;
            }
            int temp1=per[i];
            j=i+1;
            while(i<=k){
                if(per[j]!=c[i]) break;
                j++;i++;
            }
            int temp2=per[j];
            int maxx=vis[temp2];
            int id=upper_bound(vec[temp1].begin(),vec[temp1].end(),maxx)-vec[temp1].begin();
            int tt=vec[temp1][id];
            printf("%d %d\n",a[mp[tt]],b[mp[tt]]);
        }
    }
    return 0;
}





