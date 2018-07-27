/****************
*PID:uva11729
*Auth:Jonariguez
*****************
贪心： J大的先安排
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;

struct pp{
    int B,J;
}s[maxn];

int cmp(const pp &x,const pp &y){
    return x.J>y.J;
}

int main()
{
    int i,j,n,res,kcase=1;
    while(scanf("%d",&n),n){
        for(i=0;i<n;i++)
            scanf("%d%d",&s[i].B,&s[i].J);
        sort(s,s+n,cmp);
        int now=0;
        res=0;
        for(i=0;i<n;i++){
            now+=s[i].B;            //now更新目前交代到的时间
            res=max(res,now+s[i].J);    //res更新目前的兵最迟什么时候结束
        }
        printf("Case %d: %d\n",kcase++,res);
    }
    return 0;
}
