/*
BIT
一开始算成比自己弱的了。无论算比自己弱的还是强的都能算，都是
固定一端，然后比较另一端。
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=100000+1;
int bit[maxn+10],vis[maxn+10];

struct pp{
    int s,e,id;
}seg[maxn+10];

int cmp(const pp &x,const pp &y){   //注意排序的方式，是先按区间右端降序，相等则按左端升序
    if(x.e==y.e)
        return x.s<y.s;
    return x.e>y.e;
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
    int i,j,n,res;
    while(scanf("%d",&n),n){
        for(i=0;i<n;i++){
            scanf("%d%d",&seg[i].s,&seg[i].e);
            seg[i].id=i;
        }
        sort(seg,seg+n,cmp);
        memset(bit,0,sizeof(bit));
        memset(vis,0,sizeof(vis));
        int cnt=1;
        add(seg[0].s+1,1);      //注意线段可以从0开始，所以要右移一个
        for(i=1;i<n;i++){
            vis[seg[i].id]+=sum(seg[i].s+1);
            if(seg[i].s==seg[i-1].s && seg[i].e==seg[i-1].e){   //要处理相等的情况
                vis[seg[i].id]-=cnt;cnt++;      //这里可以用vis[seg[i].id]=vis[seg[i-1].id],而不用cnt，好机智啊
            }else cnt=1;
            add(seg[i].s+1,1);
        }

        for(i=0;i<n;i++)
            printf("%d%c",vis[i],i==n-1?'\n':' ');
    }
    return 0;
}
