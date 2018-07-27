/****************
*PID:592a div2
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
char s[10][10];

int main()
{
    int i,j,n,cnta=0,cntb=0;
    int rowa=0,cola,rowb=0,colb;
    for(i=1;i<=8;i++)
        scanf("%s",s[i]+1);
    for(i=1;i<=8;i++){
        for(j=1;j<=8;j++)
            if(s[i][j]=='W'){
                int k;
                for(k=i-1;k>=1;k--)
                    if(s[k][j]=='B') break;
                if(k<1){
                    rowa=i;cola=j;
                }
            }
        if(rowa) break;
    }
    for(i=8;i>=1;i--){
        for(j=1;j<=8;j++)
            if(s[i][j]=='B'){
                int k;
                for(k=i+1;k<=8;k++)
                    if(s[k][j]=='W') break;
                if(k>8){
                    rowb=i;colb=j;
                }
            }
        if(rowb) break;
    }
    cnta=rowa-1;cntb=8-rowb;
    if(cnta<=cntb)  //A先走，所以要有等号
        printf("A\n");
    else printf("B\n");
    return 0;
}
