/****************
*PID:uva10881
*Auth:Jonariguez
*****************
最后蚂蚁的相对位置不变
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn=10000+10;

struct Ant{
    int id;
    int p;
    int d;
    bool operator < (const Ant &r) const {
        return p<r.p;
    }
}bef[maxn],aft[maxn];

const char dir[][10]={"L","Turning","R"};
int order[maxn];

int main()
{
    int i,j,n,T,L,cas,kcase=1;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d%d",&L,&T,&n);
        char str[5];
        for(i=0;i<n;i++){
            int d,p;
            scanf("%d%s",&p,str);
            if(str[0]=='L') d=-1;
            else d=1;
            bef[i]=(Ant){i,p,d};
            aft[i]=(Ant){0,p+d*T,d};
        }
        sort(bef,bef+n);
        for(i=0;i<n;i++)
            order[bef[i].id]=i;
        sort(aft,aft+n);            //aft是终态，由于相对位置不变，那么aft[0]的状态就是一开始在最左边的蚂蚁的终态
        for(i=0;i<n-1;i++)
            if(aft[i].p==aft[i+1].p)
                aft[i].d=aft[i+1].d=0;  //如果位置相同，说明在Turning
        printf("Case #%d:\n",kcase++);
        for(i=0;i<n;i++){
            int a=order[i];             //第i个输入的蚂蚁，初态时从左向右排在a=order[i],那么aft[a]的状态就是第i个输入的蚂蚁的终态
            if(aft[a].p<0 || aft[a].p>L)
                printf("Fell off\n");
            else printf("%d %s\n",aft[a].p,dir[aft[a].d+1]);
        }
        printf("\n");
    }
    return 0;
}

