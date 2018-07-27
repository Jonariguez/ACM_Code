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

char str[maxn];
int sum[2000],ans[30][2000];

int main()
{
    int i,j,n,k;
    scanf("%d",&n);
    scanf("%s",str+1);
    for(i=0;i<26;i++){
        sum[0]=0;
        for(j=1;j<=n;j++)
            if(str[j]-'a'!=i) sum[j]=sum[j-1];
            else sum[j]=sum[j-1]+1;
        for(j=1;j<=n;j++){
            for(k=1;k<=n;k++){
                int l=k,r=n,res=0;
                while(l<=r){
                    int m=(l+r)/2;
                    if((m-k+1)-(sum[m]-sum[k-1])<=j){
                        res=m;l=m+1;
                    }else r=m-1;
                }
                ans[i][j]=max(ans[i][j],res-k+1);
            }
        }
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int m;
        scanf("%d%s",&m,str);
        int d=str[0]-'a';
        printf("%d\n",ans[d][m]);
    }


    return 0;
}




