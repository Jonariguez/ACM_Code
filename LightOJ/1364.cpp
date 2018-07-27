/****************
*PID:lightoj1364
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

const int maxn=100+10;
int C,D,H,S,cnt[maxn];
double dp[15][15][15][15][5][5];

void Init(){
    int i,j,c,d,h,s;
    for(c=0;c<=13;c++)
    for(d=0;d<=13;d++)
    for(h=0;h<=13;h++)
    for(s=0;s<=13;s++)
    for(i=0;i<=4;i++)
    for(j=0;j<=4;j++)
    dp[c][d][h][s][i][j]=-1.0;
}

//分别为当前C，D，H，S的个数和大小王代表的花色(1,2,3,4)
double dfs(int c,int d,int h,int s,int x1,int x2){
    if(c>13 || d>13 || h>13 || s>13) return 0;  //这是不可能出现这样的情况，其实是这样的概率为0，概率为0期望自然为0
    cnt[1]=c;cnt[2]=d;cnt[3]=h;cnt[4]=s;
    if(x1) cnt[x1]++;
    if(x2) cnt[x2]++;
    double &res=dp[c][d][h][s][x1][x2];
    if(res>-0.5) return res;
    res=0;
    if(cnt[1]>=C && cnt[2]>=D && cnt[3]>=H && cnt[4]>=S) return res;
    int tot=cnt[1]+cnt[2]+cnt[3]+cnt[4];
    int k,now=54-tot;
    if(now==0) return 0;
    if(x1==0){
        double temp=1000;
        for(k=1;k<=4;k++)
            temp=min(temp,dfs(c,d,h,s,k,x2));   //具体是当做什么花色，这里贪心地取最小值
        res+=temp;
    }
    if(x2==0){
        double temp=1000;
        for(k=1;k<=4;k++)
            temp=min(temp,dfs(c,d,h,s,x1,k));
        res+=temp;
    }
    res+=(13-c)*dfs(c+1,d,h,s,x1,x2)+(13-d)*dfs(c,d+1,h,s,x1,x2)+(13-h)*dfs(c,d,h+1,s,x1,x2)
        +(13-s)*dfs(c,d,h,s+1,x1,x2);
    res=res/now+1;
    return res;
}

int main()
{
    int i,j,T,kcase=1;
    sc(T);
    while(T--){
        scanf("%d%d%d%d",&C,&D,&H,&S);
        int x=0;
        x+=max(0,C-13);x+=max(0,D-13);
        x+=max(0,H-13);x+=max(0,S-13);
        printf("Case %d: ",kcase++);
        if(x>2){
            puts("-1");continue;
        }
        Init();
        printf("%.9f\n",dfs(0,0,0,0,0,0));
    }
    return 0;
}





