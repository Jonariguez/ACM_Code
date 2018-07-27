/****************
*PID:poj3009
*Auth:Jonariguez
*****************
深搜
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int a[22][22],w,h;
int sx,sy,gx,gy,res;

bool check(int x,int y){
    return x==gx && y==gy;
}

void dfs(int x,int y,int now){
    if(now>=res) return ;
    now++;
    int xx=x,yy=y;
    while(yy>0 && a[xx][yy]==0){
        if(check(xx,yy)){
            if(now<=10 && res>now){
                res=now;return;
            }
        }
        yy--;
    }
    if(yy && fabs(yy-y)>=2){     // 没出界,fabs判断两者之间不能相邻才能朝这个方向throw
        a[xx][yy]=0;dfs(xx,yy+1,now);a[xx][yy]=1;
    }
    xx=x;yy=y;
    while(yy<=w && a[xx][yy]==0){
        if(check(xx,yy)){
            if(now<=10 && res>now){
                res=now;return ;
            }
        }
        yy++;
    }
    if(yy<=w && fabs(yy-y)>=2){     // 没出界
        a[xx][yy]=0;dfs(xx,yy-1,now);a[xx][yy]=1;
    }
    xx=x;yy=y;
    while(xx>0 && a[xx][yy]==0){
        if(check(xx,yy)){
            if(now<=10 && res>now){
                res=now;return ;
            }
        }
        xx--;
    }
    if(xx && fabs(xx-x)>=2){     // 没出界
        a[xx][yy]=0;dfs(xx+1,yy,now);a[xx][yy]=1;
    }
    xx=x;yy=y;
    while(xx<=h && a[xx][yy]==0){
        if(check(xx,yy)){
            if(now<=10 && res>now){
                res=now;return ;
            }
        }
        xx++;
    }
    if(xx<=h && fabs(xx-x)>=2){     // 没出界
        a[xx][yy]=0;dfs(xx-1,yy,now);a[xx][yy]=1;
    }
}

int main()
{
    int i,j;
    while(scanf("%d%d",&w,&h)){
        if(w==0 && h==0) break;
        for(i=1;i<=h;i++){
            for(j=1;j<=w;j++){
                scanf("%d",&a[i][j]);
                if(a[i][j]==2){
                    sx=i;sy=j;a[i][j]=0;
                }else if(a[i][j]==3){
                    gx=i;gy=j;a[i][j]=0;
                }
            }
        }
    /*    for(i=1;i<=h;i++){
            for(j=1;j<=w;j++)
            printf("%d ",a[i][j]);
            printf("\n");
        }*/
     //   printf("sx=%d sy=%d\n",sx,sy);
     //   printf("gx=%d gy=%d\n",gx,gy);
        res=11;
        dfs(sx,sy,0);
        if(res==11)
            printf("-1\n");
        else printf("%d\n",res);
    }
    return 0;
}
