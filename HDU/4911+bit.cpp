/*
ƒÊ–Ú∂‘(BIT+¿Î…¢ªØ)
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=100000+10;
int bit[maxn],pos[maxn],n;

struct pp{
    int v,id;
}s[maxn];

int cmp(const pp &x,const pp &y){
    return x.v<y.v;
}

void add(int i,int v){
    while(i<=n){
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
    int i,j,k,cnt;
    ll res;
    while(scanf("%d%d",&n,&k)!=EOF){
        for(i=1;i<=n;i++){
            scanf("%d",&s[i].v);
            s[i].id=i;
        }
        sort(s+1,s+n+1,cmp);
        memset(bit,0,sizeof(bit));
        pos[s[1].id]=1;
        for(i=2;i<=n;i++){
            if(s[i].v==s[i-1].v)
                pos[s[i].id]=pos[s[i-1].id];
            else
                pos[s[i].id]=pos[s[i-1].id]+1;
        }
        res=0;
        for(i=n;i>0;i--){
            res+=sum(pos[i]-1);
            add(pos[i],1);
        }
        if(res-k<=0)
            printf("0\n");
        else
            printf("%lld\n",res-k);
    }
    return 0;
}

