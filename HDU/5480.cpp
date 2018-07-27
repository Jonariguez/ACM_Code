/****************
*PID:hdu5480
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+10;
int c[maxn];
bool h[maxn];
bool l[maxn];
int bit1[maxn],bit2[maxn];

void add(int *bit,int i,int v,int n){
    while(i<=n){
        bit[i]+=v;
        i+=i&(-i);
    }
}

int sum(int *bit,int i){
    int res=0;
    while(i>0){
        res+=bit[i];
        i-=i&(-i);
    }
    return res;
}

int main()
{
    int i,j,n,m,k,q,res,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&n,&m,&k,&q);
        int x,y;
        memset(bit1,0,sizeof(bit1));
        memset(bit2,0,sizeof(bit2));
        memset(h,0,sizeof(h));
        memset(l,0,sizeof(l));
        for(i=0;i<k;i++){
            scanf("%d%d",&x,&y);
            if(h[y]==0){
                add(bit1,y,1,n);
                h[y]=1;
            }
            if(l[x]==0){
                add(bit2,x,1,m);
                l[x]=1;
            }
        }
        int x1,y1,x2,y2;
        while(q--){
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(sum(bit1,y2)-sum(bit1,y1-1)<y2-y1+1 && sum(bit2,x2)-sum(bit2,x1-1)<x2-x1+1)
                printf("No\n");
            else
                printf("Yes\n");
        }
    }
    return 0;
}

