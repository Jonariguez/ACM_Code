/****************
*PID:630i
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
LL sum[maxn],a[maxn];
struct pp{
    LL v,id;
}s[maxn];

int cmp1(const pp &a,const pp &b){
    return a.v<b.v;
}

int cmp2(const pp &a,const pp &b){
    return a.id<b.id;
}

int main()
{
    LL i,j,n,A,cf,cm,m;
    while(scanf("%I64d%I64d%I64d%I64d%I64d",&n,&A,&cf,&cm,&m)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%I64d",&s[i].v);
            s[i].id=i;
        }
        sort(s+1,s+n+1,cmp1);
        sum[0]=0;
        for(i=1;i<=n;i++){
            a[i]=s[i].v;
            sum[i]=sum[i-1]+a[i];
        }
        LL res=0,T=m,l,r,maxnum=0,minv=A;
        for(i=0;i<=n;i++){
            m=T-(i*A-(sum[n]-sum[n-i]));  //»¹Ê£m¸ö
          //  printf("m=%I64d ",m);
            if(m<0) break;
            l=a[1];r=A;
            while(l<r-1){
                LL M=(l+r)/2;
                LL t=upper_bound(a+1,a+n-i+1,M)-a;
                if(t>=n-i+1) t=n-i;
                if(a[t]>M) t--;
             //   printf(" t=%I64d ",t);
                if(M*t-sum[t]>m)
                    r=M;
                else l=M;
            }
          //  printf("l=%I64d\n",l);
          //  l=r;
            if(i*cf+l*cm>res){
                res=i*cf+l*cm;//puts("???");
                maxnum=i;minv=l;
            }
        }
        for(i=n;i>n-maxnum;i--) s[i].v=A;
        for(i=1;i<=n;i++)
            if(s[i].v<minv) s[i].v=minv;
        printf("%I64d\n",maxnum*cf+s[1].v*cm);
        sort(s+1,s+n+1,cmp2);
        for(i=1;i<=n;i++)
            printf("%I64d ",s[i].v);
        puts("");
    }
    return 0;
}




