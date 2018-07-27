#include <stdio.h>
typedef __int64 ll;
ll base[11]={0,9,90*2,900*3,9000*4,90000*5,900000*6,9000000*7,720000000,8100000000};

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        long long res=0,now=1;
        i=0;
        while(n>=now){
            res+=base[i++];
            now*=10;
        }
        res+=(n-now/10+1)*i;
        printf("%I64d\n",res);
    }
    return 0;
}
