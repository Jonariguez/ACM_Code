/****************
*PID:poj3069
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000+10;
int a[maxn];

int main()
{
    int i,r,n,start,res;
    while(scanf("%d%d",&r,&n)){
        if(r==-1 && n==-1) break;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        res=0;start=a[0];
        i=0;
        while(i<n){
            while(i+1<n && a[i+1]-start<=r)
                i++;
            if(i>=n) break;
            res++;
            start=a[i];
            i++;
            while(i<n && a[i]-start<=r)
                i++;
            if(i>=n) break;
            start=a[i];
        }
        printf("%d\n",res);
    }
    return 0;
}
