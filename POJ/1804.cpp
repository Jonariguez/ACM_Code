/****************
*PID:poj1804
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=2000000+2;
int bit[maxn],N;
int a[1010];

void add(int i){
    while(i<=N){
        bit[i]++;
        i+=i&(-i);
    }
}

int sum(int i){
    int res=0;
    while(i>0){
        res+=bit[i];
        i-=i&(-i);
    }
    return res;
}

int main()
{
    int i,j,k=1,res,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(bit,0,sizeof(bit));
        N=0;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            a[i]+=1000001;
            N=max(N,a[i]);
        }
        res=0;
        for(i=n;i>=1;i--){
            res+=sum(a[i]-1);
            add(a[i]);
        }
        printf("Scenario #%d:\n%d\n\n",k++,res);
    }
    return 0;
}
