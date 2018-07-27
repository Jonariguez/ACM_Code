/*
hash + 二分
二分答案，即长度，最大化最大值。
对于每个长度x，一个有n-x+1个真子串
在n-x+1个子串的hash值中找是否有多于
或等于k个的相同值，有则x符合，调大x；
否则调小x
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAGIC 1121117

const int maxn=20000+10;
int n,k,a[maxn];
int hash[maxn],fac[maxn],s[maxn];   //fac[i]是MAGIC^i,hash[i]是a[0]至a[i]转化成MAGIC进制的数，a[0]权最大

//直接计算得出将a[l...r]转化成MAGIC进制的数
int Get(int l,int r){
    if(l==0) return hash[r];
    return hash[r]-hash[l-1]*fac[r-l+1];
}

bool C(int x){
    int i,j,tot=0;
    for(i=0;i+x-1<n;i++){
        int v=Get(i,i+x-1);
        s[tot++]=v;
    }
    sort(s,s+tot);
    int sum=-1,now=1;
    for(i=1;i<tot;i++){
        if(s[i]==s[i-1])
            now++;
        else now=1;
        sum=max(sum,now);
    }
    return sum>=k;
}

int main()
{
    int i,j;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    fac[0]=1;
    for(i=1;i<=n;i++)
        fac[i]=fac[i-1]*MAGIC;
    hash[0]=a[0];
    for(i=1;i<n;i++)
        hash[i]=hash[i-1]*MAGIC+a[i];
    int l=0,r=n;
    while(l<r-1){
        int m=(l+r)/2;
        if(C(m))
            l=m;
        else r=m;
    }
    printf("%d\n",l);
    return 0;
}
