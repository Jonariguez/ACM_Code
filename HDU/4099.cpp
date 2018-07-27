/****************
*PID:hdu4099
*Auth:Jonariguez
*****************
*/
#define lson k*2,l,m
#define rson k*2+1,m+1,r
#define rep(i,s,e) for(i=(s);i<=(e);i++)
#define For(j,s,e) For(j=(s);j<(e);j++)
#define sc(x) scanf("%d",&x)
#define In(x) scanf("%I64d",&x)
#define pf(x) printf("%d",x)
#define pfn(x) printf("%d\n",(x))
#define Pf(x) printf("%I64d",(x))
#define Pfn(x) printf("%I64d\n",(x))
#define Pc printf(" ")
#define PY puts("YES")
#define PN puts("NO")
#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef int Ll;
Ll quick_pow(Ll a,Ll b,Ll MOD){a%=MOD;Ll res=1;while(b){if(b&1)res=(res*a)%MOD;b/=2;a=(a*a)%MOD;}return res;}

const int maxn=100000+10;
int a[105],b[105],c[105],d[105];

struct Trie{
    int chi[maxn*70][10],val[maxn*70],Size;
    void Init(){
        memset(chi[0],0,sizeof(chi[0]));memset(val,0,sizeof(val));Size=1;
    }
    void Insert(int *c,int s,int e,int id){
        int i,now=0;
        for(i=s;i>=e;i--){
            int v=c[i];
            if(chi[now][v]==0){
                memset(chi[Size],0,sizeof(chi[Size]));
                val[Size]=id;
                chi[now][v]=Size++;
            }
            now=chi[now][v];
        }
    }
    int ask(char *str){
        int i,n=strlen(str),now=0;
        for(i=0;i<n;i++){
            int v=(str[i]-'0');
            if(chi[now][v]==0) return -1;
            now=chi[now][v];
        }
        return val[now];
    }
}trie1;


void Init(){
    trie1.Init();
    int i,j,k,cnt;
    a[1]=b[1]=1;
    c[1]=1;
    trie1.Insert(c,1,1,0);
    for(k=2;k<100000;k++){
        cnt=0;
        memset(c,0,sizeof(c));
        for(i=1;i<=100;i++){
            int temp=a[i]+b[i]+cnt;
            c[i]=temp%10;
            cnt=temp/10;
        }
        for(i=100;i>=1;i--)
            if(c[i]) break;
        int h=i,s=max(1,i-39);
        trie1.Insert(c,i,s,k);
        if(h>60){
            for(j=1;j<h;j++)
                c[j]=c[j+1];
            for(j=1;j<h;j++)
                b[j]=b[j+1];
            for(j=h;j<=100;j++) c[j]=b[j]=0;
          /*  cnt=1;
            for(j=h-59;j<=h;j++){   //大于60位了，就截图最高位的60位，注意b要和c同时截取。
                c[cnt]=c[j];    //因为避免这种情况的出现：633+654=1287 假设截取前3位,c->128 b应该为65，而不是654
                b[cnt++]=b[j];
            }
            for(j=cnt;j<=100;j++) c[j]=b[j]=0;*/
        }
        memset(a,0,sizeof(a));
        for(i=1;i<=100;i++){
            a[i]=b[i];
        }
        for(i=1;i<=100;i++)
            b[i]=c[i];
    }
}

int main()
{
    int i,j,kcase=1,T;
    Init();
    scanf("%d",&T);
    char str[222];
    while(T--){
        scanf("%s",str);
        printf("Case #%d: %d\n",kcase++,trie1.ask(str));
    }
    return 0;
}


