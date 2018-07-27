#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int i,j,T,res,n,m,p,q;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&n,&m,&p,&q);
        if(m*p<=q)
            res=n*p;
        else {
            res=n/m*q;
            n%=m;
            res+=min(n*p,q);
        }
        printf("%d\n",res);
    }
    return 0;
}
