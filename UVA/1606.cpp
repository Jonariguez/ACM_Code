/****************
*PID:uva1606
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

struct Point{
    int x,y;
    double rad;     //极角
    bool operator < (const Point &r) const {
        return rad<r.rad;
    }
}p[maxn],op[maxn];

int n,color[maxn];

bool Left(Point a,Point b){
    return a.x*b.y-a.y*b.x>=0;
}

int solve(){
    int i,j,k,res=0;
    for(i=0;i<n;i++){   //枚举基准点O
        k=0;            //其他点的个数，当然是等于n-1
        for(j=0;j<n;j++){
            if(j==i) continue;
            p[k].x=op[j].x-op[i].x;
            p[k].y=op[j].y-op[i].y;
            if(color[j]){
                p[k].x=-p[k].x;p[k].y=-p[k].y;  //因为这样可以改变left(即叉积的符号),而叉积又正好是我们判断
            }                                   //位置关系的依据，既然能改变符号，就能把“左侧”变成“右侧”
            p[k].rad=atan2(p[k].y,p[k].x);
            k++;
        }
        sort(p,p+k);

        int L=0,R=0,cnt=2;
        while(L<k){
            if(R==L){
                R=(R+1)%k;cnt++;    //不懂。。
            }
            while(R!=L && Left(p[L],p[R])){
                cnt++;
                R=(R+1)%k;
            }
            cnt--;  //不懂。。。
            L++;
            res=max(res,cnt);
        }
    }
    return res;
}

int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        for(i=0;i<n;i++)
            scanf("%d%d%d",&op[i].x,&op[i].y,&color[i]);
        printf("%d\n",solve());
    }
    return 0;
}



