#include <stdio.h>
#include <string.h>
typedef long long ll;

const int maxn=1024+10;
int bit[maxn][maxn],s;

void add(int x,int y,int v){
    int temp;
    while(x<=s){
        temp=y;
        while(temp<=s){
            bit[x][temp]+=v;
            temp+=temp&(-temp);
        }
        x+=x&(-x);
    }
}

ll sum(int x,int y){
    int temp;
    ll res=0;
    while(x>0){
        temp=y;
        while(temp>0){
            res+=bit[x][temp];
            temp-=temp&(-temp);
        }
        x-=x&(-x);
    }
    return res;
}


int main()
{
    int i,j,x,y,v,l,r,b,t,p;
    scanf("%d%d",&p,&s);
    while(scanf("%d",&p) && p!=3){
        if(p==1){
            scanf("%d%d%d",&x,&y,&v);
            add(x+1,y+1,v);
        }else{
            scanf("%d%d%d%d",&l,&b,&r,&t);
            ll t1=sum(r+1,t+1),t2=sum(r+1,b),t3=sum(l,t+1),t4=sum(l,b);
            printf("%lld\n",t1-t2-t3+t4);
        }
    }
    return 0;
}
