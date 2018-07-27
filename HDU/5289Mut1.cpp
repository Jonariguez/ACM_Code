/*
枚举左端点，二分右端点+ST
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+10;
int a[maxn],fax[maxn][21],fin[maxn][21],n,k;

void Init(){
    int i,j,k;
    for(i=0;i<n;i++)
        fax[i][0]=fin[i][0]=a[i];
    k=int(log(double(n))/log(2.0));
    for(j=1;j<=k;j++)
        for(i=0;i<n;i++)
            if(i+(1<<j)-1<n){
                fax[i][j]=max(fax[i][j-1],fax[i+(1<<(j-1))][j-1]);
                fin[i][j]=min(fin[i][j-1],fin[i+(1<<(j-1))][j-1]);
            }
}

int cal(int l,int r){
    int k=(int)(log((double)(r-l+1))/(log(2.0)));
    int maxv=max(fax[l][k],fax[r-(1<<k)+1][k]);
    int minv=min(fin[l][k],fin[r-(1<<k)+1][k]);
    return maxv-minv;
}

bool C(int i,int x){
    return cal(i,x)<k;
}


int main()
{
    int i,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        Init();
        ll res=0;
        for(i=0;i<n;i++){
            int l=i,r=n-1;
            while(l<r){
                int m=(l+r)/2+1;
                if(C(i,m))
                    l=m;
                else r=m-1;
            }
            res+=l-i+1;
        }
        printf("%lld\n",res);
    }
    return 0;
}
