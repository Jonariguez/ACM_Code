/*
分治，递推
还有前缀和的思想
*/
#include <stdio.h>
#include <string.h>
typedef long long ll;

long long cal(int k){
    return k==0?1:cal(k-1)*3;
}

long long f(int k,int i){
    if(i<=0) return 0;
    if(k==0) return 1;
    int t=1<<(k-1);
    if(i>=t)
        return f(k-1,i-t)+cal(k-1)*2;
    return 2*f(k-1,i);
}

int main()
{
    int i,T,a,b,k,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&k,&a,&b);
        printf("Case %d: %lld\n",kcase++,f(k,b)-f(k,a-1));
    }
    return 0;
}
