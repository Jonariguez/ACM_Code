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

const int maxn=10000000+10;
const int MOD=1e9+7;
map<LL,int> mp;

typedef struct Trie{
    int val[maxn],chi[maxn][2],Size;
    void Init(){
        memset(val,0,sizeof(val));
        memset(chi[0],0,sizeof(chi[0]));
        Size=1;
    }
    void Insert(LL v){
        int now=0,i;
        for(i=32;i>=0;i--){
            int t=0;
            if((v>>i)&1) t=1;
            if(chi[now][t]==0){
                memset(chi[Size],0,sizeof(chi[Size]));
                chi[now][t]=Size++;
            }
            now=chi[now][t];
            val[now]++;
        }
    }
    void Delete(LL v){
        int now=0,i;
        for(i=32;i>=0;i--){
            int t=0;
            if((v>>i)&1) t=1;
            now=chi[now][t];
            val[now]--;
        }
    }
    LL ask(LL v){
        LL res=0;
        int now=0,i;
        for(i=32;i>=0;i--){
            int t=0;
            if((v>>i)&1) t=1;
            t^=1;
            if(chi[now][t] && val[chi[now][t]]){
                res|=(1<<i);
                now=chi[now][t];
            }else if(chi[now][t^1] && val[chi[now][t^1]])
                now=chi[now][t^1];
            else break;
        }
        return res;
    }
}Trie;

Trie trie;

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        mp.clear();
        char str[22];
        LL x;
        trie.Init();
        trie.Insert(0LL);
        while(n--){
            scanf("%s",str);
            scanf("%I64d",&x);
            if(str[0]=='+'){
                if(mp[x]==0)
                    trie.Insert(x);
                mp[x]++;
            }else if(str[0]=='-'){
                if(mp[x]==1)
                    trie.Delete(x);
                mp[x]--;
            }else printf("%I64d\n",trie.ask(x));
        }
    }
    return 0;
}

