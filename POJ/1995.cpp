/****************
*ID:poj1995
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int quick_multi(int a,int b,int m){
    a%=m;
    int res=0;
    while(b){
        if(b&1)
            res=(res+a)%m;
        b/=2;
        a=(a*2)%m;
    }
    return res;
}

int quick_pow(int a,int b,int m){
    a%=m;
    int res=1;
    while(b){
        if(b&1)
            res=quick_multi(res,a,m);
        b/=2;
        a=quick_multi(a,a,m);
    }
    return res;
}

int main()
{
    int i,j,T,n,a,b,res,m;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&m);
        scanf("%d",&n);
        res=0;
        for(i=0;i<n;i++){
            scanf("%d%d",&a,&b);
            res+=quick_pow(a,b,m);
            res%=m;
        }
        printf("%d\n",res);
    }
    return 0;
}
