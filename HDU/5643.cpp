/****************
*PID:hdu5643
*Auth:Jonariguez
*****************
约瑟夫变形即可。
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=5000+5;
int f[maxn];

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        f[1]=0;
        for(i=2;i<=n;i++){
            f[i]=(f[i-1]+n-i+1)%i;
        }
        printf("%d\n",f[n]+1);
    }
    return 0;
}
