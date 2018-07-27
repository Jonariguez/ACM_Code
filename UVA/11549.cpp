/****************
*PID:uva11549
*Auth:Jonariguez
*****************
set≈–÷ÿ
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <set>
#include <iostream>
#include <sstream>
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
    int i,j,T,n,k;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&k);
        set<int> s;
        int res=k;
        while(!s.count(k)){
            s.insert(k);
            res=max(res,k=next(n,k));
        }
        printf("%d\n",res);
    }
    return 0;
}
