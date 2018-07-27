/****************
*PID:bc54_2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef __int64 ll;

const int maxn=100+10;
bool vis[1000000];
ll a[maxn],b[maxn];
vector<ll> prime;

void pre_table(){
    ll i,j;
    ll m=(ll)sqrt(2000000000+0.5);
    for(i=2;i<=m;i++){
        if(!vis[i]){
            prime.push_back(i);
            for(j=i*i;j<=m;j+=i)
                vis[j]=1;
        }
    }
}

void solve(ll n,ll &k){
    if(n==1) return ;
    if(n==2 || n==3){
        b[k++]=n;return ;
    }
    ll i;
    int cnt=0,flag=0;
    for(i=0;i<prime.size() && prime[i]*prime[i]<=n;i++){
        ll x;
        if(n%x==0){
            flag=0;
            while(n%x==0){
                b[k++]=x;
                cnt++;
                if(cnt>=2) break;
                n/=x;
            }
        }
        if(cnt>=2) break;
    }
    if(cnt<2 && n>1)
        b[k++]=n;
}

int main()
{
    int i,j,n,T;
    pre_table();
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        ll res=1,t,k=0;
        for(i=0;i<n;i++){
            scanf("%I64d",&a[i]);
            if(a[i]!=1)
                solve(a[i],k);
        }
        sort(b,b+k);
        if(k<2)
            printf("-1\n");
        else
        printf("%I64d\n",b[0]*b[1]);
    }
    return 0;
}
