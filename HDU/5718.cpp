/****************
*PID:hdu5718
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

char str[10000008];
int vis[11];

void print(int cur,int c){
    if(cur==9 && vis[cur]==0) return ;
    if(vis[cur]>1){
        vis[cur]--;
        print(cur,(cur+c)/10);
        printf("%d",(cur+c)%10);
    }else if(vis[cur]==1){
        vis[cur]--;
        if(cur!=9){
            print(cur+1,(cur+c)/10);
            printf("%d",(cur+c)%10);
        }else {
            printf("%d",cur+c);
        }
    }else {
        if(cur!=9)
            print(cur+1,c);
        else ;
    }
}

int main()
{
    int i,j,n,T;
    sc(T);
    while(T--){
        scanf("%s",str+1);
        n=strlen(str+1);
        memset(vis,0,sizeof(vis));
        int cnt=0;
        for(i=1;i<=n;i++)
            vis[str[i]-'0']++;
        if(vis[0]>=n-1){
            puts("Uncertain");
            continue;
        }
        int p=1;
        for(;p<=9;p++)
            if(vis[p]) break;
        vis[p]--;
        if(vis[0]){
            vis[0]--;
            for(i=9;i>=0;i--)
                while(vis[i]--) printf("%d",i);
            printf("%d\n",p);
        }else {
            int pp=1;
            for(;pp<=9;pp++)
                if(vis[pp]) break;
            print(pp,p);
            puts("");
        }
    }
    return 0;
}

