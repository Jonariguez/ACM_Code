#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

const int maxn=50000+10;
int a[maxn],fax[maxn][21],fin[maxn][21],n;

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

int main()
{
    int x,y,i,q;
    scanf("%d%d",&n,&q);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    Init();
    while(q--){
        scanf("%d%d",&x,&y);
        printf("%d\n",cal(x-1,y-1));
    }
    return 0;
}
