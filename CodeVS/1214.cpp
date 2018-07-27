/****************
*PID:cdvs1214
*Auth:Jonariguez
*****************
¾­µäÇø¼ä¸²¸Ç
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=100+10;
struct pp{
    int st,en;
}s[maxn];

int cmp(const pp &x,const pp &y){
    return x.en<y.en;
}

int main()
{
    int i,j,n,res;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        s[i].st=min(a,b);s[i].en=max(a,b);
    }
    sort(s+1,s+n+1,cmp);
    res=1;
    int now=s[1].en;
    for(i=2;i<=n;i++){
        if(s[i].st>=now){
            now=s[i].en;res++;
        }
    }
    printf("%d\n",res);
    return 0;
}
