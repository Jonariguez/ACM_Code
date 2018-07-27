/****************
*PID:uva11039
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=500000+10;

int a[maxn];

int cmp(int a,int b){
    return abs(a)<abs(b);
}

int main()
{
    int i,j,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n,cmp);
        int res=1;
        bool yes=false;
        if(a[0]>0) yes=true;
        for(i=1;i<n;i++){
            if(a[i]<0 && yes){
                res++;yes=false;
            }else if(a[i]>0 && !yes){
                res++;yes=true;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
