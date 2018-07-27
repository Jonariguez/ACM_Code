/****************
*PID:525c div2
*Auth:Jonariguez
*****************
贪心，从最长的开始围矩形能得到最优
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=100000+10;
int a[maxn];

int cmp(int i,int j){
    return i>j;
}

int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF){
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n,cmp);
        LL res=0;
        int row,col;
        for(i=0;i<n-1;i++){
            if(abs(a[i]-a[i+1])>1) continue;
            row=min(a[i],a[i+1]);col=-1;
            for(j=i+2;j<n-1;j++){
                if(abs(a[j]-a[j+1])>1) continue;
                col=min(a[j],a[j+1]);break;
            }
            if(col==-1) break;
          //  printf("col=%d,row=%d\n",col,row);
            res+=(LL)col*row;
         //   printf("res=%I64d\n",res);
            i=j+1;
        }
        printf("%I64d\n",res);
    }
    return 0;
}
