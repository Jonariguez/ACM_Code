/*
不处理xi<0的情况，只需要处理>0的情况
最后结果再*16即可。
不然会超时
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int maxn=2*40000+10;;
int a[maxn],b[maxn],c[maxn],d[maxn],s[maxn];
int p1[maxn],p2[maxn];

int main()
{
    int i,j,tot;
    tot=0;
    for(i=1;i<=100;i++){
        s[tot++]=i*i;
    }
    int A,B,C,D;
    while(scanf("%d%d%d%d",&A,&B,&C,&D)!=EOF){
     /*   for(i=0;i<tot;i++){
            a[i]=s[i]*A;
            b[i]=s[i]*B;
            c[i]=s[i]*C;
            d[i]=s[i]*D;
        }*/
        int cnt=0;
        for(i=0;i<tot;i++)
            for(j=0;j<tot;j++){
                p1[cnt]=A*s[i]+B*s[j];
                p2[cnt++]=C*s[i]+D*s[j];
            }
        sort(p2,p2+cnt);
        int res=0;
        for(i=0;i<cnt;i++)
            res+=upper_bound(p2,p2+cnt,-p1[i])-lower_bound(p2,p2+cnt,-p1[i]);
        printf("%d\n",res*16);
    }
    return 0;
}
