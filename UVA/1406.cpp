/****************
*ID:uva1406
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

const int Top=1<<16;

/*
bit[b][v]的意义是：对2^(b+1)取余等于v的数的个数。
是先n个数映射到bit中，并计数，然后查询时在[0,2^(v+1))
枚举i，并把i加上add标记，如果第v位为1，则累加bit[v][i],
如果一开始输入的n个数有等于i的数，设为x，那么此时bit[v][i]
就是一定会由x预处理时映射到，所以res就应当累加bit[v][i]

bit的意义其实就是hash
*/
int bit[17][Top];

int main()
{
    int i,j,n,a,kcase=1;
    while(scanf("%d",&n)){
        if(n==-1) break;
        memset(bit,0,sizeof(bit));
        for(i=0;i<n;i++){
            scanf("%d",&a);
            for(j=0;j<16;j++)
                bit[j][a%(1<<(j+1))]++;
        }
        long long res=0,add=0;
        char s[3];
        int v;
        while(scanf("%s",s)){
            if(s[0]=='E') break;
            scanf("%d",&v);
            if(s[0]=='C'){
                add+=v;add%=Top;
            }else{
                int remain=add%(1<<(v+1)),Max=(1<<(v+1));
                for(i=0;i<Max;i++)
                    if((remain+i)&(1<<v))
                        res+=bit[v][i];
            }
        }
        printf("Case %d: %lld\n",kcase++,res);
    }
    return 0;
}
