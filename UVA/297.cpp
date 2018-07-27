/****************
*ID:uva297
*Auth:Jonariguez
*****************
四分树，先序遍历序列就能确定一棵树，
这里遇到灰色就四下递归，遇到黑色就在该缓冲区
统计黑色点
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int len=32;   //最多包含了32*32个小正方形
const int maxn=1024+10;

int buf[33][33],cnt;
char s[maxn];


//将s[p..]导出到以（r，c）为左上角，边长为w的缓冲区中
void draw(const char* s,int& p,int r,int c,int w){
    char ch=s[p++];
    if(ch=='p'){
        draw(s,p,r,c+w/2,w/2);
        draw(s,p,r,c,w/2);
        draw(s,p,r+w/2,c,w/2);
        draw(s,p,r+w/2,c+w/2,w/2);
    }else if(ch=='f'){
        for(int i=r;i<r+w;i++)
            for(int j=c;j<c+w;j++)
                if(buf[i][j]==0){
                    buf[i][j]=1;cnt++;
                }
    }
}

int main()
{
    int i,T;
    scanf("%d",&T);
    while(T--){
        memset(buf,0,sizeof(buf));
        cnt=0;
        for(i=0;i<2;i++){
            scanf("%s",s);
            int p=0;
            draw(s,p,0,0,len);
        }
        printf("There are %d black pixels.\n", cnt);
    }
    return 0;
}
