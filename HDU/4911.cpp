/*
逆序对(归并)
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+10;

int a[maxn],c[maxn];
ll res;     //结果会爆int

void Inversion(int a[],int L,int R){
    if(L==R) return ;
    int m=(L+R)/2;
    Inversion(a,L,m);
    Inversion(a,m+1,R);
    int i=L,j=m+1,cur=L;
    while(i<=m && j<=R){
        if(a[i]<=a[j])
            c[cur++]=a[i++];
        else
            c[cur++]=a[j++],res+=m-i+1;
    }
    if(i>m)
        while(j<=R) c[cur++]=a[j++];
    else
        while(i<=m) c[cur++]=a[i++];
    for(i=L;i<=R;i++) a[i]=c[i];
}

int main()
{
    int i,j,n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        res=0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        Inversion(a,0,n-1);
        if(res-k<=0)
            printf("0\n");
        else
            printf("%lld\n",res-k);
    }
    return 0;
}
