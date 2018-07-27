/****************
*PID:463c div2
*Auth:Jonariguez
*****************
两个点的曼哈顿距离为奇数时两点不会同时攻击到同一个点.
由此将区间分为两类，两类之间不会有冲突，取每一类的最大值即可。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=2000+2;
LL a[maxn][maxn],row[maxn*2],col[maxn*2];

struct pp{
    LL v;
    int x,y;
}s[maxn*maxn/2],t[maxn*maxn/2];

int cmp(const pp &a,const pp &b){
    return a.v>b.v;
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                scanf("%I64d",&a[i][j]);
                row[j-i+n]+=a[i][j];
                col[j+i]+=a[i][j];
            }
        }
        int cnt1=0,cnt2=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if((i+j)&1){
                    s[++cnt1].x=i;s[cnt1].y=j;
                    s[cnt1].v=row[j-i+n]+col[j+i]-a[i][j];
                }else {
                    t[++cnt2].x=i;t[cnt2].y=j;
                    t[cnt2].v=row[j-i+n]+col[j+i]-a[i][j];
                }
            }
        }
      //  printf("cnt=%d\n",cnt);
        sort(s+1,s+cnt1+1,cmp);
        sort(t+1,t+cnt2+1,cmp);
        printf("%I64d\n",s[1].v+t[1].v);
        printf("%d %d %d %d\n",s[1].x,s[1].y,t[1].x,t[1].y);
    }
    return 0;
}
