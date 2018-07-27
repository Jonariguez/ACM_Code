/****************
*PID:uva1149
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
int a[maxn];

int main()
{
    int i,j,n,res,T,l;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&l);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        res=0;
        for(i=0,j=n-1;i<=j;i++){
            while(j>i && a[i]+a[j]>l){  //从前面挑选最小的，然后从后面从大往小找能和它一块放的，不能的就只能自己了
                res++;j--;
            }
            if(a[i]+a[j]>l){
                res++;break;
            }
            res++;
            j--;
        }
        printf("%d\n",res);
        if(T)
            printf("\n");
    }
    return 0;
}
