/****************
*PID:uva11489
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
int a[3];
char s[maxn];

int main()
{
    int i,j,sum,n,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        n=strlen(s);
        sum=0;
        a[0]=a[1]=a[2]=0;
        for(i=0;i<n;i++){
            int x=s[i]-'0';
            a[x%3]++;
            sum+=x;
        }
        printf("Case %d: ",kcase++);
        if(sum%3==0){
            if(a[0]%2==0)
                printf("T\n");
            else printf("S\n");
        }else {
            int p=sum%3;
            if(a[p]==0)
                printf("T\n");
            else {
                if(a[0]%2==0)
                    printf("S\n");
                else printf("T\n");
            }
        }
    }
    return 0;
}
