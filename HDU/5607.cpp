/****************
*PID:hdu5607
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=55,MOD=1e9+7;
int n,m,Q;
vector<int> G[maxn];

struct Mat{
    LL a[55][55];
    Mat operator*(const Mat &r) const {
        Mat res;
        memset(res.a,0,sizeof(res.a));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    res.a[i][j]+=a[i][k]*r.a[k][j]%MOD;
                    if(res.a[i][j]>=MOD)
                        res.a[i][j]-=MOD;
                }
            }
        }
        return res;
    }
}e,ori;

Mat Pow(Mat x,int k){
    Mat res=e;
    while(k){
        if(k&1)
            res=res*x;
        k/=2;
        x=x*x;
    }
    return res;
}

LL quick_pow(LL a,int b){
    LL res=1;
    while(b){
        if(b&1) res=(res*a)%MOD;
        b/=2;
        a=(a*a)%MOD;
    }
    return res;
}

int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    memset(e.a,0,sizeof(e.a));
    for(i=0;i<n;i++){
        e.a[i][i]=1;
        G[i].clear();
    }
    memset(ori.a,0,sizeof(ori));
    for(i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        a--;b--;
        G[a].push_back(b);
    }
    for(i=0;i<n;i++){
        LL t=quick_pow((LL)G[i].size(),MOD-2);
        for(j=0;j<G[i].size();j++){
            int v=G[i][j];
            ori.a[i][v]=t;
        }
    }
    scanf("%d",&Q);
    while(Q--){
        int u,k;
        scanf("%d%d",&u,&k);
        u--;
        Mat res;
        res=Pow(ori,k);
        for(i=0;i<n;i++)
            printf("%I64d ",res.a[u][i]);
        puts("");
    }
    return 0;
}
