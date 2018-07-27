/****************
*ID:cf567C
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef __int64 ll;

const int maxn=200000+10;
ll a[maxn],cnt;
ll L[maxn],R[maxn];

map<ll,int> id;

int ID(ll x){
    if(id.count(x)==0)
        id[x]=++cnt;
    return id[x];
}

int main()
{
    int i,j,n;
    ll k;
    while(scanf("%d%I64d",&n,&k)!=EOF){
        id.clear();
        cnt=0;
        memset(L,0,sizeof(L));
        memset(R,0,sizeof(R));
        for(i=0;i<n;i++){
            scanf("%I64d",&a[i]);
            R[ID(a[i])]++;
        }
        ll res=0;
        for(i=0;i<n;i++){
            int d=ID(a[i]);
            R[d]--;
            if(a[i]%k==0){
                int x=id.count(a[i]/k);
                int y=id.count(a[i]*k);
                if(x!=0 && y!=0)
                    res+=L[ID(a[i]/k)]*R[ID(a[i]*k)];
            }
            L[d]++;
        }
        printf("%I64d\n",res);
    }
    return 0;
}
