/****************
*PID:uva3177
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=100000+10;
int R[maxn],left[maxn],right[maxn],n;

bool C(int x){
    int l=R[1],r=x-R[1];
    left[1]=R[1];right[1]=0;
    for(int i=2;i<=n;i++){
        int v=R[i];
        if(i&1){
            if(v<=r-right[i-1]){
                right[i]=v;left[i]=0;
            }else {
                v-=r-right[i-1];right[i]=r-right[i-1];
                left[i]=v;
            }
        }else {
            if(v<=l-left[i-1]){
                left[i]=v;right[i]=0;
            }else {
                v-=l-left[i-1];left[i]=l-left[i-1];
                right[i]=v;
            }
        }
    }
    return left[n]==0;
}


int main()
{
    int i,j;
    while(scanf("%d",&n),n){
        for(i=1;i<=n;i++){
            scanf("%d",&R[i]);
        }
        if(n==1){
            printf("%d\n",R[1]);continue;
        }
        int l=0,r=0;
        R[n+1]=R[1];
        for(i=1;i<=n;i++)
            l=max(l,R[i]+R[i+1]);
        if(n&1){
            for(i=1;i<=n;i++) r=max(r,R[i]*3);
            while(l<r){
                int m=l+(r-l)/2;
                if(C(m))
                    r=m;
                else l=m+1;
            }
        }
        printf("%d\n",l);
    }
    return 0;
}
