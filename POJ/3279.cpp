/****************
*PID:poj3279
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

const int maxn=20;
int mp[maxn][maxn],flip[maxn][maxn],ans[maxn][maxn];

int n,m;
int dx[5]={0,1,0,0,-1};
int dy[5]={0,0,1,-1,0};

int get(int x,int y){
    int c=mp[x][y];
    for(int i=0;i<5;i++){
        int xx=x+dx[i],yy=y+dy[i];
        if(xx<1 || xx>m || yy<1 || yy>n) continue;
        c+=flip[xx][yy];
    }
    return c%2;
}

int cal(){
    int i,j;
    for(i=2;i<=m;i++){
        for(j=1;j<=n;j++){
            if(get(i-1,j))
                flip[i][j]=1;
        }
    }
    for(i=1;i<=n;i++)
        if(get(m,i)) return -1;
    int res=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++) res+=flip[i][j];
    return res;
}


int main()
{
    int i,j,res;
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++) sc(mp[i][j]);
    res=-1;
    for(int mask=0;mask<(1<<n);mask++){
        memset(flip,0,sizeof(flip));
        for(i=0;i<n;i++)
            if((mask>>i)&1) flip[1][n-i]=1; //这样选择的第一次遇到的最少次数就是最优解。
        int temp=cal();
        if(temp>=0 && (res<0 || res>temp)){
            res=temp;
            memcpy(ans,flip,sizeof(flip));
        }
    }
    if(res<0)
        puts("IMPOSSIBLE");
    else {
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++)
                printf("%d%c",ans[i][j]," \n"[j==n]);
        }
    }
    return 0;
}


