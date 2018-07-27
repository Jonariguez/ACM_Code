/****************
*PID:584D div1
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

bool check(int n){
    if(n==0 || n==1) return false;
    if(n==2 || n==3) return true;
    int i;
    for(i=2;(LL)i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}

int main()
{
    int i,n,p,P;
    while(scanf("%d",&n)!=EOF){
        if(check(n)){
            printf("1\n%d\n",n);continue;
        }else if(check(n-2)){
            printf("2\n2 %d\n",n-2);continue;
        }else if(check(n-4)){
            printf("3\n2 2 %d\n",n-4);continue;
        }else {
            n-=3;
            printf("3\n3");
            for(i=2;i<=n/2;i++)
                if(check(i) && check(n-i)){
                    printf(" %d %d\n",i,n-i);
                    break;
                }
        }
    }
    return 0;
}
