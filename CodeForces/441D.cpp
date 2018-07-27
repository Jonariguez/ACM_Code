/****************
*PID:441d div2
*Auth:Jonariguez
*****************
要把数列中的一个环通过交换得到有序，
最少的交换次数=环的元素个数-1
将一个n-排列通过交换变成升序需要的最少次数
为n-circnt(circnt为环的个数)
1加环：在某个换里任意交换两个元素可以增加一个环
2减环：把任意两个不同的环的两个元素交换可以把两个环合成一个环
加环可以减少操作次数。
减环可以增加操作次数。
由题中的f(p)和f(q)=m的大小关系来决定是加环还是减环。
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

const int maxn=3000+10;
int a[maxn],nxt[maxn],be[maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        for(i=1;i<=n;i++)
            scanf("%d",&nxt[i]);
        memset(be,0,sizeof(be));
        scanf("%d",&m);
        int circnt=0;
        for(i=1;i<=n;i++){
            if(be[i]==0){
                be[i]=i;
                for(j=nxt[i];j!=i;j=nxt[j]) be[j]=i;
                circnt++;
            }
        }
        if(n-circnt==m){
            puts("0");continue;
        }
        if(n-circnt>m){
            int cnt=n-circnt-m;
            pfn(cnt);
            while(cnt--){
                j=1;
                while(nxt[j]==j) j++;
                int x=n+1,k;
                for(k=nxt[j];k!=j;k=nxt[k])
                    x=min(x,k);
                printf("%d %d ",j,x);
                swap(nxt[j],nxt[x]);
            }
        }else {
            int cnt=m-(n-circnt);
            pfn(cnt);
            int id=be[1];
            while(cnt--){
                for(j=1;j<=n;j++) be[j]=0;
                be[1]=1;
                for(j=nxt[1];j!=1;j=nxt[j]) be[j]=1;
                j=1;
                while(be[j]==1) j++;
                printf("1 %d ",j);
                swap(nxt[1],nxt[j]);
            }
        }
        puts("");
    }
    return 0;
}






