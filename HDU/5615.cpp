/****************
*PID:hdu5615
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

int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        LL a,b,c;
        scanf("%I64d%I64d%I64d",&a,&b,&c);
        LL d=b*b-4*a*c;
        if(d<0){
            puts("NO");continue;
        }
        LL f=floor(sqrt(d+0.5));
        if(f*f==d)
            puts("YES");
        else puts("NO");
    }
    return 0;
}
