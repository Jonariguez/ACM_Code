/*
BIT+二分
此题1A，我很惊讶啊
*/
#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;

const int maxn=50000+10;

int bit[maxn],a[maxn],vis[maxn],n,x;

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

stack<int> st;

bool C1(int d){
    return sum(x)-sum(d-1)==x-d+1;
}

bool C2(int d){
    return sum(d)-sum(x-1)==d-x+1;
}

int main()
{
    int i,j,m;
    char s[3];
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        add(i,1);
    while(m--){
        scanf("%s",s);
        if(s[0]=='D'){
            scanf("%d",&x);
            st.push(x);
            vis[x]=1;       //毁掉
            add(x,-1);
        }else if(s[0]=='R'){
            x=st.top();
            st.pop();
            vis[x]=0;
            add(x,1);
        }else{
            scanf("%d",&x);
            if(vis[x]){
                printf("0\n");
                continue;
            }
            int l=1,r=x,res=0;
            while(l<r){
                int M=(l+r)/2;
                if(C1(M))
                    r=M;
                else l=M+1;
            }
            res=x-l+1;
            l=x,r=n;
            while(l<r){
                int M=(l+r)/2+1;
                if(C2(M))
                    l=M;
                else r=M-1;
            }
            res+=r-x+1;
            printf("%d\n",res-1);
        }
    }
    return 0;
}
