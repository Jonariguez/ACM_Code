/****************
*PID:poj2912
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <cctype>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=500+10;

int par[maxn],rel[maxn],cnt[maxn];
char str[110];
map<int,int> mp;

int find(int x){
    if(par[x]==x) return x;
    int y=find(par[x]);
    if(rel[x]==1){
        if(rel[par[x]]==0)
            rel[x]=2;
        else if(rel[par[x]]==1)
            rel[x]=0;
        else rel[x]=1;
    }else if(rel[x]==0){
        if(rel[par[x]]==0)
            rel[x]=1;
        else if(rel[par[x]]==1)
            rel[x]=2;
        else rel[x]=0;
    }else if(rel[x]==2){
        if(rel[par[x]]==0)
            rel[x]=0;
        else if(rel[par[x]]==1)
            rel[x]=1;
        else rel[x]=2;
    }
    return par[x]=y;
}

int cal(char *str,int len){
    int res=0;
    for(int i=0;i<len;i++)
        res=res*10+(str[i]-'0');
    return res;
}

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

long long seed;
inline long long rand(long long l, long long r) {
	long long mo=1e9+7, g=78125;
	return l+((seed*=g)%=mo)%(r-l+1);
}

LL n;

int main()
{
    LL i,j,res;
    while(scanf("%I64d%I64d",&n,&seed)!=EOF){
        LL maxx=0,maxy=0,minx=1e18,miny=1e18;
        for(i=0;i<n;i++){
            LL x = rand(-1000000000LL, 1000000000LL);
            LL y = rand(-1000000000LL, 1000000000LL);
            maxx=max(x,maxx);
            maxy=max(y,maxy);
            minx=min(x,minx);
            miny=min(y,minx);
        }
        printf("%I64d\n",abs(maxx-minx)+abs(maxy-miny));
    }
    return 0;
}

