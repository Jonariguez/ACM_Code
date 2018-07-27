/****************
*PID:605a div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;

LL quick_pow(LL a,LL b,LL m){
    a=(a%m+m)%m;
    LL res=1;
    while(b){
        if(b&1) res=(res*a)%m;
        b/=2;
        a=(a*a)%m;
    }
    return res;
}

int main()
{
    int i,j,n,m,a,b,c,x,y,z;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF){
        scanf("%d%d%d",&x,&y,&z);
        if(a>=x && b>=y && c>=z){
            printf("Yes\n");continue;
        }
        if(a<x && b<y && c<z){
            printf("No\n");continue;
        }
        int sum1=0,sum2=0,cnt=0;
        if(a>=x) sum1=(a-x)/2;
        else sum2+=x-a;
        if(b>=y) sum1+=(b-y)/2;
        else sum2+=y-b;
        if(c>=z) sum1+=(c-z)/2;
        else sum2+=z-c;
        if(sum1>=sum2)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
