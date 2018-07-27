/****************
*PID:617d div2
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
    int i,j,x,y,xx,yy,xxx,yyy;
    while(scanf("%d%d%d%d%d%d",&x,&y,&xx,&yy,&xxx,&yyy)!=EOF){
        if(x==xx && x==xxx || y==yy && y==yyy){
            puts("1");continue;
        }
        if(x==xx && (y==yyy || yy==yyy)){
            puts("2");continue;
        }
        if(x==xxx && (y==yy || yyy==yy)){
            puts("2");continue;
        }
        if(xx==xxx && (yy==y || yyy==y)){
            puts("2");continue;
        }
        if(y==yy && xxx!=xx && xxx!=x){
            if(xxx<max(xx,x) && xxx>min(xx,x)){
                printf("3\n");continue;
            }
            else {
                    puts("2");continue;
            }
        }
        if(y==yyy && xx!=xxx && xx!=x){
            if(xx<max(xxx,x) && xx>min(xxx,x)){
                puts("3");continue;
            }else {
                printf("2\n");continue;
            }
        }
        if(yy==yyy && x!=xx && x!=xxx){
            if(x<max(xx,xxx) && x>min(xx,xxx)){
                printf("3\n");continue;
            }else {
                puts("2");continue;
            }
        }
        if(x==xx && yyy!=yy && yyy!=y){
            if(yyy<max(yy,y) && yyy>min(yy,y)){
                printf("3\n");continue;
            }
            else {
                puts("2");continue;
            }
        }
        if(x==xxx && yy!=yyy && yy!=y){
            if(yy<max(yyy,y) && yy>min(yyy,y)){
                puts("3");continue;
            }else {
                printf("2\n");continue;
            }
        }
        if(xx==xxx && y!=yy && y!=yyy){
            if(y<max(yy,yyy) && y>min(yy,yyy)){
                printf("3\n");continue;
            }else {
                puts("2");continue;
            }
        }
        puts("3");
    }
    return 0;
}
