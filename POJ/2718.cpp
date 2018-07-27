/****************
*PID:poj2718
*Auth:Jonariguez
*****************
*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ALL(a) a.begin(),a.end()
typedef long long LL;

int s[15],vis[15],n,res;
int ba,bb;

int cmp(int a,int b){
    return a>b;
}

int cal(int *v,int n){
    if(n==0 || (n==1 && v[0]==0))
        return 0;
    int i;
    int res=0;
    if(v[0]==0){
        int t=v[0];v[0]=v[1];v[1]=t;
    }
    for(i=0;i<n;i++)
        res=res*10+v[i];
    return res;
}

void solve(int now){
    int p[11],a[11],i,m=0;
    for(i=0;i<n;i++)
        if(!vis[i]) a[m++]=s[i];
    do {
        if(a[0]!=0){
            int t=cal(a,m);
            if(fabs(now-t)<res){
                res=fabs(now-t);ba=now;bb=t;
            }
          //  res=min(res,(int)fabs(now-cal(a,m)));
        }
    }while(next_permutation(a,a+m));
}

void dfs(int cur,int now){
    if(cur==n/2){
        solve(now);return ;
    }
    int i;
    for(i=0;i<n;i++){
        if(!vis[i]){
            if(s[i]==0 && cur==0) continue;
            vis[i]=1;
            dfs(cur+1,now*10+s[i]);
            vis[i]=0;
        }
    }
}

int main()
{
    int i,j,T;
    char str[50];
    scanf("%d",&T);
    getchar();
    while(T--){
        gets(str);
        int len=strlen(str);
        n=0;
        for(i=0;i<len;i++){
            s[n++]=str[i]-'0';
            i++;
        }
        if(n&1){
            int a[11],tot=0;
            for(i=0;i<n/2+1;i++)
                a[tot++]=s[i];
            int ra=cal(a,tot);
            tot=0;
            for(i=n-1;i>n/2;i--)
                a[tot++]=s[i];
            int rb=cal(a,tot);
            printf("%d\n",ra-rb);
        }else if(n==2){
            printf("%d\n",(int)fabs(s[0]-s[1]));
        }else {
            memset(vis,0,sizeof(vis));
            res=1000000000;
            dfs(0,0);
         //   printf("%d %d \n",ba,bb);
            printf("%d\n",res);
        }

    }
    return 0;
}
