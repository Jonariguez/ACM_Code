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

char res[maxn][220];

int order[110];


int main()
{
    int i,j,T,k,m,q;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&k,&m,&q);
        priority_queue<pp> que;
        queue<int> qq;
        for(i=0;i<k;i++){
            scanf("%s%d",s[i].name,&s[i].v);
            s[i].id=i;
        }
        int tot=0;
        for(i=0;i<m;i++)
            scanf("%d%d",&z[i].t,&z[i].p);
        sort(z,z+m,cmp2);
        int maxv=0,b[3],cnt=0;
        for(i=0;i<q;i++){
            scanf("%d",&order[i]);
            if(order[i]>10000)
                b[cnt++]=order[i];
            maxv=max(maxv,order[i]);
        }
        j=0;
        for(i=0;i<m;i++){
            for(;j<z[i].t;j++)
                que.push(s[j]);
            while(!que.empty() && z[i].p--){
                pp d=que.top();que.pop();
                strcpy(res[tot++],d.name);
            }
        }
        sort(b,b+cnt);
        if(maxv>tot && tot<10000){
            while(!que.empty() && tot<maxv && tot<10000){
                pp d=que.top();que.pop();
                strcpy(res[tot++],d.name);
            }
        }
        if(cnt==0){
            for(i=0;i<q;i++){
                    printf("%s%c",res[order[i]-1],i==q-1?'\n':' ');
            }
        }else {
            sort(s+j,s+k,cmp);
            int cntt=tot,v=0;
            for(v=0;v<cnt;v++){
                pp need;
                while(!que.empty() && cntt<b[v]){
                    need=que.top();que.pop();
                }
                if(cntt==b[v]){
                    strcpy(ans[v],need.name);
                    continue;
                }
                strcmp(ans[v],s[j+b[v]-cntt-1].name);
            }
            for(i=0;i<q;i++){
                if(order[i]<=tot)
                    printf("%s%c",res[order[i]-1],i==q-1?'\n':' ');
                else if(order[i]==b[0])
                    printf("%s%c",ans[0],i==q-1?'\n':' ');
                else
                    printf("%s%c",ans[1],i==q-1?'\n':' ');
            }
        }
    }
    return 0;
}


