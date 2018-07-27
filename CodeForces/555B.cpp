#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef __int64 ll;

const int maxn=200000+10;

struct Bridge{
    int id;
    ll L;
}b[maxn];

struct Island{
    ll maxl,minl;
    int id;
}s[maxn];

struct pp{
    int id;
    ll R;
    bool operator < (const pp &r) const {
        return R>r.R;
    }
};

int cmpI(const Island &x,const Island &y){
  //  if(x.maxl==y.maxl) return x.minl<y.minl;
  //  if(x.minl==y.minl) return x.maxl<y.maxl;
    return x.minl<y.minl;
}

int cmpB(const Bridge &x,const Bridge &y){
    return x.L<y.L;
}


int cmp(const pp &x,const pp &y){
    return x.R<y.R;
}

ll x[maxn],y[maxn];
int res[maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        for(i=0;i<n;i++)
            scanf("%I64d%I64d",&x[i],&y[i]);
        for(i=0;i<n-1;i++){
            s[i].maxl=y[i+1]-x[i];
            s[i].minl=x[i+1]-y[i];
            s[i].id=i;
        }
        for(i=0;i<m;i++){
            scanf("%I64d",&b[i].L);
            b[i].id=i+1;
        }
        if(m<n-1){
            printf("No\n");continue;
        }
        priority_queue<pp> pq;
        sort(s,s+n-1,cmpI);
        sort(b,b+m,cmpB);
        ll cur=0;
        int flag=1,cnt=0;
        j=0;
        for(i=0;i<m;i++){
            cur=b[i].L;
            pp t;
            while(j<n-1 && cur>=s[j].minl && cur<=s[j].maxl){
                t.id=s[j].id;t.R=s[j].maxl;
                pq.push(t);
                j++;
            }
            if(pq.empty()) continue;
            t=pq.top();pq.pop();
            if(t.R<cur){
                flag=0;break;
            }
            res[t.id]=b[i].id;
            cnt++;
        }
        if(flag==0 || cnt<n-1)
            printf("No\n");
        else {
            printf("Yes\n");
                for(int i=0;i<n-1;i++){
                    if(i)
                        printf(" ");
                    printf("%d",res[i]);
                }
            printf("\n");
        }
    }
    return 0;
}

