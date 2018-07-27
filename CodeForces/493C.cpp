/****************
*PID:493c div2
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=200000+10;
int a[maxn],b[maxn],c[maxn*2];
int n,m,tot;

int main()
{
    int i,j;
    while(scanf("%d",&n)!=EOF){
        tot=0;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            c[tot++]=a[i];
        }
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%d",&b[i]);
            c[tot++]=b[i];
        }
        c[tot++]=0;
        sort(a,a+n);
        sort(b,b+m);
        sort(c,c+tot);
        int sum1=0,sum2=0,res=-2000000000,v=0;
        for(i=0;i<tot;i++){
            int x=c[i];
            int p1=upper_bound(a,a+n,x)-a;
            sum1=p1*2+(n-p1)*3;
            int p2=upper_bound(b,b+m,x)-b;
            sum2=p2*2+(m-p2)*3;
            if(res<sum1-sum2 || res==sum1-sum2 && sum1>v){
                res=sum1-sum2;v=sum1;
            }
        }
        printf("%d:%d\n",v,v-res);
    }
    return 0;
}


