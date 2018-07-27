/****************
*PID:poj3617
*Auth:Jonariguez
*****************
Ì°ÐÄ
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=2000+10;
char str[maxn],res[maxn];

int main()
{
    int i,j,n,k,cnt;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf(" %c",&str[i]);
    bool left;
    k=0;
    i=1;j=n;
    while(k<n){
        left=true;
        int a=i,b=j;
        while(a<b){
            if(str[a]<str[b]) break;
            else if(str[a]>str[b]){
                left=false;break;
            }
            a++;b--;
        }
        if(left)
            res[k++]=str[i++];
        else res[k++]=str[j--];
    }
    for(i=1;i<=n;i++){
        printf("%c",res[i-1]);
        if(i%80==0)
            printf("\n");
    }
    return 0;
}
