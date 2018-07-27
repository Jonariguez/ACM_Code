/****************
*PID:hdu5658
*Auth:Jonariguez
*****************
回文树
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
#define sigmaSet 26
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

const int maxn=1000+10;
int res[maxn][maxn];
char str[maxn];

typedef struct Palindromic_Tree{
    int chi[maxn][sigmaSet],len[maxn],fail[maxn],S[maxn],num[maxn],cnt[maxn];
    int tot,n,last;

    int newNode(int L){
        memset(chi[tot],0,sizeof(chi[tot]));
        cnt[tot]=num[tot]=0;
        len[tot]=L;
        return tot++;
    }
    void Init(){
        tot=0;
        newNode(0);newNode(-1);
        last=n=0;
        S[n]=-1;
        fail[0]=1;
    }
    int get_fail(int x){
        while(S[n-len[x]-1]!=S[n])
            x=fail[x];
        return x;
    }
    void add(int c){
        S[++n]=c;
        int cur=get_fail(last);
        if(chi[cur][c]==0){
            int now=newNode(len[cur]+2);
            fail[now]=chi[get_fail(fail[cur])][c];
            chi[cur][c]=now;
            num[now]=num[fail[now]]+1;
        }
        last=chi[cur][c];
        cnt[last]++;
    }
    void cal(){
        for(int i=tot-1;i>=0;i--)
            cnt[fail[i]]+=cnt[i];
    }
};

Palindromic_Tree pt;

int main()
{
    int i,j,T,n,m;
    sc(T);
    while(T--){
        scanf("%s",str+1);
        n=strlen(str+1);
        for(i=1;i<=n;i++){
            pt.Init();
            for(j=i;j<=n;j++){
                pt.add(str[j]-'a');
                res[i][j]=pt.tot-2;     //去掉两个根
            }
        }
        scanf("%d",&m);
        while(m--){
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%d\n",res[a][b]);
        }
    }
    return 0;
}



