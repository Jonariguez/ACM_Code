/****************
*PID:hdu5590
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
char s[maxn],t[maxn];

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        scanf("%s%s",s,t);
        for(i=0;i<n;i++){
            if(s[i]=='A' && t[i]=='U' || s[i]=='T' && t[i]=='A' || s[i]=='C' && t[i]=='G' || s[i]=='G' && t[i]=='C')
                continue;
            else break;
        }
        if(i<n)
            printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}
