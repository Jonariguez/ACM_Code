/****************
*PID:518c div2
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

const int maxn=100000+10;
int a[maxn],p[maxn],s[maxn];

int main()
{
    int i,j,k,n,m;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            p[a[i]]=i;
        }
        LL res=0;
        int x;
        for(i=0;i<m;i++){
            scanf("%d",&x);
            int t=p[x];
            res+=t/k+1;
            if(t){
                p[x]=t-1;p[a[t-1]]=t;
                int q=a[t];a[t]=a[t-1];a[t-1]=q;
            }
        }
        printf("%I64d\n",res);
    }
    return 0;
}
