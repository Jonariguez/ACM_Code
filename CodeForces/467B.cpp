/****************
*PID:467b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=100000+10;
int a[maxn],bit1[25],bit2[25];

int main()
{
    int i,j,n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        for(i=0;i<=m;i++) scanf("%d",&a[i]);
        int cnt1=0,cnt2=0;
        memset(bit1,0,sizeof(bit1));
        while(a[m]){
            bit1[cnt1++]=(a[m]&1);
            a[m]/=2;
        }
        int res=0;
        for(i=0;i<m;i++){
            cnt2=0;
            memset(bit2,0,sizeof(bit2));
            int cnt=0;
            while(a[i]){
                bit2[cnt2++]=(a[i]&1);
                a[i]/=2;
            }
            for(j=0;j<21;j++)
                if(bit1[j]!=bit2[j]) cnt++;
            if(cnt<=k) res++;
        }
        printf("%d\n",res);
    }
    return 0;
}


