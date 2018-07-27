/*
BIT(好题又是)

假设第i个人做裁判，分类讨论(分类加法)：前小后大，前大后小
①设从A1到Ai-1中比Ai小的有x1个，那么比Ai大的就有y1=(i-1-x1)个，
②设从Ai+1到An中比Ai小的有x2个，那么比Ai大的就有y2=(n-i-x2)个
分步乘法：对所有的x1*y2+x2*y1就是答案。
好巧哦，x1和x2都能用树状数组(比Ai小不就是在Ai前面嘛)动态维护求和(哈哈)，
然后y1和y2就能算出来。
求x2时，虽说是求在自己后面的比自己小的个数，那么我们可以逆序插入并查询
*/
#include <stdio.h>
#include <string.h>
typedef long long ll;

const int maxn=20000+10;
const int N=100000;

int bit1[N+10],bit2[N+10];
int a[maxn],small_front[maxn],small_behind[maxn];

void add(int *bit,int i,int v){
    while(i<=N){
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

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(bit1,0,sizeof(bit1));
        memset(bit2,0,sizeof(bit2));
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        ll res;
        for(i=1;i<=n;i++){
            small_front[i]=sum(bit1,a[i]);  //这里参数是a[i]
            add(bit1,a[i],1);
        }
        for(i=n;i>=1;i--){
            small_behind[i]=sum(bit2,a[i]); //这里参数是a[i],不是i
            add(bit2,a[i],1);
        }
        res=0;
        for(i=1;i<=n;i++){
            res+=small_front[i]*(n-i-small_behind[i]);
            res+=(i-1-small_front[i])*small_behind[i];
        }
        printf("%lld\n",res);
    }
    return 0;
}
