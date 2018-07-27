/****************
*PID:hdu1385
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

const int maxn=2000+10;
const int INF=1e9;
int mp[maxn][maxn],path[maxn][maxn],b[maxn];
int n;

void Init(){
    int i,j;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            if(i==j) mp[i][j]=0;
            else mp[i][j]=INF;
            path[i][j]=j;   //path[i][j]:标志i到j的最短路径经过的第一个点
        }
}

void floyd(){
    int i,j,k;
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(mp[i][k]==INF || mp[k][j]==INF) continue;
                int temp=mp[i][k]+mp[k][j]+b[k];
                if(mp[i][j]>temp){
                    mp[i][j]=temp;
                    path[i][j]=path[i][k];
                }else if(mp[i][j]==temp && path[i][j]>path[i][k])
                    path[i][j]=path[i][k];
            }
        }
    }
}

int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        Init();
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                scanf("%d",&mp[i][j]);
                if(mp[i][j]==-1)
                    mp[i][j]=INF;
            }
        }
        for(i=1;i<=n;i++)
            scanf("%d",&b[i]);
        floyd();
        int g,h;
        while(scanf("%d%d",&g,&h)!=EOF){
            if(g==-1 && h==-1) break;
            printf("From %d to %d :\n",g,h);
            if(g==h){
                printf("Path: %d\n",g);
                printf("Total cost : 0\n\n");
                continue;
            }
            int res=mp[g][h];
            printf("Path: %d",g);
            while(g!=h){
                g=path[g][h];
                printf("-->%d",g);
            }
            puts("");
            printf("Total cost : %d\n\n",res);
        }
    }
    return 0;
}




