/*
中位数前面的添1，其他的填中位数
*/
#include <stdio.h.>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

const int maxn=1000+5;
int a[maxn];

int main()
{
    int i,j,sum,cnt,n,k,p,x,y;
    //k是已知门数，[1,p],sum<=x  median>=y
    scanf("%d%d%d%d%d",&n,&k,&p,&x,&y);
    sum=cnt=0;
    for(i=1;i<=k;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
        if(a[i]<y) cnt++;
    }
    if(sum>x || cnt>n/2){
        printf("-1\n");
        return 0;
    }else if(n-k<=(n/2-cnt)){
        if(n-k+sum>x){
            printf("-1\n");return 0;
        }
    }else {
        if((n-k-(n/2-cnt))*y+sum+n/2-cnt>x){
            printf("-1\n");return 0;
        }
    }
    int f=0;
    for(i=0;i<n/2-cnt && i<n-k;i++){
        if(f) printf(" ");
        f++;
        printf("1");
    }
    for(i=n/2-cnt;i<n-k;i++){
        if(f) printf(" ");
        f++;
        printf("%d",y);
    }
    printf("\n");
    return 0;
}

/*
9 7 2 14 1
2 2 2 1 1 2 2

5 4 100 14 4
4 4 4 4

*/
