#include <stdio.h>

const int maxn=100000+10;
int a[maxn];

int Min(int x,int y){
    if(x<y) return x;
    return y;
}

int main()
{
    int i,j,T,t,s,res,sum,S,n;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&S);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sum=0;
        s=t=0;
        res=n+1;
        for(;;){
            while(t<n && sum<S)
                sum+=a[t++];
            if(sum<S) break;
            res=Min(res,t-s);
            sum-=a[s++];
        }
        if(res>n)
            printf("0\n");
        else
            printf("%d\n",res);
    }
    return 0;
}
