/****************
*PID:poj2893
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000000+5;
int bit[maxn],N;
int a[maxn];

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
    int i,j,n,m,xi,xj;
    while(scanf("%d%d",&n,&m)){
        if(n==0 && m==0) break;
        N=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                N++;
                scanf("%d",&a[N]);
                if(a[N]==0)
                    xi=i;
            }
        }
        memset(bit,0,sizeof(bit));
        int res=0;
        for(i=N;i>=1;i--){
            if(a[i]==0) continue;
            res+=sum(a[i]-1);
            add(a[i]);
        }
        if(m&1){
            if(res&1) printf("NO\n");
            else printf("YES\n");
        }else {
            if((res&1)!=((n-xi)&1))
                printf("NO\n");
            else printf("YES\n");
        }
    }
    return 0;
}
