/****************
*PID:628c edu8
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=100000+10;

char str[maxn],res[maxn];

int main()
{
    int i,j,n,k;
    while(scanf("%d%d",&n,&k)!=EOF){
        scanf("%s",str+1);
        int flag=0;
        for(i=1;i<=n;i++){
            int t=(str[i]-'a')+1;
            int d=t-1;
            flag=0;
            if(d<26-t){
                d=26-t;flag=1;
            }
            if(d<k){
                if(flag) res[i]='z';
                else res[i]='a';
                k-=d;
            }else {
                if(flag) res[i]=str[i]+k;
                else res[i]=str[i]-k;
                k=0;
                break;
            }
        }
        for(++i;i<=n;i++) res[i]=str[i];
        res[n+1]='\0';
        if(k)
            puts("-1");
        else printf("%s\n",res+1);
    }
    return 0;
}
