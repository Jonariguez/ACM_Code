/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,n) for(i=1;i<=(n);i++)
#define rep0(i,n) for(i=0;j<=(n);i++)
#define re(i,n) for(i=1;i<(n);i++)
#define re0(i,n) for(i=0;i<(n);i++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define SS(x,y) scanf("%d%d",&x,&y)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#define MP make_pair
#define PB push_back
#define X first
#define Y second
#define PI acos(-1.0)
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>
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
typedef long long Ll;
Ll Pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=4000000+10;
const int MOD=1e9+7;

char str[70005][14];

struct Trie{
    int chi[maxn][11];
    int val[maxn];
    int sz;
    Trie(){sz=1;memset(chi[0],0,sizeof(chi[0])); }
    int idx(char c) { return c-'0';}
    void Insert(char *s){
        int u=0,n=strlen(s),i;
        re0(i,n){
            int c=idx(s[i]);
            if(!chi[u][c]){
                memset(chi[sz],0,sizeof(chi[sz]));
                val[sz]=0;
                chi[u][c]=sz++;
            }
            u=chi[u][c];
            val[u]++;
        }
    }
    void Delete(char *s){
        int u=0,n=strlen(s),i;
        re0(i,n){
            int c=idx(s[i]);
            u=chi[u][c];
            val[u]--;
        }
    }
    int ask(char *s){
        int cnt=0,u=0,n=strlen(s),i;
        re0(i,n){
            int c=idx(s[i]);
            cnt++;
            if(!val[chi[u][c]]){
                return cnt;
            }
            u=chi[u][c];
        }
        return 11;
    }
}tree;

int main()
{
    int i,j,n;
    scanf("%d",&n);
    rep(i,n){
        scanf("%s",str[i]+1);
        for(j=1;j<=9;j++)
            tree.Insert(str[i]+j);
    }
    for(i=1;i<=n;i++){
        rep(j,9)
            tree.Delete(str[i]+j);
        int res=10,start,End;
        for(j=1;j<=9;j++){
            int c=tree.ask(str[i]+j);
            if(res>c){
                start=j;End=j+c-1;res=c;
            }
        }
        for(j=start;j<=End;j++)
            putchar(str[i][j]);
        puts("");
        for(j=1;j<=9;j++)
            tree.Insert(str[i]+j);
    }
    return 0;
}




