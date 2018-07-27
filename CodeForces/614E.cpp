/****************
*PID:617e div2
*Auth:Jonariguez
*****************
pre[i]=a[1]^a[2]^a[3]^..^a[i] 前缀异或和
a[l]^a[l+1]^..^a[r]=k -->pre[r]^pre[l-1]=k;
a^k^a=k^(a^a)=k^0=k

每个的枚举区间其实就是L-1≤i<j≤R
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;
LL sum[maxn],cnt[(1<<21)],a[maxn],res[maxn],n,m,k,unit;

struct command{
    LL L,R,id;
}s[maxn];

int cmp(const command &x,const command &y){
    if(x.L/unit==y.L/unit)
        return x.R<y.R;
    return x.L/unit<y.L/unit;
}

void solve(){
    LL L=1,R=0,i,now=0,v;
    for(i=0;i<m;++i){
        while(R<s[i].R){
            R++;
            v=sum[R]^k;
            now+=cnt[v];
            cnt[sum[R]]++;
        }
        while(R>s[i].R){
            cnt[sum[R]]--;
            v=sum[R]^k;
            now-=cnt[v];
            R--;
        }
        while(L<s[i].L-1){
            cnt[sum[L]]--;
            v=sum[L]^k;
            now-=cnt[v];
            L++;
        }
        while(L>s[i].L-1){
            L--;
            v=sum[L]^k;
            now+=cnt[v];
            cnt[sum[L]]++;
        }
        res[s[i].id]=now;
    }
}

int main()
{
    int i,j;
    while(scanf("%I64d%I64d%I64d",&n,&m,&k)!=EOF){
        sum[0]=0;
        for(i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
            sum[i]=sum[i-1]^a[i];
        }
        for(i=0;i<m;i++){
            scanf("%I64d%I64d",&s[i].L,&s[i].R);
            s[i].id=i;
        }
        memset(cnt,0,sizeof(cnt));
        unit=(LL)sqrt(n);
        sort(s,s+m,cmp);
        solve();
        for(i=0;i<m;++i)
            printf("%I64d\n",res[i]);
    }
    return 0;
}
