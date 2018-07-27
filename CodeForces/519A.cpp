/****************
*PID:519a div2
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
    int i,j,k,n;
    int sum1=0,sum2=0;
    char c;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            scanf(" %c",&c);
            if(c>='a' && c<='z'){
                if(c=='q') sum1+=9;
                else if(c=='r') sum1+=5;
                else if(c=='b') sum1+=3;
                else if(c=='n') sum1+=3;
                else if(c=='p') sum1+=1;
            }else if(c>='A' && c<='Z'){
                if(c=='Q') sum2+=9;
                else if(c=='R') sum2+=5;
                else if(c=='B') sum2+=3;
                else if(c=='N') sum2+=3;
                else if(c=='P') sum2+=1;
            }
        }
    }
    if(sum2>sum1)
        printf("White\n");
    else if(sum2<sum1)
        printf("Black\n");
    else printf("Draw\n");
    return 0;
}
