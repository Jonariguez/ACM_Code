/****************
*PID:A
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn=150000+10;

struct pp{
    int v,id;
    char name[220];
    bool operator < (const pp &r) const {
        if(v==r.v)
            return id>r.id;
        return v<r.v;
    }
}s[maxn];

int cmp(const pp &x,const pp &y){
    if(x.v==y.v)
        return x.id<y.id;
    return x.v>y.v;
}

struct qq{
    int t,p;
}z[maxn];

int cmp2(const qq &x,const qq &y){
    return x.t<y.t;
}

int res1[maxn];
int order[1110];
priority_queue<pp> que;

int main()
{
    int i,j,T,k,m,q;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&k,&m,&q);
        while(!que.empty())
            que.pop();
        for(i=0;i<k;i++){
            scanf("%s %d",s[i].name,&s[i].v);
            s[i].id=i;
        }
        int tot=0;
        for(i=0;i<m;i++)
            scanf("%d%d",&z[i].t,&z[i].p);
        sort(z,z+m,cmp2);
        int maxv=0;
        for(i=0;i<q;i++){
            scanf("%d",&order[i]);
            maxv=max(maxv,order[i]);
        }
        j=0;
        for(i=0;i<m;i++){
            for(;j<z[i].t;j++)
                que.push(s[j]);
            while(!que.empty() && z[i].p--){
                pp d=que.top();que.pop();
              //  strcpy(res[tot++],d.name);
                res1[tot++]=d.id;
            //  if(tot>=maxv) break;
            }
        }
        while(!que.empty()){
            pp d=que.top();que.pop();
          //  strcpy(res[tot++],d.name);
            res1[tot++]=d.id;
          //  if(tot>=maxv) break;
        }
      //  printf("j=%d\n",j);
        if(tot<maxv)
            sort(s+j,s+k,cmp);
        for(i=0;i<q;i++){
            if(order[i]<=tot)
                printf("%s%c",s[res1[order[i]-1]].name,i==q-1?'\n':' ');
            else
                printf("%s%c",s[order[i]-1].name,i==q-1?'\n':' ');
        }
    }
    return 0;
}


