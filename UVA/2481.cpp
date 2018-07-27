/*
BIT
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=100000;
int vis[maxn+10],bit[maxn];

struct pp{
    int s,e,id;
}seg[maxn+10];

int cmp(const pp &x,const pp &y){
    if(x.s==y.s)
        return x.e<y.e;
    return x.s>y.s;
}

void add(int i,int v){
    while(i<=maxn){
        bit[i]+=v;
        i+=i&(-i);
    }
}

int sum(int i){
    int res=0;
    while(i>0){
        res+=bit[i];
        i-=i&(-i);
    }
    return res;
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n),n){
        for(i=0;i<n;i++){
            scanf("%d%d",&seg[i].s,&seg[i].e);
            seg[i].id=i;
        }
        sort(seg,seg+n,cmp);
        memset(vis,0,sizeof(vis));
        memset(bit,0,sizeof(bit));
        seg[n].s=-1;seg[n].e=maxn+2;
        add(seg[0].e,1);
        int cnt=1,flag=0;
        for(i=1;i<n;i++){           //seg[0]对应的id号线段肯定是最弱的，不用处理也行
            vis[seg[i].id]+=sum(seg[i].e);
            if(seg[i].s==seg[i-1].s && seg[i].e==seg[i-1].e){    //和自己相等的不能算，所以应该减去
                vis[seg[i].id]-=cnt;cnt++;     //计算相等的线段条数，等不再相等时再一块加上cnt条
            }
            add(seg[i].e,cnt);
        /*    if(seg[i].s!=seg[i+1].s || seg[i].e!=seg[i+1].e){
                if(flag==0)
                    cnt=1;
                add(seg[i].e,cnt);
              //  printf("cnt=%d\n",cnt);
                cnt=1;
            }*/
        }
        for(i=0;i<n;i++)
            printf("%d%c",vis[i],i==n-1?'\n':' ');
    }
    return 0;
}
