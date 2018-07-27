/*
BIT
因为每次都要往前调，所以就要前面预留出100000(q,查询的次数上限)个位置，
所以BIT建立在[100001,200000]上，询问第一次x1,把x1位置-1置0，然后调到100000处，
add(100000,1)，询问第二次x2,同样把x2处置0，调到99999处，add(99999,1)……
用mp映射每个光盘的位置
*/
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

const int maxn=100000+10;
int bit[maxn*2],n,ans[maxn],mp[maxn];

void add(int i,int v){
    while(i<=200000){
        bit[i]+=v;
        i+=i&(-i);
    }
}

int sum(int i){
    int res=0;
    while(i>0){
        res+=bit[i];
        i-=i&(-i);
    }
    return res;
}

int main()
{
    int i,T,q;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&q);
        memset(bit,0,sizeof(bit));
        for(i=1;i<=n;i++){
            add(i+100000,1);
            mp[i]=i+100000;
        }
        int x,tot=0,index=100000;
        while(q--){
            scanf("%d",&x);
            int t=mp[x];
            printf("%d",sum(t-1));
            add(t,-1);
            mp[x]=index--;
            add(mp[x],1);
            if(q)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
