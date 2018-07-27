/****************
*PID:hdu5033
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const double PI=acos(-1.0);
const int maxn=100000+10;
const int inf=10000000+10;
int n,m;
double res[maxn];

struct Build{
    int x,h;
}s[maxn*4],st[maxn*4];

int cmp1(const Build &a,const Build &b){
    return a.x<b.x;
}

struct Order{
    int x,id;
}q[maxn];

int cmp2(const Order &a,const Order &b){
    return a.x<b.x;
}

bool judge(Build a,Build b,Build c){        //这里c写成&c就WA，因为if会对c进行修改......
    if(c.h<=0) c.h=0;
    return (long long)(c.h-b.h)*(c.x-a.x)>=(long long)(c.h-a.h)*(c.x-b.x);
}

double getAngle(Build &a,Build &b){
    return atan((double)(b.x-a.x)/(double)a.h);
}

void pre_solve(){
    int i,j,t;
    int top=0;
    for(i=0;i<n;i++){
        if(s[i].h<=0){
            while(top>=2 && judge(st[top-2],st[top-1],s[i]))
                top--;
            res[-s[i].h]+=getAngle(st[top-1],s[i]);
        }else{
            while(top && st[top-1].h<=s[i].h)
                top--;
            while(top>=2 && judge(st[top-2],st[top-1],s[i]))
                top--;
            st[top++]=s[i];
        }
    }
}

int main()
{
    int i,j,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d%d",&s[i].x,&s[i].h);
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%d",&q[i].x);
            s[n].x=q[i].x;s[n++].h=-i;
            q[i].id=i;
        }
        memset(res,0,sizeof(res));
        sort(s,s+n,cmp1);
        sort(q,q+m,cmp2);
        pre_solve();
        reverse(s,s+n);
        for(i=0;i<n;i++)
            s[i].x=10000000-s[i].x;
        pre_solve();
        printf("Case #%d:\n",kcase++);
        for(i=0;i<m;i++)
            printf("%.10lf\n",res[i]*180.0/PI);
    }
    return 0;
}
