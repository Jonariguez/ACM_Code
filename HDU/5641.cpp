/****************
*PID:hdu5641
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

const int maxn=1000+10;
LL a[maxn];
int vis[11],col[11],row[11];

int main()
{
    int i,j,n,m,T;
    scanf("%d",&T);
    col[1]=1;col[2]=2;col[3]=3;
    col[4]=1;col[5]=2;col[6]=3;
    col[7]=1;col[8]=2;col[9]=3;
    row[1]=1;row[2]=1;row[3]=1;
    row[4]=2;row[5]=2;row[6]=2;
    row[7]=3;row[8]=3;row[9]=3;
    while(T--){
        scanf("%d",&n);
        int f=0;
        for(i=1;i<=n;i++){
            scanf("%I64d",&a[i]);
            if(a[i]<=0 || a[i]>9) f=1;
        }
        if(f || n<4){
            printf("invalid\n");
            continue;
        }
        int yes=0;
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;i++){      //ÖØ¸´
            vis[a[i]]++;
            if(vis[a[i]]>1){
                yes=1;
                break;
            }
        }
        if(yes){
            puts("invalid");
            continue;
        }
        yes=1;
        memset(vis,0,sizeof(vis));
        vis[a[1]]=1;
        for(i=2;i<=n;i++){
            if(vis[a[i]]){
                yes=0;break;
            }
            vis[a[i]]=1;
            if(row[a[i-1]]==row[a[i]]){
                if(abs(a[i]-a[i-1])==1) continue;
                if(vis[(a[i]+a[i-1])/2]==0){
                    yes=0;break;
                }
            }else if(col[a[i]]==col[a[i-1]]){
                if(abs(a[i]-a[i-1])==3) continue;
                if(vis[(a[i]+a[i-1])/2]==0){
                    yes=0;break;
                }
            }else {
                if(a[i]==1 && a[i-1]==9 || a[i]==9 && a[i-1]==1 || a[i]==3 && a[i-1]==7 || a[i]==7 && a[i-1]==3){
                    if(vis[5]==0){
                        yes=0;break;
                    }
                }
            }

        }
        if(yes==0)
            puts("invalid");
        else puts("valid");
    }
    return 0;
}
