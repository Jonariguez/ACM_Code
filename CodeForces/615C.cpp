/****************
*PID:615c div2
*Auth:Jonariguez
*****************
暴力匹配，正着反着各扫一遍
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=2200;
char s[maxn],t[maxn],ss[maxn];
int ans[maxn][2];

int main()
{
    int i,j,n,m,res;
    while(scanf("%s%s",s+1,t+1)!=EOF){
        n=strlen(s+1);m=strlen(t+1);
        strcpy(ss+1,s+1);strrev(ss+1);
      //  printf("s=%s\nss=%s\nt=%s\n",s+1,ss+1,t+1);
        res=0;
        int yes=1;
        for(i=1;i<=m;){
            int pos=i,now,p1,p2;
            for(j=1;j<=n;j++){
                int k=j;
                now=i;
                while(k<=n && s[k]==t[now]) k++,now++;
              //  printf("k1=%d now1=%d\n",k,now);
                if(pos<now){
                    pos=now;
                    p1=j;p2=k-1;
                }
            }
            for(j=1;j<=n;j++){
                int k=j;
                now=i;
                while(k<=n && ss[k]==t[now]) k++,now++;
              //  printf("k2=%d now2=%d\n",k,now);
                if(pos<now){
                    pos=now;
                    p1=n-j+1;p2=n-k+2;
                }
            }
            if(pos==i){
                yes=0;break;
            }
            i=pos;
            ans[res][0]=p1;ans[res++][1]=p2;
        }
        if(yes==0) res=-1;
        printf("%d\n",res);
        for(i=0;i<res;i++)
            printf("%d %d\n",ans[i][0],ans[i][1]);
    }
    return 0;
}
