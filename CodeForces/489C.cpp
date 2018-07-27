/****************
*PID:489c div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=1000+10;
int a[maxn];

int main()
{
    int i,j,n,m,s;
    while(scanf("%d%d",&m,&s)!=EOF){
        if(m==1 && s==0){
            printf("0 0\n");continue;
        }
        if(s==0 || m*9<s){
            printf("-1 -1\n");continue;
        }
        memset(a,0,sizeof(a));
        int t=s;
        for(i=m;i>=1;i--){
            if(t>9){
                a[i]=9;t-=9;
            }else {
                a[i]=t-1;break;
            }
        }
        a[1]++;
        for(i=1;i<=m;i++) printf("%d",a[i]);
        printf(" ");
        memset(a,0,sizeof(a));
        for(i=1;i<=m;i++){
            if(s>9){
                a[i]=9;s-=9;
            }else {
                a[i]=s;break;
            }
        }
        for(i=1;i<=m;i++) printf("%d",a[i]);
        puts("");
    }
    return 0;
}

