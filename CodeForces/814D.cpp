/****************
*PID:
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,n) for(i=1;i<=(n);i++)
#define rep0(j,n) for(j=0;j<=(n);j++)
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
#define PB push_back
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
typedef long long Ll;
Ll Pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=200000+10;
const int MOD=1e9+7;

int cnt[maxn];

struct Node{
    double x,y,r,ar;
}s[maxn];

double dis(int i,int j){
    return sqrt((s[i].x-s[j].x)*(s[i].x-s[j].x)+(s[i].y-s[j].y)*(s[i].y-s[j].y));
}


int main()
{
    int i,j,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%lf%lf%lf",&s[i].x,&s[i].y,&s[i].r);
        s[i].ar=s[i].r*s[i].r*PI;
    }
    memset(cnt,0,sizeof(cnt));
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j) continue;
            if(dis(i,j)<s[i].r && s[i].r>s[j].r){    //i°üº¬j
                cnt[j]++;
            }
        }
    }
    double res=0;
    for(i=1;i<=n;i++){
        if(cnt[i]==0) res+=s[i].ar;
        else if(cnt[i]&1) res+=s[i].ar;
        else res-=s[i].ar;
    }
    printf("%.8f\n",res);
    return 0;
}




