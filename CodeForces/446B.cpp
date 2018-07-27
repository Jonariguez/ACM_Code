/****************
*PID:446b div1
*Auth:Jonariguez
*****************
预处理出行和列取i次最多能取多少分dr[i],dc[i]
枚举行取多少次
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=1000+10;
const int maxk=1000000+5;
LL row[maxn],col[maxn],a[maxn][maxn],dr[maxk],dc[maxk];
priority_queue<LL> Row,Col;

int main()
{
    int i,j,n,m,k;
    LL p;
    while(scanf("%d%d%d%I64d",&n,&m,&k,&p)!=EOF){
        memset(col,0,sizeof(col));
        memset(row,0,sizeof(row));
        while(!Row.empty())
            Row.pop();
        while(!Col.empty())
            Col.pop();
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%I64d",&a[i][j]);
                row[i]+=a[i][j];
                col[j]+=a[i][j];
            }
            Row.push(row[i]);
        }
        for(i=1;i<=m;i++)
            Col.push(col[i]);
        for(i=1;i<=k;i++){
            dr[i]=Row.top();Row.pop();Row.push(dr[i]-p*m);
            dr[i]+=dr[i-1];
            dc[i]=Col.top();Col.pop();Col.push(dc[i]-p*n);
            dc[i]+=dc[i-1];
        }
        LL res=-1e17;
        int r;
        for(r=0;r<=k;r++)
            res=max(res,dr[r]+dc[k-r]-p*r*(k-r));
        printf("%I64d\n",res);
    }
    return 0;
}
