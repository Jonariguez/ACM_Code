/****************
*PID:476b div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int i,j,n,m;
    char s[12],t[12];
    while(scanf("%s%s",s+1,t+1)!=EOF){
        int p=0;
        n=strlen(s+1);
        for(i=1;i<=n;i++){
            if(s[i]=='+') p++;
            else p--;
        }
        int cnt=0;
        for(i=1;i<=n;i++) if(t[i]=='?') cnt++;
      //  printf("
        int tot=(1<<cnt),res=0;
        for(i=0;i<tot;i++){
            int c=0,now=0;
            for(j=1;j<=n;j++){
                if(t[j]=='+') now++;
                else if(t[j]=='-') now--;
                else {
                    if((i>>c)&1) now++;
                    else now--;
                    c++;
                }
            }
            if(now==p) res++;
        }
      //  printf("tot=%d res=%d\n",tot,res);
        printf("%.10f\n",(double)res/tot);
    }
    return 0;
}
