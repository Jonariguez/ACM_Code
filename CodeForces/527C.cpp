/****************
*PID:527C div2
*Auth:Jonariguez
*****************
线段树
分别在二维上维护最长区间，两个最长区间围成的矩形面积就是答案
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef __int64 LL;

const int maxn=200000+10;

typedef struct Tree{
    int sum[maxn*4],val[maxn*4],L[maxn*4],R[maxn*4];
    void pushUp(int k,int l,int r){
        int lc=k*2,rc=k*2+1,m=(l+r)/2;
        sum[k]=max(sum[lc],sum[rc]);
      //  if(k==1){
      //      printf("R[lc]=%d L[rc]=%d\n",R[lc],L[rc]);
      //  }
        if(val[m]==0)
            sum[k]=max(sum[k],R[lc]+L[rc]);
        if(L[lc]==m-l+1 && val[m]==0){
            L[k]=L[lc]+L[rc];//printf("???\n");
        }else
            L[k]=L[lc];
        if(R[rc]==r-m && val[m]==0){
            R[k]=R[rc]+R[lc];//printf("!!\n");
        }else
            R[k]=R[rc];
     //   printf("L[%d]=%d\n",lc,L[lc]);
     //   printf("R[%d]=%d\n",lc,R[lc]);
     //   printf("L[%d]=%d\n",k,L[k]);
     //   printf("sum[%d]=%d\n",k,sum[k]);
    }
    void build(int k,int l,int r){
        sum[k]=0;
        val[k]=0;
        if(l==r){
            sum[k]=1;L[k]=1;R[k]=1;
            return ;
        }
        int m=(l+r)/2;
        build(k*2,l,m);
        build(k*2+1,m+1,r);
        pushUp(k,l,r);
    }
    void update(int p,int k,int l,int r){
        if(l==r){
            val[l]=1;return ;
        }
        int m=(l+r)/2;
        if(p<=m)
            update(p,k*2,l,m);
        else
            update(p,k*2+1,m+1,r);
        pushUp(k,l,r);
    }
    int get(){
        return sum[1];
    }
}Tree;

Tree wd,hd;

int main()
{
    int i,w,h,n;
    scanf("%d%d%d",&w,&h,&n);
    wd.build(1,1,w);
    hd.build(1,1,h);
  //  printf("w=%d  h=%d\n",wd.get(),hd.get());
    while(n--){
        char s[3];
        int d;
        scanf("%s%d",s,&d);
        if(s[0]=='V')
            wd.update(d,1,1,w);
        else
            hd.update(d,1,1,h);
     //   printf("w=%d  h=%d\n",wd.get(),hd.get());
        printf("%I64d\n",(LL)wd.get()*hd.get());
    }
    return 0;
}
