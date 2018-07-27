/****************
*PID:hdu1540
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=50000+10;
int n,m,bit[maxn],vis[maxn];

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

stack<int> ss;

bool C(int i,int x){
    return sum(x)-sum(i-1)==(x-i+1);
}

bool C2(int x,int i){
    return sum(i)-sum(x-1)==i-x+1;
}

int main()
{
    int i,j,x;
    while(scanf("%d%d",&n,&m)!=EOF){
        memset(bit,0,sizeof(bit));
        memset(vis,0,sizeof(vis));
        for(i=1;i<=n;++i)
            add(i,1);
        char str[4];
        while(m--){
            scanf("%s",str);
            if(str[0]=='D'){
                scanf("%d",&x);
                if(vis[x]==0)
                    add(x,-1);
                ss.push(x);
                vis[x]=1;
            }else if(str[0]=='Q'){
                scanf("%d",&x);
                if(vis[x]) printf("0\n");
                else {
                    int l=1,r=x,res=0;
                    while(l<r){
                        int M=(l+r)/2;
                        if(C(M,x))
                            r=M;
                        else l=M+1;
                    }
                //    printf("l=%d r=%d\n",l,r);
                    res=x-l+1;
                    l=x;r=n;
                    while(l<r){
                        int M=(l+r)/2+1;
                        if(C(x,M))
                            l=M;
                        else r=M-1;
                    }
                 //   printf("l=%d r=%d\n",l,r);
                    res+=r-x;
                    printf("%d\n",res);
                }
            }else {
                x=ss.top();ss.pop();
                if(vis[x])
                    add(x,1);
                vis[x]=0;
            }
        }
    }
    return 0;
}
