/*
哈希 最多的相同等级的人的个数就是答案
hash,next等这些在HDUOJ都是已用变量
*/
#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;
#define MOD 70003
typedef long long ll;

const int maxn=3000+10;
map<ll,int> mp;

int main()
{
    int i,j,n,res;
    while(scanf("%d",&n)!=EOF){
        res=-1;
        ll x;
        mp.clear();
        for(i=0;i<n;i++){
            scanf("%lld",&x);
            res=max(res,++mp[x]);
        }
        printf("%d\n",res);
    }
    return 0;
}
