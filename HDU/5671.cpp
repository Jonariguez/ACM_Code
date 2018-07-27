/****************
*PID:hdu5671
*Auth:Jonariguez
*****************
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

const int maxn=1000+10;
int mp[maxn][maxn];
int col[maxn],row[maxn];
int pc[maxn],pr[maxn];

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        int n,m,q;
        scanf("%d%d%d",&n,&m,&q);
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                sc(mp[i][j]);
        for(i=1;i<=n;i++)
            row[i]=i;
        for(i=1;i<=m;i++)
            col[i]=i;
        memset(pc,0,sizeof(pc));
        memset(pr,0,sizeof(pr));
        for(i=1;i<=q;i++){
            int a,b,c;
            scanf("%d%d%d",&c,&a,&b);
            if(c==1)
                swap(row[a],row[b]);
            else if(c==2)
                swap(col[a],col[b]);
            else if(c==3)
                pr[row[a]]+=b;
            else if(c==4)
                pc[col[a]]+=b;
        }
        for(i=1;i<=n;i++){
            int r=row[i];
            for(j=1;j<=m;j++){
                int c=col[j];
                printf("%d%c",mp[r][c]+pr[r]+pc[c]," \n"[j==m]);
            }
        }
    }
    return 0;
}



