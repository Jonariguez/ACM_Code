/****************
*PID:uva11549
*Auth:Jonariguez
*****************
Floyd ÅÐÈ¦
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int buf[100];

int next(int n,int k){
    if(k==0) return 0;
    long long K=(long long)k*k;
    int p=0;
    while(K){
        buf[p++]=K%10;K/=10;
    }
    n=min(p,n);
    int v=0;
    for(int i=0;i<n;i++)
        v=v*10+buf[--p];
    return v;
}

int main()
{
    int i,T,n,k;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        int res=k,k1=k,k2=k;
        do{
            k1=next(n,k1);
            k2=next(n,k2);
            res=max(res,k2);
            k2=next(n,k2);
            res=max(res,k2);
        }while(k1!=k2);
        printf("%d\n",res);
    }
    return 0;
}
