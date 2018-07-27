/****************
*PID:603a div1
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
char str[maxn];

int main()
{
    int i,j,m,n;
    while(scanf("%d",&n)!=EOF){
        scanf("%s",str+1);
        if(n==1 || n==2){
            printf("%d\n",n);continue;
        }
        int res=1,d=str[1]-'0';
        for(i=2;i<=n;i++){
            if(str[i]-'0'==(d^1)){
                res++;d^=1;
            }
        }
        int yes=0,s=1,t=n;
        for(s=2;s<=n;s++)
            if(str[s]==str[s-1]) break;
        for(t=n-1;t>=1;t--)
            if(str[t]==str[t+1]) break;
        if(s<=n && t>=1 && s!=t+1)
            res+=2;
        else {
            for(i=2;i<n;i++)
                if(str[i]==str[i-1] && str[i]==str[i+1]){
                    yes=1;break;
                }
            if(yes) res+=2;
            else {
                for(i=1;i+3<=n;i++)
                    if(str[i]==str[i+1] && str[i+2]==str[i+3] && str[i+1]!=str[i+2]){
                        yes=1;break;
                    }
                if(yes) res+=2;
                else {
                    int y=0;
                    if(str[1]==str[2] || str[n-1]==str[n] || (n>=3 && str[1]!=str[2] && str[2]==str[3]) || (n>=3 && str[n]!=str[n-1] && str[n-1]==str[n-2])) y=1;
                    if(y) res++;
                    else
                        for(j=1;j<n;j++)
                            if(str[j]==str[j+1]){
                                res++;break;
                            }
                }
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
