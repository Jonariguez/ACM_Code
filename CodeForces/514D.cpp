/****************
*PID:
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
const int maxm=7;
int head[maxm],tail[maxm],que[maxm][maxn],a[maxn][maxm],ans[maxm];

int main()
{
    int i,j,n,m,k;
    while(scanf("%d%d%d",&n,&m,&k)!=EOF){
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        if(n==1 || k==0){
            int sum=0;
            for(i=1;i<=m;i++) sum+=a[1][i];
            if(sum<=k)
                for(i=1;i<=m;i++) printf("%d ",a[1][i]);
            else for(i=1;i<=m;i++) printf("0 ");
            continue;
        }
        for(i=0;i<=m;i++){
            head[i]=1;tail[i]=0;
        }
      //  puts("");
        int s=1,t=1,resa,resb,res=0,now=0,temp=0;
        while(t<n){
            while(t<=n){
                now=temp;temp=0;
                for(i=1;i<=m;i++){
                    int v=a[t][i];
                    temp+=max(a[que[i][head[i]]][i],v);
                }
            //    printf("t=%d\n",t);
                if(temp<=k){
                    for(i=1;i<=m;i++){
                        int v=a[t][i];
                        while(tail[i]>=head[i] && v>=a[que[i][tail[i]]][i]) tail[i]--;
                        que[i][++tail[i]]=t;
                  //      printf("tail=%d ",tail[i]);
                        temp+=a[que[i][head[i]]][i];
                  //      printf("%d \n",que[i][head[i]]);
                    }
                 //   puts("");
                    t++;
                }
                else break;
            }
            if(t-s>res){
                res=t-s;
                for(i=1;i<=m;i++) ans[i]=que[i][head[i]];
            }
            if(t>=n) break;
            for(i=1;i<=m;i++)
                if(que[i][head[i]]==s) head[i]++;
            s++;now=0;
           // printf("t=%d\n",t);
        }
        for(i=1;i<=m;i++)
            printf("%d ",a[ans[i]][i]);
        puts("");
    }
    return 0;
}
