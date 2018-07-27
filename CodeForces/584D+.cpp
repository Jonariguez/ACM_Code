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

bool vis[400];

void pre_solve(){
    int i,j;
    for(i=2;i<=300;i++)
        if(!vis[i])
            for(j=i*2;j<=300;j+=i) vis[j]=1;
}

bool check(int n){
    if(n==2 || n==3) return true;
    int i;
    for(i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}

int main()
{
    int i,n,p,P;
    pre_solve();
    while(scanf("%d",&n)!=EOF){
        if(check(n)){
            printf("1\n%d\n",n);continue;
        }else if(check(n-2)){
            printf("2\n2 %d\n",n-2);continue;
        }else if(check(n-4)){
            printf("3\n2 2 %d\n",n-4);continue;
        }else {
            p=n-2;
            while(!check(p))
                p--;
            n-=p;
            printf("3\n%d",p);
            for(i=2;i<=n/2;i++)
                if(!vis[i] && !vis[n-i]){
                    if(i)
                    printf(" %d",i);
                    if(n-i)
                    printf(" %d",n-i);
                    printf("\n");break;
                }
        }
    }
    return 0;
}
