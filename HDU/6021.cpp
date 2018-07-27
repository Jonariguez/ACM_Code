/****************
*PID:hdu6021
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

LL Pow(LL a,LL b){
    LL res=1;
    while(b){
        if(b&1)
            res=(res*a)%MOD;
        b/=2;
        a=(a*a)%MOD;
    }
    return res;
}

int cnt[30],c[30],vis[30];
char str[30];
LL fact[30];

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

int LCM(int a,int b){
    int g=gcd(a,b);
    return a/g*b;
}

vector<int> cir;

int main()
{
    fact[0]=1;
    for(int i=1;i<=26;i++)
        fact[i]=(fact[i-1]*i)%MOD;
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("%s",str+1);
        memset(vis,0,sizeof(vis));
        for(i=1;i<=26;i++){
            c[i]=1;
            int t=(str[i]-'a')+1;
            while(t!=i){
                c[i]++;
                t=(str[t]-'a')+1;
            }
            vis[c[i]]++;
        }
        cir.clear();
        for(i=1;i<=26;i++){
           // printf("i=%d vis[i]=%d\n",i,vis[i]);
            if(vis[i]){
                cir.push_back(i);cnt[cir.size()-1]=vis[i];
               // printf("cir[%d]=%d,cnt[%d]=%d\n",cir.size()-1,cir[cir.size()-1],cir.size()-1,cnt[cir.size()-1]);
            }
        }
        int N=(int)cir.size();
        int all=(1<<N);
        LL res=0;
        for(i=1;i<all;i++){
            int c_one=0,lcm=1;
            for(j=0;j<N;j++){
                if((i>>j)&1){
                    c_one++;
                    lcm=LCM(lcm,cir[j]);
                }
            }
            LL ans=0;
            for(int S0=i;S0;S0=(S0-1)&i){
                int c_ones=0;
                LL sum=0;
                for(j=0;j<N;j++){
                    if((S0>>j)&1){
                        c_ones++;
                        sum+=cnt[j];
                    }
                }
                if((c_one&1)!=(c_ones&1))
                    ans=(ans-Pow(sum,(LL)n)+MOD)%MOD;
                else ans=(ans+Pow(sum,(LL)n))%MOD;
            }
            res+=ans*lcm;
            res%=MOD;
        }
        printf("%lld\n",res);
    }
    return 0;
}


