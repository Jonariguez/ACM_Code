/*
原理见P338，uva1363

i一定要是long long的，坑我两次了........
*/
#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;
map<int,long long> m;

int main()
{
    int j,T;
    long long res,t,n,i;
    scanf("%d",&T);
    while(T--){
        scanf("%lld",&n);
        t=m[n];
        if(t){
            printf("%lld\n",t);continue;
        }
        i=1;
        res=0;
        while(i<=n){
            long long p=n/i,q=n%i;
            long long cnt=n-i;
            if(p>0) cnt=min(cnt,q/p);
            res+=(cnt+1)*p;
            i+=cnt+1;
        }
        m[n]=res;
        printf("%lld\n",res);
    }
    return 0;
}
