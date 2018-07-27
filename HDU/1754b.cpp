#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn=200000+10;
int dat[maxn*4];
int n,m;

void update(int k,int v){
    k+=m-1;
    dat[k]=v;
    while(k>1){
        k/=2;
        dat[k]=max(dat[k*2],dat[k*2+1]);
    }
}

int maxv;

//用全局变量更新结果时，只需要在包含时更新，然后根据区间中点M判断是否向做后向右走
void ask(int a,int b,int k,int l,int r){
    if(a<=l && r<=b){
        maxv=max(maxv,dat[k]);return ;
    }
    int M=(l+r)/2;
    if(a<=M) ask(a,b,k*2,l,M);
    if(b>M)  ask(a,b,k*2+1,M+1,r);
}

int main()
{
    int i,j,k,q;
    char s[4];
    while(scanf("%d%d",&n,&q)!=EOF){
        m=1;
        while(m<n) m*=2;
        memset(dat,0,sizeof(dat));
        for(i=1;i<=n;i++){
            scanf("%d",&k);
            update(i,k);
        }
        while(q--){
            int a,b;
            scanf("%s%d%d",s,&a,&b);
            if(s[0]=='Q'){
                maxv=-1;
                ask(a,b,1,1,m);
                printf("%d\n",maxv);
            }
            else update(a,b);
        }
    }
    return 0;
}


