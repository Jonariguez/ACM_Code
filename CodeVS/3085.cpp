/****************
*PID:cdvs3085
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

const int mod=1000;

map<int,int> mp;

int quick_pow(int a,int b){
    int res=1;
    while(b){
        if(b&1) res=(res*a)%mod;
        b/=2;
        a=(a*a)%mod;
    }
    return res;
}

int main()
{
    int i,j,n,m,p;
    scanf("%d",&p);
    for(n=1;;n++){
        int t=quick_pow(p,n);
        if(mp[t]!=0){
            printf("%d %d\n",n,mp[t]);
            return 0;
        }
        mp[t]=n;
    }
    return 0;
}
