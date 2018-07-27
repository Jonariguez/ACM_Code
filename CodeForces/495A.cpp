/****************
*PID:495a div2
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
int a[10][10];

int cal(int i,int A,int B){
    int x,y;
    x=i/10;y=i%10;
    return a[x][A]*a[y][B];
}
char s[3];
int main()
{
    int i,j,A,B,n,m;
    memset(a,0,sizeof(a));
    a[0][1]=a[0][7]=1;a[3][1]=a[3][7]=1;
    a[4][1]=1;a[6][5]=1;a[7][1]=1;a[8][1]=a[8][0]=a[8][2]=a[8][3]=a[8][4]=a[8][5]=a[8][6]=a[8][7]=a[8][9]=1;
    a[9][1]=a[9][3]=a[9][4]=a[9][5]=a[9][7]=1;
    for(i=0;i<=9;i++) a[i][i]=1;
    while(scanf("%s",s)!=EOF){
       // printf("A=%d,B=%d\n",A,B);
        A=s[0]-'0';B=s[1]-'0';
        int res=0;
        for(i=0;i<100;i++)
            res+=cal(i,A,B);
        printf("%d\n",res);
    }
    return 0;
}
