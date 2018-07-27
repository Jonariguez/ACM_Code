/****************
*PID:poj2431
*Auth:Jonariguez
*****************
注意后面加个s[n]
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn=10000+10;

struct pp{
    int a,v;
}s[maxn];

int cmp(const pp &x,const pp &y){
    return x.a<y.a;
}

int main()
{
    int i,j,L,p,now,n,res;
    scanf("%d",&n);
    int x;
    for(i=0;i<n;i++)
        scanf("%d%d",&s[i].a,&s[i].v);
    scanf("%d%d",&L,&p);
    for(i=0;i<n;i++)
        s[i].a=L-s[i].a;
    sort(s,s+n,cmp);
    priority_queue<int> que;
    now=p;
    res=0;s[n].v=0;s[n].a=L;
    for(i=0;i<=n;i++){
        while(!que.empty() && s[i].a>now){
            now+=que.top();que.pop();
            res++;
        }
        if(now<s[i].a){
            printf("-1\n");return 0;
        }
        que.push(s[i].v);
    }
    printf("%d\n",res);
    return 0;
}
