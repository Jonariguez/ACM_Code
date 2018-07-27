/****************
*PID:471d div2
*Auth:Jonariguez
*****************
KMP
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=200000+10;
const LL mod=0x7FFFFFFF;
LL a[maxn],b[maxn],f[maxn],D,res,n,w;
//map<LL,int> Hash;

LL getFail(LL *p,LL *f){
    LL m=w-1;
    f[0]=0;f[1]=0;
    for(LL i=1;i<m;i++){
        LL j=f[i];
        while(j && p[i]!=p[j]) j=f[j];
        f[i+1]=(p[i]==p[j]?j+1:0);
    }
}

void find(LL *T,LL *P,LL *f){
    LL N=n-1,m=w-1;
    getFail(P,f);
    LL j=0;
    for(LL i=0;i<N;i++){
        while(j && P[j]!=T[i]) j=f[j];
        if(P[j]==T[i]) j++;
        if(j==m){
            res++;j=f[j];
        }
    }
}



int main()
{
    int i,j;
    while(scanf("%I64d%I64d",&n,&w)!=EOF){
        scanf("%I64d",&a[0]);
        for(i=1;i<n;i++){
            scanf("%I64d",&a[i]);
            a[i-1]-=a[i];
        }
        scanf("%I64d",&b[0]);
        for(i=1;i<w;i++){
            scanf("%I64d",&b[i]);
            b[i-1]-=b[i];
        }
        if(w==1){
            printf("%d\n",n);
            continue;
        }
        if(n<w){
            printf("0\n");continue;
        }
        getFail(b,f);
        res=0;
        find(a,b,f);
        printf("%I64d\n",res);
    }
    return 0;
}



