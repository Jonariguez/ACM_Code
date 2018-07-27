/*
暴力枚举各个长度：
假设长度为a的腿又y条，那么就有两种腿要砍：
一、长度大于a的，全部砍掉
二、长度小于a的，假设有x条，需要砍掉x-y+1条最
好砍的(即d最小的)，

第一种情况可以先预处理前缀和，O(1)的时间求出消耗的d
第二种情况，因为d的范围小，可以用下标法表示，即
small[i]=u，表示长度为i的腿有u条，只需要i从1到200
砍够x-y+1条就可以了。然后时时更新small数组
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
const int maxd=202;
int vis[maxn],a[maxn],l[maxn],sum[maxn],cnt[maxn],small[maxd],n;

struct pp{
    int l,d;
}s[maxn];

int cmp(const pp &x,const pp &y){
    if(x.l==y.l) return x.d<y.d;
    return x.l<y.l;
}

int getBig(int x){
    return sum[n-1]-sum[vis[x]];
}

int getSma(int x){
    int i,res=0;
    for(i=1;i<=200;i++){
        if(x>=small[i]){
            res+=small[i]*i;
            x-=small[i];
        }
        else {
            res+=i*x;break;
        }
    }
    return res;
}


int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF){
        memset(cnt,0,sizeof(cnt));
        int tot=0;
        for(i=0;i<n;i++){
            scanf("%d",&s[i].l);
            if(cnt[s[i].l]==0)
                a[tot++]=s[i].l;
            cnt[s[i].l]++;
        }
        for(i=0;i<n;i++)
            scanf("%d",&s[i].d);
        sort(s,s+n,cmp);
        sum[0]=s[i].d;
        for(i=1;i<n;i++){
            sum[i]=sum[i-1]+s[i].d;
            if(s[i].l!=s[i-1].l)
                vis[s[i-1].l]=i-1;
        }
        vis[s[n-1].l]=n-1;
        int cur,res=20000001;
        for(i=0;i<n;i++){
            if(i==0 || s[i].l!=s[i-1].l){
                int y=cnt[s[i].l],x=i;
                int t=getBig(s[i].l);
                if(x>=y)       //去掉x-y+1个
                    t+=getSma(x-y+1);
                res=min(res,t);
            }
            small[s[i].d]++;
        }
        printf("%d\n",res);
    }
    return 0;
}

