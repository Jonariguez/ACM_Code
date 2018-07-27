/****************
*PID:poj2443
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=10000+10;
const int SIZE=32;
int st[maxn][32];

int main()
{
    int i,j,n,m;
    scanf("%d",&n);
    memset(st,0,sizeof(st));
    for(i=0;i<n;i++){
        scanf("%d",&m);
        int a;
        while(m--){
            scanf("%d",&a);
            st[a][i/32]|=(1LL<<(i%32));
        }
    }
    scanf("%d",&m);
    int a,b;
    while(m--){
        scanf("%d%d",&a,&b);
        for(i=0;i<32;i++){
            if(st[a][i]&st[b][i]) break;
        }
        if(i<32) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
