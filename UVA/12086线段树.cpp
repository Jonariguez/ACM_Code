#include <stdio.h>
#include <string.h>
typedef long long ll;

const int maxn=200000+10;

ll sum[maxn*4];

void pushUp(int k){
    sum[k]=sum[k*2]+sum[k*2+1];
}

void update(int p,int v,int k,int l,int r){
    if(l==r){
        sum[k]=v;return ;
    }
    int m=(l+r)/2;
    if(p<=m)
        update(p,v,k*2,l,m);
    else
        update(p,v,k*2+1,m+1,r);
    pushUp(k);
}

ll ask(int a,int b,int k,int l,int r){
    if(a<=l && r<=b)
        return sum[k];
    int m=(l+r)/2;
    ll res=0;
    if(a<=m)
        res+=ask(a,b,k*2,l,m);
    if(b>m)
        res+=ask(a,b,k*2+1,m+1,r);
    return res;
}

int main()
{
    int i,j,kcase=1,a,n,x,y;
    char s[3];
    bool flag=false;
    scanf("%d",&n);
    while(n){
        for(i=1;i<=n;i++){
            scanf("%d",&a);
            update(i,a,1,1,n);
        }
        printf("Case %d:\n",kcase++);
        while(scanf("%s",s)){
            if(strcmp(s,"END")==0) break;
            scanf("%d%d",&x,&y);
            if(s[0]=='S')
                update(x,y,1,1,n);
            else
                printf("%lld\n",ask(x,y,1,1,n));
        }
        scanf("%d",&n);
        if(n)
            printf("\n");
    }
    return 0;
}
