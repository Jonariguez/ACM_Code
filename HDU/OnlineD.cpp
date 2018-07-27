/****************
*PID:D
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=1000+10;
int a[maxn],o[maxn];

int main()
{
    int i,j,q,x,n,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        int root;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        root=a[1];
        scanf("%d",&q);
        for(i=0;i<q;i++)
            scanf("%d",&o[i]);
        for(i=0;i<q;i++){
            int x=o[i];
            if(o[i]==a[1]){
                printf("\n");
                continue;
            }
            root=a[1];j=1;
            while(root!=x){
                if(x<root){
                    printf("E");
                    root=a[j+1];
                    j++;
                }else {
                    printf("W");
                    int v;
                    for(v=j+1;v<=n;v++)
                        if(a[v]>root) break;
                    root=a[v];j=v;
                }
            }
            printf("\n");
        }
    }
    return 0;
}

