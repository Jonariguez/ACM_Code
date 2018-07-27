/****************
*PID:hdu5455
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000000+10;
char str[maxn];

int main()
{
    int i,j,n,T,kcase=1;
    scanf("%d",&T);
    while(T--){
        scanf("%s",str);
        printf("Case #%d: ",kcase++);
        n=strlen(str);
        if(n<=2){
            printf("-1\n");
            continue;
        }
        int res=0,b=maxn,cnt=0,k=0;
        bool yes=true;
        for(i=0;i<n;i++)
            if(str[i]=='c') break;
        if(i==n){
            printf("%d\n",n);
            continue;
        }
        int m=0;
        for(++i;m<n;m++){
            if(str[i]=='c'){
                if(cnt<2){
                    yes=false;
                    break;
                }
                res++;
                cnt=0;
            }else if(str[i]=='f')
                cnt++;
            else {
                yes=false;break;
            }
            i=(i+1)%n;
        }
        if(yes)
            printf("%d\n",res);
        else
            printf("-1\n");
    }
    return 0;
}

