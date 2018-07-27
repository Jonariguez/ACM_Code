/****************
*PID:uva1618
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=5000+5;

unsigned short small_L[maxn][maxn],small_R[maxn][maxn],big_L[maxn][maxn],big_R[maxn][maxn];
int a[maxn];

void pre_solve(int n){
    int i,j,t;
    for(int p=1;p<=n-3;p++){        //for P,cal small_R[] and big_R[]
        int x=a[p],last_s=-1,last_b=-1;
        for(j=p+1;j<=n;j++){
            if(a[j]>a[p]){
                big_R[p][j]=last_b;last_b=j;
                small_R[p][j]=last_s;
            }else{
                small_R[p][j]=last_s;last_s=j;
                big_R[p][j]=last_b;
            }
        }
    }
    for(int s=n;s>=4;s--){
        int last_s=-1,last_b=-1;
        for(j=s-1;j>=1;j--){
            if(a[j]>a[s]){
                big_L[s][j]=last_b;last_b=j;
                small_L[s][j]=last_s;
            }else{
                small_L[s][j]=last_s;last_s=j;
                big_L[s][j]=last_b;
            }
        }
    }
}

int main()
{
    int i,T,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        pre_solve(n);
        bool yes=false;
        int s,p,q,r;
        for(p=1;p<=n-3;p++){
            for(s=n;s-p>=3;s--){
                int x=big_R[p][s],y=small_L[s][p];
                if(a[s]<a[p] && x!=65535 && y!=65535 && x>y){
                    yes=true;break;
                }
                x=small_R[p][s],y=big_L[s][p];
                if(a[s]>a[p] && x!=65535 && y!=65535 && x>y){
                    yes=true;break;
                }
            }
            if(yes) break;
        }
        if(yes)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}



