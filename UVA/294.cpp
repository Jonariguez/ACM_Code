/*
直接暴力枚举
时间复杂度O(10000*log(10^9))
*/
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int L,int U,long long& res){
    int i,j,x,cnt,ans;
    long long t;
    res=0;
    for(j=L;j<=U;j++){
        x=j;
        t=1;
        for(i=2;i*i<=x;i++){
            if(x%i==0){
                cnt=0;
                while(x%i==0){
                    cnt++;x/=i;
                }
                t*=(cnt+1);
            }
        }
        if(x>1) t*=2;       //如果还有素因子，指数cnt为1，所有要乘2的
        if(t>res){
            res=t;ans=j;
        }
    }
    return ans;
}


int main()
{
    int i,L,U,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&L,&U);
        long long res;
        int num=solve(L,U,res);
        printf("Between %d and %d, %d has a maximum of %lld divisors.\n",L,U,num,res);
    }
    return 0;
}
