/****************
*PID:626a div2
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

const int maxn=200+10;
char s[maxn];

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        int res=0;
        scanf("%s",s+1);
        for(i=1;i<=n;i++){
            int l=0,u=0;
            for(j=i+1;j<=n;j++){
                l=0;u=0;
                for(int k=i;k<=j;k++){
                    if(s[k]=='U') u++;
                    else if(s[k]=='R') l++;
                    else if(s[k]=='D') u--;
                    else l--;
                }
                if(l==0 && u==0) res++;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
