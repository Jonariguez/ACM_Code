/****************
*PID:zoj3768
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;

int sum[100000],cnt;
map<int,int> mp;

void init(){
    cnt=1;
    mp[1]=1;
    sum[1]=1;
    while(true){
        if(sum[cnt]>=123456789) break;
        cnt++;
        sum[cnt]=sum[cnt-1]+cnt;
        mp[sum[cnt]]=cnt;
    }
}

bool solve(int x){
    int l=1,r=upper_bound(sum,sum+cnt,x)-sum;
    while(l<=r){
        if(sum[l]+sum[r]>x)
            r--;
        else if(sum[l]+sum[r]<x)
            l++;
        else {
            printf("%d %d",l,r);
            return true;
        }
    }
    return false;
}

int main()
{
    int i,j,n,T;
    init();
    cnt++;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if(mp.count(n)){
            printf("%d\n",mp[n]);
            continue;
        }
        if(solve(n)){
            printf("\n");
            continue;
        }
        int r=upper_bound(sum,sum+cnt,n)-sum;
        for(i=1;i<r;i++){
            if(solve(n-sum[i])){
                printf(" %d\n",i);
                break;
            }
        }
    }
    return 0;
}
