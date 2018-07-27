#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

//注意尺取法的思想，不要只固定在尺取下标，还可以尺取前缀和，只要是单调的量都可以尺取，好！
const int maxn=100000+10;
int n;
struct pp
{
    int v,id;
}ss[maxn];

int cmp(const pp &x,const pp &y){
    if(x.v==y.v) return x.id<y.id;
    return x.v<y.v;
}

void ask(int x){
    int i,s,t,sum,indexs,indext,Min,res;
    Min=1000000002;
    s=0,t=1;res=ss[0].v;
    while(s<=n && t<=n){
        int temp=ss[t].v-ss[s].v;
        if(abs(temp-x)<Min){
            indexs=ss[s].id;indext=ss[t].id;
            Min=abs(temp-x);
            res=temp;
        }
        if(temp>x)
            s++;
        else if(temp<x) t++;
        else break;
        if(s==t) t++;
    }
    if(indexs>indext) swap(indexs,indext);
    printf("%d %d %d\n",res,indexs+1,indext);     //注意indexs要加1
}

int main()
{
    int i,j,t,sum,v,k,T;
    while(scanf("%d%d",&n,&k)){
        if(n==0 && k==0) break;
        sum=0;
        ss[0].id=ss[0].v=0;
        for(i=1;i<=n;i++){
            scanf("%d",&t);
            sum+=t;
            ss[i].id=i,ss[i].v=sum;
        }
        sort(ss,ss+n+1,cmp);
        while(k--){
            scanf("%d",&v);
            ask(v);
        }
    }
    return 0;
}
