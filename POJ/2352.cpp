/*
BIT
一开始考虑用二维BIT来维护，可数组开不下，还想着要不要离散化一下。。
不过发现它给的数据是y一级，x二级升序输入的，所以边插入边查询就对了。
（其实如果给的数据是乱序，那么我们也可以按y和x排序之后再这样解决，是一样的。（如果是乱序，那么这个题的质量不就更高了吗）
*/
#include <stdio.h>
#include <string.h>

const int maxX=32000+10;
const int N=32001;
const int maxn=15000+10;
int bit[maxX],x[maxn],y[maxn],res[maxn];

void add(int i,int v){
    while(i<=N){
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
    scanf("%d",&n);
    memset(res,0,sizeof(res));
    for(i=0;i<n;i++){
        scanf("%d%d",&x[i],&y[i]);
        add(x[i]+1,1);
        int t=sum(x[i]+1)-1;
        res[t]++;
    }
    for(i=0;i<n;i++)
        printf("%d\n",res[i]);
    return 0;
}
