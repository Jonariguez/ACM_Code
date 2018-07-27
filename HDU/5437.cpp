/****************
*PID:hdu5437
*Auth:Jonariguez
*****************
Changchun 01
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=150000+10;

struct pp{
    int id,v;
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

struct time{
    int t,p;
    bool operator < (const time &r) const {
        return t<r.t;
    }
}z[maxn];

int order[110],res[maxn];

priority_queue<pp> que;

int main()
{
    int i,j,T,m,q,k;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&k,&m,&q);
        for(i=0;i<k;i++){
            scanf("%s%d",s[i].name,&s[i].v);
            s[i].id=i;
        }
        for(i=0;i<m;i++){
            scanf("%d%d",&z[i].t,&z[i].p);
        }
        int d=m;
        sort(z,z+m);
     /*   m=0;
        for(i=1;i<d;i++){
            if(z[i].t==z[i-1].t){
                z[m].t=z[i].t;z[m].p+=z[i].p;
            }else {
                z[++m].t=z[i].t;z[m].p=z[i].p;
            }
        }
        printf("m=%d\n",m);
        for(i=0;i<=m;i++)
            printf("t=%d p=%d\n",z[i].t,z[i].p);
        printf("\n");*/
        for(i=0;i<q;i++)
            scanf("%d",&order[i]);
        while(!que.empty())
            que.pop();
        j=0;
        int tot=0;
     /*   for(i=0;i<=m;i++){
            while(j<z[i].t){
                que.push(s[j]);j++;
            }
            while(!que.empty() && z[i].p--){
                pp d=que.top();que.pop();
                res[tot++]=d.id;
            }
        }
        while(!que.empty()){
            pp d=que.top();que.pop();
            res[tot++]=d.id;
        }*/
        z[m].t=maxn;
        for(i=0;i<k;i++){
            que.push(s[i]);
            if(i==z[j].t-1){
                int num=z[j].p;
                while(!que.empty() && num--){
                    res[tot++]=que.top().id;
                    que.pop();
                }
                j++;
            }
        }
        while(!que.empty()){
            pp d=que.top();que.pop();
            res[tot++]=d.id;
        }
        for(i=0;i<q;i++)
            printf("%s%c",s[res[order[i]-1]].name,i==q-1?'\n':' ');
    }
    return 0;
}
