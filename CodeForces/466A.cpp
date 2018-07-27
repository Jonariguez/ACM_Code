/****************
*PID:466a div2
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
int a[maxn];

int main()
{
    int i,j,n,m,a,b,res;
    while(scanf("%d%d%d%d",&n,&m,&a,&b)!=EOF){
        res=0;
        if(m>n){
            if(b>=a*n)
                printf("%d\n",a*n);
            else printf("%d\n",b);
        }else {
            if(b>=a*m){
                res+=a*m*(n/m);
                n%=m;
                if(b>a*n)
                    res+=a*n;
                else res+=b;
            }else {
                res+=b*(n/m);
                n%=m;
                if(b>a*n)
                    res+=a*n;
                else res+=b;
            }
            printf("%d\n",res);
        }
    }
    return 0;
}
