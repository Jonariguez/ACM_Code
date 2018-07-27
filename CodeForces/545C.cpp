/*
需要注意的就是如果第i个树向右倒，那么i+1棵树
也有可能向左倒。
还有就是特判1,2
*/
#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;

const int maxn=100000+10;
int x[maxn],h[maxn];

int main()
{
    int i,n,res;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d%d",&x[i],&h[i]);
    res=1;  //第一棵肯定能倒
    for(i=1;i<n-1;i++){
        if(h[i]<x[i]-x[i-1]){
            res++;
        }
        else if(h[i]<x[i+1]-x[i]){
            x[i]+=h[i];     //如果向右倒的话就相当于x[i]右移了
            res++;
        }
    }
    res++;  //最后一个棵肯定能倒
    if(n==1 || n==2)
        res=n;
    printf("%d\n",res);
    return 0;
}
