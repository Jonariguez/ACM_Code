/****************
*PID:uva11100
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=10000+10;
int a[maxn];
set<int> s;
map<int,int> mp;

int main()
{
    int i,j,n,kcase=0;
    while(scanf("%d",&n),n){
        if(kcase) puts("");
        kcase++;
        int res=0;
        mp.clear();
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            res=max(res,++mp[a[i]]);
           // s.insert(a[i]);
        }
        printf("%d\n",res);
        sort(a+1,a+n+1);
        int cnt=(n+res-1)/res;
        for(i=1;i<=res;i++){
            for(j=i;j<=n;j+=res){
                if(j!=i) printf(" ");
                printf("%d",a[j]);
            }
            puts("");
        }
    }
    return 0;
}

