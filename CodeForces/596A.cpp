/****************
*PID:596a div2
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

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        if(n==1){
            int x,y;
            scanf("%d%d",&x,&y);
            printf("-1\n");
        }else if(n==2){
            int x1,x2,y1,y2;
            scanf("%d%d",&x1,&y1);
            scanf("%d%d",&x2,&y2);
            if(x1!=x2 && y1!=y2)
                printf("%d\n",abs(x1-x2)*abs(y1-y2));
            else printf("-1\n");
        }else if(n==3){
            int x1,x2,y1,y2,x3,y3;
            scanf("%d%d",&x1,&y1);
            scanf("%d%d",&x2,&y2);
            scanf("%d%d",&x3,&y3);
            if(x1==x2){
                if(x1==x3) printf("-1\n");
                else if(y3!=y2 && y3!=y1) printf("-1\n");
                else printf("%d\n",abs(y1-y2)*abs(x1-x3));
            }else if(x1==x3){
                if(x1==x2) printf("-1\n");
                else if(y1!=y2 && y3!=y2) printf("-1\n");
                else printf("%d\n",abs(y1-y3)*abs(x1-x2));
            }else if(x2==x3){
                if(x1==x3) printf("-1\n");
                else if(y1!=y2 && y3!=y1) printf("-1\n");
                else printf("%d\n",abs(y3-y2)*abs(x1-x3));
            }else printf("-1\n");
        }else {
            int x[5],y[5],xx[5],yy[5];
            for(i=1;i<=4;i++)
                scanf("%d%d",&x[i],&y[i]);
            for(j=2;j<=4;j++)
                if(x[j]==x[1]) break;
            if(j>4){
                printf("-1\n");continue;
            }
            xx[1]=x[1];yy[1]=y[1];yy[2]=y[j];xx[2]=x[j];
            int k=3;
            for(i=2;i<=4;i++)
                if(j!=i){
                    xx[k]=x[i];yy[k]=y[i];k++;
                }
            if(xx[3]!=xx[4]){
                printf("-1\n");
                continue;
            }
            if(yy[1]==yy[3] && yy[2]==yy[4] || yy[1]==yy[4] && yy[2]==yy[3]){
                printf("%d\n",abs(xx[1]-xx[3])*(max(abs(yy[1]-yy[4]),abs(yy[1]-yy[3]))));
                continue;
            }else printf("-1\n");
        }
    }
    return 0;
}

