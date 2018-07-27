/****************
*PID:hdu5497
*Auth:Jonariguez
*****************
要删除m长度的区间，因为长度固定，那么只需枚举起点，然后维护。
一开始删除开头的[1,m-1]区间，所以此时的逆序对数只算区间[m,n]的即可，
然后将"m区间"右移一位，设此时区间为[i,i+m-1],那么右移一位，即是：
将A[i]添加上，A[i+m]去掉。如下：
[1....i----i+m-1,i+m,~~~~~~n]       (....部分为一步一步添加的，用c维护，~~~~~~部分是放好的需要一步步去掉的，用d
设now为目前的逆序对数。
加上A[i],则增加的逆序对数为：
①A[i]以前(...部分)比A[i]大的，   -----------用c BIT维护
②A[i+m]及后面比A[i]小的          -----------用d BIT维护
加上A[i]:add(c,A[i],1)
去掉A[i+m]，则减少的逆序对数为：
①A[i]及以前比A[i+m]大的           -----------用c BIT维护
②A[i+m]及后面比A[i+m]小的         -----------用d BIT维护
去掉A[i+m]:add(d,A[i+m],-1);
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;
int n,m;
int A[maxn],c[maxn],d[maxn];

void add(int *bit,int i,int v){
    while(i<=n){
        bit[i]+=v;
        i+=i&(-i);
    }
}

int sum(int *bit,int i){
    int res=0;
    while(i>0){
        res+=bit[i];
        i-=i&(-i);
    }
    return res;
}

LL solve(){
    int i,j;
    memset(c,0,sizeof(c));
    memset(d,0,sizeof(d));
    LL now=0;
    for(i=n;i>m;i--){
        now+=sum(d,A[i]-1); //注意这里是A[i]-1
        add(d,A[i],1);
    }
    LL res=now;
    for(i=1;i+m-1<=n;i++){
        res=min(res,now);
        if(i+m>n) break;
        now+=sum(c,n)-sum(c,A[i])+sum(d,A[i]-1);
        add(c,A[i],1);

        now-=sum(c,n)-sum(c,A[i+m])+sum(d,A[i+m]-1);
        add(d,A[i+m],-1);
    }
    return res;
}

int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%d",&A[i]);
        printf("%lld\n",solve());
    }
    return 0;
}
