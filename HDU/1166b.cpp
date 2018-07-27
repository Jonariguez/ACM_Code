/*
 构造完全二叉树
 */
#include <stdio.h>
#include <string.h>
typedef long long ll;

const int maxn=50000+10;
int dat[maxn*4];
int n,m;

void update(int k,int v){
    k+=m-1;
    dat[k]+=v;
    while(k>1){
        k/=2;
        dat[k]=dat[k*2]+dat[k*2+1];
    }
}

ll query(int a,int b,int k,int l,int r){
    if(a<=l && r<=b) return dat[k];
    int M=(l+r)/2;
    ll res=0;
    if(a<=M) res+=query(a,b,k*2,l,M);
    if(b>M)  res+=query(a,b,k*2+1,M+1,r);
    return res;
}

int main()
{
    int i,j,k,T,kcase=1;
    char s[5];
    scanf("%d",&T);
    while(T--){
        printf("Case %d:\n",kcase++);
        scanf("%d",&n);
        memset(dat,0,sizeof(dat));
        m=1;
        while(m<n) m*=2;
        for(i=1;i<=n;i++){
            scanf("%d",&k);
            update(i,k);
        }
        while(scanf("%s",s)){
            if(s[0]=='E') break;
            int a,b;
            scanf("%d%d",&a,&b);
            if(s[0]=='A')
                update(a,b);
            else if(s[0]=='S')
                update(a,-b);
            else
                printf("%lld\n",query(a,b,1,1,m));      //注意这里是m不是n，因为最底层是m个叶子节点(完全二叉树)
        }
    }
    return 0;
}
