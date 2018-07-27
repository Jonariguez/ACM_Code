/****************
*PID:465a div2
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
char s[maxn];

int main()
{
    int i,j,n,m;
    while(scanf("%d",&n)!=EOF){
        int res=0;
        scanf("%s",s+1);
        for(i=1;i<=n;i++){
            if(s[i]=='1')
                res++;
            else{
                res++;break;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
