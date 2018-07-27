/****************
*PID:la4382
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=1000000+10;
int sum[maxn],f[maxn];

int Judge(int n){
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return 0;
    return 1;
}

void pre_solve(){
    sum[0]=0;sum[1]=0;
    int temp=3+7;
    for(int i=2;i<=1000000;i++){
        temp+=3;
        sum[i]=sum[i-1]+Judge(temp);
    }
}


int main()
{
    int i,j,n,T;
    pre_solve();
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        printf("%d\n",sum[n]);
    }
    return 0;
}
