/****************
*PID:uva437
*Auth:Jonariguez
*****************
给出每个立方体的x,y,z之后，分别按照各种方式放置
共6种，则把这个6个状态都存起来，然后底面两边长x,y
排序，z作为高，然后求最长上升子序列。
注意每个立方体的个数是无限的，所以每个立方体的
6种状态都可能选，所以都存下来了
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=33;

int dp[maxn*7];

struct pp{
    int x,y,z;
    pp(int xx=0,int yy=0,int zz=0):x(xx),y(yy),z(zz){}
}s[maxn*7];

int cmp(const pp &a,const pp &b){
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

int main()
{
    int i,j,n,kcase=1;
    while(scanf("%d",&n),n){
        int m=0,x,y,z;
        for(i=0;i<n;i++){
            scanf("%d%d%d",&x,&y,&z);
            s[m++]=pp(x,y,z);
            s[m++]=pp(x,z,y);
            s[m++]=pp(y,x,z);
            s[m++]=pp(y,z,x);
            s[m++]=pp(z,x,y);
            s[m++]=pp(z,y,x);
        }
        sort(s,s+m,cmp);
        int res=0;
        for(i=0;i<m;i++){
            dp[i]=s[i].z;
            for(j=0;j<i;j++)
                if(s[i].x>s[j].x && s[i].y>s[j].y)
                    dp[i]=max(dp[i],dp[j]+s[i].z);
            res=max(res,dp[i]);
        }
        printf("Case %d: maximum height = %d\n",kcase++,res);
    }
    return 0;
}

