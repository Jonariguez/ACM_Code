/****************
*PID:hdu5640
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        int res=0;
        if(n>m)
            swap(n,m);
        while(n!=0 && m!=0){
            if(n>m)
                swap(n,m);
                res+=m/n;
            m%=n;
        }
        printf("%d\n",res);
    }
    return 0;
}
