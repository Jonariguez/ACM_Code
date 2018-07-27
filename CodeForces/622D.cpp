/****************
*PID:622d edu7
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=1000000+10;
int a[maxn],n;

int main()
{
    int i,j,now,left,right;
    while(scanf("%d",&n)!=EOF){
        if(n==1){
            printf("1 1\n");continue;
        }
        int b=0;
        if(n&1){
            left=1;right=n;
            for(i=1;i<n;i+=2){
                a[left]=i;a[right]=i;
                left++;right--;
            }
            a[left]=n;
            left=n+2;right=2*n;
            for(i=2;i<=n;i+=2){
                a[left]=i;a[right]=i;
                left++;right--;
            }
            a[n+1]=n;
        }else {
            left=1;right=n;
            for(i=1;i<=n;i+=2){
                a[left]=i;a[right]=i;
                left++;right--;
            }
            left=n+2;right=2*n;
            for(i=2;i<n;i+=2){
                a[left]=i;a[right]=i;
                left++;right--;
            }
            a[left]=n;
            a[n+1]=n;
        }
        for(i=1;i<=2*n;i++)
            printf("%d ",a[i]);
        puts("");
    }
    return 0;
}




