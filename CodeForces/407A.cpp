/****************
*PID:407a div1
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

const int maxn=1000000+10;
int f[maxn];
vector<pair<int,int> > A,B;

bool solve(int n,vector<pair<int,int> > &p){
    p.clear();
    int temp=n*n;
    bool ok=false;
    for(int x=1;x*x<=temp/2;x++){
        int y=temp-x*x;
        if(f[y]){
            y=f[y];ok=true;
            p.push_back(make_pair(x,y));
        }
    }
    return ok;
}

int main()
{
    int i,j,n,m,a,b;
    memset(f,0,sizeof(f));
    f[0]=0;f[1]=1;
    for(i=2;i<=1000;i++){
        f[i*i]=i;
    }
    while(scanf("%d%d",&a,&b)!=EOF){
        int ax,ay,bx,by;
        A.clear();
        B.clear();
        if(a>b) swap(a,b);
        int temp=b*b-a*a;
        if(solve(a,A) && solve(b,B)){
            int yes=0;
            for(i=0;i<A.size();i++){
                for(j=0;j<B.size();j++){
                    ax=A[i].first;ay=A[i].second;
                    bx=B[j].first;by=B[j].second;
                    if(ax*by==bx*ay && bx!=ay){
                        yes=1;break;
                    }
                }
                if(yes) break;
            }
            if(yes==0){
                if(temp && f[temp]){
                    int x=f[temp],y=a;
                    a=min(x,y);b=max(x,y);
                    if(solve(a,A) && solve(b,B)){
                        int yes2=0;
                        for(i=0;i<A.size();i++){
                            for(j=0;j<B.size();j++){
                                ax=A[i].first;ay=A[i].second;
                                bx=B[j].first;by=B[j].second;
                                if(ax*by==bx*ay && bx!=ay){
                                    yes2=1;break;
                                }
                            }
                            if(yes2) break;
                        }
                        if(yes2==0){
                            puts("NO");
                        }else {
                            puts("YES");
                            printf("0 0\n");
                            printf("%d %d\n",bx,by);
                            printf("%d %d\n",ay,-ax);
                        }
                    }else puts("NO");
                }else puts("NO");
            }else {
                puts("YES");
                printf("0 0\n");
                printf("%d %d\n",bx,by);
                printf("%d %d\n",ay,-ax);
            }
        }else if(temp && f[temp]){
            int x=f[temp],y=a;
            a=min(x,y);b=max(x,y);
            if(solve(a,A) && solve(b,B)){
                int yes2=0;
                for(i=0;i<A.size();i++){
                    for(j=0;j<B.size();j++){
                        ax=A[i].first;ay=A[i].second;
                        bx=B[j].first;by=B[j].second;
                        if(ax*by==bx*ay && bx!=ay){
                            yes2=1;break;
                        }
                    }
                    if(yes2) break;
                }
                if(yes2==0){
                    puts("NO");
                }else {
                    puts("YES");
                    printf("0 0\n");
                    printf("%d %d\n",bx,by);
                    printf("%d %d\n",ay,-ax);
                }
            }else puts("NO");
        }else puts("NO");
    }
    return 0;
}
