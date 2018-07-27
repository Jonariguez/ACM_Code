/*
BIT(好题！!)
首先有交点就是两条路的两个端点编号，某条路与另一条路比，在一岸编号小，而在另一岸
编号大，如a--b，c--d，即a>c,b<d或a<c,b>d。
用BIT做就是离线处理(发现用BIT做题多是用离线或逆序处理),先排序，然后保证一岸小，
再去计算另一岸编号比自己小的个数，累加即答案
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=1000+10;

int bit[maxn],n,m;
struct pp{
    int x,y;
}s[1000000];

void add(int i,int v){
    while(i<=m){
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

int cmp(const pp &a,const pp &b){
    if(a.x==b.x)
        return a.y>b.y;     //这样按y降序排序可以不用处理x相等的情况
    return a.x>b.x;
}

int main()
{
    int i,j,k,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&m,&k);
        memset(bit,0,sizeof(bit));
        for(i=0;i<k;i++)
            scanf("%d%d",&s[i].x,&s[i].y);
        sort(s,s+k,cmp);
        ll res=0;
        add(s[0].y,1);
        for(i=1;i<k;i++){
            res+=sum(s[i].y-1);
            add(s[i].y,1);
        }
        printf("Test case %d: %lld\n",kcase++,res);
    }
    return 0;
}
