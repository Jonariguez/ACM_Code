/****************
*PID:622c Edu7
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

const int maxn=200000+10;
int a[maxn],last[maxn];

int main()
{
    int i,j,n,m;
    scanf("%d%d",&n,&m);
    memset(last,0,sizeof(last));
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    last[n]=n+1;
    for(i=n-1;i>=1;i--)
        if(a[i]==a[i+1])
            last[i]=last[i+1];
        else last[i]=i+1;
    while(m--){
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        if(a[l]!=x) printf("%d\n",l);
        else {
            if(last[l]>r) puts("-1");
            else printf("%d\n",last[l]);
        }
    }
    return 0;
}
