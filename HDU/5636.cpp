/****************
*PID:hdu5636
*Auth:Jonariguez
*****************
�������ߵĶ˵㿴���ؼ�����floyd��Ȼ��������x,y
����̾���ʱ������"6"���µ�֮��ľ���������
���롣
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+5;
const LL MOD=1e9+7;
int a[10],d[10][10];

int main()
{
    int i,j,k,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=3;i++){
            scanf("%d%d",&a[i],&a[i+3]);
        }
        for(i=1;i<=6;i++){
            for(j=1;j<=6;j++){
                d[i][j]=abs(a[i]-a[j]);
            }
        }
        for(i=1;i<=3;i++)
            d[i][i+3]=d[i+3][i]=1;
        for(k=1;k<=6;k++){
            for(i=1;i<=6;i++){
                for(j=1;j<=6;j++){
                    if(d[i][j]>d[i][k]+d[k][j])
                        d[i][j]=d[i][k]+d[k][j];
                }
            }
        }
        int x,y;
        LL res=0;
        for(k=1;k<=m;k++){
            scanf("%d%d",&x,&y);
            int ans=abs(x-y);
            for(i=1;i<=6;i++){
                for(j=1;j<=6;j++){
                    ans=min(ans,abs(x-a[i])+d[i][j]+abs(a[j]-y));
                }
            }
            res=(res+(LL)k*ans)%MOD;
        }
        printf("%lld\n",res);
    }
    return 0;
}


